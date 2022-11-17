#include <cs50.h>
#include <stdio.h>


int get_height(void);
void final_pyramid(int height);


int main(void)
{
    int height;
    // gets the height from user
    height = get_height();
    //prints the final two pyramids with 2 spaces between
    final_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void final_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        //prints left pyramid
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        //dots between pyramids
        printf("  ");

        //prints right pyramid
        for (int p = 0; p < i + 1; p++)
        {
            printf("#");
        }
        printf("\n");
    }
}
