#include <cs50.h>
#include <stdio.h>

int quarters(int cash);
int dimes(int cash);
int nickels(int cash);
int pennies(int cash);

int main(void)
{
    int cash;
    do
    {
        cash = get_int("Change owed: ");
    } while (cash < 0);

    int n = 0;
    int change = quarters(cash);
    cash = cash - (change * 25);
    n = change;
    change = dimes(cash);
    cash = cash - (change * 10);
    n = n + change;
    change = nickels(cash);
    cash = cash - (change * 5);
    n = n + change;
    change = pennies(cash);
    cash = cash - (change * 1);
    n = n + change;
    printf("%i \n", n);
}

int quarters(int cash)
{
    int counter = 0;
    while (cash >= 25)
    {
        counter++;
        cash = cash - 25;
    }
    return counter;
}
int dimes(int cash)
{
    int counter = 0;
    while (cash >= 10)
    {
        counter++;
        cash = cash - 10;
    }
    return counter;
}
int nickels(int cash)
{
    int counter = 0;
    while (cash >= 5)
    {
        counter++;
        cash = cash - 5;
    }
    return counter;
}
int pennies(int cash)
{
    int counter = 0;
    while (cash >= 1)
    {
        counter++;
        cash = cash - 1;
    }
    return counter;
}
