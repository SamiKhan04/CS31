#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

/* return 0 if is successful (i.e., neither of the following problems occurs)
return 1 if any input word portion (defined below) is longer than the maximum line length*/

const int MAX_LINE_LENGTH = 600;
// const int SPLIT_LENGTH = 100;

int wordLength(char line[], int n, int pos, int lineLength) {
    int count = 0;
    for (int i = pos; i < n; ++i) {
        if(isspace(line[i])) {
            return count;
        }
        if (line[i] == '-') {
            count++;
            return count;
        }
        count++;
    }

    if (count > lineLength) {
        return 1;
    }
    return count;
}

int lineLengthy(char line[], int n, int pos, int lineLength) {
    int length = 0;
    bool hasSMTH = false;
    for (int i = pos; i < n; ++i) {
        if (!isspace(line[i]) && line[i] != '\n') {
            hasSMTH = true;
        }
        if (line[i] == '\n') {
            if (length != 0) {
                length--;
                if (!hasSMTH) {
                    return 0;
                }
                return length;
            }
        }
        length++;
    }
    if (!hasSMTH) {
        return 0;
    }
    return length;
}

void write(ostream& out, char line[], int n, int lineLength) {

    bool para = false;
    bool paragraph = false;
    bool firstAt = false;
    bool prevSpace = false;
    int wordStart = 0;
    int lineSplit = 0;
    bool specialSpace = false;
    int spaces = 0;
    bool splitted = false;
    // int wordLength = 0;
    ofstream outfile("result.txt");
    if (!outfile) {
        cerr << "Error: Could not create result.txt!" << endl;
        return;
    }
    int j;
    for (j = 0; j < n; ++j) {
        if (!isspace(line[j])) {
            break;
        }
    }

    if (j == n) {
        return;
    }

    for (int i = 0; i < n; ++i) {

         int wordL = wordLength(line, n, i, lineLength);
         int lengthL = lineLengthy(line, n, i, lineLength);

        // if (lengthL == 0) {
        //     return;
        // }

        if (isprint(line[i]) && i+1 < n && line[i+1] == '\n' && lineSplit <= lineLength) {
            line[i+1] = ' ';
            // outfile << line[i];
            // continue;
        }

    //    if (i + 1 > n) {
    //         if (isspace(line[i])) {
    //             break;
    //         }
    //         break;
    //    }

        // if (i+1 < n && isspace(line[i+1] && i + 2 < n && line[i+2] == '\n')) {
        //     line[i] == '\n';
        //     outfile << line[i];
        //     continue;
        // }


        // if (isspace(line[i]) && i+1 < n && line[lengthL+2] == '\n') {
        //     line[i] = '\n';
        //     // outfile << line[i];
        //     continue;
        // }
        // if (isspace(line[i]) && isprint(line[i-1]) && lineLength+wordL <= lineSplit) {
        //     // if (lineSplit >= lineLength) {
        //     //     outfile << '\n';
        //     //     lineSplit = 0;
        //     // }
        //     // line[wordL+1] = '\n';
        //     // outfile << line[wordL+1];
        //     continue;
        // }

        if (line[i] == '.' || line[i] == '?' || line[i] == '!' || line[i] == ':' && i + 1 < n && line[i+1] != '\n' && line[i+1] != '\0')
        {
            specialSpace = true;

        }

        // if (spaces > 0 && isspace(line[i-1]) && line[i] != ' ') {
        //     spaces = 0;
        //     line[i-1] = line[i];
        //     continue;
        // }

        if (prevSpace && isspace(line[i])) {
            continue;
        }

        else if (isspace(line[i]) && paragraph) {
            paragraph = false;
            continue;
        }

       
          if (wordStart != 0) {
            if (lineSplit+wordL > lineLength) {
                lineSplit = 0;
                line[wordStart-1] = '\n';
                outfile << line[wordStart-1];
                wordStart = 0;
                wordL = 0;
                outfile << line[i];
                prevSpace = false;
                continue;
            }
        }

        // else if (lineSplit == lineLength) {
        //     if (isspace(line[i+lineSplit])) {
        //         line[i+lineSplit] = '\n';
        //         outfile << line[i+lineSplit];
        //         lineSplit = 0;
        //         wordStart = 0;
        //         // prevSpace = false;
        //         continue;
        //     }

       
        // if (lineSplit == lineLength) {
        //     outfile << '\n';
        //     lineSplit = 0;
        //     cout << "i: " << i << ", line[i]: " << line[i] << ", lineSplit: " << lineSplit << ", wordStart: " << wordStart << ", wordLength: " << wordL << endl;
        //     continue;
        // }

        if (firstAt && line[i] == '@' && para) {
            outfile << '\n';
            outfile << '\n';
            prevSpace = false;
            para = false;
            paragraph = true;
            lineSplit = 0;
            cout << "i: " << i << ", line[i]: " << line[i] << ", lineSplit: " << lineSplit << ", wordStart: " << wordStart << ", wordLength: " << wordL << endl;
            continue;
        }

        // if (paragraph && isspace(line[i])) {
        //     line[i] = line[i+1];
        //     i--;
        //     paragraph = false;
        //     // continue;
        // }

        if (line[i] == '@') {
            if (i != 0 && isspace(line[i-1])) {
            firstAt = true;
            }
            cout << "i: " << i << ", line[i]: " << line[i] << ", lineSplit: " << lineSplit << ", wordStart: " << wordStart << ", wordLength: " << wordL << endl;
            continue;
        }

        if (line[i] == 'P') {
            para = true;
            cout << "i: " << i << ", line[i]: " << line[i] << ", lineSplit: " << lineSplit << ", wordStart: " << wordStart << ", wordLength: " << wordL << endl;
            continue;
        }

        // if (prevSpace && isspace(line[i])) {
        //     cout << "i: " << i << ", line[i]: " << line[i] << ", lineSplit: " << lineSplit << ", wordStart: " << wordStart << ", wordLength: " << wordL << endl;
        //     continue;
        // }

        if (prevSpace && !isspace(line[i])) {
            prevSpace = false;
            wordStart = i;
        }

        if (isspace(line[i])) {
            prevSpace = true;
            wordL = 0;
        }

        // if (!isspace(line[i])) {
        //     wordLength++;
        // }

        
        outfile << line[i];
        if (specialSpace) {
            if (!isspace(line[i]) && i + 1 < n && line[i+1] != '\0' && line[i+1] != '\n' && !isspace(line[i+1])) {
            outfile << ' ';
            spaces++;
            lineSplit++;
            }
            // if (i + 2 < n && line[i+2] != '\0' && line[i+2] != '\n') {
            //     outfile << ' ';
            //     spaces++;
            // }
            specialSpace = false;
        }

        
        lineSplit++;
        cout << "i: " << i << ", line[i]: " << line[i] << ", lineSplit: " << lineSplit << ", wordStart: " << wordStart << ", wordLength: " << wordL << endl;
    }
}

