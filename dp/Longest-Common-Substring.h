#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ������Ӵ���Longest-Common-Substring��LCS��
class LCStrSolution {
public:
	// DP:
	// X[i] == Y[j]��dp[i][j] = dp[i-1][j-1] + 1
	// X[i] != Y[j]��dp[i][j] = 0
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

		cout << p.substr(maxId, maxLen) << endl;
		return maxLen;
	}

	int longestCommonSubstr2(string p, string q) {
		int maxLen = 0;
		int maxId = 0;
		int n = p.size();
		int m = q.size();
		vector<int> dp(m+1, 0);

		for (int i=1; i<=n; i++)
		{
			for (int j=m; j>0; j--)
			{
				if(p[i-1]==q[j-1])
					dp[j] = dp[j-1]+1;
				else
					dp[j] = 0;

				//maxLen = max(maxLen, dp[i][j]);
				if (dp[j]>maxLen)
				{
					maxLen = dp[j];
					maxId = i-maxLen;
				}
			}
		}

		cout << p.substr(maxId, maxLen) << endl;
		return maxLen;
	}

public:
	// ��׺����
	// ���ں�׺��������͵���Ѱ��һ���ַ������ظ��Ӵ������ԣ����������ַ���
	// ���Խ������ӵ�һ�����ĳһ���Ӵ�s�����ǵĹ����Ӵ�����sһ���������Ӻ��ַ�����׺�����г�������
	// �����ͽ�������Ӵ�ת����ظ��Ӵ���������

	// ���ҵ������ظ��Ӵ�ʱ����һ������X��Y�Ĺ����Ӵ���Ҳ������X��Y�������ظ��Ӵ�
	// ��������ʱ��������X�������һ�������ַ���#���������Ӻ�ΪX#Y
	// ֻ���ҵ��������ظ��Ӵ�ǡ����һ����#��ǰ�棬�������ظ��Ӵ�����X��Y�Ĺ����Ӵ�
	
	int LCStr_suffix(string p, string q) {
		string str = p + '#' + q;
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

	int repeatLen(char* p, char* q) {
		int len = 0;
		while (*p && *q && *p++==*q++) {
			if (*p=='#' || *q=='#')
				break;
			len++;
		}
		int count = 0;
		while(*p)
		{
			if(*p++ == '#')
			{
				++count;
				break;
			}
		}
		while(*q)
		{
			if(*q++ == '#')
			{
				++count;
				break;
			}
		}
		if(count == 1)
			return len;
		return 0;
	}

	static bool pstrcmp(const char* p, const char* q) {
		int t = strcmp(p, q);
		return t<=0 ? true : false;
	}

};