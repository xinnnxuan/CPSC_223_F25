/**
 * file:        bubbleSort.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Implementation of standard bubble sort algorithm with O(n²) time complexity
 */

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.h"

class BubbleSort : public Sort
{

public:
    BubbleSort()
    {
        name = "Bubble Sort";
    }

    void doSort(std::vector<int> &vec)
    {
        int n = vec.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    doSwap(vec[j], vec[j + 1]);
                }
            }
        }
    }

    void doSwap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

#endif