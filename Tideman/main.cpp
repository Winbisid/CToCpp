#include <iostream>
//Buggy

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;


// Array of candidates
std::string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, std::string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool constitute_circle(int base, int loser); // helper function for lock_pairs
void print_winner(void);

int main(int argc, char** argv){


    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // Print candidates
    printf("Candidates: ");

    for (int i = 0; i <  candidate_count; i++)
    {
        printf("%s ", candidates[i]);
    }

    printf("\n");

    pair_count = 0;
    int voter_count;
    std::cout << "Number of voters: ";
    std::cin >> voter_count;

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // std::string name = get_string("Rank %i: ", j + 1);
                std::string name;
                std::cout << "Rank of voters: ";
                std::cin >> name;


            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;

return 0;
}

bool vote(int rank, std::string name, int ranks[])
{
    // Check if 'name' exist inside the candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // The specification assume that no two candidates have the same name, so we can ignore checking for duplicates.
        if(name == candidates[i]) {
            // Set rank
            // 'i' here is the index of the candidate in the candidates array
            ranks[rank] = i;
            return true;
        }
    }
    // candidate doesn't exist
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // The specification assumes that every voter will rank each of the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Ex: int ranks[] = {2, 0, 1}
        // Loop 1 => preferences[2][0] += 1, preferences[2][1] += 1
        // Loop 2 => preferences[0][1] += 1
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

bool constitute_circle(int base, int loser)
{
    // Recursive function to check if a new lock will constitute a circle
    // If it makes a circle, return true
    if (loser == base)
    {
        // If the loser is the base of the circle again
        return true;
    }

    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If the pair is locked, check if it will constitute a circle again
        if (locked[loser][i])
        {
            if (constitute_circle(base, i))
            {
                return true;
            }
        }
    }

    // doesn't constitute a circle
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // A candidate win if there's no arrow pointing at him

    for (int i = 0; i < candidate_count; i++)
    {
        bool pointed_at = false;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                pointed_at = true;
            }
        }

        if (!pointed_at)
        {
            printf("Winner: %s\n", candidates[i]);
        }
    }

    return;
}