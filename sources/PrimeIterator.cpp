#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{

    // Ctors & Dtors:
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &mcon)
        : magicalContainer(mcon),
          mainIter(magicalContainer.container.begin()),
          primeIter(magicalContainer.primeContainer.begin())
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &mcon, std::vector<int>::iterator position)
        : magicalContainer(mcon), mainIter(magicalContainer.container.begin()), primeIter(position)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // functions to implement:
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return {magicalContainer, magicalContainer.primeContainer.begin()};
        // MagicalContainer::PrimeIterator newIter(magicalContainer, magicalContainer.begin());
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return {magicalContainer, magicalContainer.primeContainer.end()};
        // return newIter;
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

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return primeIter > other.primeIter;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return primeIter < other.primeIter;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
            return *this;
        }

        primeIter = other.primeIter;
        return *this;
    }
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

    int MagicalContainer::PrimeIterator::operator*()
    {
        return *(primeIter);
    }

};