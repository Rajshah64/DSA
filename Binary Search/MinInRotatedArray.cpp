#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int Min(vector<int>& a) {
	int low = 0;
	int high = a.size() - 1;
	int ans = 10000;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[low] <= a[high]) {
			ans = min(ans, a[low]);
			break;
		}
		//left sorted 
		if (a[low] <= a[mid]) {
			ans = min(ans, a[low]);
			low = mid + 1;
		}
		//right sorted
		else {
			high = mid - 1;
			ans = min(ans, a[mid]);
		}
		
	}
	return ans;
}

int main() {
	vector<int> a = { 3,1,2};
	cout << "the minimum value in the vector is: " << Min(a) << endl;
	return 0;
}




























