/**
 * file:        insertionSort.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Implementation of insertion sort algorithm that builds sorted array one element at a time
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort.h"

class InsertionSort : public Sort
{

public:
    InsertionSort()
    {
        name = "Insertion Sort";
    }

    void doSort(std::vector<int> &vec)
    {
        int n = vec.size();

        for (int i = 1; i < n; i++)
        {
            int key = vec[i];
            int j = i - 1;

            while (j >= 0 && vec[j] > key)
            {
                vec[j + 1] = vec[j];
                j--;
            }

            vec[j + 1] = key;
        }
    }
};

#endif