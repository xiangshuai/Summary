#include "Longest-Repeat-Substring.h"
#include <iostream>
using namespace std;

int main() {
	LRSSolution sl;
	string str = "baaaxxgqafsdfacsdsgaefawfesdfacsdfgaebaaaa";
	sl.LRS_base(str);
	sl.LRS_suffix(str);
}