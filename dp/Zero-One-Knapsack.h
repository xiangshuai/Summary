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
	/* 0-1���� �汾1
	* Time Complexity  O(N*V)
	* Space Complexity O(N*V)
	* ״̬ת�Ʒ��̣�f(i,v) = max{ f(i-1,v), f(i-1,v-c[i])+w[i] }
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

	/* 0-1���� �汾2
	* Time Complexity  O(N*V)
	* Space Complexity O(V)
	* ״̬ת�Ʒ��̣�f(v) = max{ f(v), f(v-c[i])+w[i] }
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

	/* 0-1����(ǡ������) �汾3
	* Time Complexity  O(N*V)
	* Space Complexity O(V)
	* ״̬ת�Ʒ��̣�f(v) = max{ f(v), f(v-c[i])+w[i] }
	*/

	//��01�����У���ʱ�ʵ���ǡ��װ��������ʱ������ֵ���벻Ҫ��װ����������������ڳ�ʼ����ʱ����ʵ����û��Ҫ�����װ������������£���ʼ������ֵ��Ϊ0���ǲ����ڷǷ�״̬�ģ����еĶ��ǺϷ�״̬����Ϊ����ʲô����װ����������0���������Ҫ��ǡ��װ��������������ʼ��������f[0]=0,������f[1��v]����Ϊ-�޻���һ���Ƚϴ�ĸ�������ʾ��״̬�ǷǷ��ġ�
	//�����ĳ�ʼ���ܹ���֤������������״̬�ǺϷ��ģ�ǡ��װ��������ô���ܵõ��Ϸ���״̬�����������״̬�ǷǷ��ģ���ǰ�����״̬��Ȼ�Ƿ�����������ǡ��װ���������
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