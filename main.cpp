#include "libraries.h"
#include "global_variables.h"
#include "sort_functions.h"
#include "help_functions.h"
#include "storage_class.h";

int main(int argc, char* args[]) {
	SDL_RenderSetScale(render, 8, 9);
	SDL_SetWindowPosition(window, 60, 32);

	Storage storage{};
	storage.shuffle();

	bool running{ true };
	while (running) {
		intro();
		int choice{ makeChoice() };

		switch (choice) {
		case 0:
			running = false;
			break;
		case 1:
			SDL_Delay(two_secs);
			bubbleSort(storage.getStorage());
			break;
		case 2:
			SDL_Delay(two_secs);
			quickSort(storage.getStorage(), 0, MAX_SIZE - 1);
			break;
		case 3:
			SDL_Delay(two_secs);
			selectionSort(storage.getStorage());
			break;
		case 4:
			SDL_Delay(two_secs);
			insertionSort(storage.getStorage());
			break;
		case 5:
			SDL_Delay(two_secs);
			mergeSort(storage.getStorage(), 0, MAX_SIZE - 1);
			break;
		case 6:
			SDL_Delay(two_secs);
			bogoSort(storage.getStorage());
			break;
		case 7:
			SDL_Delay(two_secs);
			gnomeSort(storage.getStorage());
			break;
		case 8:
			SDL_Delay(two_secs);
			cocktailSort(storage.getStorage());
			break;
		case 9:
			SDL_Delay(two_secs);
			shellSort(storage.getStorage());
			break;
		}

		if (running) {
			std::cout << "\nArray swaps: " << swaps << ". " <<
				"Array accesses: " << array_accesses << ".\n";
			swaps = 0; array_accesses = 0;

			printSortInfo(choice);
			storage.checkSort();
			storage.shuffle();
		}
	}
	close();
	return 0;
}