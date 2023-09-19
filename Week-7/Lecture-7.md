# Lecture 7

## Flat-File Database

- As you have likely seen before, data can often be described ==in patterns of columns and tables==. Spreadsheets like those created in Microsoft Excel and Google Sheets can be ==outputted== to a `csv` or ==*comma-separated values* file==.

- If you look at a `csv` file, you’ll notice that the file is ==flat== in that all of our data is stored in a ==single table== represented by a text file. We call this form of data a *==flat-file database==*.

- Python comes with native support for `csv` files.

    ```python
    # Prints all favorites in CSV using csv.reader
    import csv
    
    # Open CSV file
    with open("favorites.csv", "r") as file:
        # Create reader
        reader = csv.reader(file)
        # Skip header row
        next(reader)
        # Iterate over CSV file, printing each favorite
        for row in reader:
            print(row[1])
    ```

    We created a `reader` that will hold the result of `csv.reader(file)`. The `csv.reader` function reads each row from the file, and in our code we store the results in `reader`.

- Python also allows you to index by the keys of a list. Modify your code as follows:

    ```python
    # Prints all favorites in CSV using csv.DictReader
    import csv
    
    # Open CSV file
    with open("favorites.csv", "r") as file:
        # Create DictReader
        reader = csv.DictReader(file)
        # Iterate over CSV file, printing each favorite
        for row in reader:
            print(row["language"])
    ```

    Notice that this example ==directly utilizes the `language` key== in the print statement.

- Python also allows ==sorting== `counts`. Improve your code as follows:

    ```python
    # Sorts favorites by key
    import csv
    
    # Open CSV file
    with open("favorites.csv", "r") as file:
        # Create DictReader
        reader = csv.DictReader(file)
        # Counts
        counts = {}
        # Iterate over CSV file, counting favorites
        for row in reader:
            favorite = row["language"]
            if favorite in counts:
                counts[favorite] += 1
            else:
                counts[favorite] = 1
                
    # Print counts
    for favorite in sorted(counts):
        print(f"{favorite}: {counts[favorite]}")
    ```

    Notice the `sorted(counts)` at the bottom of the code.

- Python allows for the utilization of *anonymous* or `lambda` functions. These functions can be utilized when you want to not bother creating an entirely different function. Notice the following modification:

    ```python
    ...
    for favorite in sorted(counts, key=lambda language: counts[language], reverse=True):
        print(f"{favorite}: {counts[favorite]}")
    ```

## Relational Databases.

- Relational databases ==store data in rows and columns== in structures called *==tables==*.

- SQL allows for four types of ==commands==:

    ```sql
    Create
    Read
    Update
    Delete
    ```

- SQL supports many commands to ==access data==, including:

    ```sql
    AVG
    COUNT
    DISTINCT
    LOWER
    MAX
    MIN
    UPPER
    ```

- For example, you can type `SELECT COUNT(language) FROM favorites;`. Further, you can type `SELECT DISTINCT(language) FROM favorites;` to get a list of the individual languages within the database. You could even type `SELECT COUNT(DISTINCT(language)) FROM favorites;` to get a count of those.

    ```python
    # Searches database popularity of a problem
    import csv
    from cs50 import SQL
    
    # Open database
    db = SQL("sqlite:///favorites.db")
    # Prompt user for favorite
    favorite = input("Favorite: ")
    # Search for title
    rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")
    # Get first (and only) row
    row = rows[0]
    # Print popularity
    print(row["COUNT(*)"])
    ```

- SQL offers ==additional commands== we can utilize in our ==queries==:

    ```sql
    WHERE     -- adding a Boolean expression to filter our data
    LIKE      -- filtering responses more loosely
    ORDER BY  -- ordering responses
    LIMIT     -- limiting the number of responses
    GROUP BY  -- grouping responses together
    ```

    Notice that we use `--` to write a comment in SQL.

- We can execute `SELECT COUNT(*) FROM favorites WHERE language = 'C';`. A count is presented.

- Further, we could type `SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Mario';`.

- Similarly, we could execute `SELECT language, COUNT(*) FROM favorites GROUP BY language;`. This would offer a temporary table that would show the language and count.

- We could improve this by typing `SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*);`. This will order the resulting table by the `count`.

- We can also `INSERT` into a SQL database utilizing the form `INSERT INTO table (column...) VALUES(value, ...);`.

- We can execute `INSERT INTO favorites (language, problem) VALUES ('SQL', 'Fiftyville');`.

- We can can execute `UPDATE favorites SET language = 'C++' WHERE language = 'C';`. This will result in overwriting all previous statements where C was the favorite programming language.

- We can `DELETE FROM favorites WHERE problem = 'Tideman';`.

## IMDb

