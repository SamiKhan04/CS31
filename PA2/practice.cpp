#include <iostream>

using namespace std;

int main () {
    // cout << "hi";
    // cout << "hi";
	    int side;

	    cout << "Enter a number: ";
	    cin >> side;

	    for (int i = 0; i < side; i++)
	    {
		for (int j = i; j >= 0; j--)
		{
		    cout << "#";
		}
		cout << "\n";
	    }
	
}