class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        vector<long long> nums(k+1, 0);
        nums[0]=1;
        int index3 = 0, index5 = 0, index7=0;
        for(int i=1; i<k+1; i++) {
            nums[i] = min(nums[index3]*3, min(nums[index5]*5, nums[index7]*7));
            while(nums[index3]*3<=nums[i]) index3++;
            while(nums[index5]*5<=nums[i]) index5++;
            while(nums[index7]*7<=nums[i]) index7++;
        }
        return nums[k];
    }
};
