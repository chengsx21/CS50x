# Lecture 4

## Memory

+ You can imagine as an image as a map of bits, where zeros represent black and ones represent white.
+ ==*RGB*==, or *red, green, blue*, are numbers that ==represent the amount of each of these colors.==

## Hexadecimal

+ ==*Hexadecimal*== is a system of counting that has 16 counting values. 
+ Hexadecimal is useful because it can be represented using fewer digits. Hexadecimal allows us to ==represent information more succinctly==.

## Addresses

+ The `C` language has two powerful operators that relate to ==memory==:

    ```shell
      & Provides the address of something stored in memory.
      * Instructs the compiler to go to a location in memory.
    ```

+ 
    We can leverage this knowledge by modifying our code as follows:

    ```c
    #include <stdio.h>
    int main(void) {
        int n = 50;
        printf("%p\n", &n);
    }
    ```

    Notice the `%p`, which allows us to ==view the address of a location in memory==. `&n` can be literally translated as “the address of `n`.”

## Pointers

- A *==pointer==* is a variable that contains the address of some value. Most succinctly, a pointer is an ==address in your computer’s memory==.

- 
    Modify your code as follows:

    ```
    #include <stdio.h>
    
    int main(void)
    {
        int n = 50;
        int *p = &n;
        printf("%p\n", p);
    }
    ```

    You can visualize our code as follows:

    ![Same value of 50 in a memory location with a pointer value stored elsewhere](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide078.png)

    Indeed, a ==pointer== is usually stored as an ==8-byte== value.

## Strings

- Recall that ==a string== is simply an ==array of characters==. For example, `string s = "HI!"` can be represented as follows:

    ![The string HI with an exclaimation point stored in memory](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide085.png)

- As you can imagine, `s` needs to be stored somewhere. You can visualize the relationship of `s` to the string as follows:

    ![Same string HI with a pointer pointing to it](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide086.png)

    Notice how ==a pointer== called `s` ==tells the compiler where the first byte of the string exists in memory==.

- Modify your code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    int main(void) {
        string s = "HI!";
        printf("%p\n", s);
        printf("%p\n", &s[0]);
        printf("%p\n", &s[1]);
        printf("%p\n", &s[2]);
        printf("%p\n", &s[3]);
    }
    ```

    Notice the above ==prints the memory locations of each character== in the string `s`.

- :warning: Likewise, you can modify your code as follows:

    ```c
    #include <stdio.h>
    int main(void) {
    		// 字符串常量的本质表现是代表它的第一个字符的地址
      	char *s = "HI!";
        printf("%s\n", s);
    }
    ```

    Notice that this code will ==present the string== that starts at the location of `s`.

## Pointer Arithmetic

- You can modify your code to accomplish the same thing in a longer form as follows:

    ```c
    #include <stdio.h>
    int main(void) {
        char *s = "HI!";
        printf("%c\n", s[0]);
        printf("%c\n", s[1]);
        printf("%c\n", s[2]);
    }
    ```

    Notice that we are printing each character at the location of `s`.

- Further, you can modify your code as follows:

    ```c
    #include <stdio.h>
    int main(void) {
        char *s = "HI!";
        printf("%c\n", *s);
        printf("%c\n", *(s + 1));
        printf("%c\n", *(s + 2));
    }
    ```

    Notice that the first character at the location of `s` is printed. Then, the character at the location `s + 1` is printed, and so on.

## Comparing Strings

- A ==string== of characters is simply ==an array of characters identified by its first byte==. We could not compare two strings using the `==` operator.

- Utilizing the `==` operator in an attempt to compare strings will attempt to compare the ==memory locations== of the strings ==instead of the characters therein==. Accordingly, we recommended the use of `strcmp`.

- To illustrate this, type `code compare.c` and write code as follows:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    
    int main(void) {
        // Get two strings
        char *s = get_string("s: ");
        char *t = get_string("t: ");
        // Compare strings' addresses
        if (s == t)
            printf("Same\n");
        else
            printf("Different\n");
    }
    ```

    Noticing that typing in `HI!` for both strings still results in the output of `Different`. You can use the following to visualize why:

    ![two strings stored separately in memory](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide115.png)

