#include<iostream>
#include<vector>

using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void merge(vector<int>& a, int low,int mid, int high) {
	int left = low;
	int right = mid + 1;
	vector<int> res;
	while (left <= mid && right <= high) {
		if (a[left] <= a[right]) {
			res.push_back(a[left]);
			left++;
		}
		else {
			res.push_back(a[right]);
			right++;
		}

	}
	while (left <= mid) {
		res.push_back(a[left]);
		left++;
	}
	while (right <= high) {
		res.push_back(a[right]);
		right++;
	}
	for (int i = low; i <=high; i++)
	{
		a[i] = res[i - low]; 
	}
}


int partitionFunction(vector<int>& a, int low,  int high) {
	int i = low;
	int j = high;
	int pivot = a[low];
	while (i < j) {
		while (a[i] <= pivot && i <= high-1) {
			i++;
		}
		while (a[j] > pivot && j >= low+1) {
			j--;
		}
		if (i < j) {
			swap(a[i], a[j]);
		}

	}
	swap(a[low], a[j]);
	return j;
}

vector<int> SelectionSort(vector<int>& a) {
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < a.size(); j++) {
			if (a[j] < a[i]) {
				swap(a[i], a[j]);
			}
		}

	}
	return a;
}

vector<int> BubbleSort(vector<int>& a) {
	for (int i = a.size(); i >0; i--)
	{
		for (int j = 0; j < i-1; j++) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
			}
		}

	}
	return a;
}

vector<int> InsertionSort(vector<int>& a) {
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j < i; j++) {
			int k = j + 1;
			if (a[i - j] < a[i - k]) { swap(a[i - j], a[i - k]); }
		}
	}
	return a;
}

//Divde and Merge
void MergeSort(vector<int>& a,int low,int high) {
	//time complexity of Nlog(N).
	if (low == high) { return ; }
	int mid = (low + high)/2;
	MergeSort(a, low, mid);
	MergeSort(a, mid + 1, high);
	merge(a, low, mid, high);
}

void QuickSort(vector<int>& a,int low, int high) {
	//time complexity is Nlog(N).
	if (low < high) {
		int partition = partitionFunction(a, low, high);
		QuickSort(a, low, partition - 1);
		QuickSort(a, partition + 1, high);
	}
}


int main() {
	vector<int> a = {13,46,24,52,20,9 };
	cout << "the sorted array is: " << endl;
	QuickSort(a,0,a.size()-1);
	for (int i = 0; i < a.size(); i++)
	{	
		cout << a[i]<<" ";
	}
	cout << endl;
	return 0;
}