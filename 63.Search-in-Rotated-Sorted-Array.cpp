/*
当数组元素有重复时，修改findPivot函数里>改成>=即可，其余与62题基本一样
*/
class Solution {
public:
    /**
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    int findPivot(vector<int> A){
        int L = 0, R = A.size()-1;
        while(L < R-1){
            int mid = L + (R-L)/2;
            if(A[mid] >= A[L]){
                L = mid;
            }else{
                R = mid;
            }
        }
        if(A[L] > A[R]) return R;
        else return 0;
    }
    int binarySearch(vector<int> A, int L, int R, int target){
        while(L < R){
            int mid = L + (R-L)/2;
            if(A[mid] > target){
                R = mid-1;
            }else if(A[mid] < target){
                L = mid+1;
            }else{
                return mid;
            }
        }
        if(A[L] == target) return L;
        else return -1;
    }
    bool search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return false;
        if(A.size() == 1) return A[0]==target?true:false;
        if(A.size() == 2) return (A[0]==target || A[1]==target)?true:false;
        int pivot = findPivot(A);
        int index = -1;
        if(pivot == 0){
            // no rotation
            index = binarySearch(A, 0, A.size()-1, target);
        }else if(target >= A[0]){
            index = binarySearch(A, 0, pivot-1, target);
        }else{
            index = binarySearch(A, pivot, A.size()-1, target);
        }
        return index==-1?false:true;
    }
};