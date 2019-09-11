/*
STL的sort()函数可以过，归并排序过不了，快速排序可以过
*/
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    int partition(vector<int> &A, int L, int R){
        int temp = A[L];
        int i = L;
        int j = R;
        while(i < j){
            while(i < j && A[j] > temp) j--;
            A[i] = A[j];
            while(i < j && A[i] <= temp) i++;
            A[j] = A[i];
        }
        A[i] = temp;
        return i;
    }
    void quickSort(vector<int> &A, int L, int R){
        if(L < R){
            int pos = partition(A, L, R);
            quickSort(A, L, pos-1);
            quickSort(A, pos+1, R);
        }
    }
    void sortIntegers2(vector<int> &A) {
        // write your code here
       //sort(A.begin(),  A.end());
       quickSort(A, 0, A.size()-1);
    }
};