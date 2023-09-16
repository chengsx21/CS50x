#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct {
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++) {
        string name = get_string("Vote: ");
        if (!vote(name))
            printf("Invalid vote.\n");
    }

    print_winner();
}

bool vote(string name) {
    for (int i = 0; i < candidate_count; i++) {
        if (!strcmp(candidates[i].name, name)) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void) {
    for (int i = candidate_count - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (candidates[j].votes > candidates[j + 1].votes) {
                candidate t = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = t;
            }
        }
    }

    int max = candidates[candidate_count - 1].votes;
    for (int i = candidate_count - 1; i >= 0; i--) {
        if (candidates[i].votes == max)
            printf("%s\n", candidates[i].name);
        else
            break;
    }
    return;
}
