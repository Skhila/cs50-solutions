#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int make_cipher(int key);

int main(int argc, string argv[])
{
    // Check arguments
    int arg_digit = 0;
    if (argc == 2)
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (isdigit(argv[1][i]))
            {
                continue;
            }
            else
            {
                arg_digit = 1;
                break;
            }

        }
        if (arg_digit == 0)
        {
            int usr_key = atoi(argv[1]);
            make_cipher(usr_key);
        }
        // If argument is not integer print instructions
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // If there is more or less than 1 CL argument
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

// Create ciphertext
int make_cipher(int key)
{
    string text = get_string("Plaintext:  ");
    printf("Ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i ++)
    {
        // If character is lowercase letter
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = 'a' + ((text[i] - 'a') + key) % 26;
        }
        // If character is uppercase letter
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = 'A' + ((text[i] - 'A') + key) % 26;
        }
    }
    // Mission success ;)
    printf("%s\n", text);
    return 0;
}
