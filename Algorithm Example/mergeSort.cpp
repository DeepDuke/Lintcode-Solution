#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nums = {3, 2, 4, 1, 9, 8, 7, 5, 6, 0};

void merge(vector<int> &A, int L1, int R1, int L2, int R2){
	// merge two sorted array
	int i = L1;
	int j = L2;
	int index = 0;
	vector<int> B(A.size());
	while(i <= R1 && j <= R2){
		if(A[i] < A[j]){
			B[index++] = A[i++];
		}else{
			B[index++] = A[j++];
		}
	}
	while(i <= R1) B[index++] = A[i++];
	while(j <= R2) B[index++] = A[j++];
	for(int k = 0; k < index; k++){
		A[L1+k] = B[k];
	}
}
void mergeSort1(vector<int> &A, int L, int R){
	if(L < R){
		int mid = (L + R) / 2;
		mergeSort1(A, L, mid);
		mergeSort1(A, mid+1, R);
		merge(A, L, mid, mid+1, R);
	}
}
void mergeSort2(vector<int> &A){
	for(int step = 2; step/2 < A.size(); step += 2){
		for(int i = 0; i < A.size(); i += step){  // for every big group
		    int mid = i + step/2 - 1;
		    if(mid+1 < A.size()){
		    	// exist right interval, and merge two small groups into a big group
		    	int R = i+step-1;
		    	if(R > A.size()-1)
		    	    R = A.size()-1;
		    	merge(A, i, mid, mid+1, R);
			}
		}
	}
}
int main()
{
	// print before sort
	cout << "nums before sort:\n";
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << endl;
	// merge sort
    // mergeSort1(nums, 0, nums.size()-1);
    mergeSort2(nums);	
	// print
	cout << "nums after sort:\n";
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	return 0;
} 
