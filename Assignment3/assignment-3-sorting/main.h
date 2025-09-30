/**
 * file:        main.h
 * author:      Johanna Fan
 * date:        September 25, 2025
 * description: Header file containing function declarations and includes for the sorting benchmark program
 */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "sort.h"
#include "bubbleSort.h"
#include "bubblesort_optimized.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "standardSort.h"

void printVector(std::vector<int> &vec);
void fillVectorRandom(std::vector<int> &vec, int count);
void fillVectorAsc(std::vector<int> &vec, int count);
void fillVectorDsc(std::vector<int> &vec, int count);
void testSort(Sort* sort, std::vector<int> &vec, std::string initialCondition, int size, int iterationCount);

#endif