#include "MagicalContainer.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel
{

    // Ctors & Dtors:
    MagicalContainer::MagicalContainer() : container(0), crossEnd(container.end())
    {
    }

    MagicalContainer::~MagicalContainer()
    {
    }

    // functions to implement:
    void MagicalContainer::addElement(int number)
    {
        container.emplace_back(number);

        std::sort(container.begin(), container.end());

        if (isPrime(number))
        {
            // cout << number << " is prime!" << endl;
            primeContainer.emplace_back(number);
            std::sort(primeContainer.begin(), primeContainer.end());
            // cout << " in the primeContainer: " << *primeContainer.begin() << endl;
        }

        updateCrossEnd();
    }
    int MagicalContainer::size()
    {
        return container.size();
    }

    void MagicalContainer::removeElement(int number)
    {
        if (!isNumberInContainer(number))
        {
            throw std::runtime_error("number isn't in the container!");
        }

        if (isPrime(number))
        {
            // Erase the desired number from the prime list:
            removePrime(number);
        }

        //  Erase the desired number:
        for (std::vector<int>::iterator it = container.begin(); it != container.end();)
        {
            if (*it == number)
            {
                it = container.erase(it);
                return;
            }
            else
                ++it;
        }
        updateCrossEnd();
    }

    // my added functions:
    bool MagicalContainer::isPrime(int number)
    {

        // if is 2:
        if (number == 2)
        {
            return true;
        }
        // if is negative, 0, 1 or an even number:
        if (number <= 1 || number % 2 == 0)
        {
            return false;
        }

        for (int i = 3; i * i <= number; i += 2)
        {
            if (number % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    void MagicalContainer::removePrime(int number)
    {
        // Erase the desired number from the prime list:
        for (std::vector<int>::iterator it = primeContainer.begin(); it != primeContainer.end();)
        {
            if (*(it) == number)
            {
                it = primeContainer.erase(it);
                return;
            }
            else
                ++it;
        }
    }

    bool MagicalContainer::isNumberInContainer(int number)
    {
        return std::find(container.begin(), container.end(), number) != container.end();
    }

    std::vector<int>::iterator MagicalContainer::begin() { return container.begin(); }

    std::vector<int>::iterator MagicalContainer::end() { return container.end(); }

    bool MagicalContainer::operator==(const MagicalContainer &other) const
    {
        return container == other.container;
    }
    bool MagicalContainer::operator!=(const MagicalContainer &other) const
    {
        return !((*this) == other);
    }

    void MagicalContainer::updateCrossEnd()
    {
        std::vector<int>::iterator lowIter = container.begin();
        std::vector<int>::iterator highIter = std::prev(container.end());

        int turn = 0;
        while (lowIter != highIter)
        {
            if (turn == 0)
            {
                ++lowIter;
                turn = 1;
            }
            else
            {
                --highIter;
                turn = 0;
            }
        }
        crossEnd = lowIter;
    //      std::cout << "endcross is: ";
    // std::cout<< *(crossEnd) << std::endl;
    }

} // namespace ariel
