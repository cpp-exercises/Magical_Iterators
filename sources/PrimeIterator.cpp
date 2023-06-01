//
// Created by renana on 6/1/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// Constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : container(container), index(0) {
    std::vector<int> primeElements;
    for (const int& element : container.getElements()) {
        if (isPrime(element)) {
            primeElements.push_back(element);
        }
    }
    container.setElements(primeElements);
}

// Copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : container(other.container), index(other.index) {}

// Destructor
MagicalContainer::PrimeIterator::~PrimeIterator() = default;

// Dereference operator
int& MagicalContainer::PrimeIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

// Pre-increment operator
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++index;
    return *this;
}

// Equality operator
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other_iterator) const {
    return index == other_iterator.index;
}

// Inequality operator
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other_iterator) const {
    return index != other_iterator.index;
}

// Greater than operator
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other_iterator) const {
    return index > other_iterator.index;
}

// Less than operator
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other_iterator) const {
    return index < other_iterator.index;
}

// Begin function
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return PrimeIterator(container);
}

// End function
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    PrimeIterator it(container);
    it.index = container.size();
    return it;
}

// Check if a number is prime
bool MagicalContainer::PrimeIterator::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
