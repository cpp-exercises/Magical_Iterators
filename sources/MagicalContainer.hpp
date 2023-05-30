#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H

#include <vector>
#include <algorithm>
#include <cstddef>

namespace ariel{

    class MagicalContainer {

    private:
        std::vector<int> elements;
    public:
        MagicalContainer(); // Default constructor
        MagicalContainer(const MagicalContainer& other); // Copy constructor
        ~MagicalContainer(); // Destructor

        std::vector<int>& getElements();
        void setElements(std::vector<int> elements);
        void addElement(int element);
        void removeElement(int element);
        int size() const;


        class AscendingIterator {

        private:
            MagicalContainer& container;
            int index;

        public:

            AscendingIterator(const AscendingIterator& copy_container);
            ~AscendingIterator();

            AscendingIterator(MagicalContainer& container);

            int& operator*() const;
            AscendingIterator& operator++();
            bool operator==(const AscendingIterator& other_iterator) const;
            bool operator!=(const AscendingIterator& other_iterator) const;

            AscendingIterator begin() const;
            AscendingIterator end() const;

        };

        class SideCrossIterator {

        private:
            MagicalContainer& container;
            int index;

        public:

            SideCrossIterator(const SideCrossIterator& other_container);
            ~SideCrossIterator();
            SideCrossIterator(MagicalContainer& container);

            int& operator*() const;
            SideCrossIterator& operator++();
            bool operator==(const SideCrossIterator& other_iterator) const;
            bool operator!=(const SideCrossIterator& other_iterator) const;
            bool operator>(const SideCrossIterator& other_iterator) const;
            bool operator<(const SideCrossIterator& other_iterator) const;

            SideCrossIterator begin() const;
            SideCrossIterator end() const;

        };

        class PrimeIterator  {

        private:

            MagicalContainer& container;
            int index;
            bool isPrime(int n);

        public:

            PrimeIterator(const PrimeIterator& other_container);
            ~PrimeIterator();

            PrimeIterator(MagicalContainer& container);

            int& operator*() const;
            PrimeIterator& operator++();
            bool operator==(const PrimeIterator& other_iterator) const;
            bool operator!=(const PrimeIterator& other_iterator) const;
            bool operator>(const PrimeIterator& other_iterator) const;
            bool operator<(const PrimeIterator& other_iterator) const;

            PrimeIterator begin() const;
            PrimeIterator end() const;

        };
    };//magical

}



#endif // MAGICAL_ITERATORS_MAGICALCONTAINER_H