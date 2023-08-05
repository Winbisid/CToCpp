#include <iostream>
#include <string>
#include <cmath>

std::string get_textInput(std::string text){
    std::cout << "Text : \n";
    std::getline(std::cin, text);
    return text;
}

int count_letters(std::string text){

    int letter_length;

    for(int i = 0, length = text.size(); i < length; i++){

        if (text[i] < 'A' || text[i] > 'z' || (text[i] > 'Z' && text[i] < 'a') ){
            letter_length += 0;
        }
        if (isupper(text[i])){
            letter_length++;
        }else if (islower(text[i])){
            letter_length++;
        }
    }            
    // std::cout << letter_length << " letters\n";
    return letter_length;
}

int count_words(std::string text){

    int word_length;

    for(int i = 0, length = text.size(); i < length; i++){

        if (text[i] == ' '){
        (word_length++);
        }else{
        word_length+= 0;
        }
    }
    // std::cout << word_length + 1 << " words\n";
    return word_length + 1;
}
int count_sentences(std::string text){

    int sentence_length;

    for(int i = 0, length = text.size(); i < length; i++){

        if (text[i] == '.' || text[i] == '!' || text[i] == '?' ){
        sentence_length++;
        }else{
        sentence_length+= 0;
        }
    }
    // std::cout << sentence_length << " sentences\n";
    return sentence_length;
}


int main(){

    std::string text = get_textInput("");

    double a = count_letters(text);
    double b = count_words(text);
    double c = count_sentences(text);

    double L = a / b * 100;
    double S = c / b * 100;

    // std::cout << L << " L\n";
    // std::cout << S << " S\n";

    double index_grade = 0.0588 * L - 0.296 * S - 15.8;

    // std::cout << index_grade;

    if(round(index_grade)<1){
        std::cout << "Before Grade 1";
    }else if(round(index_grade)>=16){
        std::cout << "Grade 16+ (Senior Undergraduate and above)";
    }else{
        std::cout << "Grade " << round(index_grade);
    }

return 0;
}

// int count_letters (std::string get_textInput){
//     int letter_length = get_textInput.length();
//     std::cout << letter_length;
//     return letter_length;


    // count_letters(text);
    // std::cout << "\n";
    // count_words(text);
    // std::cout << "\n";
    // count_sentences(text);
// }