## Copying

- In your terminal window, type `code copy.c` and write code as follows:

    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        // Get a string
        string s = get_string("s: ");
        // Copy string's address
        string t = s;
        // Capitalize first letter in string
        t[0] = toupper(t[0]);
        // Print string twice
        printf("s: %s\n", s);
        printf("t: %s\n", t);
    }
    ```

    Notice that `string t = s` ==copies the address== of `s` to `t`. This does not accomplish what we are desiring. ==The string is not copied – only the address is.==

- Before we address this challenge, it’s important to ensure that we don’t experience a *==segmentation fault==* through our code, where we attempt to copy `string s` to `string t`, where `string t` does not exist. We can employ the `strlen` function as follows to assist with that:

    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        // Get a string
        string s = get_string("s: ");
        // Copy string's address
        string t = s;
        // Capitalize first letter in string
        if (strlen(t) > 0)
            t[0] = toupper(t[0]);
        // Print string twice
        printf("s: %s\n", s);
        printf("t: %s\n", t);
    }
    ```

    Notice that `strlen` is used to make sure `string t` exists. If it does not, nothing will be copied. You can visualize the above code as follows:

    ![two pointers pointing at the same memory location with a string](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide124.png)

- To be able to make an ==authentic copy== of the string, we will need to introduce two new building blocks. First, `malloc` allows you, the programmer, to *==allocate==* a block of a specific size of memory. Second, `free` allows you to tell the compiler to *==free up==* that block of memory you previously allocated.

- We can modify our code to ==create an authentic copy== of our string as follows:

    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(void) {
        // Get a string
        char *s = get_string("s: ");
        // Allocate memory for another string
        char *t = malloc(strlen(s) + 1);
        // Copy string into memory, including '\0'
        for (int i = 0; i <= strlen(s); i++)
            t[i] = s[i];
        // Capitalize copy
        t[0] = toupper(t[0]);
        // Print strings
        printf("s: %s\n", s);
        printf("t: %s\n", t);
    }
    ```

    Notice that `malloc(strlen(s) + 1)` creates a block of memory that is the length of the string `s` plus one. This allows for the ==inclusion of the *null* `\0` character== in our final, copied string.

- It turns out that there is an inefficiency in our code. Modify your code as follows:

    ```c
    ...
    int main(void) {
        ...
        for (int i = 0, n = strlen(s); i <= n; i++)
    	  ...
    }
    ```

    It’s best ==not to call unneeded functions== in the ==middle condition== of the `for` loop, as it will run over and over again.

- The `C` Language has a ==built-in function== to copy strings called `strcpy`. It can be implemented as follows:

    ```c
    ...
    int main(void) {
    		...
        // Copy string into memory
        strcpy(t, s);
    		...
    }
    ```

- Both `get_string` and `malloc` return `NULL`, a special value in memory, in the event that something goes wrong. You can write code that can check for this `NULL` condition as follows:

    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(void) {
        // Get a string
        char *s = get_string("s: ");
        if (s == NULL)
            return 1;
    
    		// Allocate memory for another string
        char *t = malloc(strlen(s) + 1);
        if (t == NULL)
            return 1;
    
        // Copy string into memory
        strcpy(t, s);
        // Capitalize copy
        if (strlen(t) > 0)
            t[0] = toupper(t[0]);
        // Print strings
        printf("s: %s\n", s);
        printf("t: %s\n", t);
        // Free memory
        free(t);
        return 0;
    }
    ```

    Notice that if ==the string obtained is of length `0` or malloc fails==, `NULL` is returned. Further, notice that `free` lets the computer know you are done with this block of memory you created via `malloc`.

## Valgrind

- *==Valgrind==* is a tool that can check to see if there are ==memory-related issues== with your programs wherein you utilized `malloc`. Specifically, it checks to see ==if you `free` all the memory you allocated==.

