#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "intersection-of-two-arrays/Solution.h"

using namespace std::string_literals;
using namespace std;

// start with a pointer to the first char, another to the last, and move them towards each other until they meet.
static void twoPointerTraversal(std::string const& value)
{
	auto start = value.begin();
	auto end = value.rbegin();

	// compares the mid char, use end.base() -1 to exclude mid char
	while (start < end.base())
	{
		std::cout << *start << " " << *end << '\n';

		start++;
		end++;
	}
}

static bool isPalindrome(const int value)
{
	if (value < 0)
	{
		return false;
	}

	auto reversed = 0L;
	auto original = value;

	while (original > 0)
	{
		reversed = reversed * 10 + original % 10;
		original /= 10;
	}

	return reversed == value;
}

int main()
{
	// twoPointerTraversal("abcba"s);

	//auto pal = isPalindrome(12332);
	//std::cout << std::boolalpha << "Is palindrome: " << pal << '\n';

	intersection_of_two_arrays::Solution i;
	auto v1 = std::vector<int>{ 1, 2, 3 };
	auto v2 = std::vector<int>{ 1, 2, 4 };
	auto common = intersection_of_two_arrays::Solution::intersection(v1, v2);
}
