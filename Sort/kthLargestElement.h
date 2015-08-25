#include <vector>
using namespace std;

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(k>n) return -1;
        return findKElement(nums, n-k, 0, n-1);
    }
    
    int findKElement(vector<int> &nums, int k, int left, int right) {
        if(left>=right) return nums[left];
        int m = partition(nums, left, right);
        if(m==k) return nums[k];
        if(m<k) findKElement(nums, k, m+1, right);
        else findKElement(nums, k, left, m-1);
    }
    
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        swap(nums, left, right);
        int index = left;
        for(int i=left; i<right; i++) {
            if(nums[i]<=pivot) 
                swap(nums, i, index++);
        }
        swap(nums, index, right);
        return index;
    }
    
    int swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
