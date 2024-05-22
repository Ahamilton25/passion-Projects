//Dominic Brunson
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;


string readFile(string filename) {
  ifstream f;

  f.open(filename);  // Open the file with the provided filename

  if (f.is_open()) {  // Check if the file is successfully opened
    string filetext = "";  // Initialize an empty string to store the contents of the file
    string temp;
    while (getline(f, temp)) {  // Read each line of the file and store it in 'temp'
      filetext.append(temp + " ");  // Append the line to 'filetext', along with a space separator
    }
    f.close();  // Close the file
    return filetext;  // Return the contents of the file
  } 
  else{
    return "";  // Return an empty string if the file failed to open
  }
}

void scanInt(string file, int* values, int* valCount) {
  int curr = 0;  // Variable to store the current integer being scanned
  bool negative = false;  // Flag to indicate if the current number is negative

  for (int i = 0; i < file.size(); i++) {  // Iterate through each character of the file string
  //cout << file.at(i) << "\t" << curr << endl;  // Debugging line
    if (isdigit(file.at(i))) {  // Check if the character is a digit
      if (file.at(i) == '0' && curr == 0) {  // Handle leading zero case
        values[*valCount] = 0;
        *valCount += 1;
        negative = false;
        continue;
      }
      curr *= 10;  // Multiply the current value by 10 to shift it left
      curr += (file.at(i) - '0');  // Add the digit to the current value
    }
        else if (file.at(i) == '-') {  // Check if the character is a minus sign indicating a negative number
            negative = true;
        }
        else {  // Handle non-digit characters (end of a number)
            if (curr != 0) {  // Check if there was a number being read
                if (negative) {  // Apply negative sign if necessary
                    curr *= -1;
                }
                values[*valCount] = curr;  // Store the number in the 'values' array
                *valCount += 1;  // Increment the count of values
                curr = 0;  // Reset the current value
                negative = false;  // Reset the negative flag
            }
        }
    }
    return;  // Function does not return anything (void)
}

void scanString(string file, string *words, int *count)
{
    int last = 0; // Variable to keep track of the index of the last non-alphabetic character

    for (int i = 0; i < file.size(); i++) {
        // Check if the current character is not alphabetic
        if (!isalpha(file.at(i))) {
            words[*count] = file.substr(last, i - last); // Extract the word between the last non-alphabetic character and the current character
            *count += 1; // Increment the word count

            // Skip any consecutive non-alphabetic characters
            while (!isalpha(file.at(i)) && i < file.size() - 1) {
                i++;
            }

            last = (int)i; // Update the index of the last non-alphabetic character
        }
    }

    return;
}


void findIntDupes(int *a0, int *c0, int *a1, int *c1, int *b, int *c)
{
  for (int i = 0; i < *c0; i++) {
    int curr = a0[i]; // Get the current value from the first array
    for (int j = 0; j < *c1; j++) {
      if (a1[j] == curr) { // Check if the current value exists in the second array
        bool unique = true; // Flag to track uniqueness
        for (int k = 0; k < *c; k++) {
          if (b[k] == curr){ // Check if the current value already exists in the result array
              unique = false; // Set the uniqueness flag to false
          }
        }
        if (unique) {
          b[*c] = curr; // Store the unique value in the result array
          *c += 1; // Increment the count of unique values in the result array
        }
      }
    }
  }

    return; // Exit the function
}


void findStringDupes(string *w0, int *c0, string *w1, int *c1, string *w, int *c){
  for (int i = 0; i < *c0; i++) {
    string curr = w0[i]; // Get the current string from the first array
    for (int j = 0; j < *c1; j++) {
      if (curr.compare(w1[j]) == 0) { // Check if the current string matches with an element in the second array
        bool unique = true; // Flag to track uniqueness
        for (int k = 0; k < *c; k++) {
          if (curr.compare(w[k]) == 0){ // Check if the current string already exists in the result array
            unique = false; // Set the uniqueness flag to false
          }
            }
        if (unique) {
          w[*c] = curr; // Store the unique string in the result array
          *c += 1; // Increment the count of unique strings in the result array
        }
      }
    }
  }
    return;
}


