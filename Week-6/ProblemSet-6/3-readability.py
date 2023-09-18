from cs50 import get_string

def count_letters(text):
    count = 0
    for char in text:
        if char.islower() or char.isupper():
            count += 1
    return count


def count_words(text):
    flag = False
    count = 0
    for i, char in enumerate(text):
        if not flag and char != ' ':
            flag = True
        if flag and char == ' ':
            flag = False
            count += 1
        if i == len(text) - 1 and char != ' ':
            count +=1
    return count


def count_sentences(text):
    count = 0
    for char in text:
        if char == '.' or char == '!' or char == '?':
            count += 1
    return count


def calculate_grade(letters, words, sentences):
    grade = round(0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8)
    if grade < 1:
        print("Before Grade 1\n")
    elif grade > 15:
        print("Grade 16+\n")
    else:
        print(f"Grade {grade}\n")


def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    calculate_grade(letters, words, sentences)


main()
