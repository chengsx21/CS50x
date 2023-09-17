# Lecture 5

## Data Structures

- *==Data structures==* essentially are ==forms of organization in memory==. *Abstract data structures* are those that we can conceptually imagine.

## Stacks and Queues

- *==Queues==* have specific properties. Namely, they are *==FIFO==* or “first in first out.” Queues have specific actions associated with them. For example, an item can be *==enqueued==*; that is, the item can join the line or queue. Further, an item can be *==dequeued==* or leave the queue once it reaches the front of the line.

- Queues contrast a *==stack==*. Fundamentally, the properties of a stack are different than a queue. Specifically, it is *==LIFO==* or “last in first out.” Stacks have specific actions associated with them. For example, *==push==* places something on top of a stack. *==Pop==* is removing something from the top of the stack.

- In code, you might imagine a stack as follows:

    ```c
    const int CAPACITY = 50;
    
    typedef struct {
        person people[CAPACITY];
        int size;
    } stack;
    ```

- Since the capacity of the array is always ==predetermined== in this code. Therefore, the stack may always be ==oversized==. It would be nice for our stack to be ==dynamic== – able to grow as items are added to it.

## Resizing Arrays

- An array is a block of contiguous memory. In memory, there are other values being stored by other programs, functions, and variables. Many of these may be ==unused garbage== values that were ==utilized at one point but are available now for use==.

- Imagine you wanted to store a fourth value `4` in our array. What would be needed is to ==allocate a new area of memory== and ==move the old array==. Old garbage values would be ==overwritten== with our new data.

    ![Three boxes with 1 2 3 above four boxes with 1 2 3 and a garbage value](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide026.png)

- One of the ==drawbacks== of this approach is that it’s bad design: Every time we ==add a number==, we have to ==copy the array== item by item. Wouldn’t it be nice if we were able to put the `4` somewhere else in memory? By definition, this would no longer be an array because `4` would ==no longer be in contiguous memory==.

- We can leverage our understanding of pointers to create a better design in this code.

    ```c
    // Implements a list with an array of dynamic size
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void) {
        // List of size 3
        int *list = malloc(3 * sizeof(int));
        if (list == NULL)
            return 1;
        list[0] = 1;
        list[1] = 2;
        list[2] = 3;
    
      	// List of size 4
        int *tmp = malloc(4 * sizeof(int));
        if (tmp == NULL) {
            free(list);
            return 1;
        }
      
        // Copy list of size 3 into list of size 4
        for (int i = 0; i < 3; i++)
            tmp[i] = list[i];
        tmp[3] = 4;
      
        // Free list of size 3
        free(list);
        list = tmp;
      
        // Print list
        for (int i = 0; i < 4; i++)
            printf("%i\n", list[i]);
        free(list);
        return 0;
    }
    ```

    It’s useful to think about `list` and `tmp` as both ==signs that point at a chunk of memory==. Technically, by the end of the above code, `tmp` and `list` both pointed to the same block of memory.

- C comes with a very useful function called `realloc` that will ==reallocate the memory== for you. `realloc` takes two arguments. First, it asks you to specify the array you are attempting to copy. Second, it asks you to specify the size to which you would like the final array to be. Modify your code as follows:

    ```c
    ...
    int main(void) {
    		...
        // Resize list to be of size 4
        int *tmp = realloc(list, 4 * sizeof(int));
        if (tmp == NULL) {
            free(list);
            return 1;
        }
        list = tmp;
    		...
    }
    ```

    Notice that `int *tmp = realloc(list, 4 * sizeof(int))` creates a list of size four integers. Then, it ==copies the values== of `list` to this new array. Finally, a pointer called `tmp` points to the location of memory of this new array. ==The copying is handled by `realloc`.== Once that copy is made, the ==memory at the location of `list` is freed==. Then, the pointer called `list` is pointed at the location of `tmp`, where the new array is located.

## Linked Lists

- Today, you are introduced to the `->` operator. It is an arrow. This operator ==goes to an address== and ==looks inside of a structure==.

- A *==Linked list==* is one of the most powerful data structures within C. A linked list allows you to include values that are ==located at varying areas of memory==. Further, they allow you to ==dynamically== grow and shrink the list as you desire.

- We could ==utilize more memory== to keep track of ==where the next item is==.

    ![Three boxes with 1 2 3 in separate areas of memory with smaller boxes attached where memory addresses are in those attached boxes now with a final box with the memory address of the first box](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide042.png)

- These boxes are called *==nodes==*. A *node* contains both an *==item==* and a pointer called *==next==*. In code, you can imagine a node as follows:

    ```c
    typedef struct node {
        int number;
        struct node *next;
    } node;
    ```

