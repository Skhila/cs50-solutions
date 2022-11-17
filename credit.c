#include <cs50.h>
#include <stdio.h>

int calculate_checksum(long number);
void validity(int checksum, long number, int digits);
int count_digits(long number);


int main(void)
{
    //user prompt card number (long)
    long number = get_long("Number: ");

    //calculate checksum
    int checksum = calculate_checksum(number);

    //calculates digits
    int digits = count_digits(number);

    //output: validity and the type of the card
    validity(checksum, number, digits);
}


//counts digits of a number
int count_digits(long number)
{
    int digits = 0;
    while (number != 0)
    {
        number = number / 10;
        digits++;
    }
    return digits;
}

// checks validity and the type of the card
void validity(int checksum, long number, int digits)
{

    if (checksum % 10 == 0)
    {
        while (number >= 100)
        {
            number = number / 10;
        }
        if ((number == 34 || number == 37) && digits == 15)
        {
            printf("AMEX\n");
        }
        else if (number / 10 == 4 && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }
        else if ((number == 51 || number == 52 || number == 53 || number == 54 || number == 55) && digits == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// calculates checksum for future validity calcualtions
int calculate_checksum(long number)
{
    int id = 0;
    int remainder = 0;
    int checksum = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        if (id % 2 == 0)
        {
            checksum += remainder;
            id++;
        }
        else if (id % 2 == 1)
        {
            checksum += (remainder * 2) % 10 + (remainder * 2) / 10;
            id++;
        }
    }
    return checksum;
}
