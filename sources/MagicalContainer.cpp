//
// Created by Renana on 5/25/23.
//

#include "MagicalContainer.hpp"
using namespace std

namespace ariel{

    // MagicalContainer Implementation:

    MagicalContainer::MagicalContainer(){}
    MagicalContainer::~MagicalContainer(){}

    void MagicalContainer::addElement(int element){
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element){
        for (auto my_element = elements.begin(); my_element != elements.end(); ++my_element) {
            if (*my_element == element) {
                elements.erase(my_element);
                break;
            }
        }
    }

    int MagicalContainer::getSize() const{
        return elements.size();
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
//        if (this != &other) {
//            container = other.container;
//            index = other.index;
//        }
//        return *this;
            return *this;
    }

    bool AscendingIterator::operator==(const AscendingIterator& other) const {
//        return (&container == &other.container) && (index == other.index);
        return false;
    }

    bool AscendingIterator::operator!=(const AscendingIterator& other) const {
//        return !(*this == other);
        return false;
    }

    int AscendingIterator::operator*() const {
        return container.elements[index];
    }

    AscendingIterator& AscendingIterator::operator++() {
//        ++index;
//        return *this;
            retuen  *this;
    }

    bool AscendingIterator::operator>(const AscendingIterator& other) const {
//        return index > other.index;
            return false;
    }

    bool AscendingIterator::operator<(const AscendingIterator& other) const {
//        return index < other.index;
        return false;
    }

    AscendingIterator* AscendingIterator::begin() {
    }

    AscendingIterator* AscendingIterator::end() {
    }

    // SideCrossIterator Implementation

    SideCrossIterator::SideCrossIterator(const MagicalContainer& cont, int frontIdx, int backIdx, bool moveF)
            : container(cont), frontIndex(frontIdx), backIndex(backIdx), moveFront(moveF) {}

    SideCrossIterator::SideCrossIterator()
            : container(MagicalContainer()), frontIndex(0), backIndex(0), moveFront(true) {}

    SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
            : container(other.container), frontIndex(other.frontIndex), backIndex(other.backIndex), moveFront(other.moveFront) {}

    SideCrossIterator::~SideCrossIterator() {}

    SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other) {
//        if (this != &other) {
//            container = other.container;
//            frontIndex = other.frontIndex;
//            backIndex = other.backIndex;
//            moveFront = other.moveFront;
//        }
//        return *this;

        return *this;
    }

    bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
//        return (&container == &other.container) && (frontIndex == other.frontIndex) && (backIndex == other.backIndex) && (moveFront == other.moveFront);
        return false;
    }

    bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
//        return !(*this == other);
        return false;

    }

    int SideCrossIterator::operator*() const {

    }

    SideCrossIterator& SideCrossIterator::operator++() {
        return *this;
    }

    bool SideCrossIterator::operator>(const SideCrossIterator& other) const {
//        return frontIndex > other.frontIndex;
        return false;

    }

    bool SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return false;
    }

    SideCrossIterator* SideCrossIterator::begin() {
    }

    SideCrossIterator* SideCrossIterator::end() {
    }

    // PrimeIterator Implementation

    PrimeIterator::PrimeIterator(const MagicalContainer& cont, int idx)
            : container(cont), currentIndex(idx) {}

    PrimeIterator::PrimeIterator()
            : container(MagicalContainer()), currentIndex(0) {}

    PrimeIterator::PrimeIterator(const PrimeIterator& other)
            : container(other.container), currentIndex(other.currentIndex) {}

    PrimeIterator::~PrimeIterator() {}

    PrimeIterator& PrimeIterator::operator=(const PrimeIterator& other) {
//        if (this != &other) {
//            container = other.container;
//            currentIndex = other.currentIndex;
//        }
//        return *this;
                return *this;
    }

    bool PrimeIterator::operator==(const PrimeIterator& other) const {
//        return (&container == &other.container) && (currentIndex == other.currentIndex);
        return false;
    }

    bool PrimeIterator::operator!=(const PrimeIterator& other) const {
//        return !(*this == other);
        return false;

    }

    int PrimeIterator::operator*() const {
//        return container.elements[currentIndex];
        return false;
    }

    PrimeIterator& PrimeIterator::operator++() {
        return *this;
    }

    bool PrimeIterator::operator>(const PrimeIterator& other) const {
//        return currentIndex > other.currentIndex;
        return false;
    }

    bool PrimeIterator::operator<(const PrimeIterator& other) const {
//        return currentIndex < other.currentIndex;
        return false;
    }

    PrimeIterator* PrimeIterator::begin() {
    }

    PrimeIterator* PrimeIterator::end() {
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

}// namespace ariel