#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//write by Wictor Wilcken/ github = /WictorAW

int main(int argc, string argv[])
{
    if (argc == 2) // check if you have 2 arguments
    {
        int length = strlen(argv[1]); // get the string lenght

        for (int i = 0; i < length; i++) // check if key lenght is != 26 or if is a alpha
        {
            if (!isalpha(argv[1][i]) || length != 26)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        for (int i = 0; i < length; i++)// check if key isnt duplicate
        {
            int j = 0;
            for (int k = 0; k < length; k++)
            {
                if (toupper(argv[1][k]) == toupper(argv[1][i]))
                {
                    j++;
                    if (j >= 2)
                    {
                        printf("repeated value, check the key\n");
                        return 1;
                    }
                }
            }
        }
        //if everything is ok, run
        string key = argv[1];
        string text = get_string("plaintext:");
        printf("ciphertext:");
        int textlength = strlen(text);
        int k = 0;
        int p = 0;

        for (int i = 0; i < textlength; i++) // run until i = length
        {
            if (isupper(text[i]))// if upper run the algorithm to trade plain for cypher
            {
                p = text[i];
                k = toupper(key[p - 'A']);// maybe toupper isnt necessary, but i take the p value - 'A' value and get a number between 0 ~ 26
                text[i] = k;// trade value
                printf("%c", text[i]);
            }

            else if (islower(text[i]))// if lower run the algorithm to trade plain for cypher
            {
                p = text[i];// get plain text value
                k = tolower(key[p - 'a']);// maybe tolower isnt necessary, but i take the p value - 'a' value and get a number between 0 ~ 26
                text[i] = k;// trade value
                printf("%c", text[i]);
            }

            else// if isnt a word, then just print
            {
                printf("%c", text[i]);
            }
        }
    }
    else// if argc != 2
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    printf("\n");
    return 0;// exit after run
}
