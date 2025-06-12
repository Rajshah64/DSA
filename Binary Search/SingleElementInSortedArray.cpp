#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int element(vector<int>& a) {
	int low = 1;
	int high = a.size()  - 2;
	if (a[0] != a[1]) { return a[0]; }
	if (a[a.size() - 1] != a[high]) { return a[a.size() - 1]; }
	while (low <= high) {
		int mid = (low+high) / 2;
		if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1]) {
			return a[mid];
		}
		if (mid%2==0 && a[mid] == a[mid - 1]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;

		}
	}
	return -1;

}

int main() {
	vector<int> a = {1,1,2,3,3,4,4,8,8};
	cout << "the single element in the array is: " << element(a) << endl;
	return 0;
}