int render(int lineLength, istream& inf, ostream& outf) {
    if (lineLength < 1) {
        return 2;
    }

    // if (lineLength > 250)
    // {
    //     return 2;
    // }


    char line[MAX_LINE_LENGTH];
    // int split[SPLIT_LENGTH];
    char c;
    // int countLines = 0;
    // cout << "hi" << endl;
    // int countWords = 0;
    int chs = 0;
    while(inf.get(c))
    {
        // cout << c << endl;
        
        // if (isspace(c)) {
        //     continue;
        // }
        if (chs < MAX_LINE_LENGTH + 1) {
            line[chs] = c;
            chs++;
        }
    }
        line[chs] = '\0';
    int n;

    for (n = 0; n < chs; ++n) {
        cout << line[n];
        if (line[n] == '\n') {
            cout << endl;
        }
    }

    write(outf, line, n, lineLength);

    // cout << countWords << endl;
    return 0;
}

int main()
{
    const int MAX_FILENAME_LENGTH = 100;
    for (;;)
    {
        cout << "Enter input file name (or q to quit): ";
        char filename[MAX_FILENAME_LENGTH];
        cin.getline(filename, MAX_FILENAME_LENGTH);
        if (strcmp(filename, "q") == 0)
            break;
        ifstream infile(filename);
        if (!infile)
        {
            cerr << "Cannot open " << filename << "!" << endl;
            continue;
        }
        cout << "Enter maximum line length: ";
        int len;
        cin >> len;
        cin.ignore(10000, '\n');
        int returnCode = render(len, infile, cout);
        cout << "Return code is " << returnCode << endl;
    }
}

// #include <iostream>
// #include <sstream>
// #include <streambuf>
// #include <string>
// #include <cassert>
// using namespace std;

// class LimitOutputStreambuf : public streambuf
// {
//     public:
//         LimitOutputStreambuf(streambuf* sb, size_t lim)
//          : real_streambuf(sb), limit(lim)
//         {
//                 static char dummy;
//                 setp(&dummy, &dummy);
//         }
//     private:
//         streambuf* real_streambuf;
//         size_t limit;

//         int overflow(int c)
//         {
//                 if (limit == 0)
//                         return traits_type::eof();
//                 limit--;
//                 return real_streambuf->sputc(c);
//         }
// };

