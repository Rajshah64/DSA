//#include<bits/c++.h>
#include <iostream>
#include<math.h>
using namespace std;

void ptn1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void ptn2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void ptn3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i ; j++) {
            cout << j<<" ";
        }
        cout << endl;
    }
}

void ptn4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void ptn5(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout <<"* ";
        }
        cout << endl;
    }
}

void ptn5v2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n ; j >= i; j--) {
            cout << "* ";
        }
        cout << endl;
    }
}

void ptn6(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j<<" ";
        }
        cout << endl;
    }
}

void ptn7(int n) {
    for (int i = 0; i < n; i++) {
        //space
        for (int j = n; j >= i; j--) {
            cout << " ";
        }
        //start pattern
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        //star pattern
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void ptn8(int n) {
    for (int i = 0; i < n; i++) {
        //space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        //star pattern
        for (int j = n; j > i; j--) {
            cout << "*";
        }
        //star pattern
        for (int j = n-1; j > i; j--) {
            cout << "*";
        }
        cout << endl;
    }
}


void ptn9(int n) {
    for (int i = 0; i < n; i++) {
        //space
        for (int j = n-1; j > i; j--) {
            cout << " ";
        }
        //start pattern
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        //star pattern
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        //space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        //star pattern
        for (int j = n; j > i; j--) {
            cout << "*";
        }
        //star pattern
        for (int j = n - 1; j > i; j--) {
            cout << "*";
        }
        cout << endl;
    }
}

void ptn10(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i <= (n-1); i++) { 
        for (int j = 1; j <= (n-i); j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void ptn11(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    cout << "1 ";
                }
                else {
                    cout << "0 ";
                }
            }
            else {
                if (j % 2 == 0) {
                    cout << "0 ";
                }
                else {
                    cout << "1 ";
                }
            }
        }
        cout << endl;
    }
}

void ptn12(int n) {
    for (int i = 1; i <= n; i++) {
        //pattern
        for (int j = 1; j <= i; j++) {
            cout << j<<" ";
        }
        //space 
        for (int k = (2*n)-(2*i); k >=1; k--) {
            cout << "  ";
        }
        //star pattern
        for (int j = 1; j <= i; j++) {
            cout << i-j+1<< " ";
        }
        cout << endl;
    }
}

void ptn13(int n) {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << k++ << " ";
        }
        cout << endl;
    }
}

void ptn14(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char(64+j) << " ";
        }
        cout << endl;
    }
}

// complete rest of the patterns in your free time I think you have got the understanding of how to do it but dont become over confident.

//did not know in first attempt
void ptn22(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int bottom = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << (n - min(min(top, down), min(bottom, right)))<<" ";

        }
        cout << endl;
    }
}


int main()
{   
    int n;
    cout << "Enter the length: ";
    cin >> n;
    ptn22(n);
    //for (int i = 0; i < n; i++) {
    //    int t;
    //    cin >> t;
    //    print2(t);

    //}



    return 0;
}
