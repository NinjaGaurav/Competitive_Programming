#include <iostream>
using namespace std;
int main() {
	// your code goes here
	int t, c;
	long int n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (c = 0;n > 0;)
		{
			
			if (n >= 100)
			{
				n -= 100;
				c++;
			}
			else if (n >= 50)
			{
				n -= 50;
				c++;
			}
			else if (n >= 10)
			{
				n -= 10;
				c++;
			}
			else if (n >= 5)
			{
				n -= 5;
				c++;
			}
			else if (n >= 2)
			{
				n -= 2;
				c++;
			}
			else if (n >= 1)
			{
				n -= 1;
				c++;
			}
		}
		cout << c << endl;
	}
	return 0;
}
