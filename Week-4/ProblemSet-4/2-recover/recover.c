#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error opening file %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int cnt = 0;
    FILE *output = NULL;
    char filename[8];

    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] | 0x0f) == 0xef) {
            printf("Found JPEG %i\n", cnt);
            sprintf(filename, "%03i.jpg", cnt++);
            fclose(output);
            output = fopen(filename, "w");
        }
        if (cnt)
            fwrite(&buffer, BLOCK_SIZE, 1, output);
    }
    printf("Found %i JPEGs\n", cnt); 

    fclose(input);
    fclose(output);
    return 0;
}
