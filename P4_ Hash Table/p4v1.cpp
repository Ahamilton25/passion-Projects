#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

unsigned long djb2(string str) {
    const char *ptr = str.c_str();
    unsigned long hash = 5381;
    int c;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

class Entry {
public:
    Entry() : word(""), lines({}) {}
    Entry(string word, vector<int> lines) : word(move(word)), lines(move(lines)) {}

    string word;
    vector<int> lines;
};

class HashTable {
public:
    HashTable(int size, char strategy, int dhParam = 0)
        : table(size), strategy(strategy), dhParam(dhParam), collisions(0) {}

    void insert(const string &word, int line) {
        int index = hash(word);
        int j = 0;
        while (true) {
            int pos = resolve_collision(index, j);
            if (table[pos].word.empty()) {
                table[pos] = Entry(word, {line});
                break;
            } else if (table[pos].word == word) {
                table[pos].lines.push_back(line);
                break;
            } else {
                this->collisions++;
            }
            ++j;
        }
    }

    pair<vector<int>, int> search(const string &word) {
        int index = hash(word);
        int j = 0;
        int searchCollisions = 0;
        vector<int> lines;
        while (true) {
            int pos = resolve_collision(index, j);
            if (table[pos].word.empty()) {
                break;
            } else if (table[pos].word == word) {
                lines = table[pos].lines;
                break;
            } else {
                ++searchCollisions;
            }
            ++j;
        }
        return {lines, searchCollisions};
    }

    int getCollisions() const {
        return collisions;

    }

private:
    Entry * table;
    char strategy;
    int dhParam;
    int collisions;


    int hash(const string &word) {
        return djb2(word) % size;
    }

    int resolve_collision(int index, int j) {
        if (strategy == 'l') {
            return (index + j) % size;
        } else if (strategy == 'q') {
            return (index + j * j) % size;
        } else{
            return (index + j * (dhParam - (djb2(table[index].word) % dhParam))) % size;
        }
    }
};

string preprocess(const string &word) {
    string result;
    for (char c : word) {
        if (isalnum(c)) {
            result.push_back(tolower(c));
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    ifstream inputFile(argv[1]);
    ifstream queryFile(argv[2]);
    int size = stoi(argv[3]);
    char strategy = argv[4][0];
    int dhParam = (strategy == 'd') ? stoi(argv[5]) : 0;

    HashTable table(size, strategy, dhParam);
    string line;
    int lineNumber = 0;
    int totalWords = 0;
    int uniqueWords = 0;
    string tempstr;
    


    while(!inputFile.eof()){
inputFile >> tempstr;
        totalWords++;
    }
    

    while (getline(inputFile, line)) {
        ++lineNumber;
        
        istringstream iss(line);
        string word;
        while (iss >> word) {
            string processedWord = preprocess(word);
            if (!processedWord.empty()) {
                pair<vector<int>, int> searchResult = table.search(processedWord);
                vector<int> lines = searchResult.first;

                if (lines.empty()) {
                    uniqueWords++;
                }
                table.insert(processedWord, lineNumber);
            }
        }
    }

    cout << "The number of words found in the file was " << (totalWords) << endl;
    cout << "The number of unique words found in the file was " << (uniqueWords) << endl;
    cout << "The number of collisions was " << table.getCollisions() << endl << endl;

    string queryWord;
    while (getline(queryFile, queryWord)) {
        pair<vector<int>, int> searchResult = table.search(preprocess(queryWord));
        vector<int> lines = searchResult.first;
        int collisions = searchResult.second;

        cout << queryWord << " appears on lines ";
        if (!lines.empty()) {
            cout << "[" << lines[0];
            for (size_t i = 1; i < lines.size(); ++i) {
                cout << "," << lines[i];
            }
            cout << "]" << endl;
        } else {
            cout << "[]" << endl;
        }
        cout << "The search had " << collisions << " collisions"  << endl << endl;
    }

    return 0;
}
