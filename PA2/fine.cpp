#include <iostream>
#include <string>

using namespace std;

const int TIER1 = 60;
const int TIER2 = 90;

const double FINE1 = .1111;
const double FINE2 = .153;
const double FINE3 = .18;
const double FINE4 = .21;

int main() {
       string identification;
       double overstated_amt;
       string location;
       double fine;

       cout << "Identification: " ;
       getline(cin, identification);

       if (identification == "") {
        cout << "You must enter a property identification.";
        return 1;
       }

       cout << "Overstated amount (in millions): ";
       cin >> overstated_amt;
       cin.ignore(10000, '\n');
       
       if (overstated_amt <= 0) {
        cout << "The overstated amount must be positive.";
        return 1;
       }
       
       cout << "Location: ";
       getline(cin, location);

       if (location == "") {
        cout << "You must enter a location.";
        return 1;
       }

       if (overstated_amt >= TIER1) {
              fine = TIER1 * FINE1;
              overstated_amt = overstated_amt - TIER1;
       }
       else {
              fine = overstated_amt * FINE1;
              overstated_amt = 0;
       }
       if (overstated_amt >= TIER2) {
              if (location == "florida" || location == "new york") {
                     fine = fine + TIER2 * FINE3;
                     overstated_amt = overstated_amt - TIER2;
              }
              else {
                     fine = fine + TIER2 * FINE2;
                     overstated_amt = overstated_amt - TIER2;
              }
       }

       if (overstated_amt > TIER1) {
              if (location == "florida" || location == "new york") {
                     fine = fine + overstated_amt * FINE3;
                     overstated_amt = 0;
              }
              else {
                     fine = fine + overstated_amt * FINE2;
                     overstated_amt = 0;
              }
       }

       if (overstated_amt > 0) {
              fine = fine + overstated_amt * FINE4;
       }

       cout << "---" << endl;
       cout << "The fine for " << identification << " is $" << fine << " million.";
}