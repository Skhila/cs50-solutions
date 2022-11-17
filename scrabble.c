#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print final results
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}


// Calculating score
int compute_score(string word)
{
    // Player score
    int score = 0;
    // Ascii value for each char
    int ascii_char = 0;
    // Index in POINTS array
    int index = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        ascii_char = toupper(word[i]);
        index = (int) toupper(word[i]) - 65;
        if (ascii_char < 65 || ascii_char > 90)
        {
            continue;
        }
        score += POINTS[index];
    }
    return score;
}
