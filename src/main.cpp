// main.cpp

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
#include <cassert>
#include "utils.hpp"

const std::vector<std::string> units = {
	"zero", 
	"jeden", 
	"dwa", 
	"trzy", 
	"cztery", 
	"pięć", 
	"sześć", 
	"siedem", 
	"osiem", 
	"dziewięć"
	};
const std::vector<std::string> specialTens = {
	"", 
	"jedenaście", 
	"dwanaście", 
	"trzynaście", 
	"czternaście", 
	"piętnaście", 
	"szesnaście", 
	"siedemnaście", 
	"osiemnaście", 
	"dziewiętnaście"
	};
const std::vector<std::string> tens = {
	"", 
	"dziesięć", 
	"dwadzieścia", 
	"trzydzieści", 
	"czterydzieści", 
	"pięćdziesiąt", 
	"sześćdziesiąt", 
	"siedemdziesiąt", 
	"osiemdziesiąt", 
	"dziewięćdziesiąt"
	};
const std::vector<std::string> hundreds = {
	"", 
	"sto", 
	"dwieście", 
	"trzysta", 
	"czterysta", 
	"pięćset", 
	"sześćset", 
	"siedemset", 
	"osiemset", 
	"dziewięćset"
	};

// zwraca max trzy cyfry z segmentu liczby, czyli jeden xxx z xxx,xxx,xxx
std::string literalsegment(size_t seg) {
	std::string ret = "";
	int s = (seg % 1000) / 100;
	if (s != 0) {
		ret += hundreds[s];
		if ((seg % 100) > 0) ret += " ";
	}
	if (int dj = (seg % 100); dj >= 11 && dj <= 19) {
		// specjalne dziesiatki
		dj = dj % 10;
		ret += specialTens[dj];
	} else {
		// normalne dziesiatki
		int d = dj / 10; // dziesiatki
		int j = dj % 10; // jednosci
		if (d != 0) ret += tens[d];
		if (d != 0 && j != 0) ret += " ";
		if (j != 0) ret += units[j];
	}
	return ret;
}

const std::vector<std::vector<std::string>> segments = {
	{"", "", ""},
	{"tysiąc", "tysiące", "tysięcy"},
	{"milion", "miliony", "milionów"},
	{"miliard", "miliardy", "miliardów"},
	{"bilion", "biliony", "bilionów"}
};

auto literalsegments(size_t number) {
	std::vector<std::string> ret = {};
	size_t segment = 0;
	while (number > 0) {
		auto xxx = number % 1000;
		auto s = literalsegment(xxx);
		if (segment > 0) {
			assert(segment < segments.size());
			if (xxx == 1) s += " " + segments[segment][0];
			else if (((xxx % 10) >= 2 && (xxx % 10) <= 4) && !(xxx >= 11 && xxx <= 19)) s += " " + segments[segment][1];
			else s += " " + segments[segment][2];
		}
		ret.push_back(s);
		number /= 1000;
		segment++;
	}
	return ret;
}

int main(int argc, const char** argv) {
	std::vector<size_t> testcases = {};
	for (size_t i = 0; i < 4; i++) {
		testcases.push_back(random<size_t>(100000000000000, 999999999999999));
	}
	std::sort(testcases.begin(), testcases.end(), std::less<>());
	for (const auto& i : testcases) {
		std::cout << i << ": ";
		const auto ls = literalsegments(i);
		for (auto iter = ls.rbegin(); iter != ls.rend(); iter++) {
			std::cout << *iter << ' ';
		}
		std::cout << std::endl;
	}
}