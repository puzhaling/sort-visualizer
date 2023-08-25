#include "libraries.h"
#include "global_variables.h"
#include "help_functions.h"

/*--------------------------------------------------------------------------------------------------------*/
/*only rightmost pivot version is implemented*/
std::size_t partition(std::vector<int>& nums, std::size_t low, std::size_t high) {

	/*Choosing the pivot as the righmost element*/
	int pivot = nums[high];

	/*Index of smaller element and indicates*/
	/*the right position of pivot found so far*/
	std::size_t i = (low - 1);

	for (std::size_t j = low; j <= high - 1; ++j) {
		++array_accesses;

		/*If current element is smaller than the pivot*/
		if (nums[j] < pivot) {

			/*Increment index of smaller element*/
			++i;
			std::swap(nums[i], nums[j]);
			++swaps;

			/*i and j show which part of the array is currently being sorted*/
			show_state(nums, i, j);
			SDL_Delay(15);
		}
	}
	std::swap(nums[i + 1], nums[high]);
	return i + 1;
}

void quickSort(std::vector<int>& nums, std::size_t low, std::size_t high) {
	if (low < high) {

		/*placing pivot at the right place and
		  recursively sort the remaining parts of array*/
		std::size_t pivot{ partition(nums, low, high) };

		quickSort(nums, low, pivot - 1);
		quickSort(nums, pivot + 1, high);
	}
}
/*--------------------------------------------------------------------------------------------------------*/

void selectionSort(std::vector<int>& nums) {
	std::size_t min_index{};

	std::size_t size{ nums.size() };
	for (std::size_t i{ 0 }; i < size; ++i) {

		min_index = i;
		for (std::size_t j{ i + 1 }; j < size; j++) {
			++array_accesses;
			if (nums[j] < nums[min_index])
				min_index = j;
		}

		if (min_index != i) {
			std::swap(nums[min_index], nums[i]);
			++swaps;

			/*i and min_index show which part of the array is currently being sorted*/
			show_state(nums, i, min_index);
			SDL_Delay(60);
		}
	}
	return;
}

void bubbleSort(std::vector<int>& nums) {
	for (std::size_t i = 0; i < nums.size(); ++i) {
		for (std::size_t j = i; j < nums.size(); ++j) {
			++array_accesses;
			if (nums[i] > nums[j]) {
				std::swap(nums[i], nums[j]);
				++swaps;

				/*i and j show which part of the array is currently being sorted*/
				show_state(nums, i, j);
				SDL_Delay(10);
			}
		}
	}
	return;
}

void insertionSort(std::vector<int>& nums) {
	for (int i{ 1 }; i < nums.size(); ++i) {
		int key{ nums[i] };
		int j{ i - 1 };

		// Move elements of nums[0..i - 1],
		// that are greater than key,
		// to one position ahead of their
		// current position
		while (j >= 0 && nums[j] > key) {
			++array_accesses;
			nums[j + 1] = nums[j];
			++swaps;

			/*i and j show which part of the array is currently being sorted*/
			show_state(nums, i, j);
			SDL_Delay(10);

			--j;
		}
		nums[j + 1] = key;
	}
}

/*--------------------------------------------------------------------------------------------------------*/
void merge(std::vector<int>& nums, std::size_t l, std::size_t m, std::size_t r) {
	std::size_t i{}, j{};
	int k{};

	std::size_t n1{ m - l + 1 };
	std::size_t n2{ r - m };

	std::vector<int>L(n1);
	std::vector<int>R(n2);

	for (i = 0; i < n1; ++i) {
		++array_accesses;
		L[i] = nums[l + i];
		++swaps;
	}
	for (j = 0; j < n2; ++j) {
		++array_accesses;
		R[j] = nums[m + 1 + j];
		++swaps;
	}

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		++array_accesses;
		if (L[i] <= R[j]) {
			nums[k] = L[i];
			++swaps;

			/*i and j show which part of the array is currently being sorted*/
			show_state(nums, i, j);
			SDL_Delay(12);

			++i;
		}
		else {
			nums[k] = R[j];
			++swaps;

			/*i and j show which part of the array is currently being sorted*/
			show_state(nums, k, j);
			SDL_Delay(12);

			j++;
		}
		k++;
	}

	while (i < n1) {
		nums[k] = L[i];
		++array_accesses;

		/*k and i show which part of the array is currently being sorted*/
		show_state(nums, k, i);
		SDL_Delay(12);

		i++; k++;
	}

	while (j < n2) {
		nums[k] = R[j];
		++array_accesses;
		++swaps;

		/*k and j show which part of the array is currently being sorted*/
		show_state(nums, k, j);
		SDL_Delay(10);

		j++; k++;
	}
}

