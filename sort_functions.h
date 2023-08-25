#ifndef SORT_FUNCTIONS
#define SORT_FUNCTIONS

#include "libraries.h"

int partition(std::vector<int>& nums, std::size_t low, std::size_t high);
void quickSort(std::vector<int>& nums, std::size_t low, std::size_t high);

void bubbleSort(std::vector<int>& nums);
void selectionSort(std::vector<int>& nums);
void insertionSort(std::vector<int>& nums);

void merge(std::vector<int>& nums, std::size_t l, std::size_t m, std::size_t r);
void mergeSort(std::vector<int>& nums, std::size_t l, std::size_t r);

bool bogoCheck(std::vector<int>& nums);
void bogoSort(std::vector<int>& nums);

void gnomeSort(std::vector<int>& nums);
void cocktailSort(std::vector<int>& nums);
void shellSort(std::vector<int>& nums);

#endif
