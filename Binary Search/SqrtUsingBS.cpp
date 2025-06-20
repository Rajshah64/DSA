#include<iostream>

using namespace std;

int sqrtBS(int n ) {
	int low = 1;
	int high = n;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long val = (mid * mid);
		if (val > n) {
			
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		
	}
	return high;
}


int main() {
	int n = 36;
	cout << "the sqrt of the given number(to the nearest integer) is: " << int(sqrt(n)) << endl;
	return 0;
}