- Consider the following code:

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void) {
        int *x = malloc(3 * sizeof(int));
        x[0] = 72;
        x[1] = 73;
        x[2] = 33;
      	// `free(x)` is needed
    }
    ```

    If you type `make memory` followed by `valgrind ./memory`, you will get a report from valgrind that will report where memory has been lost as a result of your program.

## Garbage Values

- When you ask the compiler for a block of memory, there is no guarantee that this memory will be ==empty==. It’s very possible that this memory that you allocated was ==previously utilized by the computer==. Accordingly, you may see *==junk==* or *==garbage values==*. This is a result of you getting a block of memory but not initializing it. For example, consider the following code:

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void) {
        int scores[1024];
        for (int i = 0; i < 1024; i++)
            printf("%i\n", scores[i]);
    }
    ```

    Notice that running this code will allocate `1024` locations in memory for your array, but the `for` loop will likely show that not all values therein are `0`. It’s always best practice to be aware of the potential for garbage values when you do not initialize blocks of memory to some other value like zero or otherwise.

## Swap

- In the real world, a common need in programming is to swap two values. Naturally, it’s hard to swap two variables without a temporary holding space. 

    ```c
    #include <stdio.h>
    void swap(int a, int b);
    
    int main(void) {
        int x = 1;
        int y = 2;
        printf("x is %i, y is %i\n", x, y);
        swap(x, y);
        printf("x is %i, y is %i\n", x, y);
    }
    
    void swap(int a, int b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    ```

    Notice that while this code runs, it does not work.

- When you pass values to a function, you are only ==providing copies==. In previous weeks, we discussed the concept of *scope*. ==The values of `x` and `y` created in the curly `{}` braces of the `main` function only have the scope of the `main` function.==

    ![a rectangle with machine code at top followed by globals heap and stack](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide163.png)

    Notice that *==global==* variables, which we have not used in this course, live in one place in memory. Various ==functions== are stored in the `stack` in another area of memory.

- Now, consider the following image:

    ![a rectangle with main function at bottom and swap function directly above it](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide167.png)

    Notice that `main` and `swap` have ==two separate *frames* or areas of memory==. Therefore, we cannot simply pass the values from one function to another to change them.

- Modify your code as follows:

    ```c
    #include <stdio.h>
    void swap(int *a, int *b);
    
    int main(void) {
        int x = 1;
        int y = 2;
        printf("x is %i, y is %i\n", x, y);
        swap(&x, &y);
        printf("x is %i, y is %i\n", x, y);
    }
    
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    ```

    Notice that variables are ==not passed by *value* but by *reference*==. That is, the ==addresses== of `a` and `b` are provided to the function. Therefore, the `swap` function can ==know where to make changes== to the actual `a` and `b` from the main function.

    ![a and b stored in main function being passed by reference to the swap function](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide173.png)

## Overflow

- A *==heap overflow==* is when you overflow the heap, touching areas of memory you are not supposed to.
- A *==stack overflow==* is when too many functions are called, overflowing the amount of memory available.
- Both of these are considered *==buffer overflows==*.

## `scanf`

- `scanf` is a ==built-in function== that can ==get user input==.

    ```
    #include <stdio.h>
    
    int main(void)
    {
        int x;
        printf("x: ");
        scanf("%i", &x);
        printf("x: %i\n", x);
    }
    ```

    Notice that the value of `x` is stored at the location of `x` in the line `scanf("%i", &x)`.

- However, attempting to reimplement `get_string` is not easy. Consider the following:

    ```c
    #include <stdio.h>
    
    int main(void) {
        char s[4];
        printf("s: ");
        scanf("%s", s);
        printf("s: %s\n", s);
    }
    ```

    Notice that if we pre-allocate an array of size `4`, we can type `cat` and the program functions. However, a string larger than this would create an error.

## Files

- You can read from and manipulate files. Consider the following code for `phonebook.c`:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
        // Open CSV file
        FILE *file = fopen("phonebook.csv", "a");
        // Get name and number
        char *name = get_string("Name: ");
        char *number = get_string("Number: ");
        // Print to file
        fprintf(file, "%s,%s\n", name, number);
        // Close file
        fclose(file);
    }
    ```

    Notice that this code uses ==pointers== to ==access the file==.