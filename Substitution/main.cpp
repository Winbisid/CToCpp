#include <iostream>
#include <string>

int main(int argc, char** argv){

std::string plaintext;
std::string ciphertext;
std::cout << "plaintext: ";
std::getline(std::cin, plaintext);

std::string key = argv[1];

if(argc > 2 || argc <= 1){
    std::cout << "Usage: ./Substitution key\n";
    return 1;
}

for(int i = 0, length = key.length(); i < length; i++){
    if(length>26||length<26 || !(isalpha(key[i]))){
        std::cout << "Key must contain 26 characters\n";
        return 2;
    }

    int count = 1; //Updates the count again to 1 for every new character

    for(int j = i+1; j < length; j++) {
    if(key[i] == key[j]) {
    count++;
    //Set string[j] to 0 to avoid printing the visited character 
    key[j] = '0';
        }
    }
    if(count > 1){
        std::cout << "No duplicate key characters allowed.";
        return 3;
    }

    // std::cout << key[i];
}

// std::cout << "\n";
    std::cout << "ciphertext: ";

for(int k = 0, length = plaintext.length(); k < length; k++){
            if (islower(plaintext[k])){
        int index = plaintext[k]-'a';
        unsigned char newkey = key[index];
        ciphertext[k] = tolower(newkey);
        }else if (isupper(plaintext[k])){
            int index = plaintext[k]-'A';
        unsigned char newkey = key[index];
        ciphertext[k] = toupper(newkey);
        }
        else{
            ciphertext[k] = plaintext[k];
        }
        std::cout << ciphertext[k];
    }
// for(int k = 0, length = plaintext.length(); k < length; k++){
//             if (isupper(plaintext[k])){
//         ciphertext += key[plaintext[k]-'A'];
//         }else if (islower(plaintext[k])){
//             ciphertext += key[plaintext[k]-'a'];
//         }
//         // else{
//         //     std::cout << plaintext[k];
//         // }
//     }


return 0;
}













































    /*
    char c;
do{
std::string name1, name2;
std::cout << "Enter name: \n";
std::getline(std::cin, name1);
std::cout << "Hello " << name1 << "\n";

std::cout << "Do you want to continue? Y|N \n";
std::cin >> c;
}while(c ='Y'||'y');
*/
/*
    std::cout << "Name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << name;
*/
/*
    std::string name;
    std::getline(std::cin, name);

    for(int i = 0, length = name.length(); i < length; i++){
        std::cout << name[i];
    }
*/
    // std::cout << "Hello, " << argv[1];

    // for(int i = 1, n = argc; i < n; i++){
    //     std::cout << argv[i] << "\n";
    // }

    // std::cout << valid_triangle(13,-34,4);
/*
bool valid_triangle(int l1, int l2, int l3){
    if(!(l1 > 0 && l2 > 0 && l3 > 0)){
        return false;
    }else if(!(l1 + l2 > l3 || l1+l3 > l2 || l2+l3 > l1)){
        return false; 
    }else{
        return true;
    }
}
*/