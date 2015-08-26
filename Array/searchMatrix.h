#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int cnt = 0;
        int n = matrix.size();
        if(n<1) return cnt;
        int m = matrix[0].size();
        int row=0;
        for(; row<n; row++) {
            if(matrix[row][0]<=target && matrix[row][m-1]>=target) break;
        }
        if(row==n) return 0;
        
        int left = 0;
        int right = m-1;
        int mid = 0;
        while(left<=right) {
            mid = (left+right)/2;
            if(matrix[row][mid]==target) {
                cnt++;
                break;
            }
            else if(matrix[row][mid]<target) left = mid+1;
            else right = mid-1;
        }
        
        int p = matrix[row][mid]==target ? mid : left;
        for(int i=0; i<p; i++) {
            int top = row;
            int bottom = n-1;
            while(top<=bottom) {
                int cmid = (top+bottom)/2;
                if(matrix[cmid][i]==target) {
                    cnt++;
                    break;
                }
                else if(matrix[cmid][i]<target) top = cmid+1;
                else bottom = cmid-1;
            }
        }
        
        return cnt;
    }
};

