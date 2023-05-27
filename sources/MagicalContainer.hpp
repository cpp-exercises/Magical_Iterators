//
// Created by Renana on 5/25/23.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H
#include <iostream>
#include <vector>
#include <cmath>
/*Create a user-defined container class named "MagicalContainer" that can store integers representing mystical elements.
 * Implement necessary methods for adding elements, removing elements, and retrieving the size of the container.
 * You can use a dynamic array or any other suitable data structure for internal storage.*/
class MagicalContainer {
private:
    std::vector<int> elements;
public:
    MagicalContainer();
    ~MagicalContainer();
    void addElement(int element);
    void removeElement(int element);
    int getSize() const;
};


#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
