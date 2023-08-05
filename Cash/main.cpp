#include <iostream>

int get_cents(int c){
    do{
        std::cout << "How much change is owed?\n";
        std::cin >> c;    
    } while(c<1);
    std::cout << "I owe you " << c << " cents\n";
    return c;
}
int quarters_owed(int get_cents){
    return get_cents/25;
}
int dimes_owed(int get_cents){
    return get_cents/10;
}
int nickels_owed(int get_cents){
    return get_cents/5;
}
int pennies_owed(int get_cents){
    return get_cents/1;
}

void real_change(){
    int change_owed = get_cents(change_owed);
        //How many coins would someone realistically get
    std::cout << "I can give you : \n";
    std::cout << quarters_owed(change_owed) << " quarters\n";    //quarters owed
    
    int remaining_change = change_owed - (quarters_owed(change_owed)*25); //change after subtracting quarters //16
    std::cout << dimes_owed(remaining_change) << " dimes\n";   //dimes owed
    remaining_change -= (dimes_owed(remaining_change)*10); //change after subtracting dimes //6
     std::cout << nickels_owed(remaining_change) << " nickels\n";   //nickels owed
    remaining_change -= (nickels_owed(remaining_change)*5); //change after subtracting nickels
    std::cout << pennies_owed(remaining_change) << " pennies\n";   //pennies owed
    std::cout << "Thanks for shopping\n";   //pennies owed*/
}
int main(){
/*
//How many of each coin type can be had if only that type of coin is available/allowed 
std::cout << quarters_owed(change_owed) << " quarters\n";
std::cout << dimes_owed(change_owed) << " dimes\n";
std::cout << nickels_owed(change_owed) << " nickels\n";
std::cout << pennies_owed(change_owed) << " pennies\n";
*/

real_change();

return 0;
}