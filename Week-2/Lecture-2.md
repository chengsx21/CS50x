# Lecture 2

## Compiling

- *==Encryption==* is the act of hiding plain text from prying eyes. *==decrypting==*, then, is the act of taking an encrypted piece of text and returning it to a human-readable form.
- You can attempt to enter into the terminal window: `clang -o hello hello.c`. You will be met by an error that indicates that clang ==does not know where to find the `cs50.h` library==.
- Attempting again to compile this code, run the following command in the terminal window: `clang -o hello hello.c -lcs50`. This will enable the compiler to access the `cs50.h` library.
- Compiling involves major steps, including the following:
    - First, *==preprocessing==* is where the header files in your code, designated by a `#` (such as `#include <cs50.h>`) are effectively ==copied and pasted== into your file. During this step, the code from `cs50.h` is copied into your program. Similarly, just as your code contains `#include <stdio.h>`, code contained within `stdio.h` somewhere on your computer is copied to your program. This step can be visualized as follows.
    - Second, *==compiling==* is where your program is converted into ==assembly code==.
    - Third, *==assembling==* involves the compiler converting your assembly code into ==machine code==.
    - Finally, during the *==linking==* step, code from your included libraries are converted also into machine code and combined with your code. The final ==executable file== is then outputted.

## Debugging

+ `printf` is a very useful way of debugging your code.
+ A second tool in debugging is called a *==debugger==*, a software tool created by programmers to help track down bugs in code.

## Arrays

- Each data type requires a certain amount of system resources:
    - `bool` 1 byte
    - `int` 4 bytes
    - `long` 8 bytes
    - `float` 4 bytes
    - `double` 8 bytes
    - `char` 1 byte
    - `string` ? bytes
- Inside of your computer, you have a finite amount of memory available. Physically, on the memory of your computer, you can imagine how specific types of data are stored on your computer. ==*Arrays*== are a way of ==storing data back-to-back in memory== such that this data is ==easily accessible==.
- Not only can arrays be ==containers==: They can be ==passed between functions==.

## Strings

- A `string` is simply an array of variables of type `char`: an ==array of characters==.

- A string is an array of characters that ==begins with the first character== and ==ends with a special character== called a `NUL character`.


    ![hi with terminator](https://cs50.harvard.edu/x/2023/notes/2/cs50Week2Slide116.png)

- Imagining this in ==decimal==, your array would look like the following:

    ![hi with decimal](https://cs50.harvard.edu/x/2023/notes/2/cs50Week2Slide117.png)

- A common problem within programming, and perhaps C more specifically, is to discover the ==length of an array==. How could we implement this in code? Type `code length.c` in the terminal window and code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    
    int main(void) {
        // Prompt for user's name
        string name = get_string("Name: ");
    
        // Count number of characters up until '\0' (aka NUL)
        int n = 0;
        while (name[n] != '\0') {
            n++;
        }
        printf("%i\n", n);
    }
    ```

    Notice that this code loops until the `NUL` character is found.

- Since this is such a common problem within programming, other programmers have ==created code== in the `string.h` ==library== to find the length of a string.

    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        // Prompt for user's name
        string name = get_string("Name: ");
        int length = strlen(name);
        printf("%i\n", length);
    }
    ```

- `ctype.h` is another library that is quite useful. Imagine we wanted to create a program that ==converted all lowercase characters to uppercase ones==. In the terminal window type `code uppercase.c` and write code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        string s = get_string("Before: ");
        printf("After:  ");
        for (int i = 0, n = strlen(s); i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                printf("%c", s[i] - 32);
            }
            else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    ```

    Notice that this code ==*iterates* through each value== in the string.

- 
    While the program does what we want, there is an ==easier== way using the `ctype.h` ==library==. Modify your program as follows:

    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        string s = get_string("Before: ");
        printf("After:  ");
        for (int i = 0, n = strlen(s); i < n; i++) {
            if (islower(s[i])) {
                printf("%c", toupper(s[i]));
            }
            else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    ```

    Notice that the program uses `islower` to detect if each character is uppercase or lowercase. Then, the `toupper` function is passed `s[i]`.

- 
    Again, while this program does what is desired, there is an opportunity for improvement. As the documentation for `ctype.h` states, `toupper` is ==smart enough== to know that if it is passed what is already an uppercase letter, it will simply ignore it.

    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        string s = get_string("Before: ");
        printf("After:  ");
        for (int i = 0, n = strlen(s); i < n; i++) {
            printf("%c", toupper(s[i]));
        }
        printf("\n");
    }
    ```

- You can read about all the capabilities of the `ctype` library on the [Manual Pages](https://manual.cs50.io/#ctype.h).

## Command-Line Arguments

- `Command-line arguments` are those ==arguments that are passed to your program at the command line==. For example, ==all those statements typed after== `clang` are considered command line arguments.

- Would it not be nice to be able to take arguments before the program even runs? Modify your code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    
    int main(int argc, string argv[]) {
        if (argc == 2) {
            printf("hello, %s\n", argv[1]);
        }
        else {
            printf("hello, world\n");
        }
    }
    ```

    Notice that this program knows both `argc`, the number of command line arguments, and `argv` which is an array of the characters passed as arguments at the command line. Therefore, using the syntax of this program, executing `./greet David` would result in the program saying `hello, David`.

## Exit Status

- When ==a program ends==, ==a special exit code== is provided to the computer.

- When a program exits ==without error==, a status code of `0` is provided the computer. Often, when an ==error occurs== that results in the program ending, a status of `1` is provided by the computer.

- You could write a program as follows that illustrates this by typing `code status.c` and writing code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    
    int main(int argc, string argv[]) {
        if (argc != 2) {
            printf("Missing command-line argument\n");
            return 1;
        }
        printf("hello, %s\n", argv[1]);
        return 0;
    }
    ```

    Notice that if you fail to provide `./status David`, you will get an exit status of `1`. However, if you do provide `./status David`, you will get an exit status of `0`.

## Cryptography

- ==Cryptography== is the art of ==ciphering and deciphering== a message.
- `plaintext` and a `key` are provided to a `cipher`, resulting in ciphered text.
- The key is a special argument passed to the cipher along with the plaintext. The cipher ==uses the key to make decisions== about how to implement its cipher algorithm.