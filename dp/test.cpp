#include "Longest-Increasing-Subsequence.h"
#include "Longest-Common-Substring.h"
#include "Longest-Common-Subsequence.h"
#include "Zero-One-Knapsack.h"
#include <iostream>
using namespace std;

int main() {
	int a[] = {35, 36, 39, 3, 15, 27, 6, 28 };
	vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));

	LISeqSolution sl;
	cout <<  sl.longestIncreSubseq(nums) << endl;


	//// 0-1背包
	//vector<Item> in;
	//in.push_back(Item(3, 4));
	//in.push_back(Item(4, 6));
	//in.push_back(Item(5, 7));
	//ZOKSolution zoksl;
	//zoksl.ZeroOneKnapsack(in, 10);
	
	//// 最长公共子序列
	//LCSeqSolution sl;
	//string a = "aaabafascasdfeafsdfacea";
	//string b = "fadbaacadgfacafafdsf";
	//cout << sl.longestCommonSubseq(a, b) << endl;
	//cout << sl.longestCommonSubseq2(a, b) << endl;

	//// 最长公共字串
	//string a = "aaabaa";
	//string b = "fadbaacadgafdsf";
	//LCStrSolution sl;
	//sl.longestCommonSubstr(a, b);
	////sl.LCStr_suffix(a, b);
	//sl.longestCommonSubstr2(a, b);
}