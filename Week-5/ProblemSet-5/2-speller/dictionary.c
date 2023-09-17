// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>    // fopen, fclose, fscanf
#include <stdlib.h>   // malloc, free
#include <string.h>   // strcpy
#include <strings.h>  // strcasecmp

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node {
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 10007;
const unsigned int A = 9973;
int tsize = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word) {
    node *n = table[hash(word)];
    while (n != NULL) {
        if (strcasecmp(word, n->word) == 0)
            return true;
        n = n->next;
    }
    return false;
}

// Hashes word to a number
// Remember to handle case conditions
unsigned int hash(const char *word) {
    int index = 0;
    while (*word) {
        if (isupper(*word))
            index = (index * A + (*word + 32)) % N;
        else
            index = (index * A + *word) % N;
        word++;
    }
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
        return false;

    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF) {
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return false;
        strcpy(n->word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;
        tsize++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
    return tsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    for (int i = 0; i < N; i++) {
        node *n = table[i];
        while (n != NULL) {
            node *c = n;
            n = n->next;
            free(c);
        }
    }
    return true;
}
