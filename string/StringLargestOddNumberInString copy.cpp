#include<iostream>
#include<string>

using namespace std;

string largestOddNumber(string num) {
	char a;
	for (int i = 0; i < num.length(); i++)
	{
		a = num[num.length()-i-1];
		if (a - '0' % 2 == 1) {
			return num.substr(0, i + 1);
		}
	}
	return "";
}

int main() {
	string s="35427";
	//cout << s[4] << endl;
	cout << " the largest odd integer is: " << largestOddNumber(s) << endl;
	return 0;
}