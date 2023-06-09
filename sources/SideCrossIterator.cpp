#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{

    // // class MagicalContainer::SideCrossIterator;

    // Ctors & Dtors:
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &mcon)
        : magicalContainer(mcon),
          lowSideIter(magicalContainer.container.begin()),
          highSideIter(std::prev(magicalContainer.container.end())),
          currTurn(0), steps(0)
    {
        if (magicalContainer.size() == 0)
        {
            *this = end();
        }
    }
    // MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(
        MagicalContainer &mcon,
        std::vector<int>::iterator lowPosition,
        std::vector<int>::iterator highPosition,
        int currTurn)
        : magicalContainer(mcon),
          lowSideIter(lowPosition),
          highSideIter(highPosition),
          currTurn(currTurn)
    {
    }

    // functions to implement:
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return {magicalContainer, magicalContainer.container.begin(),
                std::prev(magicalContainer.container.end()), 0};
    }


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return {magicalContainer, magicalContainer.container.end(), magicalContainer.container.end(), 2};
    }

    // MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    // {
    //     return {magicalContainer, magicalContainer.crossEnd, magicalContainer.crossEnd, 2};
    // }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::lastElem()
    {
        return {magicalContainer, magicalContainer.crossEnd, magicalContainer.crossEnd, 0};
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {

        if (*this == end())
        {
            throw std::runtime_error("can't increment beyond container's limits");
            return *this;
        }
        if (lowSideIter > highSideIter || steps == magicalContainer.size()-1)
        {
            lowSideIter = magicalContainer.container.end();
            highSideIter = magicalContainer.container.end();            
            currTurn = 2;
            return *this;
        }
        if (currTurn == 0)
        {
            ++lowSideIter;
            currTurn = 1;
        }
        else // currTurn == 1
        {
            --highSideIter;
            currTurn = 0;
        }
        ++steps;
        
        return *this;
    } // prefix

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return (lowSideIter > other.lowSideIter) ||
               (highSideIter < other.highSideIter) ||
               (lowSideIter == other.lowSideIter && highSideIter < other.highSideIter && currTurn > other.currTurn);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return !((*this) == other || (*this) > other);
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (magicalContainer != other.magicalContainer)
        {
            throw std::runtime_error("Itertators have different magicalContainers");
            return *this;
        }

        lowSideIter = other.lowSideIter;
        highSideIter = other.highSideIter;
        currTurn = other.currTurn;
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(
        const MagicalContainer::SideCrossIterator &other) const
    {
        return (lowSideIter == other.lowSideIter) &&
               (highSideIter == other.highSideIter) &&
               (currTurn == other.currTurn);
    }
    bool MagicalContainer::SideCrossIterator::operator!=(
        const MagicalContainer::SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return currTurn == 0 ? *(lowSideIter) : *(highSideIter);
    }

};