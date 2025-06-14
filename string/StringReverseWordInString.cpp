#include<iostream>
#include<cctype>
#include<string>

using namespace std;

string reverseWords(string s) {
	string temp="";
	string res="";
	char a;
	for (int i = 0; i < s.length(); i++)
	{
		//isalnum checks if the character is numeric or alphabet
		a = s[i];
		if (isalnum(a)) {
			temp += a;
		}
		//s.insert(pos,string) inserts the char or string at the given pos
		else {
			if (temp != "") {
				res.insert(0, " ");
				res.insert(0, temp);
				temp = "";
			}
			
		}
		
	}
	if (temp != "") {
		res.insert(0, " ");
		res.insert(0, temp);
	}
	res.pop_back();
	//pop_back removes the last character
	return res;
}
//This is not the best solution. We will get the best solution next time.


int main() {
	string s = "a good   example";
	cout <<  reverseWords(s) << endl;
	return 0;
}