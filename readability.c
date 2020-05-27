#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text); //function for count the number of letters from Text
int count_words(string text); //function for count the number of words from Text
int count_sentences(string text); //function for count the number of sentences from Text
void readability_calc(string text); //function that performs the Coleman-liau index


int main(void)
{
    string text = get_string("Text: "); //input text from user

    readability_calc(text);
}

int count_letters(string text)
{

    int totalLetters = 0;
    int length = strlen(text);

    for (int i = 0; i <= length; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) //get letters between upper and lower case
        {
            totalLetters++;
        }
    }
    return totalLetters;
}

int count_words(string text)
{

    int totalWords = 1;
    int length = strlen(text);

    for (int i = 0; i <= length; i++)
    {
        if (((text[i] >= '[' && text[i] <= 'z') || (text[i] >= '!' && text[i] <= '_'))
            && (text[i + 1] == ' ')) //get words if the caracter is between  those conditions and if the next caracter is a space
        {
            totalWords++;
        }

    }
    return totalWords;
}
int count_sentences(string text)
{
    int totalSentences = 0;
    int length = strlen(text);
    for (int i = 0; i <= length; i++)
    {
        if (((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) &&
            (text[i + 1] == '!' || text[i + 1] == '.'
             || text[i + 1] == '?')) //get sentences if the i and the next i is a letter and a sentence finish
        {
            totalSentences++;
        }
    }
    return totalSentences;
}
void readability_calc(string text)
{
    float L = (float)(count_letters(text) * 100) / count_words(text); //letters in the text * 100 /  number of words in the text
    float S = (float)(count_sentences(text) * 100) / count_words(text); //sentences in the text * 100 /  number of words in the text
    float index = 0.0588 * L - 0.296 * S - 15.8; //Coleman-liau index calculation
    int indexRounded = round(index); //round by the nearest number
    if (indexRounded <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indexRounded > 1 && indexRounded < 16)
    {

        printf("Grade %i\n", indexRounded);
    }
    else if (indexRounded >= 16)
    {

        printf("Grade 16+\n");
    }
}