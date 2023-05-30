#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H

#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;
        bool isPrime(int n);
    public:
        void addElement(int elem);
        void removeElement(int elem);
        std::vector<int> getElements();
        int size() const;

        class AscendingIterator {
        private:
            MagicalContainer* container;
            int index;

        public:
            AscendingIterator begin() const;
            AscendingIterator end() const;
            AscendingIterator();
            AscendingIterator(MagicalContainer* container, int index);
            AscendingIterator(MagicalContainer* container);
            AscendingIterator& operator++();
            bool operator==(const AscendingIterator& it) const;
            bool operator!=(const AscendingIterator& it) const;
            bool operator>(const AscendingIterator& it) const;
            bool operator<(const AscendingIterator& it) const;
            AscendingIterator& operator<<(int count);
            AscendingIterator& operator>>(int count);
            int operator*() const;
        };

        class SideCrossIterator {
        private:
            MagicalContainer* container;
            int index;

        public:
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
            SideCrossIterator();
            SideCrossIterator(MagicalContainer* container, int index);
            SideCrossIterator(MagicalContainer* container);
            SideCrossIterator& operator++();
            bool operator==(const SideCrossIterator& it) const;
            bool operator!=(const SideCrossIterator& it) const;
            bool operator>(const SideCrossIterator& it) const;
            bool operator<(const SideCrossIterator& it) const;
            SideCrossIterator& operator<<(int count);
            SideCrossIterator& operator>>(int count);
            int operator*() const;
        };

        class PrimeIterator {
        private:
            MagicalContainer* container;
            int index;

        public:
            PrimeIterator begin() const;
            PrimeIterator end() const;
            PrimeIterator();
            PrimeIterator(MagicalContainer* container, int index);
            PrimeIterator(MagicalContainer* container);
            PrimeIterator& operator++();
            bool operator==(const PrimeIterator& it) const;
            bool operator!=(const PrimeIterator& it) const;
            bool operator>(const PrimeIterator& it) const;
            bool operator<(const PrimeIterator& it) const;
            PrimeIterator& operator<<(int count);
            PrimeIterator& operator>>(int count);
            int operator*() const;
        };
    };
} // namespace ariel

#endif // MAGICAL_ITERATORS_MAGICALCONTAINER_H