void mergeSort(std::vector<int>& nums, std::size_t l, std::size_t r) {
	if (l < r) {
		std::size_t m = l + (r - l) / 2;

		/*Sort first and second halves recursively*/
		mergeSort(nums, l, m);
		mergeSort(nums, m + 1, r);

		merge(nums, l, m, r);
	}
}

/*--------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------*/
bool bogoCheck(std::vector<int>& nums) {
	std::size_t n{ nums.size() };
	while (--n > 0) {
		if (nums[n] < nums[n - 1])
			return false;
	}
	return true;
}

void bogoSort(std::vector<int>& nums) {
	int timer{ 3 };
	array_accesses = nums.size() * timer;
	/*if array is not sorted then shuffle it again*/
	while (!bogoCheck(nums)) {
		/*prevent infinite loop, just for demonstation*/
		if (timer-- == 0)
			return;

		std::size_t n{ nums.size() };
		for (std::size_t i = 0; i < n; ++i) {
			std::swap(nums[i], nums[rand() % n]);
			show_state(nums, 0, i);
			SDL_Delay(12);
		}
	}
	return;
}
/*--------------------------------------------------------------------------------------------------------*/

void gnomeSort(std::vector<int>& nums) {
	std::size_t i{ 0 };

	while (i < nums.size()) {
		if (i == 0)
			++i;
		if (nums[i] >= nums[i - 1])
			++i;
		else {
			std::swap(nums[i], nums[i - 1]);
			show_state(nums, 0, i);
			SDL_Delay(10);
			--i;
			++swaps;
		}
		++array_accesses;
	}
	return;
}

void cocktailSort(std::vector<int>& nums) {
	bool flag{ true };
	std::size_t start{ 0 }, end{ nums.size() - 1 };
	while (flag) {
		flag = false;
		for (std::size_t i{ start }; i < end; ++i) { //scan from left to right as bubble sort
			++array_accesses;
			if (nums[i] > nums[i + 1]) {
				std::swap(nums[i], nums[i + 1]);
				++swaps;
				show_state(nums, i, i);
				SDL_Delay(5);

				flag = true;
			}
		}

		if (!flag) break;  //if nothing has changed simply break the loop;

		flag = false;
		end--; //decrease the end pointer
		for (std::size_t i{ end - 1 }; i > start; --i) { //scan from right to left
			++array_accesses;
			if (nums[i] > nums[i + 1]) {
				std::swap(nums[i], nums[i + 1]);
				++swaps;
				show_state(nums, 0, i);
				SDL_Delay(5);

				flag = true;
			}
		}
		start++;
	}
	return;
}

void shellSort(std::vector<int>& nums) {

	std::size_t n{ nums.size() };
	// Start with a big gap, then reduce the gap
	for (std::size_t gap{ n / 2 }; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (std::size_t i{ gap }; i < n; ++i)
		{
			++array_accesses;
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			std::int32_t temp{ nums[i] };

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			std::size_t j;
			for (j = i; j >= gap && nums[j - gap] > temp; j -= gap) {
				nums[j] = nums[j - gap];
				show_state(nums, i, j);
				SDL_Delay(10);
				++swaps;
			}

			//  put temp (the original a[i]) in its correct location
			nums[j] = temp;
			++swaps;
			show_state(nums, i, j);
			SDL_Delay(10);
		}
	}
	return;
}
