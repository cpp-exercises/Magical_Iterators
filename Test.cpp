#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;


TEST_SUITE("MagicalContainer PrimeIterator") {
    TEST_CASE("Prime numbers") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        MagicalContainer::PrimeIterator primeIter(container);

        std::vector<int> primes = {2, 3, 17};
        std::vector<int>::size_type index = 0;
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
            CHECK(*it == primes[index]);
            ++index;
        }
    }

    TEST_CASE("Remove non-prime number") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        container.removeElement(9);

        MagicalContainer::PrimeIterator primeIter(container);

        std::vector<int> primes = {2, 3, 17};
        std::vector<int>::size_type index = 0;
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
            CHECK(*it == primes[index]);
            ++index;
        }
    }

    TEST_CASE("Empty container") {
        MagicalContainer emptyContainer;

        MagicalContainer::PrimeIterator primeIter(emptyContainer);
        CHECK(primeIter.begin() == primeIter.end());
    }
}

TEST_SUITE("MagicalContainer AscendingIterator") {
    TEST_CASE("Ascending order") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        MagicalContainer::AscendingIterator ascIter(container);

        std::vector<int> ascending = {2, 3, 9, 17, 25};
        std::vector<int>::size_type index = 0;
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
            CHECK(*it == ascending[index]);
            ++index;
        }
    }

    TEST_CASE("Remove element in ascending order") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        container.removeElement(9);

        MagicalContainer::AscendingIterator ascIter(container);

        std::vector<int> ascending = {2, 3, 17, 25};
        std::vector<int>::size_type index = 0;
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
            CHECK(*it == ascending[index]);
            ++index;
        }
    }
}

TEST_SUITE("MagicalContainer SideCrossIterator") {
    TEST_CASE("Side-cross order") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        MagicalContainer::SideCrossIterator sideCrossIter(container);

        std::vector<int> sideCross = {17, 3, 2, 9, 25};
        std::vector<int>::size_type index = 0;
        for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
            CHECK(*it == sideCross[index]);
            ++index;
        }
    }

    TEST_CASE("Remove element in side-cross order") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        container.removeElement(2);

        MagicalContainer::SideCrossIterator sideCrossIter(container);

        std::vector<int> sideCross = {17, 3, 9, 25};
        std::vector<int>::size_type index = 0;
        for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
            CHECK(*it == sideCross[index]);
            ++index;
        }
    }
}

TEST_SUITE("Adding and Removing Elements Simultaneously") {
    MagicalContainer container;

    TEST_CASE("Adding and removing single element") {
        container.addElement(10);
        container.removeElement(10);
        CHECK(container.size() == 0);
    }

    TEST_CASE("Adding and removing multiple elements") {
        container.addElement(10);
        container.addElement(20);
        container.removeElement(10);
        container.addElement(30);
        container.removeElement(20);
        CHECK(container.size() == 1);
    }
}

TEST_SUITE("Test AscendingIterator class ") {

    TEST_CASE("Test * operator returns the correct element") {
        // Setup
        MagicalContainer container;
        container.addElement(4);
        container.addElement(1);
        container.addElement(9);
        MagicalContainer::AscendingIterator ascIter(container);
        auto first_asc_iterator = ascIter.begin();
        auto second_asc_iterator = ascIter.begin();
        // Assertion
        CHECK_EQ(*first_asc_iterator, 1);
        CHECK_EQ(*second_asc_iterator, 1);
    }

    TEST_CASE("Test ++ operator") {
        // Setup
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        MagicalContainer::AscendingIterator ascIter(container);
        auto first_asc_iterator = ascIter.begin();
        auto second_asc_iterator = ascIter.begin();
        // Action
        ++first_asc_iterator;

        // Assertions
        CHECK_EQ(*first_asc_iterator, 5);
        CHECK_NE(first_asc_iterator, second_asc_iterator);
        CHECK_FALSE(first_asc_iterator == second_asc_iterator);

        // Action
        ++second_asc_iterator;

        // Assertions
        CHECK_EQ(*second_asc_iterator, 5);
        CHECK_EQ(first_asc_iterator, second_asc_iterator);

        // Action
        ++second_asc_iterator;

        // Assertions
        CHECK_EQ(*second_asc_iterator, 8);

        // Action
        ++first_asc_iterator;

        // Assertions
        CHECK_EQ(*first_asc_iterator, 8);
        CHECK_EQ(first_asc_iterator, second_asc_iterator);
    }
}

