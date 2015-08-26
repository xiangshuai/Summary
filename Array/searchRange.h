#include <vector>
using namespace std;

class SRSolution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ret(2, -1);
        int n = A.size();
        if(n<1) return ret;
        int left = 0;
        int right = n-1;
        while(left<=right) {
            int mid = (left+right)/2;
            if(A[mid]==target) {
                int low = mid;
                int upper = mid;
                while(low>0 && A[low-1]==target) low--;
                while(upper<n-1 && A[upper+1]==target) upper++;
                ret[0] = low;
                ret[1] = upper;
                return ret;
            }
			else if(A[mid]<target) left = mid+1;
			else right = mid-1;
        }
        return ret;
    }

public:
	vector<int> searchRangeAd(vector<int> &A, int target) {
		// write your code here
		vector<int> ret(2, -1);
		int n = A.size();
		if(n<1) return ret;
		int left = 0;
		int right = n-1;

		// low
		while(left<right-1) {
			int mid = (left+right)/2;
			if(A[mid]==target) {
				right = mid;
			}
			else if(A[mid]<target) left = mid;
			else right = mid;
		}
		if(A[left]==target) ret[0] = left;
		else if(A[right]==target) ret[0] = right;

		//upper
		left = 0;
		right = n-1;
		while(left<right-1) {
			int mid = (left+right)/2;
			if(A[mid]==target) {
				left = mid;
			}
			else if(A[mid]<target) left = mid;
			else right = mid;
		}
		if(A[right]==target) ret[1] = right;
		else if(A[left]==target) ret[1] = left;

		return ret;
	}
};
