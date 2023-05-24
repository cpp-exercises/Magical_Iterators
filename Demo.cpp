#include <iostream>
#include "sources/MagicalContainer.h"
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}
