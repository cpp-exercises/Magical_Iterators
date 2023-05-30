//
// Created by renana on 5/30/23.
//
#include "doctest.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer PrimeIterator") {

    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    SECTION("Prime numbers") {
        // Use PrimeIterator to iterate over prime numbers only
        MagicalContainer::PrimeIterator primeIter(container);

        std::vector<int> primes = {2, 3, 17};
        int index = 0;
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
            CHECK(*it == primes[index]);
            ++index;
        }
    }

    SECTION("Remove non-prime number") {
    // Remove a non-prime number and check if it's skipped in PrimeIterator
    container.removeElement(9);

    MagicalContainer::PrimeIterator primeIter(container);

    std::vector<int> primes = {2, 3, 17};
    int index = 0;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        CHECK(*it == primes[index]);
        ++index;
        }
    }

    SECTION("Empty container") {
        // Create an empty container and check if PrimeIterator handles it correctly
        MagicalContainer emptyContainer;

        MagicalContainer::PrimeIterator primeIter(emptyContainer);
        CHECK(primeIter.begin() == primeIter.end());
    }
}

TEST_CASE("MagicalContainer AscendingIterator") {

    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    SECTION("Ascending order") {
    // Use AscendingIterator to iterate over elements in ascending order
    MagicalContainer::AscendingIterator ascIter(container);

    std::vector<int> ascending = {2, 3, 9, 17, 25};
    int index = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        CHECK(*it == ascending[index]);
        ++index;
    }
}

SECTION("Remove element in ascending order") {
    // Remove an element and check if it's skipped in AscendingIterator
    container.removeElement(9);

    MagicalContainer::AscendingIterator ascIter(container);

    std::vector<int> ascending = {2, 3, 17, 25};
    int index = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        CHECK(*it == ascending[index]);
        ++index;
    }
}

}

TEST_CASE("MagicalContainer SideCrossIterator") {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    SECTION("Side-cross order") {
        // Use SideCrossIterator to iterate over elements in a side-cross pattern
        MagicalContainer::SideCrossIterator sideCrossIter(container);

        std::vector<int> sideCross = {17, 3, 2, 9, 25};
        int index = 0;
        for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
            CHECK(*it == sideCross[index]);
            ++index;
        }
    }

    SECTION("Remove element in side-cross order") {
        // Remove an element and check if it's skipped in SideCrossIterator
        container.removeElement(2);

        MagicalContainer::SideCrossIterator sideCrossIter(container);

        std::vector<int> sideCross = {17, 3, 9, 25};
        int index = 0;
        for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
            CHECK(*it == sideCross[index]);
            ++index;
        }
    }
}
