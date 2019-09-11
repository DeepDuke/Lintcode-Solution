/*
Type: heap sort
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        priority_queue<int> q;
        for(auto ele: nums){
            q.push(ele);
        }
        for(int i = 0; i < n-1; i++){
            q.pop();
        }
        return q.top();
    }
};