
#include <iostream>
#include <utility>  // for std::pair
#include <vector>
using namespace std;

pair<int,int> largest(int a[], int n) {
    int largest = a[0];
    int slargest = -1;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] > largest) {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > slargest) {
            slargest = a[i];
        }
    }
    return {largest,slargest};
}

int main()
{
    int a[6] = { 1,5,7,6,3,4 };
    pair<int, int> result = largest(a, 6);
    cout << "the largest element is: " << result.first << endl << "the second largest element is: " << result.second << endl;
}