// class StreambufSwitcher
// {
//     public:
// 	StreambufSwitcher(ios& dest, streambuf* sb,
// 					ios::iostate exceptions = ios::goodbit)
// 	 : dest_stream(dest), oldsb(dest.rdbuf(sb)), oldex(dest.exceptions())
// 	{ dest_stream.exceptions(exceptions); }
// 	StreambufSwitcher(ios& dest, ios& src)
// 	 : StreambufSwitcher(dest, src.rdbuf(), src.exceptions())
// 	{}
// 	~StreambufSwitcher()
// 	{ dest_stream.rdbuf(oldsb); dest_stream.exceptions(oldex); }
//     private:
// 	ios& dest_stream;
// 	streambuf* oldsb;
// 	ios::iostate oldex;
// };

// string repeat(size_t n, string s)
// {
// 	string result;
// 	result.reserve(n * s.size());
// 	for ( ; n > 0; n--)
// 		result += s;
// 	return result;
// }

// int render(int lineLength, istream& inf, ostream& outf);

// void testone(int n)
// {
// 	istringstream iss;
// 	StreambufSwitcher ssi(cin, iss.rdbuf());

// 	ostringstream oss;
// 	LimitOutputStreambuf lob(oss.rdbuf(), 1000*1000+10);
// 	StreambufSwitcher sso(cout, &lob);

// 	LimitOutputStreambuf lob2(cerr.rdbuf(), 0);
// 	StreambufSwitcher sse(cerr, &lob2);

