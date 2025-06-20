#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
	int low = 1;
	int high= *max_element(nums.begin(), nums.end());
	cout << low << endl << high << endl;
	int ans =INT_MAX;
	int sum = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		sum = 0;
		for (int i = 0; i < nums.size();i++) {
			sum+=((nums[i] + mid - 1) / mid);
		}
		cout << sum << endl;
		if (sum > threshold) {
			low = mid + 1;
		}
		else{
			if (mid < ans) { ans = mid; }
			high = mid - 1;
		}
	}
	return ans;

}
int main(){
	vector<int> num = { 2,3,5,7,11 };
	cout << "The smallest value is: " << smallestDivisor(num,11) << endl;
	return 0;
}