- Further, linked lists cannot be indexed into like is possible in an array because we need to pass through the first n−1 elements to find the location of the nth element. Because of this, the list pictured above ==must be linearly searched==.

- Conceptually, we can imagine the process of creating a linked list.

    ![One garbage value called n with another pointer called list](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide059.png)

    ![n and list both pointing to a node with 1 as the number and null as the value of next](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide068.png)

- To implement this in code, modify your code as follows:

    ```c
    // Prepends numbers to a linked list, using while loop to print
    
    #include <cs50.h>
    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct node {
        int number;
        struct node *next;
    } node;
    
    int main(int argc, char *argv[]) {
        // Memory for numbers
        node *list = NULL;
    
        // For each command-line argument
        for (int i = 1; i < argc; i++) {
            // Convert argument to int
            int number = atoi(argv[i]);
            // Allocate node for number
            node *n = malloc(sizeof(node));
            if (n == NULL)
                return 1;
            n->number = number;
            n->next = NULL;
            // Prepend node to list
            n->next = list;
            list = n;
        }
    
        // Print numbers
        node *ptr = list;
        while (ptr != NULL) {
            printf("%i\n", ptr->number);
            ptr = ptr->next;
        }
    
        // Free memory
        ptr = list;
        while (ptr != NULL) {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    ```

## Trees

- *==Binary search trees==* are another data structure that can be used to store data more efficiently such that it can be searched and retrieved. In code, this can be implemented as follows.

    ```c
    // Implements a list of numbers as a binary search tree
    
    #include <stdio.h>
    #include <stdlib.h>
    
    // Represents a node
    typedef struct node {
        int number;
        struct node *left;
        struct node *right;
    }
    node;
    
    void free_tree(node *root);
    void print_tree(node *root);
    
    int main(void) {
        // Tree of size 0
        node *tree = NULL;
    
        // Add number to list
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return 1;
        n->number = 2;
        n->left = NULL;
        n->right = NULL;
        tree = n;
    
        // Add number to list
        n = malloc(sizeof(node));
        if (n == NULL) {
            free_tree(tree);
            return 1;
        }
        n->number = 1;
        n->left = NULL;
        n->right = NULL;
        tree->left = n;
    
        // Add number to list
        n = malloc(sizeof(node));
        if (n == NULL) {
            free_tree(tree);
            return 1;
        }
        n->number = 3;
        n->left = NULL;
        n->right = NULL;
        tree->right = n;
    
        // Print tree
        print_tree(tree);
        // Free tree
        free_tree(tree);
        return 0;
    }
    
    void free_tree(node *root) {
        if (root == NULL)
            return;
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
    
    void print_tree(node *root) {
        if (root == NULL)
            return;
        print_tree(root->left);
        printf("%i\n", root->number);
        print_tree(root->right);
    }
    ```

- Searching this tree could be implemented as follows:

    ```c
    bool search(node *tree, int number) {
        if (tree == NULL)
            return false;
        else if (number < tree->number)
            return search(tree->left, number);
        else if (number > tree->number)
            return search(tree->right, number);
        else if (number == tree->number)
            return true;
    }
    ```

    Notice this search function begins by going to the location of `tree`. Then, it uses recursion to search for `number`.

## Dictionaries

- *==Dictionaries==*, like actual book-form dictionaries that have a word and a definition, have ==a *key* and a *value*==. The *holy grail* of time complexity is O(1) or *constant time*. That is, the ultimate is for access to be instantaneous.

## Hashing and Hash Tables

- *==Hashing==* is the idea of taking a value and being able to output a value that ==becomes a shortcut== to it later.

- A *==hash function==* is an algorithm that ==reduces a larger value to something small and predictable==. Generally, this function takes in an item you wish to add to your hash table, and returns an integer representing the array index in which the item should be placed.

- A *==hash table==* is a fantastic combination of ==both arrays and linked lists==. When implemented in code, a hash table is an ==*array* of *pointers* to *node*s==.

    ![a verticle column of 26 boxes one for each letter of the alphabet with various names from the harry potter unverise emergint to the right albus is with a and harry is with h](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide169.png)

## Tries

- *==Tries==* are always ==searchable in constant time==. One downside to *Tries* is that they tend to take up a ==large amount of memory==. Notice that we need 26×5=130 `nodes` just to store *Hagrid*.

    ![hagrid being spelled with one letter at a time where one letter is associated with one list H from one list A from another and so on ](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide207.png)

- *Harry* would then be stored as follows:

    ![hagrid being spelled with one letter at a time where one letter is associated with one list H from one list A from another and so on and harry being spelled similarly where hagrid and harry share a two common letters H and A](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide209.png)