#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void greet(ostream& outf) {
    outf << "Hello" << endl;
}

int countLines(istream& inf) {
    int lineCount = 0;
    string line;
    while (getline(inf, line)) {
        lineCount++;
    }
    cout << line << endl;
    return lineCount;
}


int main() {

    ifstream infile("data.txt");
    if (!infile) {
        cerr << "Error: Cannot open data.txt!" << endl;
    }

    int fileLines = countLines(infile);
    cout << "data.txt has " << fileLines << " lines." << endl;
    cout << "Type lines, then ctrl-Z (Windows) or ctrl-D (macOS/Linux):" << endl;
    int keyboardLines = countLines(cin);
    cout << "You typed " << keyboardLines << " lines." << endl;


    // ofstream outfile("greeting.txt");
    // if (!outfile) {
    //     cerr << "Error: Cannot create greeting.txt!" << endl;
        //return 1;
    // }
    
    // greet(outfile);
    // greet(cout);

    // ofstream outfile("results.txt");
    // // if (!outfile) {
    // //     cerr << "Error: Cannot create results.txt!" << endl;
    // //     return -1;
    // // }

    // // outfile << "This will be written to the file" << endl;
    // // outfile << "2 + 2 = " << 2+2 << endl;
    // // outfile << "yao" << endl;
    
    // ifstream infile("data.txt");
    // if (!infile) {
    //     cerr << "Error: Cannot open data.txt!" << endl; 
    // }

    // int k;
    // infile >> k;
    // infile.ignore(10000, '\n');
   
    // string s;
    // infile >> s;
    // getline(infile, s);
    
    // char c;
    // infile.get(c);

    // //useful for Project 5
    // //processes input char by char
    // const int MAX = 40;
    // char line[40];
    // // infile.getline(line, MAX);

    // while (infile.getline(line, MAX)) {
    //     //process line
    // }

    // char c;
    // while (infile.get(c)) {
    //     //... process c
    // }

}