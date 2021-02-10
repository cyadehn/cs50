#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop through candidates for comparison with passed in name
    for (int i = 0; i < candidate_count; i++)
    {
        // If passed name is in the candidates array, record vote in main preferences array
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    // If no valid candidate found, return false to end program
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop through all voters
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through voter's preferences
        for (int j = 0; j < candidate_count; j++)
        {
            int pref_index = preferences[i][j];
            // Check if candidate has been eliminated
            if (!candidates[pref_index].eliminated)
            {
                // Record vote and continue to the next voter
                candidates[pref_index].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Sort descending candidates by votes cast
    // Loop to sort for each candidate in array
    for (int i = 0; i < candidate_count; i++)
    {
        // Store current candidate for future swap
        candidate current = candidates[i];
        int swap_index = i;
        // Loop through each candidate after the ith item to check for larger values
        for (int n = i; n < candidate_count; n++)
        {
            if (candidates[n].votes > current.votes)
            {
                swap_index = n;
            }
        }
        // Swap ith and smallest items, if not the same ith item
        if (swap_index != i)
        {
            candidates[i] = candidates[swap_index];
            candidates[swap_index] = current;
        }
    }
    // Calculate majority vote needed
    int majority = voter_count / 2;
    // Check first sorted candidate for winning vote
    if (candidates[0].votes > majority)
    {
        // Print winner's name
        printf("%s\n", candidates[0].name);
        return true;
    }
    // Exit without a winner to continue runoff
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = 0;
    // Perform linear search for the non-eliminated candidate with the smallest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        candidate current = candidates[i];
        if (current.eliminated == true)
        {
            continue;
        }
        if (i == 0 || current.votes < min)
        {
            min = current.votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Store first candidate's vote count
    int comparison_count = candidates[0].votes;
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Check remaining candidates for a match, returning false if a count is different
        if (candidates[i].votes != comparison_count)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Eliminate candidates who have the min/least votes
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
