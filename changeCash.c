#include <stdio.h>
#include <math.h>
#include <cs50.h>

float get_positive_float(void);
int minimumValue(float);

int main(void)
{

    float amount = get_positive_float() ;
    printf("%i\n", minimumValue(amount));

}

float get_positive_float(void)// check positive
{

    float n;

    do
    {
        n = get_float("Change owed:");
    }
    while (n < 0);
    return n;
}

int minimumValue(float value)// change fuction
{
    int i = 0;
    int dolar = floor(value) / 0.25; // get the minimum dolar

    value = value - floor(value); // take cents from value, floor help me with decimals
    value = round(value * 100); // round cents to convert above

    while (value > 0) // while value > 0  keep incrising i
    {

        if (value >= 25)
        {
            value = value - 25;
            i++;
        }
        else if (value >= 10 && value < 25)
        {
            value = value - 10;
            i++;
        }
        else if (value >= 5 && value < 10)
        {
            value = value - 5;
            i++;
        }
        else if (value >= 1 && value < 5)
        {
            value = value - 1;
            i++;
        }
    }

    return dolar + i;// total
}

