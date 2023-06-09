#pragma once

#include <vector>

namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> container;

        // for following primes:
        std::vector<int> primeContainer;

        // for following crossIter end:

        // my added private functions:
        void removePrime(int number);
        bool isNumberInContainer(int number);
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
        void updateCrossEnd();

    public:
        std::vector<int>::iterator crossEnd;
        // Ctors & Dtors:
        MagicalContainer();
        ~MagicalContainer();

        // functions to implement:
        void addElement(int number);
        int size();
        void removeElement(int number);

        // my added functions:
        bool isPrime(int number);
        bool operator==(const MagicalContainer &other) const;
        bool operator!=(const MagicalContainer &other) const;

        // public classes to implement:

        class AscendingIterator
        {
        private:
            MagicalContainer &magicalContainer;
            std::vector<int>::iterator mainIter;

        public:
            // Ctors & Dtors:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(MagicalContainer &container, std::vector<int>::iterator position);
            ~AscendingIterator();

            // functions to implement:
            AscendingIterator begin();
            AscendingIterator end();
            AscendingIterator &operator++();
            int operator*();
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator!=(const AscendingIterator &other) const;
            bool operator==(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &magicalContainer;
            std::vector<int>::iterator lowSideIter;
            std::vector<int>::iterator highSideIter;
            int currTurn, steps;

            // my added private functions:
            SideCrossIterator lastElem();

        public:
            // Ctors & Dtors:
            SideCrossIterator(MagicalContainer &mcon);
            SideCrossIterator(MagicalContainer &mcon,
                              std::vector<int>::iterator lowPosition,
                              std::vector<int>::iterator highPosition,
                              int currTurn);

            // functions to implement:
            SideCrossIterator begin();
            SideCrossIterator end();
            SideCrossIterator &operator++();
            int operator*();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator!=(const SideCrossIterator &other) const;
            bool operator==(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &magicalContainer;
            std::vector<int>::iterator mainIter;
            std::vector<int>::iterator primeIter;

        public:
            // Ctors & Dtors:
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(MagicalContainer &mcon, std::vector<int>::iterator position);
            ~PrimeIterator();

            // functions to implement:
            PrimeIterator begin();
            PrimeIterator end();
            PrimeIterator &operator++();
            int operator*();
            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator!=(const PrimeIterator &other) const;
            bool operator==(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
        };
    };

};
