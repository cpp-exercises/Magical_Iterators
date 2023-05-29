#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

    // MagicalContainer Implementation:

    MagicalContainer::MagicalContainer() {}
    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        for (auto my_element = elements.begin(); my_element != elements.end(); ++my_element) {
            if (*my_element == element) {
                elements.erase(my_element);
                break;
            }
        }
    }

    int MagicalContainer::size() const {
        return elements.size();
    }

    std::vector<int>& MagicalContainer::getElements() {
        return this->elements;
    }

    void MagicalContainer::setElements(std::vector<int> elements) {
        this->elements = elements;
    }

    std::ostream& operator<<(std::ostream& os, const AscendingIterator& it) {
        os << *it; // Output the value pointed by the iterator
        return os;
    }


    // AscendingIterator Implementation:
    AscendingIterator::AscendingIterator(const MagicalContainer& my_container, int idx)
            : container(my_container), index(idx) {}

    AscendingIterator::AscendingIterator()
        : container(MagicalContainer()), index(0) {}

    AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : container(other.container), index(other.index) {}


AscendingIterator::~AscendingIterator() {}

    AscendingIterator& AscendingIterator::operator=(const AscendingIterator& other) {
        return *this;
    }

    bool AscendingIterator::operator==(const AscendingIterator& other) const {
        return false;
    }

    bool AscendingIterator::operator!=(const AscendingIterator& other) const {
        return false;
    }

    int AscendingIterator::operator*() const {
        return container.elements[index];
    }

    AscendingIterator& AscendingIterator::operator++() {
        return *this;
    }

    bool AscendingIterator::operator>(const AscendingIterator& other) const {
        return false;
    }

    bool AscendingIterator::operator<(const AscendingIterator& other) const {
        return false;
    }

    AscendingIterator AscendingIterator::begin() const{
        return nullptr;
    }

    AscendingIterator AscendingIterator::end() const{
        return nullptr;
    }

    // SideCrossIterator Implementation

    SideCrossIterator::SideCrossIterator(const MagicalContainer &cont, int index)
            : container(cont), index(index){}

    SideCrossIterator::SideCrossIterator()
            : container(MagicalContainer()), index(0) {}

    SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
            : container(other.container), index(other.index) {}

    SideCrossIterator::~SideCrossIterator() {}

    SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other) {
        return *this;
    }

    bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return false;
    }

    bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return false;
    }

    int SideCrossIterator::operator*() const {
        return 0;
    }

    SideCrossIterator& SideCrossIterator::operator++() {
        return *this;
    }

    bool SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return false;
    }

    bool SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return false;
    }

    SideCrossIterator SideCrossIterator::begin() const{
        return nullptr;
    }

    SideCrossIterator SideCrossIterator::end() const{
        return nullptr;
    }

    // PrimeIterator Implementation

    PrimeIterator::PrimeIterator(const MagicalContainer &cont, int idx)
            : container(cont), currentIndex(idx) {}

    PrimeIterator::PrimeIterator()
            : container(MagicalContainer()), currentIndex(0) {}

    PrimeIterator::PrimeIterator(const PrimeIterator &other)
            : container(other.container), currentIndex(other.currentIndex) {}

    PrimeIterator::~PrimeIterator() {}

    PrimeIterator& PrimeIterator::operator=(const PrimeIterator& other) {
        return *this;
    }

    bool PrimeIterator::operator==(const PrimeIterator& other) const {
        return false;
    }

    bool PrimeIterator::operator!=(const PrimeIterator& other) const {
        return false;
    }

    int PrimeIterator::operator*() const {
        return false;
    }

    PrimeIterator& PrimeIterator::operator++() {
        return *this;
    }

    bool PrimeIterator::operator>(const PrimeIterator& other) const {
        return false;
    }

    bool PrimeIterator::operator<(const PrimeIterator& other) const {
        return false;
    }

    PrimeIterator PrimeIterator::begin() const{
        return nullptr;
    }

    PrimeIterator PrimeIterator::end() const{
        return nullptr;
    }

    bool PrimeIterator::isPrime(int num) const {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

