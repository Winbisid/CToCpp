#include <iostream>
#include <string>
#include <cmath>

// char rotate(char x, int y){
// if(isalpha(x)){
//     y%=26;
//     }else{
//         return x+=y;
//     }
// return x;
// }

// void cipherText(){
//     int key;
//     std::string plainText;

//     std::cout << "key: ";
//     std::cin >> key;
//     std::cout << "plaintext: ";
//     std::cin >> plainText;

// 	char arr[plainText.length() + 1];

//     std::cout << "ciphertext: ";
//     for (int x = 0; x < sizeof(arr); x++) {
//         arr[x] = rotate(plainText[x], key);
//         std::cout << arr[x];
// }
// }

// int main(/*int argc, std::string argv[]*/){

// cipherText();

// return 0;

// }

    // main function takes 2 arguments, first one takes number of arguments, and the second one takes an array of strings
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./caesar k";
        return 1;
    }
std::string argument = argv[1];
    // checking if one of the arguments isalpha (we need an integer) - Looping through the string of integers
    for (int key = 0; key < argument.size(); key++)
    {
        if (isalpha(argv[1][key]))
        {
            std::cout << "Usage: ./caesar key\n";
            return 1;
        }
    }

    int key = stoi(argument) % 26; // converts the ASCII to an integer from "20" to 20 as an integer

    // takes the plaintext from the user
    std::string plaintext;
    std::cout << "plaintext: ";
    std::cin >> plaintext;

    std::cout << "ciphertext: ";

    // iterates over the plain text with a for loop
    for (int i = 0, length = plaintext.size(); i < length; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            //prints the current element of the array if it's not alpha
            std::cout << plaintext[i];
            continue;
        }
        // checking if the current element it's uppercase
        int offset = isupper(plaintext[i]) ? 65 : 97;
        // calculating how far the current element is from lowercase "a" or uppercase "A"
        int pi = plaintext[i] - offset;
        // index of the letter cyphering
        int ci = (pi + key) % 26;

        // printing the new character cyphered
        std::cout << char(ci + offset);
    }

    std::cout << "\n";
    return 0;


}