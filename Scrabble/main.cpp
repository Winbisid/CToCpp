#include <iostream>

int compute_score(std::string word){
    int POINTS[]{1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,4,10};

    int score;

    for(int i = 0, length = word.size(); i < length; i++){

        if (word[i] < 'A' || word[i] > 'z' || (word[i] > 'Z' && word[i] < 'a') ){
            score += 0;
            // std::cout << "You entered an invalid character" << std::endl;
        }
        if (isupper(word[i])){
            score += POINTS[word[i]-'A'];
        }else if (islower(word[i])){
            score += POINTS[word[i]-'a'];
        }
    }
    return score;
}

void get_words(std::string a, std::string b){
std::string word1;
std::string word2;

std::cout << "Player 1 : \n";
std::cin >> word1;
std::cout << "Player 2 : \n";
std::cin >> word2;

int score1 = compute_score(word1);
int score2 = compute_score(word2);

if (score1>score2){
    std::cout << "Player 1 wins!\n";
    }else if (score1<score2){
    std::cout << "Player 2 wins!\n";
    }else if (score1==score2){
    std::cout << "It's a tie!\n";
    }else{
        std::cout << "ERROR!!\n";
    }
}

int main(){

get_words("a", "b");

return 0;
}
// return (score1>score2) ? score1 : score2;