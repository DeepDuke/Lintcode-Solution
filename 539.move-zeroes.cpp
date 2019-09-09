class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int swap_pos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(swap_pos < i) swap_pos = i+1;  // find non-zero after i
                for(; swap_pos < nums.size(); swap_pos++){
                    if(nums[swap_pos] != 0){
                        swap(nums[i], nums[swap_pos]);
                        break;
                    }
                }
            }
        }
    }
};