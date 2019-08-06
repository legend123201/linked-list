#include <iostream>
#include <string>
using namespace std;

void swap(string &a, string &b)
{
	string t;
	a = t;
	a = b;
	b = t;
}

string IntToString(int& a)
{
	string result;
	while (a != 0) {
		result += a % 10 + '0';
		a /= 10;
	}
	for (int i = 0; i < result.length() / 2; i++)
	{
		swap(result[i], result[result.length()-1-i]);
	}
	return result;
}

int main()
{
//	int a = 1234;
//	cout << IntToString(a);
}
