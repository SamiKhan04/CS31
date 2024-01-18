// Financial fraud fine computation

#include <iostream>
#include <string>
using namespace std;

int main()
{
      // Get and validate identification

    cout << "Identification: ";
    string identification;
    getline(cin, identification);
    if (identification == "")
    {
        cout << "---\nYou must enter a property identification." << endl;
        return 1;
    }

      // Get and validate overstated amount

    cout << "Overstated amount (in millions): ";
    double overstatedAmount;
    cin >> overstatedAmount;
    cin.ignore(10000, '\n');
    if (overstatedAmount <= 0)
    {
        cout << "---\nThe overstated amount must be positive." << endl;
        return 1;
    }

      // Get and validate location

    cout << "Location: ";
    string location;
    getline(cin, location);
    if (location == "")
    {
        cout << "---\nYou must enter a location." << endl;
        return 1;
    }

      // Overstated amount tier thresholds and fine rates

    const double TIER2_THRESHOLD    = 60;
    const double TIER3_THRESHOLD    = 150;
    const double TIER1_RATE         = 0.1111;
    const double TIER2_RATE_USUAL   = 0.153;
    const double TIER2_RATE_SPECIAL = 0.18;
    const double TIER3_RATE         = 0.21;

      // Compute fine

    double fine;

    if (overstatedAmount <= TIER2_THRESHOLD)
        fine = overstatedAmount * TIER1_RATE;
    else
    {
          // Compute fine for the portion of overstatedAmount in first tier

        fine = TIER2_THRESHOLD * TIER1_RATE;

          // Determine rate for second tier

        double rate_2 = TIER2_RATE_USUAL;
        if (location == "florida"  ||  location == "new york")
            rate_2 = TIER2_RATE_SPECIAL;

        if (overstatedAmount <= TIER3_THRESHOLD)
        {
              // Add fine for remainder of overstatedAmount (in 2nd tier)

            fine += (overstatedAmount - TIER2_THRESHOLD) * rate_2;
        }
        else
        {
              // Add fine for the portion of overstatedAmount in 2nd tier
              // and the remainder of overstatedAmount (in 3rd tier)

            fine += (TIER3_THRESHOLD - TIER2_THRESHOLD) * rate_2 +
                          (overstatedAmount - TIER3_THRESHOLD) * TIER3_RATE;
        }   
    }

      // Print fine

    cout.setf(ios::fixed);
    cout.precision(3);
    cout << "---\n" << "The fine for " << identification << " is $" << fine
         << " million." << endl;
}