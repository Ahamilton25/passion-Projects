/*
Ardise Hamilton
CWID:11837629
CS101
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <cctype> 
#include <climits>
#include <cstring>
#define MAX_SIZE 20000                   //max size outline
using namespace std;

void Merge(int numbers[], int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   int* mergedNumbers = nullptr;

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}

void MergeSort(int numbers[], int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

void PrintCommon(int arr1[], int arr2[], int sizeArr1, int sizeArr2) { //Print common integers
    for (int i = 0; i < sizeArr1; ++i) {     //access array1
        bool isDuplicate = false;                                      //control determining when like values are found
        for (int j = 0; j < i; ++j) {        //access array2               
            if (arr1[i] == arr1[j]) {        // Match found send to if statement
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {                   // no match found ignore and keep going
            continue;
        }
        for (int j = 0; j < sizeArr2; ++j) {      //Print liked terms compared to array1
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << endl;
                break;
            }
        }
    }
}

void removeDuplicates(int arr[], int& size) {     //Remove duplicate integers within each array to make printing commons easier
    int index = 0;
    for (int i = 0; i < size - 1; ++i) {           //bool variable to determine duplicates 
        bool isDuplicate = false;
        for (int j = 0; j < index; ++j) {          //if bool is switched to true send to if 
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {                        //remove duplicate and shift the array
            arr[index] = arr[i];
            ++index;
        }
    }
    size = index;
}

bool stringCompare(const string& a, const string& b) {
    return a < b;
}

void quicksort(string arr[], int left, int right) {    //Quicksort algorithm from zybooks with alreations
    int i = left, j = right;                           // determine positions to sort while determing the pivot of the intervl
    string pivot = arr[(left + right) / 2];

    while (i <= j) {                                  // Instead of using numerical ideal replace with C++ string functions and bool "stringCompare"
        while (stringCompare(arr[i], pivot))
            i++;
        while (stringCompare(pivot, arr[j]))
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);                //swap values 
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void removeDuplicatesString(string arr[], int& size) {              //Remove all duplicated values in each array after sorting calls
    int index = 0;
    for (int i = 0; i < size; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < index; ++j) {                           //When a duplicate is found bool will be true and pass to next "if"
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {                                        //Remove duplicate and shift array while updating size
            arr[index] = arr[i];
            ++index;
        }
    }
    size = index;
}

void PrintCommonString(string arr1[],string arr2[], int sizeArr1, int sizeArr2){   //Print common words to std output
   int i = 0;
   int j = 0;
   
   for(i =0; i<sizeArr1;++i){                                     //scan array1
      bool isSame = false;                                       //bool allows to determine when a match is found
      for(j = 0; j< sizeArr2; ++j){                              //access array2
         if(arr1[i] == arr2[j]){                                 //When common print if not skip
            isSame = true;
            cout<<arr1[i]<<endl;
            break;
         }
         else{
            continue;
         }
      }
   }
}

int main(int argc, char* argv[]){

    if(argc != 4){                                                   //Verify user provided necessary arguments
        cout << "Invalid number of arguments." << endl;
        return 1;
    }

    string dataType = argv[1];                  //Command prompt arguments
    string input1 = argv[2];
    string input2 = argv[3];

    ifstream file1(input1);                    //Dedicated file streams for each document
    ifstream file2(input2);
    
    int vec1[MAX_SIZE], vec2[MAX_SIZE];        //Integer arrays with maximum size allocated
    
    int count;                                  
    int count1;
    
    string txt1[MAX_SIZE];                     //Declare string arrays with maximum array length
    string txt2[MAX_SIZE];

    if(dataType == "i"){                       //If user chooses integer mode
        int num, i = 0, j = 0;

        while(file1 >> num){                   // Extract the integers from file1
            vec1[i++] = num;
            
        }

        count1 = i;                            //Track the number of integers in array1

        while(file2 >> num){                   //Extract the integers from file2
            vec2[j++] = num;
        }
            count = j;                         //Track the number of integers in array2
           
        MergeSort(vec1, 0, count1 - 1);        // Sort first array
        MergeSort(vec2, 0, count - 1);         //sort second array
    
        PrintCommon(vec1, vec2, count1, count);    //Print the common integers to output
    }
    
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
   
    
     if(dataType == "s"){                                   //If user chooses string mode
        string word;
        int i = 0, j = 0;
        
        while(file1 >> word){                                //Extract all words in file1 in array1
            txt1[i++] = word;
            
        }
        count1 = i;                                         //Track the active number of words in array1
            
        while(file2 >> word){                               //Extract all words from second file
            txt2[j++] = word;
        }
            count = j;
  
         quicksort(txt1, 0, count1 - 1);                    //Recursive quicksort call to sort both arrays
         quicksort(txt2, 0, count - 1);
          
    
    removeDuplicatesString(txt1, count1);                   //Remove all common words inside arrays before commons identified
    removeDuplicatesString(txt2, count);
    
    
    PrintCommonString(txt1, txt2, count1, count);           //call void function to print common values
     }
    
    return 0;
}