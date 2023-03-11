#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Functions
int compute_score(string word); // Calculates score of word
bool check_input(char letter); // Checks if current char is a letter

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("\nPlayer 1 Wins!");
    } else if (score1 < score2) {
        printf("\nPlayer 2 wins!");
    } else {
        printf("\nTie!");
    }

    printf("Score 1 = %i\nScore 2 = %i", score1, score2);
}

// Calculates score of word
int compute_score(string word)
{
    int total = 0; // Keeps value of points of a word

    // TODO: Compute and return score for string
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // If current index of word is a letter, then finds its value and adds to total points
        if (check_input(word[i])) {
            total += POINTS[toupper(word[i]) - 65];
        }
    }
    return total; // Returns the amount of points the word is worth
}

// Checks if the current index in the string is a letter, returns true if so
bool check_input(char letter)
{
    // If letter is between the ascii values that the alphabet is in, then reutrns true
    if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122)) {
        return true;
    } else {
        return false;
    }
}