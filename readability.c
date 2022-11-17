#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_avg_letters(string text);
int count_avg_sentences(string text);
int count_words(string text);
int count_sentences(string text);
int *count_words_letters_sentences(int *arr, string text);


int main(void)
{
    // Text
    string user_text = get_string("Text: ");

    // Calculating words, letters and sentences
    int word_letter_sentence[3];
    int *lws = count_words_letters_sentences(word_letter_sentence, user_text);
    int letters = lws[0];
    int words = lws[1] + 1;
    int sentences = lws[2];

    // Calculating average letters and sentences in 100 words
    float avg_letters = (letters / (float) words) * 100;
    float avg_sentences = (sentences / (float) words) * 100;

    // Calculating grade
    double grade = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;
    int final_grade = round(grade);
    if (final_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (final_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", final_grade);
    }
}

// Count words, letters and sentences in text
int *count_words_letters_sentences(int *arr, string text)
{
    int ascii_char;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        ascii_char = text[i];
        // Word count
        if (ascii_char == 32)
        {
            arr[1] += 1;
        }
        // Sentence count
        else if (ascii_char == 33 || ascii_char == 46 || ascii_char == 63)
        {
            arr[2] += 1;
        }
        // Letter count
        else if (toupper(ascii_char) > 64 && toupper(ascii_char) < 91)
        {
            arr[0] += 1;
        }
    }
    return arr;
}
