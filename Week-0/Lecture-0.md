# Lecture 0

## Welcome!

- You will be “drinking from the firehose” of knowledge during this course. You’ll be amazed at what you will be able to accomplish in the coming weeks.
- The most important opening consideration in this course: ==Give the time you need to learn through this course.== Everyone learns differently. If something does not work out well at the start, know that with time you will grow and grow in your skill.

## Computational Thinking

- Essentially, ==computer programming== is about ==taking some input== and ==creating some output== - thus solving a problem. What happens in between the input and output, what we could call *==a black box==,* is the focus of this course.
- For example, we may need to take attendance for a class. We could use a system called *unary* to count, one finger at a time. Computers today count using a system called *binary*. It’s from the term *binary digit* that we get a familiar term called *bit*. A *bit* is a zero or one.
- Computers generally use ==eight bits to represent a number==. For example, `00000101` is the number 5 in *binary*.

## Text

- Just as numbers are binary patterns of ones and zeros, letters are ==represented using ones and zeros== too!

- Since there is an overlap between the ones and zeros that represent numbers and letters, ==the *ASCII* standard== was created to map specific letters to specific numbers.

- Here is an expanded map of ASCII values:

    ![ASCII map](https://cs50.harvard.edu/x/2023/notes/0/cs50Week0Slide93.png)

- If you wish, you can learn more about [ASCII](https://en.wikipedia.org/wiki/ASCII).

## Emojis

- Since there were not enough digits in binary to represent all the various characters that could be represented by humans, ==the *Unicode* standard== ==expanded the number of bits== that can be transmitted and understood by computers.
- 
    Computer scientists faced a challenge when wanting to assign various skin tones to each emoji to allow the communication to be further personalized. In this case, the creators and contributors of emojis decided that the initial bits would be the structure of the emoji itself, followed by skin tone.
- ==More and more features== are being added to the Unicode standard to ==represent further characters and emojis==.
- If you wish, you can learn more about [Unicode](https://en.wikipedia.org/wiki/Unicode).
- If you wish, you can learn more about [emojis](https://en.wikipedia.org/wiki/Emoji).

## RGB

- Red, green, and blue (called `RGB`) is ==a combination of three numbers==.

    ![red green blue boxes](https://cs50.harvard.edu/x/2023/notes/0/cs50Week0Slide118.png)

- Taking our previously used 72, 73, and 33, which said `HI!` via text, would be interpreted by image readers as a light shade of yellow. The red value would be 72, the green value would be 73, and the blue would be 33.

    ![yellow box](https://cs50.harvard.edu/x/2023/notes/0/cs50Week0Slide120.png)



## Images, Video and Sound

- Images are simply collections of RGB values.
- Videos are sequences of many images that are stored together, just like a flipbook.
- Music can be represented through MIDI data.

## Algorithms

- ==Problem-solving== is central to computer science and computer programming.
- A final and perhaps better approach could be to go to the middle of the phone book and ask, “Is the name I am looking for to the left or to the right?” Then, repeat this process, cutting the problem in half and half and half.
- Each of these approaches could be called algorithms. The speed of each of these algorithms can be pictured as follows in what is called *==big-O notation==*.

## Pseudocode

- The ability to create *==pseudocode==* is central to one’s success in both this class and in computer programming.

- Pseudocode is a ==human-readable version of code==. For example, considering the third algorithm above, we could compose pseudocode as follows:

    ```pseudocode
    Pick up phone book
    Open to middle of phone book
    Look at page
    If person is on page
         Call person
    Else if person is earlier in book
        Open to middle of left half of book
        Go back to line 3
    Else if person is later in book
        Open to middle of right half of book
        Go back to line 3
    Else
        Quit
    ```

- Pseudocoding is such an important skill for at least two reasons. First, when you pseudocode before you create formal code, it allows you to ==think through the logic== of your problem in advance. Second, when you pseudocode, you can later ==provide this information to others== that are seeking to understand your coding decisions and how your code works.

- Notice that the language within our pseudocode has some unique features. First, some of these lines begin with verbs like *pick up,* *open,* *look at.* Later, we will call these *==functions==*.

- Second, notice that some lines include statements like `if` or `else if.` These are called *==conditionals==*.

- Third, notice how there are expressions that can be stated as *true* or *false,* such as “person is earlier in the book.” We call these *==boolean expressions==*.

- Finally, notice how these statements like “go back to line 3.” We call these *==loops==*.