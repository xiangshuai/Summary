#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 最长重复子串（可重叠） Longest Repeat Substring
class LRSSolution {
public:
	// 基本算法 O(n^3)
	int repeatLen(char* p, char* q) {
		int len = 0;
		while (*p && *q && *p++==*q++)
			len++;
		return len;
	}

	int LRS_base(string str) {
		int n = str.size();
		int maxLen = 0;
		int maxId = 0;
		for (int i=0; i<n; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				int len = repeatLen(&str[i], &str[j]);
				if (len>maxLen)
				{
					maxLen = len;
					maxId = i;
				}
			}
		}
		cout << str.substr(maxId, maxLen) << endl;
		return maxLen;
	}

	// 后缀数组
public:
	int LRS_suffix(string str) {
		int n = str.size();
		int maxLen = 0;
		char *lrstr;
		vector<char*> suffix(n, NULL);
		for (int i=0; i<n; i++)
			suffix[i] = &str[i];

		sort(suffix.begin(), suffix.end(), pstrcmp);

		for (int i=0; i<n-1; i++)
		{
			int len = repeatLen(suffix[i], suffix[i+1]);
			if (len>maxLen)
			{
				maxLen = len;
				lrstr = suffix[i];
			}
		}
		cout << string(lrstr, lrstr+maxLen) << endl;
		return maxLen;
	}

	static bool pstrcmp(const char* p, const char* q) {
		int t = strcmp(p, q);
		return t<=0 ? true : false;
	}
};