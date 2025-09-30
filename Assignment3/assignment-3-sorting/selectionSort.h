/**
 * file:        selectionSort.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Implementation of selection sort algorithm that repeatedly finds minimum element and swaps to correct position
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort.h"

class SelectionSort : public Sort
{

public:
    SelectionSort()
    {
        name = "Selection Sort";
    }

    void doSort(std::vector<int> &vec)
    {
        int n = vec.size();

        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (vec[j] < vec[minIndex])
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                int temp = vec[i];
                vec[i] = vec[minIndex];
                vec[minIndex] = temp;
            }
        }
    }
};

#endif