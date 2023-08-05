#include <iostream>

int main()
{
int n;
do{
std::cout << "Enter a number from 1 to 8 : " << "\n";
std::cin >> n;
}while( n > 8 || n<1);

for(int i = 0; i < n; i++){

    for(int j = 0; j < n; j++){
    
    if(i+j < n-1){
        std::cout << " ";
        }else{
        std::cout << "#";
    }
}    
std::cout << "\n";
}


return 0;
}