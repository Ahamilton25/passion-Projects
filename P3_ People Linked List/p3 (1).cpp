#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Person::Person()
{
    this->height = 0;
    this->weight = 0;
    this->nextHeight = nullptr;
    this->nextWeight = nullptr;
}

Person::Person(string first, string last, int height, int weight)
{
    this->first = first;
    this->last = last;
    this->height = height;
    this->weight = weight;
    this->nextHeight = nullptr;
    this->nextWeight = nullptr;
}

PersonList::PersonList()
{
    this->size = 0;
    this->headHeightList = nullptr;
    this->headWeightList = nullptr;
}

int PersonList::getSize()
{
    return size;
}

void PersonList::printByHeight(ostream &os)
{
    Person *currNode = headHeightList;

    // Check if all heights are the same
    bool sameHeight = true;
    while (currNode != nullptr && sameHeight)
    {
        if (currNode->nextHeight != nullptr && currNode->height != currNode->nextHeight->height)
        {
            sameHeight = false;
        }
        currNode = currNode->nextHeight;
    }

    // If all heights are the same, print in descending weight order
    if (sameHeight)
    {
        currNode = headWeightList;
        while (currNode != nullptr)
        {
            os << currNode->first << ' ' << currNode->last << ": height=" << currNode->height << ", weight=" << currNode->weight << endl;
            currNode = currNode->nextWeight;
        }
    }
    else
    {
        // Print in descending height order
        currNode = headHeightList;
        while (currNode != nullptr)
        {
            os << currNode->first << ' ' << currNode->last << ": height=" << currNode->height << ", weight=" << currNode->weight << endl;
            currNode = currNode->nextHeight;
        }
    }
}

void PersonList::printByWeight(ostream &os)
{
    Person *currNode = headWeightList;
    Person *nextNode = nullptr;

    // Check if all weights are the same
    bool sameWeight = true;
    while (currNode != nullptr && sameWeight)
    {
        nextNode = currNode->nextWeight;
        if (nextNode != nullptr && currNode->weight != nextNode->weight)
        {
            sameWeight = false;
        }
        currNode = nextNode;
    }

    // Print in the appropriate order
    if (sameWeight)
    {
        currNode = headWeightList;
        while (currNode != nullptr)
        {
            os << currNode->first << ' ' << currNode->last << ": height=" << currNode->height << ", weight=" << currNode->weight << endl;
            currNode = currNode->nextWeight;
        }
    }
    else
    {
        currNode = headWeightList;
        while (currNode != nullptr)
        {
            os << currNode->first << ' ' << currNode->last << ": height=" << currNode->height << ", weight=" << currNode->weight << endl;
            currNode = currNode->nextWeight;
        }
    }
}


bool PersonList::exists(string first, string last)
{
    Person *currNode = headHeightList;
    while (currNode != nullptr)
    {
        if (currNode->first == first && currNode->last == last)
        {
            return true;
        }
        currNode = currNode->nextHeight;
    }
    return false;
}

int PersonList::getHeight(string first, string last)
{
    Person *currNode = headHeightList;
    while (currNode != nullptr)
    {
        if (currNode->first == first && currNode->last == last)
        {
            return currNode->height;
        }
        currNode = currNode->nextHeight;
    }
    return -1;
}

int PersonList::getWeight(string first, string last)
{
    Person *currNode = headWeightList;
    while (currNode != nullptr)
    {
        if (currNode->first == first && currNode->last == last)
        {
            return currNode->weight;
        }
        currNode = currNode->nextWeight;
    }
    return -1;
}

bool PersonList::add(string first, string last, int height, int weight)
{
    if (this->exists(first, last))
    {
        return false;
    }

    Person *p = new Person(first, last, height, weight);

    if (size == 0)
    {
        this->headHeightList = p;
        this->headWeightList = p;
    }
    else
    {
        // Insert by height
        if (height >= this->headHeightList->height)
        {
            p->nextHeight = this->headHeightList;
            this->headHeightList = p;
        }
        else
        {
            Person *current = this->headHeightList;
            while (current->nextHeight != nullptr && height < current->nextHeight->height)
            {
                current = current->nextHeight;
            }
            p->nextHeight = current->nextHeight;
            current->nextHeight = p;
        }

        // Insert by weight
        if (weight <= this->headWeightList->weight)
        {
            p->nextWeight = this->headWeightList;
            this->headWeightList = p;
        }
        else
        {
            Person *current = this->headWeightList;
            while (current->nextWeight != nullptr && weight > current->nextWeight->weight)
            {
                current = current->nextWeight;
            }
            p->nextWeight = current->nextWeight;
            current->nextWeight = p;
        }
    }

    size++;
    return true;
}

bool PersonList::remove(string first, string last)
{
    if (!exists(first, last))
    {
        return false;
    }
    Person *currNode = headWeightList;
    Person *prevNode = nullptr;
    while (currNode != nullptr)
    {
        if (currNode->first == first && currNode->last == last)
        {
            if (prevNode == nullptr)
            {
                headWeightList = currNode->nextWeight;
            }
            else
            {
                prevNode->nextWeight = currNode->nextWeight;
            }
            break;
        }
        prevNode = currNode;
        currNode = currNode->nextWeight;
    }

    currNode = headHeightList;
    prevNode = nullptr;
    while (currNode != nullptr)
    {
        if (currNode->first == first && currNode->last == last)
        {
            if (prevNode == nullptr)
            {
                headHeightList = currNode->nextHeight;
            }
            else
            {
                prevNode->nextHeight = currNode->nextHeight;
            }
            break;
        }
        prevNode = currNode;
        currNode = currNode->nextHeight;
    }
    size--;
    return true;
}

bool PersonList::updateName(string first, string last, string newFirst, string newLast)
{
    if (!exists(first, last))
    {
        return false;
    }
    Person *currNode = headWeightList;
    while (currNode != nullptr)
    {
        if (currNode->last == last && currNode->first == first)
        {
            currNode->last = newLast;
            currNode->first = newFirst;
            return true;
        }
        currNode = currNode->nextWeight;
    }
    return false;
}

bool PersonList::updateHeight(string first, string last, int height)
{
    if (!exists(first, last))
    {
        return false;
    }
    int tempStoreWeight = getWeight(first, last);

    remove(first, last);

    add(first, last, height, tempStoreWeight);

    return true;
}

bool PersonList::updateWeight(string first, string last, int weight)
{
    if (!exists(first, last))
    {
        return false;
    }
    int tempStoreHeight = getHeight(first, last);

    remove(first, last);

    add(first, last, tempStoreHeight, weight);

    return true;
}

PersonList::~PersonList()
{
    Person *currNode = headHeightList;
    while (currNode != nullptr)
    {
        Person *next = currNode->nextHeight;
        delete currNode;
        currNode = next;
    }
    size = 0;
}

PersonList::PersonList(const PersonList &src)
{
    this->size = 0;
    this->headHeightList = nullptr;
    this->headWeightList = nullptr;
    
    Person *currNode = src.headWeightList;
    while (currNode != nullptr)
    {
        add(currNode->first, currNode->last, currNode->height, currNode->weight);
        currNode = currNode->nextWeight;
    }
}

const PersonList &PersonList::operator=(const PersonList &src)
{
    if (this != &src)
    {
        this->~PersonList();
       
        this->size = 0;
        this->headHeightList = nullptr;
        this->headWeightList = nullptr;

        Person *currNode = src.headWeightList;
        while (currNode != nullptr)
        {
            add(currNode->first, currNode->last, currNode->height, currNode->weight);
            currNode = currNode->nextWeight;
        }
    }
    return *this;
}
