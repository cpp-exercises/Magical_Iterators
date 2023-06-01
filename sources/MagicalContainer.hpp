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
            AscendingIterator() = delete;
            ~AscendingIterator();

            AscendingIterator(MagicalContainer& container);

            int& operator*() const;
            AscendingIterator& operator++();
            bool operator==(const AscendingIterator& other_iterator) const;
            bool operator!=(const AscendingIterator& other_iterator) const;
            // Assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);

            // Move assignment operator
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
            AscendingIterator begin() const;
            AscendingIterator end() const;
            int getCurrentIndex() const;

            MagicalContainer& getContainer() const;
        };

        class SideCrossIterator {

        private:
            MagicalContainer& container;
            int index;

        public:

            SideCrossIterator(const SideCrossIterator& other_container);
            SideCrossIterator(const SideCrossIterator&& other_container) noexcept;
            SideCrossIterator() =delete;
            ~SideCrossIterator();
            SideCrossIterator(MagicalContainer& container);

            int& operator*() const;
            SideCrossIterator& operator++();
            bool operator==(const SideCrossIterator& other_iterator) const;
            bool operator!=(const SideCrossIterator& other_iterator) const;
            bool operator>(const SideCrossIterator& other_iterator) const;
            bool operator<(const SideCrossIterator& other_iterator) const;
            // Assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);

            // Move assignment operator
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
            MagicalContainer& getContainer() const;
            int getCurrentIndex() const;


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
            PrimeIterator(PrimeIterator &&other) noexcept;
            int operator*() const;
            PrimeIterator& operator++();
            bool operator==(const PrimeIterator& other_iterator) const;
            bool operator!=(const PrimeIterator& other_iterator) const;
            bool operator>(const PrimeIterator& other_iterator) const;
            bool operator<(const PrimeIterator& other_iterator) const;
            // Assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);
            MagicalContainer& getContainer() const;
            int getCurrentIndex() const;


            // Move assignment operator
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
            PrimeIterator begin() const;
            PrimeIterator end() const;

        };
    };//magical

}



#endif // MAGICAL_ITERATORS_MAGICALCONTAINER_H