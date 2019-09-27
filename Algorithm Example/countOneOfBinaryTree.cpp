#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printBuma(int n){
	unsigned a = n;
	unsigned cnt = 0; 
	vector<unsigned> vec;
	while(a){
		vec.push_back(a&1);
		a >>= 1;
		if(vec[vec.size()-1] == 1) cnt++;
	}
	for(int i = vec.size()-1; i >= 0; i--){
		cout << vec[i];
	}
}
void myPrint(int n){
	// 输出n的补码, 补码中1的个数 
	unsigned a = n;
	unsigned cnt = 0; 
	vector<unsigned> vec;
	while(a){
		vec.push_back(a&1);
		a >>= 1;
		if(vec[vec.size()-1] == 1) cnt++;
	}
	for(int i = vec.size()-1; i >= 0; i--){
		cout << vec[i];
	}
	cout << "\tnumber of 1:\t" << cnt << endl;
}

class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while(n != 0){
         	cout <<"n:\t";
         	myPrint(n);
         	cout << "n-1:\t";
         	printBuma(n-1);
         	cout << "\n";
             cnt++;
             n = n & (n-1);
         }
         return cnt;
     }
};

int main()
{
	Solution solve;
	cout << solve.NumberOf1(-6) << endl;
	return 0;
} 