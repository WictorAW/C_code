#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc == 2) // run if you have 2 arguments
    {
        int length = strlen(argv[1]); // get the string lenght

        for (int i = 0; i < length; i++) // check for non-numeric key
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //else
        int key = atoi(argv[1]);
        string text = get_string("plaintext: "); // get input from user
        printf("ciphertext: ");
        int textlength = strlen(text); // get text length

        for (int i = 0; i < textlength; i++) // run until i = length
        {
            if (isupper(text[i]))
            {
                printf("%c", (((text[i] - 'A') + key) % 26) + 'A'); // 'A' = 65
            }

            else if (islower(text[i]))
            {
                printf("%c", (((text[i] - 'a') + key) % 26) + 'a'); // 'a' = 97
            }

            else
            {
                printf("%c", text[i]);
            }
        }
    }
    else // if argc != 2
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("\n");
    return 0;
}