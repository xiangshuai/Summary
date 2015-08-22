#include <string>
#include <vector>
using namespace std;

// 最长公共子序列（Longest-Common-Subsequence，LCS）
//  dp[i][j] = 0  如果i=0或j=0
//	dp[i][j] = dp[i-1][j-1] + 1  如果X[i-1] = Y[i-1]
//  dp[i][j] = max{ dp[i-1][j], dp[i][j-1] }  如果X[i-1] != Y[i-1]
class LCSeqSolution {
public:
	int longestCommonSubseq(string p, string q) {
		int n = p.size();
		int m = q.size();
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				if (p[i-1]==q[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		output(dp, p, q);
		cout << "\n";
		return dp[n][m];
	}

	void output(vector<vector<int>> &dp, string p, string q) {
		int n = dp.size();
		if (n<1) return ;
		int m = dp[0].size();
		int i = n-1;
		int j = m-1;
		vector<char> out;
		while(i && j) {
			if (p[i-1]==q[j-1] && dp[i][j]==dp[i-1][j-1]+1)
			{
				out.push_back(p[i-1]);
				i--;
				j--;
			}
			else if(p[i-1]!=q[j-1] && dp[i][j]==dp[i][j-1]) j--;
			else i--;
		}

		for (int i=0; i<out.size(); i++)
			cout << out[i] << " ";
	}


	// 滚动数组
	int longestCommonSubseq2(string p, string q) {
		int n = p.size();
		int m = q.size();
		vector<vector<int>> dp(2, vector<int>(m+1, 0));
		int k;
		for (int i=1; i<=n; i++)
		{
			k = i & 1;
			for (int j=1; j<=m; j++)
			{
				if (p[i-1]==q[j-1])
					dp[k][j] = dp[k^1][j-1]+1;
				else
					dp[k][j] = max(dp[k^1][j], dp[k][j-1]);
			}
		}
		return dp[k][m];
	}

};