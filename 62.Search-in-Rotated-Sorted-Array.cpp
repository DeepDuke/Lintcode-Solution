class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int findPivot(vector<int> A){
        int L = 0, R = A.size()-1;
        while(L < R-1){
            int mid = L + (R-L)/2;
            if(A[mid] > A[L]){
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
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return -1;
        if(A.size() == 1) return target == A[0]?0:-1;
        if(A.size() == 2){
            if(A[0] == target) return 0;
            if(A[1] == target) return 1;
        }
        int pivot = findPivot(A);
        cout << "pivot: " << pivot << endl;
        int index = -1;
        if(pivot == 0){
            // no rotation
            index = binarySearch(A, 0, A.size()-1, target);
        }else if(target >= A[0]){
            index = binarySearch(A, 0, pivot-1, target);
        }else{
            index = binarySearch(A, pivot, A.size()-1, target);
        }
        return index;
    }
};