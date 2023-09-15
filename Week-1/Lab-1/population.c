#include <cs50.h>
#include <stdio.h>

int main(void) {
    // Prompt for start size
    int start_size;
    do start_size = get_int("Start size: ");
    while (start_size < 9);

    // Prompt for end size
    int end_size;
    do end_size = get_int("End size: ");
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    int year = 0;
    while (start_size < end_size) {
        int born_size = start_size / 3;
        int dead_size = start_size / 4;
        start_size += born_size;
        start_size -= dead_size;
        year++;
    }

    // Print number of years
    printf("Years: %d", year);
}
