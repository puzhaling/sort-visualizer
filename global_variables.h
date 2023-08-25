#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

#include "libraries.h"
inline constexpr int two_secs{ 2000 };
inline constexpr std::size_t MAX_SIZE{ 100 };

namespace win_info {
	inline constexpr std::uint16_t WIDTH{ 740 };
	inline constexpr std::uint16_t HEIGHT{ 832 };
}

inline SDL_Window* window{ SDL_CreateWindow("Sort Visualizer", NULL, NULL, win_info::WIDTH, win_info::HEIGHT, 0) };
inline SDL_Renderer* render{ SDL_CreateRenderer(window, -1, 0) };

inline unsigned long long swaps{ 0 };
inline unsigned long long array_accesses{ 0 };

#endif
