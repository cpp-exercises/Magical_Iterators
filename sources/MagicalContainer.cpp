#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// MagicalContainer implementation

MagicalContainer::MagicalContainer() = default; // Default constructor

MagicalContainer::MagicalContainer(const MagicalContainer& other) = default; // Copy constructor

MagicalContainer::~MagicalContainer() = default; // Destructor

std::vector<int>& MagicalContainer::getElements() {
    return elements;
}

void MagicalContainer::setElements(std::vector<int> elements) {
    this->elements = std::move(elements);
}

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end()) {
        elements.erase(it);
    } else {
        throw std::invalid_argument("Element not found in the container.");
    }
}

int MagicalContainer::size() const {
    return elements.size();
}

// AscendingIterator implementation

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& copy_container)
        : container(copy_container.container), index(copy_container.index) {}

MagicalContainer::AscendingIterator::~AscendingIterator() = default; // Destructor

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : container(container), index(0) {
    std::vector<int> sortedElements = container.getElements();
    std::sort(sortedElements.begin(), sortedElements.end());
    container.setElements(sortedElements);
}

int& MagicalContainer::AscendingIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other_iterator) const {
    return index == other_iterator.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other_iterator) const {
    return index != other_iterator.index;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator it(container);
    it.index = container.size();
    return it;
}

// SideCrossIterator implementation

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other_container)
        : container(other_container.container), index(other_container.index) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default; // Destructor

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : container(container), index(0) {
    std::vector<int> sortedElements = container.getElements();
    std::sort(sortedElements.begin(), sortedElements.end());

    std::vector<int> crossElements(sortedElements.size());
    size_t start = 0;
    size_t end = sortedElements.size() - 1;
    for (size_t i = 0; i < crossElements.size(); i += 2) {
        crossElements[i] = sortedElements[start];
        crossElements[i + 1] = sortedElements[end];
        start++;
        end--;
    }

    container.setElements(crossElements);
}

int& MagicalContainer::SideCrossIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    ++index;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return index > other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return index < other.index;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator it(container);
    it.index = container.size();
    return it;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other_container)
        : container(other_container.container), index(other_container.index) {}

MagicalContainer::PrimeIterator::~PrimeIterator() = default; // Destructor

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

int& MagicalContainer::PrimeIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++index;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other_iterator) const {
    return index == other_iterator.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other_iterator) const {
    return index != other_iterator.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other_iterator) const {
    return index > other_iterator.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other_iterator) const {
    return index < other_iterator.index;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return PrimeIterator(container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    PrimeIterator it(container);
    it.index = container.size();
    return it;
}