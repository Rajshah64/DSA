#include<iostream>
#include <vector>

using namespace std;

int UpperBound(vector<int>& a, int n, int target) {
	//arr[index]>=x to satisfy it as a lower bound
	int low = 0;
	int high = n - 1;
	int ans = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (target >= a[mid]) { low = mid + 1; }
		else
		{
			ans = mid;
			high = mid - 1;
		}

	}
	return ans;

}

int LowerBound(vector<int>& a, int n, int target) {
	//arr[index]>=x to satisfy it as a lower bound
	int low = 0;
	int high = n - 1;
	int ans = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (target == a[mid]) { return mid; }
		else if (target > a[mid]) { low = mid + 1; }
		else
		{
			ans = mid;
			high = mid - 1;
		}

	}
	return ans;

}



int main() {
	vector<int> nums = { 2,4,6,8,10 };
	int target, result;
	cout << "What is the target? ";
	cin >> target;
	result = UpperBound(nums, 5, target);
	cout << "\nthe upper bound is " << upper_bound(nums.begin(), nums.end(), 9) - nums.begin();
	cout << "\nThe upper bound from code is " << result  << endl;
	return 0;
}