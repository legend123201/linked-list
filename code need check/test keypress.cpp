#include <iostream> 
#include <conio.h> 
using namespace std; 

int main()
{
	int keypress = 0;
	while(keypress != 'o')
	{
		keypress = _getch();
		cout << keypress << endl;
	}
	return 0;
}
