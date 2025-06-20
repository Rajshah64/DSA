#include<iostream>
#include<vector>
//#include<algorithm>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
	int low = 0;
	int high = arr.size()-1;
	while (low<=high) {
		int mid = ( low+high) / 2;
		int missing = arr[mid] - (mid+1);
		if (missing < k) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low + k;
	//return high+1+k;

}

int main() {
	vector<int > num = { 2,3,4,7,11 };
	cout << "the Kth missing element is: " << findKthPositive(num, 5) << endl;
	return 0;
}