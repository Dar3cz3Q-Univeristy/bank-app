#pragma once

#include <array>
#include <algorithm>

const int spacePlaces[] = { 3, 6, 11, 16, 21, 26, 31 };

namespace ArrayCheck {
	static bool contains(int n) {
		return std::find(std::begin(spacePlaces), std::end(spacePlaces), n) != std::end(spacePlaces);
	}
}