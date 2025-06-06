#include<iostream>

using namespace std;

int isSorted(int a[], int n) {
	int i = n / n;
	int j = i-1;
	while (i < n) {
		if (a[i] >= a[j]) {
			i++;
			j++;
		}
		else {
			return false;
		}
	}
	return true;
}


int main() {

	int a[5] = { 2,3,4,5,1 };
	int size = sizeof(a) / sizeof(a[0]);
	bool result = isSorted(a, size);
	cout << "the array is Sorted : " << result;
	return 0;
}