#include<iostream>
#include<vector>

using namespace std;

int SearchInsertPosition(vector<int>& a, int target) {
	return lower_bound(a.begin(), a.end(), target) - a.begin();
}

int Floor(vector<int>& a,int n, int target) {
	int low = 0;
	int high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = (low+high) / 2;
		if (target == a[mid]) { return mid; }
		else if (target > a[mid]) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}

int Ceil(vector<int>& a, int n, int target) {
	//a[mid]>=target
	int low = 0;
	int high = n - 1;
	int ans = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (target == a[mid]) { return mid; }
		else if (target > a[mid]) { low = mid + 1; }
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	return ans;
}

int main() {
	vector<int> a = {10,20,30,40,50};
	int floor = Floor(a, 5, 25);
	int ceil = Ceil(a, 5, 25);
	cout << floor << " and " << ceil << endl;
	return 0;
}




// This is a classic example of applying the result. This is a lower bound question and we had to do nothing but understand the question
//The question was
//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//You must write an algorithm with O(log n) runtime complexity.
