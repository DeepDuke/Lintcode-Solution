/*
Type: two pointers
*/
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void mySort(vector<int> &colors, int color, int &L, int R){
        int slow = L, fast = L;
        while(fast <= R){
            if(colors[fast] == color){
                swap(colors[slow], colors[fast]);
                slow++;
            }
            fast++;
        }
        L = slow;
    }
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int L = 0, R = colors.size()-1;
        for(int i=1; i <= k; i++){
            mySort(colors, i, L, R);
        }
    }
};