TEST_SUITE("Test SideCrossIterator class") {

    TEST_CASE("Test * operator returns the correct element") {
        // Setup
        MagicalContainer container;
        container.addElement(4);
        container.addElement(1);
        container.addElement(9);
        MagicalContainer::SideCrossIterator sideCrossIter(container);
        auto first_sideCross_iterator = sideCrossIter.begin();
        auto second_sideCross_iterator = sideCrossIter.begin();
        // Assertion
        CHECK_EQ(*first_sideCross_iterator, 1);
        CHECK_EQ(*second_sideCross_iterator, 1);
    }

    TEST_CASE("Test ++ operator") {
        // Setup
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        MagicalContainer::SideCrossIterator sideCrossIter(container);
        auto first_sideCross_iterator = sideCrossIter.begin();
        auto second_sideCross_iterator = sideCrossIter.begin();
        // Action
        ++first_sideCross_iterator;

        // Assertions
        CHECK_EQ(*first_sideCross_iterator, 5);
        CHECK_NE(first_sideCross_iterator, second_sideCross_iterator);
        CHECK_FALSE(first_sideCross_iterator == second_sideCross_iterator);

        // Action
        ++second_sideCross_iterator;

        // Assertions
        CHECK_EQ(*second_sideCross_iterator, 5);
        CHECK_EQ(first_sideCross_iterator, second_sideCross_iterator);

        // Action
        ++second_sideCross_iterator;

        // Assertions
        CHECK_EQ(*second_sideCross_iterator, 8);

        // Action
        ++first_sideCross_iterator;

        // Assertions
        CHECK_EQ(*first_sideCross_iterator, 8);
        CHECK_EQ(first_sideCross_iterator, second_sideCross_iterator);
    }
}

TEST_SUITE("Test PrimeIterator class") {

    TEST_CASE("Test * operator returns the correct element") {
        // Setup
        MagicalContainer container;
        container.addElement(4);
        container.addElement(1);
        container.addElement(9);
        MagicalContainer::PrimeIterator primeIter(container);
        auto first_prime_iterator = primeIter.begin();
        auto second_prime_iterator = primeIter.begin();
        // Assertion
        CHECK_EQ(*first_prime_iterator, 2);
        CHECK_EQ(*second_prime_iterator, 2);
    }

    TEST_CASE("Test ++ operator") {
        // Setup
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        MagicalContainer::PrimeIterator primeIter(container);
        auto first_prime_iterator = primeIter.begin();
        auto second_prime_iterator = primeIter.begin();
        // Action
        ++first_prime_iterator;

        // Assertions
        CHECK_EQ(*first_prime_iterator, 5);
        CHECK_NE(first_prime_iterator, second_prime_iterator);
        CHECK_FALSE(first_prime_iterator == second_prime_iterator);

        // Action
        ++second_prime_iterator;

        // Assertions
        CHECK_EQ(*second_prime_iterator, 5);
        CHECK_EQ(first_prime_iterator, second_prime_iterator);

        // Action
        ++second_prime_iterator;

        // Assertions
        CHECK_EQ(*second_prime_iterator, 8);

        // Action
        ++first_prime_iterator;

        // Assertions
        CHECK_EQ(*first_prime_iterator, 8);
        CHECK_EQ(first_prime_iterator, second_prime_iterator);
    }
}

TEST_SUITE("PrimeIterator move over prime numbers only") {

    TEST_CASE("Iterating over elements") {
        MagicalContainer container;
        container.addElement(100);
        container.addElement(200);
        container.addElement(36);
        container.addElement(99);
        container.addElement(102);
        container.addElement(4);

        MagicalContainer::PrimeIterator prime_it(container);
        CHECK_EQ(prime_it, prime_it.end());
        CHECK_THROWS_AS(++prime_it, runtime_error);
    }
}

TEST_SUITE("PrimeIterator") {

    TEST_CASE("Test first prime element") {
        // Setup
        MagicalContainer container;
        container.addElement(3);
        container.addElement(7);
        container.addElement(9);
        container.addElement(23);
        container.addElement(11);
        MagicalContainer::PrimeIterator primeIter(container);
        // Action
        auto begin = primeIter.begin();

        // Assertion
        CHECK_EQ(*begin, 3);
    }

    TEST_CASE("Test second prime element") {
        // Setup
        MagicalContainer container;
        container.addElement(3);
        container.addElement(7);
        container.addElement(9);
        container.addElement(23);
        container.addElement(11);
        MagicalContainer::PrimeIterator primeIter(container);
        // Action
        auto begin = primeIter.begin();
        ++begin;

        // Assertion
        CHECK_EQ(*begin, 7);
    }

    TEST_CASE("go over the prime numbers") {
        // Setup
        MagicalContainer container;
        container.addElement(3);
        container.addElement(7);
        container.addElement(9);
        container.addElement(23);
        container.addElement(11);
        MagicalContainer::PrimeIterator primeIter(container);
        // Action
        auto begin = primeIter.begin();
        ++begin;
        ++begin;

        // Assertion
        CHECK_EQ(*begin, 11);
    }
}

TEST_SUITE(" AscendingIterator") {

    TEST_CASE("Iterating in ascending order") {
        // Setup
        MagicalContainer container;
        container.addElement(3);
        container.addElement(6);
        container.addElement(9);
        container.addElement(12);
        container.addElement(15);
        // Action
        MagicalContainer::AscendingIterator it(container);
        // Assertions
        CHECK_EQ(*it, 3);
        ++it;
        CHECK_EQ(*it, 6);
        ++it;
        CHECK_EQ(*it, 9);
        ++it;
        CHECK_EQ(*it, 12);
        ++it;
        CHECK_EQ(*it, 15);
        ++it;
        CHECK(it == it.end());
    }
}