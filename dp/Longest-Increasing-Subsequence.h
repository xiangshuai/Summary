#include <vector>
#include <iostream>
using namespace std;


// 最长递增子序列
class LISeqSolution {
public:
	int longestIncreSubseq(vector<int>& nums) {
		int lis = 0;	/* LIS 长度 */
		int n = nums.size();
		vector<int> dp(n, 1);	/* dp[i]记录到[0,i]数组的LIS */

		for (int i=1; i<n; i++)
		{
			for (int j=0; j<i; j++)
			{
				if (nums[j]<=nums[i] && dp[j]+1 > dp[i])
					dp[i] = dp[j]+1;
				lis = max(lis, dp[i]);				
			}
		}
		//outPut(nums, dp, n-1, lis);
		output(nums, dp, lis);
		cout << "\n";
		return lis;
	}

	void output(vector<int>& nums, vector<int>& dp, int lis) {
		//vector<int> out;
		//int n = dp.size();
		//int k = 0;
		//for (int i=0; i<n; i++)
		//{
		//	if(lis==dp[i]) {
		//		k = i;
		//		break;
		//	}
		//}

		//while(k && lis) {
		//	out.push_back(nums[k]);
		//	for (int i=0; i<k; i++)
		//	{
		//		if (nums[k]>=nums[i] && dp[k]==dp[i]+1)
		//		{
		//			k = i;
		//			lis--;
		//		}
		//	}
		//}

		reverse(out.begin(), out.end());
		for (int i=0; i<out.size(); i++)
			cout << out[i] << " ";
	}

	void outPut(vector<int>& nums, vector<int>& dp, int index, int lis) {
		if (index<0 || lis==0)
		{
			return ;
		}

		bool isLIS = false;
		if (dp[index]==lis)
		{
			lis--;
			isLIS = true;
		}
		outPut(nums, dp, index-1, lis);
		if (isLIS)
		{
			cout << nums[index] << " ";
		}
	}
};