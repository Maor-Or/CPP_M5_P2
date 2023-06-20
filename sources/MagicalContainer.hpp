#pragma once

#include <vector>

namespace ariel
{

    class MagicalContainer
    {
    private:
        // main internal container:
        std::vector<int> container;

        // for following primes:
        std::vector<int> primeContainer;

        // for following crossIter end:
        std::vector<int>::iterator crossEnd;

        // my added private functions:
        void removePrime(int number);
        bool isPrime(int number);
        bool isNumberInContainer(int number);
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
        void updateCrossEnd();

    public:
        // Ctors & Dtors:
        MagicalContainer();
        ~MagicalContainer();

        // functions to implement:
        void addElement(int number);
        int size();
        void removeElement(int number);

        // my added functions:
        bool operator==(const MagicalContainer &other) const;
        bool operator!=(const MagicalContainer &other) const;

        // public classes to implement:

        class AscendingIterator
        {
        private:
            MagicalContainer &magicalContainer;
            std::vector<int>::iterator mainIter;

            // special constructor for begin(), end():
            AscendingIterator(MagicalContainer &container, std::vector<int>::iterator position);

        public:
            // Ctors & Dtors:
            AscendingIterator(MagicalContainer &container); // default Ctor
            AscendingIterator(const AscendingIterator &other);    // copy Ctor
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
            int currTurn, steps; //currTurn tells which iterator should de-reference 
                                  //and steps is always 0 and is 2 when last element is reached 

            // special constructor for begin(), end():
            SideCrossIterator(MagicalContainer &mcon,
                              std::vector<int>::iterator lowPosition,
                              std::vector<int>::iterator highPosition,
                              int currTurn, int steps);

        public:
            // Ctors & Dtors:
            SideCrossIterator(MagicalContainer &mcon);   // default Ctor
            SideCrossIterator(const SideCrossIterator &other); // copy Ctor
            ~SideCrossIterator();

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

            // special constructor for begin(), end():
            PrimeIterator(MagicalContainer &mcon, std::vector<int>::iterator position);
    
        public:
            // Ctors & Dtors:
            PrimeIterator(MagicalContainer &container); // default Ctor
            PrimeIterator(const PrimeIterator& other);        //copy Ctor
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
