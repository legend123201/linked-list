#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string CharToString(char* c)
{
	int i = 0;
	string result;
	while (c[i] != '\0')
	{
		result += c[i];
		i++;
	}
	return result;
}

int StringToInt(string str)
{
	int result = 0;
	for(int i = 0; i < str.length(); i++)
	{
		result = result * 10 + (int)(str[i]-'0');
	}
	return result;
}

int main()
{
	char b[8];
//	string a = CharToString();
//	cout << b;
	string a = "1234";
	cout << StringToInt(a);
	return 0;
}
