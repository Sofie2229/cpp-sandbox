#include "numberbuilder.hpp"
#include <string>

namespace numberbuilder {

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

std::vector<std::string> literalsegmentssuffixed(size_t number) {
	// if (number == 0);
	std::vector<std::string> ret = {};
	size_t segment = 0;
	while (number > 0) {
		auto xxx = number % 1000;
		auto s = literalsegment(xxx);
		if (segment > 0) {
			assert(segment < segments.size());
			if (xxx == 1) {
				ret.push_back(segments[segment][0]);
			}
			else {
				if (((xxx % 10) >= 2 && (xxx % 10) <= 4) &&
					!((xxx % 100) >= 11 && (xxx % 100) <= 19)) {
					s += " " + segments[segment][1];
				} else {
					s += " " + segments[segment][2];
				}
				ret.push_back(s);
			}
		} else {
			ret.push_back(s);
		}
		number /= 1000;
		segment++;
	}
	return ret;
}

std::string numberbuilder(size_t number) {
	auto ls = literalsegmentssuffixed(number);
	std::string ret = "";
	if (number != 0) {
		for (auto iter = ls.rbegin(); iter != ls.rend() ; iter++) {
			ret += *iter + " ";
		}
		ret.pop_back();
	} else {
		return units[0];
	}
	return ret;
}

}