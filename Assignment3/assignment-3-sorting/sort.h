/**
 * file:        sort.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Base class defining the interface for all sorting algorithms with timing and validation functionality
 */

#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

class Sort
{

public:
    std::string name;
    double sortTime;
    clock_t time_begin;
    clock_t time_end;

    virtual ~Sort()
    {
    }

    std::string toString()
    {
        std::string str = "Sort type: " + name;
        return str;
    }

    std::string getName()
    {
        return name;
    }

    double getSortTime()
    {
        return sortTime;
    }

    void checkSorted(std::vector<int> &vec)
    {
        if (vec.size() > 1)
        {
            for (std::size_t i = 1; i < vec.size(); i++)
            {
                assert(vec.at(i - 1) <= vec.at(i));
            }
        }
    }

    void sortVector(std::vector<int> &vec)
    {

        sortTime = 0.0;
        time_begin = clock();

        doSort(vec);

        time_end = clock();
        sortTime = (time_end - time_begin) / (double)CLOCKS_PER_SEC;
    }

    virtual void doSort(std::vector<int> &vec) = 0;
};

#endif