// 	switch (n)
// 	{
//                                  default: {
// 		cout << "Bad argument" << endl;
//                         } break; case  1: {
// 		iss.str("hello there\n\nthis is a test\n");
// 		assert(render(0, iss, oss) == 2);
//                         } break; case  2: {
// 		iss.str("hello there\n\nthis is a test\n");
// 		render(0, iss, oss);
// 		assert(oss.str().empty());
//                         } break; case  3: {
// 		iss.str("hello there\n\nthis is a test\n");
// 		ostringstream oss2;
// 		StreambufSwitcher sso2(cout, oss2.rdbuf());
// 		render(11, iss, oss);
// 		assert(oss2.str().empty());
//                         } break; case  4: {
// 		iss.str("hello there\n\nthis is a test\n");
// 		istringstream iss2("Z Y X W V\n");
// 		StreambufSwitcher ssi2(cin, iss2.rdbuf());
//                 render(11, iss, oss);
// 		string s = oss.str();
// 		assert(s.find_first_of("ZYXWV") == string::npos  &&
// 		s.find("hello") != string::npos);
//                         } break; case  5: {
// 		iss.str("");
// 		assert(render(10, iss, oss) == 0  &&  oss.str().empty());
//                         } break; case  6: {
// 		iss.str("     \n\n    \n\n");
// 		assert(render(10, iss, oss) == 0  &&  oss.str().empty());
//                         } break; case  7: {
// 		iss.str("abcdefghi abcdefghijk\n");
// 		assert(render(10, iss, oss) == 1);
//                         } break; case  8: {
// 		iss.str("abcdefghi abcdefghijk abc abc abc abc abc abc abc\n");
// 		assert(render(10, iss, oss) == 1);
//                         } break; case  9: {
// 		iss.str("abcdefghi abcdefghij\n");
// 		assert(render(10, iss, oss) == 0);
//                         } break; case 10: {
// 		iss.str("abcdefghi abcdefgh-ijk\n");
// 		assert(render(10, iss, oss) == 0);
//                         } break; case 11: {
// 		iss.str("hello there\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello there") != string::npos);
//                         } break; case 12: {
// 		iss.str("hello       there\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello there") != string::npos);
//                         } break; case 13: {
// 		iss.str("hello. there? bye\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello.  there?  bye") != string::npos);
//                         } break; case 14: {
// 		iss.str("hello! there: bye\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello!  there:  bye") != string::npos);
//                         } break; case 15: {
// 		iss.str("hello? there\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello?  there") != string::npos);
//                         } break; case 16: {
// 		iss.str("hello. abcdefghi\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("hello.\na") != string::npos);
//                         } break; case 17: {
// 		iss.str("hello.there\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello.there") != string::npos);
//                         } break; case 18: {
// 		iss.str("hello'3*%there\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello'3*%there") != string::npos);
//                         } break; case 19: {
// 		iss.str("hello-there\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello-there") != string::npos);
//                         } break; case 20: {
// 		iss.str("hello\nthere\n");
// 		render(30, iss, oss);
// 		assert(oss.str().find("hello there") != string::npos);
//                         } break; case 21: {
// 		iss.str("abcdefg hijkl\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("abcdefg\n") != string::npos);
//                         } break; case 22: {
// 		iss.str("abcdefg hijkl\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("\nhijkl") != string::npos);
//                         } break; case 23: {
// 		iss.str("hellohello abcdef ghi jklmnop\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("\nabcdef ghi\n") != string::npos);
//                         } break; case 24: {
// 		iss.str("hellohello abcdef ghi jklmnop qrst\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("\nqrst") != string::npos);
//                         } break; case 25: {
// 		iss.str("abcdefg x-ray\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("x-\nray") != string::npos);
//                         } break; case 26: {
// 		iss.str("abcdefg abc xyz-pq-rs\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("xyz-\npq-rs") != string::npos);
//                         } break; case 27: {
// 		iss.str("abcdefg abc x-yz-pqr\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("x-yz-\npqr") != string::npos);
//                         } break; case 28: {
// 		iss.str("abcdefg abc xyz----yz\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("xyz---\n-yz") != string::npos);
//                         } break; case 29: {
// 		iss.str("abcdefg -xyz\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find(" -\nxyz") != string::npos);
//                         } break; case 30: {
// 		iss.str("abcdefg abc abcdefghijklmnopqrstuvw\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("\nabcdefghij\nklmnopqrst\nuvw") != string::npos);
//                         } break; case 31: {
// 		iss.str("abc\n");
// 		render(10, iss, oss);
// 		assert(oss.str() == "abc\n");
//                         } break; case 32: {
// 		iss.str("abc @P@ def\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("abc\n\ndef") != string::npos);
//                         } break; case 33: {
// 		iss.str("abc @P@  @P@ def\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("abc\n\ndef") != string::npos);
//                         } break; case 34: {
// 		iss.str("abc\n@P@\ndef\n");
// 		render(10, iss, oss);
// 		assert(oss.str().find("abc\n\ndef") != string::npos);
//                         } break; case 35: {
// 		iss.str("@P@ abc @P@ def\n");
// 		render(10, iss, oss);
// 		string result("abc\n\ndef\n");
// 		assert(oss.str() == result  ||
// 				result.compare(0, 8, oss.str()) == 0);
//                         } break; case 36: {
// 		iss.str("abc @P@ def\n@P@\n");
// 		render(10, iss, oss);
// 		assert(oss.str() == "abc\n\ndef\n");
//                         } break; case 37: {
// 		iss.str("@P@ @P@ @P@ abc @P@ def @P@ @P@ @P@\n");
// 		render(30, iss, oss);
// 		assert(oss.str() == "abc\n\ndef\n");
//                         } break; case 38: {
// 		string s25 = "abcdefghijklmnopqrstuvwxy";
// 		string s178(repeat(7, s25) + "abc");
// 		iss.str(s178 + "\n");
// 		assert(render(179, iss, oss) == 0);
// 		string result(s178 + "\n");
// 		assert(oss.str() == result  ||
// 				result.compare(0, 178, oss.str()) == 0);
//                         } break; case 39: {
// 		string s24 = "abcdefghijklmnopqrstuvwx";
// 		string s123(repeat(5, s24) + "abc");
// 		iss.str(s123 + "\n" + s123 + "\n");
// 		assert(render(249, iss, oss) == 0);
// 		string result(s123 + " " + s123 + "\n");
// 		assert(oss.str() == result  ||
// 				result.compare(0, 247, oss.str()) == 0);
//                         } break; case 40: {
// 		string s10 = "a\na\na\na\na\na\na\na\na\na\n";
// 		string s100(repeat(10, s10));
// 		string s20000(repeat(200, s100)); // For some people, 200 was 20000
// 		iss.str(s20000);
// 		render(2, iss, oss);
// 		assert(oss.str() == s20000  ||
// 				s20000.compare(0, 19999, oss.str()) == 0);
//                         } break; case 41: {
// 		string s25 = "abcdefghijklmnopqrstuvwxy";
// 		string s178(repeat(7, s25) + "abc");
// 		iss.str(repeat(11, s178 + "\n"));
// 		int n = render(2000, iss, oss);
// 		string result(repeat(11-1, s178 + " ") + s178 + "\n");
// 		assert((n == 2  &&  oss.str().empty())  ||  (n == 0  &&
// 				(oss.str() == result  ||
// 				 result.compare(0, 11*(178+1)-1, oss.str()) == 0)));
//                         } break; case 42: {
// 		string s25 = "abcdefghijklmnopqrstuvwxy";
// 		string s178(repeat(7, s25) + "abc");
// 		iss.str(repeat(550, s178 + "\n"));
// 		assert(render(99000, iss, oss) == 0);
// 		string result(repeat(550-1, s178 + " ") + s178 + "\n");
// 		assert(oss.str() == result  ||
// 				 result.compare(0, 550*(178+1)-1, oss.str()) == 0);
//                         } break;
// 	}
// }

// int main()
// {

// 	cout << "Enter test number: ";
// 	int n;
// 	cin >> n;
// 	testone(n);
// 	cout << "Passed" << endl;
//     // 3, 6...
// }