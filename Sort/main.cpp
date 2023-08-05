#include <iostream>

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        std::cout << A[i] << " ";
}

int main(){

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
// Driver code
int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
  
    std::cout << "Given array is \n";
    printArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);
  
    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
  
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
}






























/*
typedef struct 
{
    std::string name;
    std::string numbers;
}
person;

// struct image_pixel
// {
//     unsigned short int red;
//     unsigned short int green;
//     unsigned short int blue;
// };

// class person
// {
//     public:
//     std::string name;
//     std::string numbers;
// };

int main(int argc, char** argv){

person people[2];
people[0].name={"Bill"};
people[1].name={"Charlie"};
people[0].numbers={"+1-600-322-3233"};
people[1].numbers={"+1-917-615-3200"};

for(int i = 0; i < 2; i++){
    if(people[i].name==argv[1]){
        std::cout << "Found\n" << people[i].name << ": " << people[i].numbers;
        return 0;
    }
}
    std::cout << "Not found\n";
    return 1;

return 0;
}

// void draw(int x){
//     if(x<=0){
//         return;
//     }
//     draw(x-1);

//     for(int i=0; i < x; i++){
//         std::cout << "#";
//         }

//     std::cout << "\n";
//     int height;
//     std::cout << "Height: ";
//     std::cin >> height;
//     draw(height);

// int collatz(int n){
//     if(n==1){
//         return 0;
//     }else if(n%2==0){
//         return 1 + collatz(n/2);
//     }else{
//         return 1 + collatz(3*n+1); 
//     }
// }
*/