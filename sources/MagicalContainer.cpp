//
// Created by Renana on 5/25/23.
//

#include "MagicalContainer.hpp"
using namespace std

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