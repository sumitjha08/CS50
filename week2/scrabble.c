#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int score_calc(string word);

int main(void)
{

    string score1 = get_string("Player 1: ");
    string score2 = get_string("Player 2: ");
    int Pscore1 = score_calc(score1);
    int Pscore2 = score_calc(score2);

    if (Pscore1 > Pscore2)
    {
        printf("Player 1 wins!\n");
    }
    else if (Pscore1 < Pscore2)
    {
        printf("player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
}
int score_calc(string word)
{
    int score = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(word[i]))
        {
            char c = toupper(word[i]);
            score += points[c - 65];
        }
    }
    return score;
}
