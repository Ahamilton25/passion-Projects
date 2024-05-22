#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {

    // Check number of arguments
    if (argc != 4) 
    {
        cout << endl << "Needs 3 command line arguments" << endl;
        return 1;   // 1 indicates error
    }

    ifstream inFS; // Decryption Key
    ifstream inFS2; // Text file to decrypt

    // Try to open files
    inFS.open(argv[1]);
    inFS2.open(argv[2]);

    // Check that files open
    if (!inFS.is_open() || !inFS2.is_open()) 
    {
        cout << "Could not open file " << argv[1] << "." << endl;
        return 1;
    }

    int count = 0; // Number of characters in the first text file
    char tempChar;

    // Count the number of characters in the first text file
    while (!inFS.eof())
    {
        inFS >> tempChar;
        count++;
    }

    // Arrays for encoded and decrypted characters
    int arraySize = count/2;
    string actualChars;
    string encodedChars;

    // Fill in arrays for encoded and decrypted characters
    inFS.close();
    inFS.open(argv[1]);

    for (int i = 0; i < arraySize; i++)
    {
        inFS >> tempChar;
        actualChars.push_back(tempChar);
    }
    for (int i = 0; i < arraySize; i++)
    {        
        inFS >> tempChar;
        encodedChars.push_back(tempChar);
    }

    // Array for unused letters of the alphabet
    string leftCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++)
    {
        if (encodedChars.find(i+65) != string::npos)
        {
            leftCharacters.erase(remove(leftCharacters.begin(), leftCharacters.end(), i+65), leftCharacters.end()); 
        }
    }

    // Put file 2 text in the output string
    string outputString; 
    while (!inFS2.eof())
    {
        string tempStr;
        inFS2 >> tempStr;
        outputString = outputString + tempStr + ' ';
    }

    // First decoding
    for (int i = 0; i < int(outputString.size()); i++)
    {
        if (encodedChars.find(outputString.at(i)) != string::npos)
        {
            outputString.at(i) = actualChars.at(encodedChars.find(outputString.at(i)));
        }
    }
    for (int i = 0; i < int(outputString.size()); i++)
    {
        if(!isalpha(outputString.at(i)) && outputString.at(i)!='\n')
        {
            outputString.at(i) = ' '; // Replace punctuation with spaces
        }
    }

    // Figure out how the last command line argument is encoded
    istringstream inSS(outputString);
    string currentString;
    string codeWord = argv[3];
    string lastCodes;
    bool shouldLoopBreak = false;
    count = 0;

    while (!shouldLoopBreak)
    {
        count = 0;
        inSS >> currentString;
        bool hasSameSize = (currentString.size() == codeWord.size());

        if (hasSameSize)
        {
            for (int i = 0; i < int(currentString.size()); i++)
            {
                if (currentString.at(i) == codeWord.at(i) || leftCharacters.find(currentString.at(i)) != string::npos)
                {
                    count++;
                }
            }
        }
        if (count == int(codeWord.size()))
        {
            lastCodes = currentString;
            shouldLoopBreak = true;
        }
    }

    // Complete cipher
    for (int i = 0; i < int(codeWord.size()); i++)
    {  
        if (encodedChars.find(lastCodes.at(i)) == string::npos) // if the character is not in the array
        {
            encodedChars.push_back(lastCodes.at(i));
            actualChars.push_back(codeWord.at(i));
        }
    }

    // If the encodedChars size is 25, add the missing letter to complete the alphabet
    string fullAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (encodedChars.size() == 25)
    {
        for (int i = 0; i < int(fullAlphabet.size()); i++)
        {
            if (encodedChars.find(fullAlphabet.at(i)) == string::npos)
            {
                encodedChars.push_back(fullAlphabet.at(i));
                break;
            }
        }
        for (int i = 0; i < int(fullAlphabet.size()); i++)
        {
            if (actualChars.find(fullAlphabet.at(i)) == string::npos)
            {
                actualChars.push_back(fullAlphabet.at(i));
            }
        }
    }

    inFS2.close();
    inFS2.open(argv[2]);

    // Print the final decrypted text
    string tempString; // Declare tempString to read lines from inFS2
    while (!inFS2.eof())
    {
        getline(inFS2, tempString);
        for (int i = 0; i < int(tempString.size()); i++)
        {
            if (encodedChars.find(tempString.at(i)) != string::npos)
            {
                cout << actualChars.at(encodedChars.find(tempString.at(i)));
            }
            else
            {
                cout << tempString.at(i);
            }
        }
        cout << endl;
    }

    // Done with files, so close them
    inFS.close();
    inFS2.close();

    return 0;
}
