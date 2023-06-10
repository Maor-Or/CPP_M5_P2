#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{
    // Ctors & Dtors:
    // default Ctor:
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &mcon)
        : magicalContainer(mcon), mainIter(magicalContainer.begin())
    {
        if (magicalContainer.size() == 0)
        {
            *this = end();
        }
    }

    // copy Ctor:
    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &other)
        : magicalContainer(other.magicalContainer), mainIter(other.mainIter) {}

    // special constructor for begin(), end():
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &mcon, std::vector<int>::iterator position)
        : magicalContainer(mcon), mainIter(position) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}


    // functions to implement:
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return {magicalContainer, magicalContainer.begin()};
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return {magicalContainer, magicalContainer.end()};
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

    bool MagicalContainer::AscendingIterator::operator==(
        const MagicalContainer::AscendingIterator &other) const
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
        }
        return mainIter == other.mainIter;
    }

    bool MagicalContainer::AscendingIterator::operator!=(
        const MagicalContainer::AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
        }
        return mainIter > other.mainIter;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return !(*this == other || *this > other);
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
        }

        mainIter = other.mainIter;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return *(mainIter);
    }

};