/**
 * file:        main.cpp
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Main program that benchmarks different sorting algorithms with various input sizes and data patterns
 */

#include <iostream>
#include <vector>
#include "main.h"

int main(int argc, char *argv[])
{

    int n;

    if (argc == 2)
    {
        n = std::stoi(argv[1]);
    }
    else
    {
        std::cout << "n size not specified, defaulting to 1000" << std::endl;
        n = 1000;
    }

    srand(time(0));

    std::vector<int> vec;

    std::vector<Sort *> sortVector;

    BubbleSort *bubbleSort = new BubbleSort();
    sortVector.push_back(bubbleSort);

    BubbleSortOptimized *bubbleSortOptimized = new BubbleSortOptimized();
    sortVector.push_back(bubbleSortOptimized);

    SelectionSort *selectionSort = new SelectionSort();
    sortVector.push_back(selectionSort);

    InsertionSort *insertionSort = new InsertionSort();
    sortVector.push_back(insertionSort);

    StandardSort *standardSort = new StandardSort();
    sortVector.push_back(standardSort);

    for (std::size_t i = 0; i < sortVector.size(); i++)
    {
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << sortVector.at(i)->toString() << std::endl;
        testSort(sortVector.at(i), vec, "Ascending", n, 5);
        testSort(sortVector.at(i), vec, "Descending", n, 5);
        testSort(sortVector.at(i), vec, "Random", n, 5);
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
    }

    delete bubbleSort;
    delete bubbleSortOptimized;
    delete selectionSort;
    delete insertionSort;
    delete standardSort;

    return 0;
}

void testSort(Sort *sort, std::vector<int> &vec, std::string initialCondition, int size, int iterationCount)
{

    double averageTime = 0.0;
    std::string results;

    for (int i = 0; i < iterationCount; i++)
    {

        if (initialCondition == "Random")
        {
            fillVectorRandom(vec, size);
        }
        else if (initialCondition == "Ascending")
        {
            fillVectorAsc(vec, size);
        }
        else if (initialCondition == "Descending")
        {
            fillVectorDsc(vec, size);
        }

        sort->sortVector(vec);

        sort->checkSorted(vec);

        averageTime += sort->sortTime;

        vec.clear();
    }

    averageTime = averageTime / iterationCount;

    printf("%s, input data: %s, n=%d, average time: %.4f secs\n", sort->name.c_str(), initialCondition.c_str(), size, averageTime);
}

void printVector(std::vector<int> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

void fillVectorRandom(std::vector<int> &vec, int count)
{

    int min = 0;
    int max = 1000000000;

    for (int i = 0; i < count; i++)
    {
        vec.push_back(rand() % (max - min) + min);
    }
}

void fillVectorAsc(std::vector<int> &vec, int count)
{

    for (int i = 0; i < count; i++)
    {
        vec.push_back(i);
    }
}

void fillVectorDsc(std::vector<int> &vec, int count)
{

    for (int i = count; i > 0; i--)
    {
        vec.push_back(i);
    }
}
