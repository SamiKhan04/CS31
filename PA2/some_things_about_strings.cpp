#include <iostream>
#include <string>

using namespace std;

int main() {
        // cout << "How many place settings would you like to buy? ";
        // int numberOfSettings;
        // cin >> numberOfSettings;

        // cout << "In which style? ";
        // string style;
        // getline(cin, style);
        
        cout << "How many place settings would you like to buy? ";
        int numberOfSettings;
        cin >> numberOfSettings;
        cin.ignore(10000, '\n');       // this is new
        cout << numberOfSettings;

        // cout << "In which style? ";
        // string style;
        // getline(cin, style);
}