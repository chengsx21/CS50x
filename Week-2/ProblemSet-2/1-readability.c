#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text) {
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
        if (islower(text[i]) || isupper(text[i]))
            count++;
    return count;
}

int count_words(string text) {
    bool flag = false;
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (flag == false && text[i] != ' ')
            flag = true;

        if (flag == true && text[i] == ' ')
            flag = false, count++;

        if (i == n - 1 && text[i] != ' ')
            count++;
    }
    return count;
}

int count_sentences(string text) {
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            count++;
    return count;
}

void calculate_grade(int letters, int words, int sentences) {
    //! Cast one or more values to float before performing division when calculating L and S!
    int grade = round(0.0588 * (100.0 * letters / words) - 0.296 * (100.0 * sentences / words) - 15.8);
    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade > 15)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);
}

int main(void) {
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    calculate_grade(letters, words, sentences);
}