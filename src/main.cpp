// main.cpp

#include <iostream>
#include <string>
#include "utils.hpp"
#include <limits>
#include <numeric>
#include "betternumbers.hpp"

int main(int argc, const char** argv) {
	using numb = Betternumbers::Number;
	numb a(21, 37);
	std::cout << a << std::endl;
}