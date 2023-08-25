#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include "libraries.h"

void intro();
int makeChoice();
void close();
void show_state(std::vector<int>& nums, std::size_t red, std::size_t blue);
void printSortInfo(char choice);

#endif