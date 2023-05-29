//
// Created by Renana on 5/25/23.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H

#include <iostream>
#include <vector>
#include <cmath>
/*Create a user-defined container class named "MagicalContainer" that can store integers representing mystical elements.
 * Implement necessary methods for adding elements, removing elements, and retrieving the size of the container.
 * You can use a dynamic array or any other suitable data structure for internal storage.*/
class MagicalContainer {
private:
    std::vector<int> elements;
public:
    MagicalContainer();
    ~MagicalContainer();
    void addElement(int element);
    void removeElement(int element);
    int getSize() const;
};

class AscendingIterator {
private:
    const MagicalContainer& container;
    int index;

public:
    AscendingIterator(const MagicalContainer& my_container, int idx);
    AscendingIterator(); //Default constructor
    AscendingIterator(const AscendingIterator& other); //Copy constructor
    ~AscendingIterator(); //Destructor

    AscendingIterator& operator=(const AscendingIterator& other); // Assignment operator
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    int operator*() const;
    AscendingIterator& operator++();
    bool operator>(const AscendingIterator& other) const;
    bool operator<(const AscendingIterator& other) const;

    AscendingIterator *begin(); //TODO: check if like this
    AscendingIterator *end();
};

class SideCrossIterator {
private:
    const MagicalContainer& container;
    int frontIndex;
    int backIndex;
    bool moveFront;

public:
    SideCrossIterator(const MagicalContainer& cont, int frontIdx, int backIdx, bool moveF);
    SideCrossIterator();
    SideCrossIterator(const SideCrossIterator& other);
    ~SideCrossIterator();

    SideCrossIterator& operator=(const SideCrossIterator& other);
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    int operator*() const;
    SideCrossIterator& operator++();
    bool operator>(const SideCrossIterator& other) const;
    bool operator<(const SideCrossIterator& other) const;

    SideCrossIterator *begin();
    SideCrossIterator *end();
};

class PrimeIterator {
private:
    const MagicalContainer& container;
    int currentIndex;

    bool isPrime(int num) const;

public:
    PrimeIterator(const MagicalContainer& cont, int idx);
    PrimeIterator();
    PrimeIterator(const PrimeIterator& other);
    ~PrimeIterator();

    PrimeIterator& operator=(const PrimeIterator& other);
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    int operator*() const;
    PrimeIterator& operator++();
    bool operator>(const PrimeIterator& other) const;
    bool operator<(const PrimeIterator& other) const;

    PrimeIterator *begin();
    PrimeIterator *end();
};

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
