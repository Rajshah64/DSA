#include <iostream>
#include<string>

using namespace std;

string removeOuterParentheses(string s) {
	string res="";
	char a;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		a = s[i];
		if (a == '(') {
			if (count > 0) {
				res += a;
			}
			count++;
		}
		else {
			count--;
			if (count > 0) {
				res += a;
			}
		}
	}
	return res;


}

int main() {
	string s = "(()())(())";
	cout << "the output is: " << removeOuterParentheses(s) << endl;
	return 0;
}