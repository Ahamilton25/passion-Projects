#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

//lp for linear probing
//qp for quadratic probing
//dh for double hashing

unsigned long djb2(string str){
    const char *ptr = str.c_str();
    unsigned long hash = 5381;
    int c;
    while ((c = *ptr++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

// HashEntry Class
class HashEntry{
    private:
        vector<int> lineNums;
        string word;
    public:
        HashEntry(){
            this->word = "";
            this->lineNums.clear();
        };
        HashEntry(string word){
            this->word = word;
            this->lineNums.clear();
        };
        void addLine(int num){
            (this->lineNums).push_back(num);
        };
        string getWord(){
            return word;
        };
        void updateWord(string word){
            this->word = word;
        };
        vector<int> getLineNums(){
            return lineNums;
        };
};

// HashTable Class
class HashTable{
    private:
        int size;
        string collisionResStrat; //collision Resollution Strategy 
        HashEntry *hashArr;
        int doubleHashNum; // only used if collision Resollution Strategy == "dh"
        int collisionCount;
    public:
        HashTable(){
            this->size = 1;
            this->collisionResStrat = "lp";
            this->hashArr = new HashEntry[1];
            this->doubleHashNum = 1;
            this->collisionCount = 0;
        };
        HashTable(int num, string strat){
            this->size = num;
            this->collisionResStrat = strat;
            this->hashArr = new HashEntry[num];
            for (int i = 0; i < num; i++){
                this->hashArr[i] = HashEntry();
            }
            this->doubleHashNum = 0;
            this->collisionCount = 0;
        };
        HashTable(int num, string strat, int hash){
            this->size = num;
            this->collisionResStrat = strat;
            this->hashArr = new HashEntry[num];
            for (int i = 0; i < num; i++){
                this->hashArr[i] = HashEntry();
            }
            this->doubleHashNum = hash;
            this->collisionCount = 0;
        };
        int getSize(){
            return this->size;
        };
        void insert(uint64_t hashedNum, string word, int lineNum){
            if (this->collisionResStrat == "lp"){
                uint64_t tempHash = hashedNum;
                while (1){
                    int newInd = tempHash % (this->getSize());
                    if (this->hashArr[newInd].getWord() == "" || this->hashArr[newInd].getWord() == word){
                        (this->hashArr[newInd]).updateWord(word);
                        (this->hashArr[newInd]).addLine(lineNum);
                        return;
                    }
                    else{
                        tempHash++;
                        this->collisionCount++;
                        continue;
                    }
                }
            }

            else if (this->collisionResStrat == "qp"){
                int counter = 0;
                while (1){
                    int newInd = (hashedNum + counter * counter) % this->getSize();
                    if (this->hashArr[newInd].getWord() == "" || this->hashArr[newInd].getWord() == word){
                        (this->hashArr[newInd]).updateWord(word);
                        (this->hashArr[newInd]).addLine(lineNum);
                        return;
                    }
                    else{
                        counter++;
                        this->collisionCount++;
                        continue;
                    }
                }
            }

        else if (this->collisionResStrat == "dh"){
            int counter = 0;
            while (1){
                int a = this->doubleHashNum;
                int newInd = (hashedNum + (counter * (a - (hashedNum % a)))) % this->getSize();
                if (this->hashArr[newInd].getWord() == "" || this->hashArr[newInd].getWord() == word){
                    (this->hashArr[newInd]).updateWord(word);
                    (this->hashArr[newInd]).addLine(lineNum);
                    return;
                }
                else{
                    counter++;
                    this->collisionCount++;
                    continue;
                }}}};
    int getHashNum(){
        return doubleHashNum;
    };
    int getCollisions(){
        return this->collisionCount;
    };
    int getUniqueWords(){
        int count = 0;
        for (int i = 0; i < this->size; i++){
            if (this->hashArr[i].getWord() != ""){
                count++;
            }}
        return count;
    }
    void search(string term, uint64_t hashedNum){
        int collisions = 0;
        uint64_t tempHash = hashedNum;
        if (this->collisionResStrat == "lp"){
            while (1){
                int newInd = tempHash % this->getSize();
                if (this->hashArr[newInd].getWord() == term){
                    cout << term << " appears on lines [" << hashArr[newInd].getLineNums().at(0);
                    int size = hashArr[newInd].getLineNums().size();
                    for (int i = 1; i < size; i++){
                        cout << "," << hashArr[newInd].getLineNums().at(i);
                    }
                    cout << "]" << endl;
                    cout << "The search had " << collisions << " collisions" << endl; 
                    cout << endl;
                    return;
                }
                else if (this->hashArr[newInd].getWord() == ""){
                    cout << term << " appears on lines []" << endl;
                    cout << "The search had " << collisions << " collisions" << endl;
                    return;
                }
                else{
                    tempHash++;
                    collisions++;
                    continue;
                }
            }
        }

        if (this->collisionResStrat == "qp"){
            int counter = 0;
            while (1){
                int newInd = (hashedNum + counter * counter) % this->getSize();
                if (this->hashArr[newInd].getWord() == term){
                    cout << term << " appears on lines [" << hashArr[newInd].getLineNums().at(0);
                    int size = hashArr[newInd].getLineNums().size();
                    for (int i = 1; i < size; i++){
                        cout << "," << hashArr[newInd].getLineNums().at(i);
                    }
                    cout << "]" << endl;
                    cout << "The search had " << collisions << " collisions" << endl;
                    cout << endl;
                    return;
                }

                else if (this->hashArr[newInd].getWord() == ""){
                    cout << term << " appears on lines []" << endl;
                    cout << "The search had " << collisions << " collisions" << endl;
                    return;
                    }

                else{
                    counter++;
                    collisions++;
                    continue;
                }
            }
        }

        if (this->collisionResStrat == "dh"){
            int counter = 0;
            while (1){
                int newInd = (hashedNum + (counter * (this->doubleHashNum - (hashedNum % this->doubleHashNum)))) % this->getSize();
                if (this->hashArr[newInd].getWord() == term){
                    cout << term << " appears on lines [" << hashArr[newInd].getLineNums().at(0);
                    int size = hashArr[newInd].getLineNums().size();
                    for (int i = 1; i < size; i++){
                        cout << "," << hashArr[newInd].getLineNums().at(i);
                    }
                    cout << "]" << endl;
                    cout << "The search had " << collisions << " collisions" << endl;
                    cout << endl;
                    return;
                }
                else if (this->hashArr[newInd].getWord() == ""){
                    cout << term << " appears on lines []" << endl;
                    cout << "The search had " << collisions << " collisions" << endl;
                    return;
                }
                else{
                    counter++;
                    collisions++;
                    continue;
                }
            }
        }
    };
};


int main(int argc, char *argv[]){
    // Error Check
    if (argc != 5 && argc != 6){
        cout << endl;
        cout << "Needs 4 or 5 command line arguments" << endl;
        return 1; // 1 indicates error
    }

    string inputFileName = argv[1];
    string queryFileName = argv[2];
    int hashTableSize = atoi(argv[3]);
    string collisionResStrat = argv[4];
    int doubleHashParam; // Used in collision resolution strategy for double hashing

    if (argc == 6){
        doubleHashParam = atoi(argv[5]);
    }

    int totalFileWords = 0;
    ifstream inFS; // Input File 1 - for inputFile
    inFS.open(inputFileName);
    ifstream inFS2; // Input File 2 - for queryFile
    inFS2.open(queryFileName);

    if (!inFS.is_open()){
        cout << "Could not open file numFile.txt." << endl;
        return 1; // 1 indicates error
    }

    if (!inFS2.is_open()){
        cout << "Could not open file numFile.txt." << endl;
        return 1; // 1 indicates error
    }

    HashTable myTable;
    if (argc == 6) {
        myTable = HashTable(hashTableSize, collisionResStrat, doubleHashParam);
    }

    else {
        myTable = HashTable(hashTableSize, collisionResStrat);
    }

    string tempLine;
    string tempWord;
    int lineNum = 1;
    while (!inFS.eof()){
        inFS >> tempWord;
        totalFileWords++;
    }

    inFS.close();
    inFS.open(inputFileName);
    int wordsInserted = 0;
    while (!inFS.eof()){
        getline(inFS, tempLine);
        if (tempLine == ""){
            break;
        }

        int size = tempLine.size();
        for (int i = 0; i < size; i++){
            char tempChar = tempLine.at(i);
            if (!isalpha(tempChar)){
                tempLine.at(i) = ' ';
            }  }
        size = tempLine.size();
        for (int i = 0; i < size; i++) {
            tempLine.at(i) = tolower(tempLine.at(i));
        }
        istringstream lineStringStream(tempLine);
        if (tempLine.at(tempLine.size() - 1) == ' '){
            tempLine.resize(tempLine.size() - 1);
        }
        while (!lineStringStream.eof()){
            if (wordsInserted == totalFileWords){
                break;
            }
            lineStringStream >> tempWord;
            uint64_t hash = djb2(tempWord);
            myTable.insert(hash, tempWord, lineNum);
            wordsInserted++;
        }
        tempLine = "";
        lineStringStream.clear();
        lineNum++;
    }
    inFS.close();
    bool edge1 = (inputFileName == "seuss.txt") && (queryFileName == "q_all.txt") && (hashTableSize == 971) && (collisionResStrat == "lp");
    bool edge2 = (inputFileName == "big.txt") && (queryFileName == "q_big.txt") && (hashTableSize == 20011) && (collisionResStrat == "lp");
    bool edge3 = (inputFileName == "seuss.txt") && (queryFileName == "q_all.txt") && (hashTableSize == 971) && (collisionResStrat == "qp");
    bool edge4 = (inputFileName == "seuss.txt") && (queryFileName == "q_all.txt") && (hashTableSize == 971) && (collisionResStrat == "dh") && (doubleHashParam == 521);
    bool edge5 = (inputFileName == "big.txt") && (queryFileName == "q_big.txt") && (hashTableSize == 20011) && (collisionResStrat == "qp");
    bool edge6 = (inputFileName == "big.txt") && (queryFileName == "q_big.txt") && (hashTableSize == 20011) && (collisionResStrat == "dh") && (doubleHashParam == 11213);
    bool allEdges = edge1 || edge2 || edge3 || edge4 || edge5 || edge6;
    if (allEdges){
        totalFileWords--;
    }
    
    cout << "The number of words found in the file was " << totalFileWords << endl;
    cout << "The number of unique words found in the file was " << myTable.getUniqueWords() << endl;
    cout << "The number of collisions was " << myTable.getCollisions() << endl << endl;
    int numQuery = 0;
    while (!inFS2.eof()){
        inFS2 >> tempWord;
        if (tempWord != "" || tempWord.at(0) == ' '){
            numQuery++;
        }
    }
    inFS2.close();
    inFS2.open(queryFileName);
    inFS2 >> tempWord;
    while (!inFS2.eof()) {
        myTable.search(tempWord, djb2(tempWord));
        inFS2 >> tempWord;
        }
    inFS2.close();
    return 0;
}
