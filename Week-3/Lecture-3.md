# Lecture 3

## Algorithms

- *==Binary search==* is a *search algorithm* that could be employed in our task of finding the 50.

- Using the nomenclature of code, we can further modify our algorithm as follows:

    ```pseudocode
    If no doors
        Return false
    If 50 is behind doors[middle]
        Return true
    Else if 50 < doors[middle]
        Search doors[0] through doors[middle-1]
    Else if 50 > doors[middle]
        Search doors[middle+1] through doors[n-1]
    ```

    Notice, looking at this approximation of code, you can nearly imagine what this might look like in actual code.

## Running Time

- Programmers are interested in both the worst case, or *==upper bound==*, and the best case, or *==lower bound==*.
- The $\Omega$ symbol is used to denote the best case of an algorithm, such as $\Omega(\log n)$.
- The $\Theta$ symbol is used to denote where the upper bound and lower bound are the same, where the best case and the worst case running times are the same.

## Linear and Binary Search

## Data Structures

+ It turns out that C allows a way by which we can ==create our own data types== via a `struct`. 

## Sorting

- *==Selection sort==* is one such search algorithm. The algorithm for selection sort in pseudocode is:

    ```pseudocode
    For i from 0 to n–1
        Find smallest number between numbers[i] and numbers[n-1]
        Swap smallest number with numbers[i]
    ```

- *==Bubble sort==* is another sorting algorithm that works by repeatedly swapping elements to “bubble” larger elements to the end. The pseudocode for bubble sort is:

    ```pseudocode
    Repeat n-1 times
    For i from 0 to n–2
        If numbers[i] and numbers[i+1] out of order
            Swap them
    ```

- 
    Analyzing Selection sort, the efficiency of this algorithm as a whole can be regarded as $\Theta(n^2)$.
- Analyzing bubble sort, the worst case is $O(n^2)$. The best case is $\Omega(n)$.

## Recursion

+ *==Recursion==* is a concept within programming where ==a function calls itself==.

## Merge Sort

+ 
    The pseudocode for ==merge sort== is quite short:

    ```pseudocode
    If only one number
        Quit
    Else
        Sort left half of number
        Sort right half of number
        Merge sorted halves
    ```

- Merge sort is a very efficient sort algorithm with a ==worst case of $O(n\log⁡n)$==. The ==best case is still $\Omega(n\log⁡n)$== because the algorithm still must visit each place in the list. Therefore, merge sort is also ==$\Theta(n\log⁡n)$== since the best case and worst case are the same.
