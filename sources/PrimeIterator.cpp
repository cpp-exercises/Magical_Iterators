#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other_container)
        : container(other_container.container), index(other_container.index) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : container(container), index(0) {
    // Skip non-prime elements
//    while (index < container.size() && !isPrime(container.getElements()[index])) {
//        ++index;
//    }
}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator&& other) noexcept
: container(other.container), index(other.index) {}

int MagicalContainer::PrimeIterator::operator*() const {
    return 0;
}

ariel::MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    // Move to the next prime element
//    do {
//        ++index;
//    } while (index < container.size() && !isPrime(container.getElements()[index]));
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other_iterator) const {
//    return index == other_iterator.index;
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other_iterator) const {
//    return index != other_iterator.index;
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other_iterator) const {
//    return index > other_iterator.index;
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other_iterator) const {
//    return index < other_iterator.index;
    return false;
}

ariel::MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
//    if (this != &other) {
//        container = other.container;
//        index = other.index;
//    }
    return *this;
}

MagicalContainer& MagicalContainer::PrimeIterator::getContainer() const {
    return container;
}

int MagicalContainer::PrimeIterator::getCurrentIndex() const {
    return 1;
}

ariel::MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(PrimeIterator&& other) noexcept {
//    if (this != &other) {
//    container = std::move(other.container);
//    index = other.index;
//    }
    return *this;
}

ariel::MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
//    PrimeIterator iter(container);
//    return iter;
    return *this;

}

ariel::MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
//    PrimeIterator iter(container);
//    iter.index = container.size();
//    return iter;
    return *this;
}

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
