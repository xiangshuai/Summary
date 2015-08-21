#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 最长公共子串（Longest-Common-Substring，LCS）
class LCStrSolution {
public:
	// DP:
	// X[i] == Y[j]，dp[i][j] = dp[i-1][j-1] + 1
	// X[i] != Y[j]，dp[i][j] = 0
	int longestCommonSubstr(string p, string q) {
		int maxLen = 0;
		int maxId = 0;
		int n = p.size();
		int m = q.size();
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				if(p[i-1]==q[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = 0;
				
				//maxLen = max(maxLen, dp[i][j]);
				if (dp[i][j]>maxLen)
				{
					maxLen = dp[i][j];
					maxId = i-maxLen;
				}
			}
		}

		cout << p.substr(maxId, maxLen);
		return maxLen;
	}
};