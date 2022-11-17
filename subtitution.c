#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int encrypt(string key);

int main(int argc, string argv[])
{
    // Check arguments
    int arg_digit = 0;
    if (argc == 2)
    {

        if (strlen(argv[1]) == 26)
        {
            for (int i = 0, len = strlen(argv[1]); i < len; i++)
            {

                if (isalpha(tolower(argv[1][i])))
                {
                    int dup_count = 0;
                    for (int j = i + 1, len1 = strlen(argv[1]); j < len1; j++)
                    {
                        if (argv[1][j] == argv[1][i])
                        {
                            printf("Key mustn't contain duplicate characters.\n");
                            return 1;
                        }
                    }
                    continue;
                }
                // If argument is not letter, return error message
                else
                {
                    printf("Key must only contain alphabetical characters.\n");
                    return 1;
                }
            }
            encrypt(argv[1]);
            return 0;
        }
        // If key is more or less than 26 characters long, return error message
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    // If there are more or less than 2 cl arguments, print error message
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}


// Encrypt the text
int encrypt(string key)
{
    string text = get_string("plaintext:  ");
    printf("ciphertext: ");
    int i = 0;
    for (int len = strlen(text); i < len; i++)
    {
        int index = toupper(text[i]) % 65;
        // If character is lowercase letter
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = tolower(key[index]);
        }
        // If character is uppercase letter
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = toupper(key[index]);
        }
    }
    // Mission success ;)
    printf("%s\n", text);
    return 0;
}
