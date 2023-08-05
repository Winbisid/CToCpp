#include <iostream>
#define MAX 9

class candidate{
    public:
    std::string name;
    int votes;
};

candidate candidates[MAX];
int candidate_count;

bool vote(std::string name);
void print_winner();

int main(int argc, char** argv){

    if(argc<2){
        std::cout << "Usage ./Plurality [candidate ...]";
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        std::cout << "Maximum number of candidates is " << MAX;
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    std::cout << "Number of voters: ";
    std::cin >> voter_count;

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        std::string name;
        std::cout << "Vote: ";
        std::cin >> name;

        // Check for invalid vote
        if (!vote(name))
        {
            std::cout << "Invalid vote.\n";
        }
    }

    // Display winner of election
    print_winner();

return 0;
}

bool vote(std::string name){
    //Loop through the Candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //check if candidate is similar to what is user's vote
        if (candidates[i].name == name)
        {
            //if similar to what user vote for, then increase the specific candidate vote and return true
            candidates[i].votes++;
            return true;
        }
    }
    //else if not similar to candidate vote return false.....and print invalid vote
    return false;
}

void print_winner(){
    //Create and variable and set it to 0
    int maximum_vote = 0;

    //iterate over list of candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //check for candidate votes that are  greater than maximum_vote and set them to maximum_vote
        if (candidates[i].votes > maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }

    //iterate over list of candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //check for candidate votes that are equal to maximum vote and print them as you go
        if (candidates[i].votes == maximum_vote)
        {
            std::cout << candidates[i].name << "\n";
        }
    }

    return;
}