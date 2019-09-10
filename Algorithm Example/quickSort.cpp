#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector<int> nums = {3, 2, 4, 1, 9, 8, 7, 5, 6, 0};
vector<int> nums = {35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55};

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
		int pivot_pos = partition(A, L, R);
		quickSort(A, L, pivot_pos-1);
		quickSort(A, pivot_pos+1, R);
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
	// quickSort
	quickSort(nums, 0, nums.size()-1);
	// print after sort
	cout << "nums after sort:\n";
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	return 0;
}
