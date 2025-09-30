/**
 * file:        bubblesort_optimized.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Optimized bubble sort with early termination when no swaps occur, improving best-case performance
 */

#ifndef BUBBLE_SORT_OPTIMIZED_H
#define BUBBLE_SORT_OPTIMIZED_H

#include "sort.h"

class BubbleSortOptimized : public Sort
{

public:
    BubbleSortOptimized()
    {
        name = "Bubble Sort";
    }

    void doSort(std::vector<int> &vec)
    {
        int n = vec.size();
        bool swapped;

        for (int i = 0; i < n - 1; i++)
        {
            swapped = false;

            for (int j = 0; j < n - i - 1; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    doSwap(vec[j], vec[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
            {
                break;
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