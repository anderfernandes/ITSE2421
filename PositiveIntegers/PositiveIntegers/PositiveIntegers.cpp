#include <iostream>
using namespace std;

int main ()
{
	cout << "Here is a list of the first 10 positive, even integers: " << endl;
	for (int n = 1; n <=10; n++)
	{
		if (n % 2 == 0)
		cout << n << endl;
	}
	return 0;
}