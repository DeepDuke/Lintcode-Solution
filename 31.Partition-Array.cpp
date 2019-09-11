/*
Type: two pointers
*/
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if(nums.size() == 0) return 0;
        vector<int> A;
        A.push_back(k);
        A.insert(A.end(), nums.begin(), nums.end());
        // quickSort partition
        int i = 0, j = A.size()-1;
        int temp = A[0];
        while(i < j){
            while(i < j && A[j] >= temp) j--;
            A[i] = A[j];
            while(i < j && A[i] < temp) i++;
            A[j] = A[i];
        }
        A[i] = temp;
        return i;
    }
};