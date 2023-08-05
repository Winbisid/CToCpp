#include <iostream>
#include <cmath>

int first_number(unsigned long long a){
    while(a >= 10){
    a /= 10;
    }
    return a;
}
int first_two_numbers(unsigned long long b){
    while(b >= 100){
    b /= 10;
    }
    return b;
}


unsigned long long int get_card_number(unsigned long long int c){
int size;
//I didn't have to put the visa_length etc in variables.
int visa_length{13};
int amex_length{15};
int mastervisa_length{16};
    do{
    std::cout << "Enter card number :\n";
    std::cin >> c;
    size = (trunc(log10(c)) + 1);
    }while(size < visa_length || size > mastervisa_length);

// std::cout << c%card_length(10,15) << "\n";
// std::cout << c%card_length(10,16) << "\n";
// std::cout << size << "\n";

    if (size==(!visa_length) || size==(!amex_length) || size==(!mastervisa_length) || size==14){
        std::cout << "Invalid card\n";
    }else if(first_two_numbers(c)==34 || first_two_numbers(c)==37){
        std::cout << "AMEX\n";
    }else if(first_two_numbers(c)==51 || first_two_numbers(c)==52 || first_two_numbers(c)==53 || first_two_numbers(c)==54 ){
        std::cout << "MASTERCARD\n";
    }else if(first_number(c)==4){
        std::cout << "VISA\n";
    } else{
        std::cout << "Invalid\n";
    }
return c;
}

auto check_algorithm(auto a){
    int sum{0};
        for(int i = 0; a != 0; i++, a/=10){
            
            if (i%2 == 0 ){
                sum += (a/=10);
            }else{
                int product = 2 * (a/=10);
                sum += (product/10 + product%10);   //because it's an int, dividing by ten will round and give the first number 
                                                    //whilst modulo 10 will give the last or second number
            }
        }
return (sum%10)==0;
}

int main(){

    unsigned long long int card = get_card_number(card);

return 0;
}


//Find the length of the number
//int size = trunc(log10(1945)) + 1;

//Find the first number of the number
/*while(number >= 10){
    number = number/10;
}*/

/*
unsigned long long card_length(unsigned long long a, unsigned long long b){
    return pow(a,b);
}*/
