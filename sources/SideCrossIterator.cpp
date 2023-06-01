//
// Created by renana on 6/1/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


// Move constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &&other) noexcept : container(other.getContainer()), index(other.getCurrentIndex()) {
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other){
    return *this;
}

// Move assignment operator
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {
return *this;
}
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

MagicalContainer& MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}

int MagicalContainer::SideCrossIterator::getCurrentIndex() const {
    return index;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator it(container);
    it.index = container.size();
    return it;
}
