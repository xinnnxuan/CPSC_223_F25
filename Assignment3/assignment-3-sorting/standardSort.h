/**
 * file:        standardSort.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Wrapper class for C++ built-in std::sort algorithm used as performance baseline
 */

#ifndef STANDARD_SORT_H
#define STANDARD_SORT_H

#include "sort.h"
#include <algorithm>

class StandardSort : public Sort
{

public:
    StandardSort()
    {
        name = "std::sort";
    }

    void doSort(std::vector<int> &vec)
    {
        std::sort(vec.begin(), vec.end());
    }
};

#endif