- IMDb offers a database of people, shows, writers, stars, genres, and ratings. Each of these tables is ==related to one another as follows==:

    ![six boxes that represent various sql tables arrows are drawn to each showing their many relationships with one another](https://cs50.harvard.edu/x/2023/notes/7/cs50Week7Slide025.png)

- After downloading [`shows.db`](https://github.com/cs50/lectures/blob/2022/fall/7/src7/imdb/shows.db), you can execute `sqlite3 shows.db` in your terminal window.

- Upon executing `.schema` you will find not only each of the tables but the individual fields inside each of these fields.

- As you can see by the image above, `shows` has an `id` field. The `genres` table has a `show_id` field which has data that is common between it and the `shows` table.

- As you can see also in the image above, `show_id` exists in all of the tables. In the `shows` table, it is simply called `id`. This common field between all the fields is called a *key*. Primary keys are used to identify a unique record in a table. *Foreign keys* are used to build relationships between tables by pointing to the primary key in another table.

- In *==sqlite==*, we have ==five datatypes==, including:

    ```sql
    BLOB     -- binary large objects that are groups of ones and zeros
    INTEGER  -- an integer
    NUMERIC  -- for numbers that are formatted specially like dates
    REAL     -- like a float
    TEXT     -- for strings and the like
    ```

- Additionally, columns can be set to add special ==constraints==:

    ```sql
    NOT NULL
    UNIQUE
    ```

- To illustrate the relationship between these tables further, we could execute the following command: `SELECT * FROM people LIMIT 10;`. Examining the output, we could execute `SELECT * FROM shows LIMIT 10;`. Further, we could execute `SELECT * FROM stars LIMIT 10;`. `show_id` is a foreign key in this final query because `show_id` corresponds to the unique `id` field in `shows`. `person_id` corresponds to the unique `id` field in the `people` column.

- We can further play with this data to understand these relationships. Execute `SELECT * FROM genres;`. There are a lot of genres!

- We can further limit this data down by executing `SELECT * FROM genres WHERE genre = 'Comedy' LIMIT 10;`. From this query, you can see that there are 10 shows presented.

- You can discover what shows these are by executing `SELECT * FROM shows WHERE id = 626124;`

## `JOIN`s

- Consider the following two tables:

    ![two boxes representing the shows and genres table with an arrow connecting id and show id](https://cs50.harvard.edu/x/2023/notes/7/cs50Week7Slide030.png)

- How could we ==combine tables temporarily==? Tables could be joined together using the `JOIN` command. Execute the following command:

    ```
    SELECT * FROM shows
    JOIN ratings on shows.id = ratings.show_id
    WHERE title = 'The Office';
    ```

- You could similarly apply `JOIN` to our Steve Carell query above by executing the following:

    ```
    SELECT title FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN shows ON stars.show_id = shows.id
    WHERE name = `Steve Carell`;
    ```

    Notice how each `JOIN` command tells us which columns are aligned to each which other columns.

- This could be ==similarly implemented== as follows:

    ```
    SELECT title FROM people, stars, shows
    WHERE people.id = stars.person_id
    AND stars.show_id = shows.id
    AND name = 'Steve Carell';
    ```

    Notice that this achieves the same results.

- The ==wildcard `%` operator== can be used to find all people whose names ==start with== `Steve C` one could employ the syntax `SELECT * FROM people WHERE name LIKE 'Steve C%';`.

## Indexes

- While relational databases have the ability to be more ==fast== and more ==robust== than utilizing a `CSV` file, data can be ==optimized within a table using *indexes*==. Indexes can be utilized to ==speed up our queries==.

- To understand how indexes can speed up our queries, we can create an index with the syntax `CREATE INDEX title_index on shows (title);`. This tells `sqlite3` to create an index and perform some special under-the-hood optimization relating to this column `title`.

- This will create a data structure called a *==B Tree==*, a data structure that looks similar to a binary tree. However, unlike a binary tree, there can be more than two child notes.

    ![one node at the top from which come four children and below that there are three children coming from one of the nodes and two from another two from another and three from another](https://cs50.harvard.edu/x/2023/notes/7/cs50Week7Slide039.png)

- Running the query `SELECT * FROM shows WHERE title = 'The Office';`, you will notice that the query ==runs much more quickly==! Unfortunately, indexing all columns would result in utilizing ==more storage space==. Therefore, there is a tradeoff for enhanced speed.

## Using SQL in Python

- Recall where we last left off in `favorites.py`. Modify your code as follows:

    ```python
    # Searches database popularity of a problem
    import csv
    from cs50 import SQL
    
    # Open database
    db = SQL("sqlite:///favorites.db")
    # Prompt user for favorite
    favorite = input("Favorite: ")
    # Search for title
    rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")
    # Get first (and only) row
    row = rows[0]
    # Print popularity
    print(row["COUNT(*)"])
    ```

    Notice that `db = SQL("sqlite:///favorites.db")` provide Python the location of the database file. Then, the line that begins with `rows` executes SQL commands utilizing `db.execute`. Further, notice that `rows` is returned as a list of dictionaries.

## Race Conditions

- You can imagine a case where ==multiple users== could be ==accessing the same database== and ==executing commands== at the same time. This could result in glitches where code is interrupted by other people’s actions. This could result in a loss of data.
- Built-in SQL features such as `BEGIN TRANSACTION`, `COMMIT`, and `ROLLBACK` help avoid some of these race condition problems.

## SQL Injection Attacks

- Now, still considering the code above, you might be wondering what the `?` question marks do above. One of the problems that can arise in real-world applications of SQL is what is called an *==injection attack==*. Without the proper protections in our own code, a bad actor could run malicious code.