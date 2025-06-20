#include<iostream>
#include<cmath>
using namespace std;

int nthroot(int n , int m) {
	int low = 1;
	int high = m;
	//int ans = -1;
	cout << low << high << endl;
	while (low <= high) {
		//cout << low << endl<< high << endl;
		int mid = (low + high) / 2;
		//cout << mid << endl;
		long long  val = pow(mid, n);
		//cout << val << endl;
		if (val == m) {
			return mid;
		}
		else if(val>m){
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}

int main() {
	int n = 16;
	//ut << pow(16, 2) << endl;
	cout << " the nth root of the given number is: " << nthroot(4,n) << endl;
	return 0;
}