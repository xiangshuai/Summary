#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		if(n<1) return ret;
		string item;
		dfs(n, n, item, ret);
		return ret;
	}

	//void dfs(int left, int right, string item, vector<string>& ret) {
	//	if(right==0) {
	//		ret.push_back(item);
	//		return ;
	//	}

	//	if(left>0) {
	//		dfs(left-1, right, item+'(', ret);
	//	}
	//	if(right>left) {
	//		dfs(left, right-1, item+')', ret);
	//	}
	//}

	void dfs(int left, int right, string& item, vector<string>& ret) {
		if(right==0) {
			ret.push_back(item);
			return ;
		}

		if(left>0) {
			item.push_back('(');
			dfs(left-1, right, item, ret);
			item.pop_back();
		}
		if(right>left) {
			item.push_back(')');
			dfs(left, right-1, item, ret);
			item.pop_back();
		}
	}
};


