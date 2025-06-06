#include <iostream>

using namespace std;


int main()
{
    int a[5] = { 3, 2, 1, 5, 2 };
    int max = a[0];
    for (int i = 0; i <= 4; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    cout << "the largest element is : " << max;
}
