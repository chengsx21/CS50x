# Lecture 6

## Python

- Python is a programming language that ==builds upon== what you have already learned in ==C==.

## Hello

- This code is transformed in Python to:

    ```python
    # get_string and print, with concatenation
    from cs50 import get_string
    answer = get_string("What's your name? ")
    print("hello, " + answer)
    print(f"hello, {answer}")
    ```

## Types

- Data types in Python ==do not need to be explicitly declared==. In Python, commonly used types include:

    ```
      bool
      float
      int
      str
    ```

    Some other data types in Python include:

    ```
      range
      list
      tuple
      dict
      set
    ```

## CS50 Library

- As with C, the ==CS50 library== can be utilized within Python. The following functions will be of particular use:

    ```
      get_float
      get_int
      get_string
    ```

    You also have the option of importing only specific functions from the CS50 library as follows:

    ```
    from CS50 import get_float, get_int, get_string
    ```

## Conditionals

## Variables

- Variable declaration is simplified too. You need not declare the type of the variable. Python favors `counter += 1` to increment by one, losing the ability found in C to type `counter++`.

## Loops

## Compare

- Notice that the two vertical bars utilized in C is replaced with `or`. Indeed, people often enjoy Python because it is more ==readable== by humans. Also, notice that `char` does not exist in Python. Instead, `str`s are utilized.

## Object-Oriented Programming

- Up until this point, our programs in this course have been linear: sequential.

- It’s possible to have certain types of values not only have properties or attributes inside of them but have functions as well. In Python, these values are known as *==objects==*

- For example, `strs` in Python have a ==built-in *methods*==. Therefore, you could modify your code as follows:

    ```python
    # Logical operators, using lists
    
    from cs50 import get_string
    
    s = get_string("Do you agree? ")
    if s.lower() in ["y", "yes"]:
        print("Agreed.")
    elif s.lower() in ["n", "no"]:
        print("Not agreed.")
    ```

## Mario

- We can take away the training wheels of the CS50 library as follows:

    ```python
    # Prints a column of bricks, catching exceptions
    
    def main():
        height = get_height()
        for i in range(height):
            print("#")
    
    
    def get_height():
        while True:
            try:
                n = int(input("Height: "))
                if n > 0:
                    return n
            except ValueError:
                print("Not an integer")
    
    
    main()
    ```

    Notice that `try` is utilized to attempt to ==convert `n` to an integer==. If it cannot do so, an error is outputted.

- In Python, we could implement by modifying your code as follows:

    ```python
    # Prints a row of 4 question marks with a loop
    
    for i in range(4):
        print("?", end="")
    print()
    ```

    Notice that you can ==override the behavior== of the `print` function to ==stay on the same line== as the previous print.

- Similar in spirit to previous iterations, we can ==further simplify== this program:

    ```python
    # Prints a row of 4 question marks without a loop
    
    print("?" * 4)
    ```

## Scores

- `list`s are a data structure within Python. `list`s have built in methods or functions within them. For example, consider the following code:

    ```python
    # Averages three numbers using a list and a loop
    
    from cs50 import get_int
    
    # Get scores
    scores = []
    for i in range(3):
        score = get_int("Score: ")
        scores.append(score)
    # Print average
    average = sum(scores) / len(scores)
    print(f"Average: {average}")
    ```

- You can even ultilize the following syntax:

    ```python
    ...
    for i in range(3):
        score = get_int("Score: ")
        scores += [score]
    ...
    ```

    Notice that `+=` is ==utilized== to append the score to the list. In this case we place square brackets around `score` because only a `list` can be added to another `list` using `+` or `+=`.

## Uppercase

- Similarly, consider the following code:

    ```python
    # Uppercases string one character at a time
    
    before = input("Before: ")
    print("After:  ", end="")
    for c in before:
        print(c.upper(), end="")
    print()
    ```

    Notice that each character is uppercased one at a time.

- Python has a ==built-in method== for `str`s.

    ```python
    # Uppercases string all at once
    
    before = input("Before: ")
    after = before.upper()
    print(f"After:  {after}")
    ```

## Greet

- As with C, you can also utilize command-line arguments.

    ```python
    # Prints a command-line argument
    
    from sys import argv
    
    if len(argv) == 2:
        print(f"hello, {argv[1]}")
    else:
        print("hello, world")
    ```

- You can print all the arguments in `argv` as follows:

    ```python
    # Printing command-line arguments, indexing into argv
    
    from sys import argv
    
    for i in range(len(argv)):
        print(argv[i])
    ```

    Notice that the above will not present the word `python` if executed, and the ==first argument will be the name of the file you are running==. You can think of the word `python` as being analogous to `./` when we were running programs in C.

## Exit Status

- The `sys` library also has built-in methods. We can use `sys.exit(i)` to exit the program with a specific exit code:

    ```python
    # Exits with explicit value, importing sys
    
    import sys
    
    if len(sys.argv) != 2:
        print("Missing command-line argument")
        sys.exit(1)
    
    print(f"hello, {sys.argv[1]}")
    sys.exit(0)
    ```

    Notice that ==dot-notation== is used to ==utilize the built-in functions== of `sys`.

## Search

- Python can also be utilized to search. You can utilize the built-in abilities of Python as follows:

    ```python
    # Implements linear search for names using `in`
    
    import sys
    
    # A list of names
    names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]
    
    # Ask for name
    name = input("Name: ")
    
    # Search for name
    if name in names:
        print("Found")
        sys.exit(0)
    
    print("Not found")
    sys.exit(1)
    ```

    Notice that the ==`in` preposition== is utilized. Python understands how to implement the lower-level code to do a linear search.

## Phonebook

- Recall that a *dictionary* or `dict` is a collection of *key* and *value* pairs.

    ```python
    # Implements a phone book
    
    from cs50 import get_string
    
    people = {
        "Carter": "+1-617-495-1000",
        "David": "+1-949-468-2750"
    }
    
    # Search for name
    name = get_string("Name: ")
    if name in people:
        print(f"Number: {people[name]}")
    ```

    Notice that the dictionary is implemented using ==curly braces==. Then, the statement `if name in people` searches to see if the `name` is in the `people` dictionary. Further, notice how, in the `print` statement, we can ==index into the people dictionary using the value of `name`==. Very useful!

## Swap

- Further, we can implement a program that swaps values as we did in C. Consider the following code in Python:

    ```python
    # Swaps two integers
    
    x = 1
    y = 2
    
    print(f"x is {x}, y is {y}")
    x, y = y, x
    print(f"x is {x}, y is {y}")
    ```

    Notice that each value is swapped, using some very *Pythonic* syntax `x, y = y, x`.

## Speech

- Using a ==third-party library==, Python can do ==text-to-speech==.

    ```python
    # Says hello to someone
    
    import pyttsx3
    
    engine = pyttsx3.init()
    name = input("What's your name? ")
    engine.say(f"hello, {name}")
    engine.runAndWait()
    ```

- Further, you can run the following code:

    ```python
    # Says "This was CS50"
    
    import pyttsx3
    
    engine = pyttsx3.init()
    engine.say("This was CS50")
    engine.runAndWait()
    ```