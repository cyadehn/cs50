#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Sort candidates in descending order
    // Loop to sort for each candidate in array
    for (int i = 0; i < candidate_count; i++)
    {
        // Store current candidate for future swap
        candidate current = candidates[i];
        int swapIndex = i;
        // Loop through each candidate after the ith item to check for larger values
        for (int n = i; n < candidate_count; n++)
        {
            if (candidates[n].votes > current.votes)
            {
                swapIndex = n;
            }
        }
        // Swap ith and smallest items, if not the same ith item
        if (swapIndex != i)
        {
            candidates[i] = candidates[swapIndex];
            candidates[swapIndex] = current;
        }
    }
    // Compare starting candidates until finding a candidate with lower vote count
    printf("Winner(s): %s", candidates[0].name);
    if (candidates[0].votes == candidates[1].votes)
    {
        int i = 1;
        while (candidates[i].votes == candidates[i-1].votes)
        {
            printf(", %s", candidates[i].name);
            i++;
        }
    }
    printf("\n");
    return;
}

