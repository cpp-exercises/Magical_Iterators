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
    }
//    else {
//        throw std::invalid_argument("Element not found in the container.");
//    }
}

int MagicalContainer::size() const {
    return elements.size();
}

