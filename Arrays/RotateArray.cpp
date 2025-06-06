#include<iostream>
#include<vector>

using namespace std;

void RotateArrayByOne(vector<int> &a,int d) {
	int size = a.size();
	int temp = a[0];
	for (int i = 1; i <size; i++) {
		a[i - 1] = a[i];
	}
	a[size-1] = temp;
}

void RotateByDPlacesLeft(vector<int>& a, int d) {
	int size = a.size();
	d = d % size;
	vector<int> temp;
	for (int i = 0; i < d; i++) {
		temp.push_back(a[i]);
	}
	for (int i = d; i < size; i++) {		
			a[i - d] = a[i];
	}
	for (int i = 0; i < temp.size(); ++i) {
		a[a.size() - temp.size() + i] = temp[i];
	}
}

void RotateByDPlacesRight(vector<int>& a, int d) {
	int size = a.size();
	d = d % size;
	d = size - d;
	//the logic is same as left shift 
	//so array after left shift = array after (size-left shift)
	vector<int> temp;
	for (int i = 0; i < d; i++) {
		temp.push_back(a[i]);
	}
	for (int i = d; i < size; i++) {
		a[i - d] = a[i];
	}
	for (int i = 0; i < temp.size(); ++i) {
		a[a.size() - temp.size() + i] = temp[i];
	}
}


int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);

	//RotateArrayByOne(a, 1);
	RotateByDPlacesRight(a, 2);
	//cout << (1 - 2) % 6;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i]<<" ";
	}
	return 0;
}