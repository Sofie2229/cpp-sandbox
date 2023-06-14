#pragma once

#include <vector>
#include <string>
#include <cassert>

namespace numberbuilder {

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

const std::vector<std::vector<std::string>> segments = {
	{"", "", ""},
	{"tysiąc", "tysiące", "tysięcy"},
	{"milion", "miliony", "milionów"},
	{"miliard", "miliardy", "miliardów"},
	{"bilion", "biliony", "bilionów"},
	{"biliard", "biliardy", "biliardów"},
	{"trylion", "tryliony", "trylionów"},
	{"tryliard", "tryliardy", "tryliardów"},
};

std::string literalsegment(size_t seg);

// array posiadajacy segmenty juz z tysiac, milion, itd.
std::vector<std::string> literalsegmentssuffixed(size_t number);

// builder do numerkuf
std::string numberbuilder(size_t number);

} // namespace numberbuilder