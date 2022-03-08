#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));

	CHECK(nospaces(mat(9, 7, '@', '@')) == nospaces("@@@@@@@@@\n"
													"@@@@@@@@@\n"
													"@@@@@@@@@\n"
													"@@@@@@@@@\n"
													"@@@@@@@@@\n"
													"@@@@@@@@@\n"
													"@@@@@@@@@"));

	CHECK(nospaces(mat(1, 11, '*', '-')) == nospaces("*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*"));	

	CHECK(nospaces(mat(5, 1, '#', '*')) == nospaces("#####"));

	CHECK(nospaces(mat(1, 1, '-', '*')) == nospaces("-"));

	CHECK(nospaces(mat(3, 3, '#', '!')) == nospaces("###\n"
													"#!#\n"
													"###"));

	CHECK(nospaces(mat(7, 7, '#', '!')) == nospaces("#######\n"
													"#!!!!!#\n"
													"#!###!#\n"
													"#!#!#!#\n"
													"#!###!#\n"
													"#!!!!!#\n"
													"#######"));

	CHECK(nospaces(mat(3, 7, '#', '!')) == nospaces("###\n"
													"#!#\n"
													"#!#\n"
													"#!#\n"
													"#!#\n"
													"#!#\n"
													"###"));

	CHECK(nospaces(mat(7, 5, '#', '!')) == nospaces("#######\n"
													"#!!!!!#\n"
													"#!###!#\n"
													"#!!!!!#\n"
													"#######"));																							 												 
	/* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(5, 10, '$', '%'));
	CHECK_THROWS(mat(2, 44, '$', '%'));
	CHECK_THROWS(mat(5, 100, '&', '%'));
	CHECK_THROWS(mat(-3, 7, '-', '+'));
    CHECK_THROWS(mat(5, -13, '+', '#'));
    CHECK_THROWS(mat(-1, -99, '$', '#'));
    CHECK_THROWS(mat(231, 0, '*', '%'));
	CHECK_THROWS(mat(230, 0, '#', '%'));
	CHECK_THROWS(mat(29, 10, '*', '%'));
	CHECK_THROWS(mat(-99, 0, '*', '%'));
	
    /* Add more test here */
}


/* Add more test cases here */