void mergeInt(int *array, int l, int m, int r){
  int i, j, k, nl, nr;

  nl = m - l + 1; // Calculate the size of the left subarray
  nr = r - m;     // Calculate the size of the right subarray

  int larr[nl], rarr[nr]; // Create temporary arrays to hold the left and right subarrays

  // Copy the elements from the original array to the temporary left subarray
  for (i = 0; i < nl; i++){
    larr[i] = array[l + i];
  }

  // Copy the elements from the original array to the temporary right subarray
  for (j = 0; j < nr; j++){
    rarr[j] = array[m + 1 + j];
  }

  i = 0; // Initial index of the left subarray
  j = 0; // Initial index of the right subarray
  k = l; // Initial index of the merged subarray

  // Merge the left and right subarrays in sorted order
  while (i < nl && j < nr) {
    if (larr[i] <= rarr[j]) {
      array[k] = larr[i];
      i++;
    }
    else {
      array[k] = rarr[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of the left subarray, if any
  while (i < nl) {
    array[k] = larr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of the right subarray, if any
  while (j < nr) {
    array[k] = rarr[j];
    j++;
    k++;
  }
}

void mergeIntSort(int *array, int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate the midpoint

        // Sort the left and right halves of the array recursively
        mergeIntSort(array, l, m);
        mergeIntSort(array, m + 1, r);

        // Merge the sorted subarrays
        mergeInt(array, l, m, r);
    }
}

void mergeString(string *array, int l, int m, int r){
    int i, j, k, nl, nr;

    nl = m - l + 1; // Calculate the size of the left subarray
    nr = r - m;     // Calculate the size of the right subarray

    string larr[nl], rarr[nr]; // Create temporary arrays to hold the left and right subarrays

    // Copy the elements from the original array to the temporary left subarray
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];

    // Copy the elements from the original array to the temporary right subarray
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];

    i = 0; // Initial index of the left subarray
    j = 0; // Initial index of the right subarray
    k = l; // Initial index of the merged subarray

    // Merge the left and right subarrays in sorted order
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        } else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subarray, if any
    while (i < nl) {
        array[k] = larr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subarray, if any
    while (j < nr) {
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSortString(string *array, int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate the midpoint

        // Sort the left and right halves of the array recursively
        mergeSortString(array, l, m);
        mergeSortString(array, m + 1, r);

        // Merge the sorted subarrays
        mergeString(array, l, m, r);
    }
}


int main(int argc, char** argv){
  if(argc != 4)
  {
    cout << "[ERROR]: Correct usage is " << argv[0] << " [TYPE] [FILE 1] [FILE 2]" << endl;
    return 0;
  }
  else
  {
    string file0 = readFile(argv[2]);
    string file1 = readFile(argv[3]);

    if(file0.compare("") == 0 || file1.compare("") == 0)
    {
      cout << "[ERROR]: One or more files could not be opened for reading" << endl;
      return 0;
    }

    if(argv[1][0] == 's' || argv[1][0] == 'S')
    {
      string w0[5000], w1[5000];
      int c0 = 0, c1 = 0;

      scanString(file0, w0, &c0);
      scanString(file1, w1, &c1);

      string w[5000];
      int c = 0;

      findStringDupes(w0, &c0, w1, &c1, w, &c);

      mergeSortString(w, 0, c - 1);

      for(int i = 0; i < c; i++) cout << w[i] << endl;

      return 0;
    }

    else if(argv[1][0] == 'i' || argv[1][0] == 'I'){
    
      int a0[5000], c0 = 0,
          a1[5000], c1 = 0;

      scanInt(file0, a0, &c0);
      scanInt(file1, a1, &c1);

      int a[5000], c = 0;

      findIntDupes(a0, &c0, a1, &c1, a, &c);

      mergeIntSort(a, 0, c - 1);

      for(int i = 0; i < c; i++) cout << a[i] << endl;

      return 0;
    }

    else{
      cout << "[ERROR]: Correct types are i (integer) or s (string)" << endl;
      return 0;
    }
  }
  
  return 0;
}