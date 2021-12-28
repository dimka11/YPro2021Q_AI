// Stones.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#include <math.h>

void split_double(double d, int precision, int& integer_part, long int& fractional_part)
{
	integer_part = (int)d;
	fractional_part = fmod(round(d * 1000.0), 1000.0);
}

struct two {
	int integer_part;
	long int fractional_part;
};

//int main() {
//	for (int i = -10; i <= 10; i++) {
//		std::cout << cos(sin(i)) << '\n';
//	}
//}

int fractional_part_as_int(long double number, long int number_of_decimal_places) {
	long double dummy;
	long double frac = modfl(number, &dummy);
	return round(frac * pow(10, number_of_decimal_places));
}

int main() {
	std:unordered_set<unsigned long int> results = std::unordered_set<unsigned long int>();
	int n;
	std::cin >> n;
	std::set<int> input = std::set<int>();

	// Copy values from std::cin to set
	std::copy_n(std::istream_iterator<int>(std::cin), n, std::inserter(input, input.begin()));


	for (auto item : input) {
		int item_ = abs(item);
		//long double res = cos(sin(item));
		//long int frac = fractional_part_as_int(res, 9);

		results.insert(item_);
	}
	std::cout << results.size();

	//auto hash = [](const two& p) { return p.fractional_part; };
	//auto equal = [](const two& p1, const two& p2) { return (p1.integer_part == p2.integer_part) && (p1.fractional_part == p2.fractional_part); };
	//std::unordered_set<two, decltype(hash), decltype(equal)> results_(n,hash, equal);

	//for (auto item : input) {
	//	int ip;
	//	long int fp;
	//	split_double(item, 9, ip, fp);
	//	results_.insert(two{ ip, fp });
	//}

	//std::cout << results_.size();
}





//int main() {
//    std::string a, b, c;
//    cin >> a >> b;
//
//    int count = 0;
//
//    std:set<char> used_chars = std::set<char>();
//
//    for (char& c : a) {
//        const bool is_in = used_chars.find(c) != used_chars.end();
//        if (is_in) continue;
//        used_chars.insert(c);
//        for (char& ic : b) {
//            if (ic == c) {
//                count++;
//            }
//        }
//    }
//
//    cout << count;
//}