#ifndef STORAGE
#define STORAGE

#include "libraries.h"
#include "global_variables.h"

class Storage {
private:
	std::vector<int>numbers;
public:
	Storage() : numbers(MAX_SIZE, 0)
	{}

	void shuffle();
	void checkSort();
	std::vector<int>& getStorage();
};

void Storage::shuffle() {
	/*Marsenne's Twister algorithm for generating random numbers*/
	std::mt19937 random_generator;
	/*class, that produces random numbers from selected range*/
	std::uniform_int_distribution random_range(1, 99);

	for (int i = 0; i < numbers.size(); ++i) {
		numbers[i] = random_range(random_generator);
	}
	system("cls"); /*clears terminal*/

	return;
}

void Storage::checkSort() {
	bool isSorted{ std::is_sorted(numbers.begin(), numbers.end()) };
	SDL_SetRenderDrawColor(render, 255, 255, 0, 255);

	std::size_t index{ 0 };
	for (int i : numbers) {
		/*i defines height of the column*/
		SDL_RenderDrawLine(render, index, 100, index, i);
		SDL_RenderPresent(render);
		SDL_Delay(10);
		++index;
	}
	std::cout << "Array is sorted: " << std::boolalpha << isSorted << '\n';
	system("pause");
	return;
}

std::vector<int>& Storage::getStorage() {
	return numbers;
}

#endif

