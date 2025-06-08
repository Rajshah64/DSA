#include<iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &a, int n , int target) {
	int low = 0;
	int high = n - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (target == a[mid]) { return mid; }
		else if (target < a[mid]) { high = mid - 1; }
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}


int BinarySearchR(vector<int>& a, int low, int high, int target) {
	
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (target == a[mid]) { return mid; }
	else if (target < a[mid]) { BinarySearchR(a, low, mid - 1, target); }
	else
	{
		BinarySearchR(a, mid + 1, high, target);
	}


}

int main() {
	vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
	int target, result;
	cout << "What is the target? ";
	cin >> target;
	result = BinarySearchR(nums, 0,9,target);
	cout << "\nThe target is(0 means not found): " << result+1  << endl;
	return 0;
}