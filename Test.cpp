//
// Created by renana on 5/30/23.
//
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;

TEST_SUITE("MagicalContainer PrimeIterator") {

MagicalContainer container;
container.addElement(17);
container.addElement(2);
container.addElement(25);
container.addElement(9);
container.addElement(3);

TEST_CASE("Prime numbers") {
MagicalContainer::PrimeIterator primeIter(container);

std::vector<int> primes = {2, 3, 17};
std::vector<int>::size_type index = 0;
for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
CHECK(*it == primes[index]);
++index;
}
}

TEST_CASE("Remove non-prime number") {
container.removeElement(9);

MagicalContainer::PrimeIterator primeIter(container);

std::vector<int> primes = {2, 3, 17};
std::vector<int>::size_type index = 0;
for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
CHECK(*it == primes[index]);
++index;
}
}

TEST_CASE("Empty container") {
MagicalContainer emptyContainer;

MagicalContainer::PrimeIterator primeIter(emptyContainer);
CHECK(primeIter.begin() == primeIter.end());
}
}

TEST_SUITE("MagicalContainer AscendingIterator") {

MagicalContainer container;
container.addElement(17);
container.addElement(2);
container.addElement(25);
container.addElement(9);
container.addElement(3);

TEST_CASE("Ascending order") {
MagicalContainer::AscendingIterator ascIter(container);

std::vector<int> ascending = {2, 3, 9, 17, 25};
std::vector<int>::size_type index = 0;
for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
CHECK(*it == ascending[index]);
++index;
}
}

TEST_CASE("Remove element in ascending order") {
container.removeElement(9);

MagicalContainer::AscendingIterator ascIter(container);

std::vector<int> ascending = {2, 3, 17, 25};
std::vector<int>::size_type index = 0;
for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
CHECK(*it == ascending[index]);
++index;
}
}

}

TEST_SUITE("MagicalContainer SideCrossIterator") {

MagicalContainer container;
container.addElement(17);
container.addElement(2);
container.addElement(25);
container.addElement(9);
container.addElement(3);

TEST_CASE("Side-cross order") {
MagicalContainer::SideCrossIterator sideCrossIter(container);

std::vector<int> sideCross = {17, 3, 2, 9, 25};
std::vector<int>::size_type index = 0;
for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
CHECK(*it == sideCross[index]);
++index;
}
}

TEST_CASE("Remove element in side-cross order") {
container.removeElement(2);

MagicalContainer::SideCrossIterator sideCrossIter(container);

std::vector<int> sideCross = {17, 3, 9, 25};
std::vector<int>::size_type index = 0;
for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
CHECK(*it == sideCross[index]);
++index;
}
}

}
