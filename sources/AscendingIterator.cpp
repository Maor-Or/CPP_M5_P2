#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{
    // Ctors & Dtors:
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &mcon)
        : magicalContainer(mcon), mainIter(magicalContainer.begin())
    {
    }
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &mcon, std::vector<int>::iterator position)
        : magicalContainer(mcon), mainIter(position)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // functions to implement:
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return {magicalContainer, magicalContainer.begin()};
        // MagicalContainer::AscendingIterator newIter(magicalContainer, magicalContainer.begin());
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return {magicalContainer, magicalContainer.end()};
        // return newIter;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (mainIter == magicalContainer.end())
        {
            throw std::runtime_error("can't increment beyond container's limits");
            return *this;
        }

        ++mainIter;
        return *this;
    } // prefix

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return mainIter > other.mainIter;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return mainIter < other.mainIter;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
            return *this;
        }

        mainIter = other.mainIter;
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(
        const MagicalContainer::AscendingIterator &other) const
    {
        return mainIter == other.mainIter;
    }
    bool MagicalContainer::AscendingIterator::operator!=(
        const MagicalContainer::AscendingIterator &other) const
    {
        return !(*this == other);
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return *(mainIter);
    }

};