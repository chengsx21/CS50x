# Lecture 1

## Functions

- The statement at the start of the code `#include <stdio.h>` is a very special command that tells the compile that you want to ==use the capabilities of *library*== called `stdio.h`. This allows you, among many other things, to ==utilize the `printf` function==. You can read about all the capabilities of this library on the [Manual Pages](https://manual.cs50.io/).

## Variables

## Conditionals

## Loops

## Linux and the Command Line

- *Linux* is an ==operating system== that is ==accessible via the command line== in the terminal window in VS Code.
- Some common command-line arguments we may use include:
    - `cd`, for changing current directory
    - `cp`, for ==copying== files and directories
    - `ls`, for listing files in a directory
    - `mkdir`, for making a directory
    - `mv`, for ==moving (renaming)== files and directories
    - `rm`, for ==removing (deleting)== files
    - `rmdir`, for ==removing (deleting)== directories
- The most commonly used is `ls` which will list all the files in the current directory or directory. Another useful command is `mv`, where you can move a file from one file to another. For example, you could use this command to rename `Hello.c` (notice the uppercase `H`) to `hello.c` by typing `mv Hello.c hello.c`. You can also create folders. You can type `mkdir pset1` to create a directory called `pset1`.

## Mario

- A general piece of advice within programming is that ==you should never fully trust your user==. They will likely misbehave, typing incorrect values where they should not. We can protect our program from bad behavior by checking to make sure the user’s input satisfies our needs. Modify your code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    
    int main(void) {
        int n;
        do {
            n = get_int("Size: ");
        }
        while (n < 1);
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
    ```

    Notice how the user is continuously prompted for the size until the user’s input is 1 or greater.

## Comments

## Abstraction

- *==Abstraction==* is the art of ==simplifying our code== such that it deals with smaller and smaller problems.
- Looking at your code, you can see how two essential problems in our code are *get size of grid* and *print grid of bricks*. We can abstract away these two problems into ==separate functions==.

## Operators and Types