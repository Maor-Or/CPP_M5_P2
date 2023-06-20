#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{

    // Ctors & Dtors:
    //default Ctor:
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &mcon)
        : magicalContainer(mcon),
          mainIter(magicalContainer.container.begin()),
          primeIter(magicalContainer.primeContainer.begin())
    {
        if (magicalContainer.primeContainer.size() == 0)
        {
            *this = end();
        }
        
    }

    //copy Ctor:
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : magicalContainer(other.magicalContainer), mainIter(other.mainIter), primeIter(other.primeIter)
    {
    }

    //special Ctor for begin(), end():
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &mcon, std::vector<int>::iterator position)
        : magicalContainer(mcon), mainIter(magicalContainer.container.begin()), primeIter(position)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // functions to implement:
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return {magicalContainer, magicalContainer.primeContainer.begin()};
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return {magicalContainer, magicalContainer.primeContainer.end()};
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (primeIter == magicalContainer.primeContainer.end())
        {
            throw std::runtime_error("can't increment beyond container's limits");
            return *this;
        }
        ++primeIter;
        return *this;
    } // prefix

    bool MagicalContainer::PrimeIterator::operator==(
        const MagicalContainer::PrimeIterator &other) const
    {
        return primeIter == other.primeIter;
    }

    bool MagicalContainer::PrimeIterator::operator!=(
        const MagicalContainer::PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return primeIter > other.primeIter;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return !(*this == other || *this > other);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
        }

        primeIter = other.primeIter;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return *(primeIter);
    }

};