/*
Type: two pointers
先把原数组从小到大排序，依次访问，先固定一个数， 看剩下的数中能不能找到两个和是这个数的相反数，
即利用twoSum的方法。
*/
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > twoSum(vector<int> numbers, int L, int R, int sum){
        //sort(numbers.begin()+L, numbers.begin()+R+1);
        int i = L, j = R;
        vector<vector<int> > ans;
        while(i < j){
            if(numbers[i] + numbers[j] < sum){
                i++;
            }else if (numbers[i] + numbers[j] > sum){
                j--;
            }else{
                vector<int> temp = {numbers[i], numbers[j], -numbers[i]-numbers[j]};
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
                
                i++;
                j--;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        sort(numbers.begin(), numbers.end());
        vector<vector<int> > ans;
        set<vector<int> > st;
        for(int i = 0; i < numbers.size()-1; i++){
            vector<vector<int> > vec = twoSum(numbers, i+1, numbers.size()-1, -numbers[i]);
            for(auto ele: vec){
                st.insert(ele);
            }
        }
        for(auto ele: st){
            ans.push_back(ele);
        }
        return ans;
    }
};