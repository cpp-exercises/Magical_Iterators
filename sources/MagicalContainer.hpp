#include "MagicalContainer.hpp"

using namespace std;
namespace ariel{

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

    vector<int> &MagicalContainer::getElements() {
        return this->elements;
    }

    void MagicalContainer::setElements(vector<int> elements) {
        this->elements = elements;
    }


    // AscendingIterator Implementation:

    AscendingIterator::AscendingIterator(const MagicalContainer &my_container, int idx)
            : container(my_container), index(idx) {}

    AscendingIterator::AscendingIterator()
            : container(MagicalContainer()), index(0) {}

    AscendingIterator::AscendingIterator(const AscendingIterator &other)
            : container(other.container), index(other.index) {}

    AscendingIterator::~AscendingIterator() {}

    AscendingIterator &AscendingIterator::operator=(const AscendingIterator &other) {
        return *this;
    }

    bool AscendingIterator::operator==(const AscendingIterator &other) const {
        return false;
    }

    bool AscendingIterator::operator!=(const AscendingIterator &other) const {
        return false;
    }

    int AscendingIterator::operator*() const {
        return container.getElements()[index];
    }

    AscendingIterator &AscendingIterator::operator++() {
        ++index;
        return *this;
    }

    bool AscendingIterator::operator>(const AscendingIterator &other) const {
        return false;
    }

    bool AscendingIterator::operator<(const AscendingIterator &other) const {
        return false;
    }

    AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(container, 0);
    }

    AscendingIterator MagicalContainer::AscendingIterator::end() {
        return AscendingIterator(container, container.size());
    }


    // SideCrossIterator Implementation:

    SideCrossIterator::SideCrossIterator(const MagicalContainer &cont, int frontIdx, int backIdx, bool moveF)
            : container(cont), frontIndex(frontIdx), backIndex(backIdx), moveFront(moveF) {}

    SideCrossIterator::SideCrossIterator()
            : container(MagicalContainer()), frontIndex(0), backIndex(0), moveFront(true) {}

    SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
            : container(other.container), frontIndex(other.frontIndex), backIndex(other.backIndex), moveFront(other.moveFront) {}

    SideCrossIterator::~SideCrossIterator() {}

    SideCrossIterator &SideCrossIterator::operator=(const SideCrossIterator &other) {
        return *this;
    }

    bool SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return false;
    }

    bool SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return false;
    }

    int SideCrossIterator::operator*() const {
        return container.getElements()[moveFront ? frontIndex : backIndex];
    }

    SideCrossIterator &SideCrossIterator::operator++() {
        if (moveFront) {
            ++frontIndex;
        } else {
            --backIndex;
        }
        return *this;
    }

    bool SideCrossIterator::operator>(const SideCrossIterator &other) const {
        return false;
    }

    bool SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return false;
    }

    SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(container, 0, container.size() - 1, true);
    }

    SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        return SideCrossIterator(container, 0, container.size() - 1, false);
    }
}