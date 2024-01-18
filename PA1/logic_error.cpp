// Code for Project 1
	// Report rice survey results
	
	#include <iostream>
	using namespace std;
	
	int main()
	{
	    int numberSurveyed;
	    int preferBasmati;
	    int preferJasmine;
	
	    cout << "How many people were surveyed? ";
	    cin >> numberSurveyed;
        if (numberSurveyed > INT_MAX) {
            cout << "Wow, way to many people. No way that many people exist.";
            return 1;
        }
	    cout << "How many of them prefer basmati rice over jasmine rice? ";
	    cin >> preferBasmati;
        if (preferBasmati > INT_MAX) {
            cout << "Wow, way to many people. No way that many people exist.";
            return 0;
        }
	    cout << "How many of them prefer jasmine rice over basmati rice? ";
	    cin >> preferJasmine;
        if (preferJasmine > INT_MAX) {
            cout << "Wow, way to many people. No way that many people exist.";
            return 0;
        }
	
	    double pctBasmati = 100.0 * preferBasmati / numberSurveyed;
	    double pctJasmine = 100.0 * preferJasmine / numberSurveyed;

	    cout.setf(ios::fixed);
	    cout.precision(1);
	
	    cout << endl;
	    cout << pctBasmati << "% prefer basmati rice over jasmine rice." << endl;
	    cout << pctJasmine << "% prefer jasmine rice over basmati rice." << endl;

	    if (preferBasmati > preferJasmine)
	        cout << "More people prefer basmati rice over jasmine rice." << endl;
        else if (preferBasmati == preferJasmine) {
            cout << "The amount of people who prefer basmati rice is the same as those who prefer jasmine rice." << endl;
        }
	    else
	        cout << "More people prefer jasmine rice over basmati rice." << endl;
	}