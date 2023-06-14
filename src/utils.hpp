#pragma once

#include <random>
#include <type_traits>

static std::default_random_engine random_engine(std::random_device{}());

template<typename T>
T random(T min, T max) {
	using dist = std::conditional_t<
		std::is_integral<int>::value,
		std::uniform_int_distribution<T>,
		std::uniform_real_distribution<T>
		>;
	return dist(min, max)(random_engine);
}