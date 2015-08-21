#include <vector>
#include <iostream>
using namespace std;

struct Item {
	int weight;
	int value;
	Item(int w, int v) : weight(w), value(v) {}
};

class ZOKSolution {
public:
	/* 0-1背包 版本1
	* Time Complexity  O(N*V)
	* Space Complexity O(N*V)
	* 状态转移方程：f(i,v) = max{ f(i-1,v), f(i-1,v-c[i])+w[i] }
	*/
	int ZeroOneKnapsack(vector<Item> &items, int volume) {
		int n = items.size();
		int v = volume;
		vector<vector<int>> dp(n+1, vector<int>(v+1, 0));

		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=v; j++)
			{
				dp[i][j] = dp[i-1][j];
				if (j>=items[i-1].weight)
				{
					int tmp = dp[i-1][j-items[i-1].weight]+items[i-1].value;
					dp[i][j] = max(dp[i][j], tmp);
				}
			}
		}
		printStatus(dp);
		outPut(items, dp);
		return dp[n][v];
	}

	/* 0-1背包 版本2
	* Time Complexity  O(N*V)
	* Space Complexity O(V)
	* 状态转移方程：f(v) = max{ f(v), f(v-c[i])+w[i] }
	*/
	int ZeroOneKnapsack2(vector<Item> &items, int volume) {
		int n = items.size();
		int v = volume;
		vector<int> dp(v+1, 0);

		for (int i=1; i<=n; i++)
		{
			for (int j=v; j>=items[i-1].weight; j--)
			{
				int tmp = dp[j-items[i-1].weight]+items[i-1].value;
				dp[j] = max(dp[j], tmp);
			}
		}
		
		cout << dp[v] << endl;
		return dp[v];
	}

	/* 0-1背包(恰好满包) 版本3
	* Time Complexity  O(N*V)
	* Space Complexity O(V)
	* 状态转移方程：f(v) = max{ f(v), f(v-c[i])+w[i] }
	*/

	//在01背包中，有时问到“恰好装满背包”时的最大价值，与不要求装满背包的区别就是在初始化的时候，其实对于没有要求必须装满背包的情况下，初始化最大价值都为0，是不存在非法状态的，所有的都是合法状态，因为可以什么都不装，这个解就是0，但是如果要求恰好装满，则必须区别初始化，除了f[0]=0,其他的f[1…v]均设为-∞或者一个比较大的负数来表示该状态是非法的。
	//这样的初始化能够保证，如果子问题的状态是合法的（恰好装满），那么才能得到合法的状态；如果子问题状态是非法的，则当前问题的状态依然非法，即不存在恰好装满的情况。
	int ZeroOneKnapsack3(vector<Item> &items, int volume) {
		int n = items.size();
		int v = volume;
		vector<int> dp(v+1, 0);

		for (int i=1; i<=v; i++)
		{
			dp[i] = -100;
		}

		for (int i=1; i<=n; i++)
		{
			for (int j=v; j>=items[i-1].weight; j--)
			{
				int tmp = dp[j-items[i-1].weight]+items[i-1].value;
				dp[j] = max(dp[j], tmp);
			}
			
			//for (int j=0; j<=v; j++)
			//{
			//	cout << dp[j] << " ";
			//}
			//cout << endl;
		}
		return dp[v];
	}

	void outPut(vector<Item> &items, vector<vector<int>>& dp) {
		int n = dp.size();
		if(n<1) return ;
		int v = dp[0].size();
		int i = n-1;
		int j = v-1;
		while(i>0) {
			if(j>=items[i-1].weight && dp[i][j]==dp[i-1][j-items[i-1].weight]+items[i-1].value) {
				cout << i << " ";
				j = j-items[i-1].weight;
			}
			i--;
		}
	}

	void printStatus(vector<vector<int>>& dp) {
		int n = dp.size();
		if (n<1) return ;
		int m = dp[0].size();
		for (int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
	}
};