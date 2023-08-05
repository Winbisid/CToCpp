/*#include <iostream>
#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

int preferences[MAX_VOTERS][MAX_CANDIDATES];

class candidate{
    public:
    std::string name;
    int votes;
    bool eliminated;
};

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, std::string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char** argv){

    if(argc<2){
        std::cout << "Usage ./Runoff [candidate ...]";
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        std::cout << "Maximum number of candidates is " << MAX_CANDIDATES;
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

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

return 0;
}

bool vote(int voter, int rank, std::string name){
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
*/



/*
//malloc & free
#include <iostream>

int main() {

    std::string s;
    std::string t = (char*) malloc(s.length()+1);

    // if(t==NULL){
    //     return 1;
    // }

    std::cin >> s;
    t = s;

    if(t.length() > 0){
    t[0] = toupper(t[0]);
    }

    std::cout << s << "\n";
    std::cout << t;

    // free(t);

    //example 2
    // int *x = (int*) malloc(3 * sizeof(int));
    // x[0]={72};
    // x[1]={73};
    // x[2]={33};

    // if(x==NULL){
    //     return 1;
    // }

    // free(x);

return 0;
}
*/

#include <iostream>

int main(){

    int scores[3];

    for(int i = 0; i < 3; i++){
        std::cout << scores[i] << "\n";
    }

return 0;
}