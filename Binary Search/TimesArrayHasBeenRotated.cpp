#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rotations(vector<int>& a) {
	int low = 0;
	int high = a.size() - 1;
	int pos = 10000;
	int temp = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[low] <= a[high]) {
			if (a[low] < pos) {
				temp = low;
				pos = a[low];
			}
			break;
		}
		if (a[low] <= a[mid]) {
			if (a[low] < pos) {
				temp = low;
				pos = a[low];
			}
			low = mid + 1;
		}
		else {
			if (a[mid] < pos) {
				temp = mid;
				pos = a[mid];
			}
			high = mid -1;
		}
	}
	return pos;
}

int main() {
	vector<int> a = { 5,1,2,3,4 };
	cout << "the answer is: " << rotations(a) << endl;
	return 0;
}