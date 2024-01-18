#include "grid.h"
#include "grid.cpp"
#include <cctype>
#include <iostream>
#include <cassert>
using namespace std;

void plotHorizontalLine(int r, int c, int distance, char ch);
void plotVerticalLine(int r, int c, int distance, char ch);
void plotRectangle(int r, int c, int height, int width, char ch);
bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg);
int performCommands(string commandString, char& plotChar, int& mode, int& badPos);

const int HORIZ = 0;
const int VERT = 1;

const int FG = 0;
const int BG = 1;

int main()
{
    // plotHorizontalLine(1,1,5, '*');
    // plotHorizontalLine(1,28,2, '@');
    // plotHorizontalLine(6,-5,7,'X');
    // const int middleCol = getCols() / 2;
    // setChar(6, middleCol, 'E');
    // setChar(8, middleCol, 'L');
    // setChar(9, middleCol, 'O');
    // setChar(7, middleCol, 'L');
    // setChar(5, middleCol, 'H');
    // if (getChar(6, middleCol) == 'E')
    //     setChar(10, middleCol, '!');
    // draw();
    // setChar(14,8,'*');
    // plotLine(14,8,-3,HORIZ, '@', BG);
    // setSize(20, 15);  // grid has 20 rows, 15 columns
    // if ( ! plotLine(14, 8, 3, HORIZ, '*', FG))   // first call
    //    cout << "1) Plotting failed when it shouldn't have!" << endl;
    // if ( ! plotLine(15, 10, -2, VERT, '@', FG))  // second call
    //    cout << "2) Plotting failed when it shouldn't have!" << endl;
    // if ( ! plotLine(13, 8, 3, HORIZ, '#', BG))   // third call
    //    cout << "3) Plotting failed when it shouldn't have!" << endl;
    // if (plotLine(13, 14, 3, HORIZ, 'X', FG))     // fourth call
    //    cout << "4) Plotting succeeded when it shouldn't have!" << endl;
    // draw();
    // draw();

    // setSize(2, 12);  // 2 rows, 12 columns
    // assert(plotLine(1, 1, 0, HORIZ, 'H', FG));
    // assert(plotLine(1, 2, 0, HORIZ, 'i', FG));
    // assert(plotLine(1, 3, 0, HORIZ, '!', FG));
    // draw();  //  displays  Hi!  in the top row of the grid
    // assert(plotLine(1, 3, 0, HORIZ, ' ', FG));
    // draw();  //  displays  Hi   in the top row of the grid
    // assert(plotLine(1, 1, 10, HORIZ, ' ', BG));
    // draw();  //  displays  Hi   in the top row of the grid
    // assert( ! plotLine(1, 1, 10, HORIZ, '\n', FG));
    // draw();  //  displays  Hi   in the top row of the grid

    // setSize(15, 22);
    // setChar(10, 16, 'X');
    // plotLine(10,15,2,HORIZ, ' ', BG);
    // draw();
    // draw();
    // //  setSize(20, 30);
    // //     for (int r = 3; r <= 9; r += 2)
    // //         plotHorizontalLine(r, 13, 17, '=');
    // //     for (int r = 11; r <= 17; r += 2)
    // //         plotHorizontalLine(r, 1, getCols()-1, '=');
    // //     for (int r = 3; r <= 9; r += 2)
    // //         for (int c = 1; c <= 11; c += 2)
    // //             setChar(r, c, '*');
    // //     for (int r = 4; r <= 8; r += 2)
    // //         for (int c = 2; c <= 10; c += 2)
    // //             setChar(r, c, '*');
    // // plotVerticalLine(1,5,10, '@');
    // // plotRectangle(1,1,10,3, '@');
    // setSize(15, 20);
    // plotLine(1,1,12,HORIZ, '@', FG);

    // setSize(15, 22);
    // setChar(10, 16, 'X');
    // // setChar(1,1, '@');
    // plotLine(10,15,2,HORIZ, ' ', BG);
    // draw();

    // char x = '@';
    // int badPos = 0;
    // int mode = FG;
    // performCommands("B!", x, mode, badPos);
    // draw();

        // setSize(12, 15);
        // char pc = '%';
        // int m = FG;
        // int bad = 999;
        // // performCommands("V2", pc, m, bad);
        // // draw();
        // // performCommands("V2H2Q2", pc, m, bad);
        // // draw();
        // // performCommands("H4V3V-1H-9", pc, m, bad);
        // // draw();
        // assert(plotLine(3, 5, 2, HORIZ, '@', FG));
        // for (int c = 5; c <= 7; c++)
        //     assert(getChar(3, c) == '@');
        // assert(getChar(3, 8) == ' ');
        // clearGrid();
        // // char pc = '%';
        // // int m = FG;
        // // int bad = 999;
        //   // A successful command string should not change bad
        // assert(performCommands("V2", pc, m, bad) == 0  &&  getChar(3, 1) == '%'  &&  bad == 999);
        // assert(performCommands("V2H2Q2", pc, m, bad) == 1  &&  bad == 4);
        // // assert(performCommands("H4V3V-1H-9", pc, m, bad) == 3  &&  bad == 7);
        // assert(performCommands("B@H", pc, m, bad) == 1  &&  bad == 3);
        // cout << "All tests succeeded." << endl;
         for (;;)
        {   
            cout << "Enter the number of grid rows and columns (max 30 each): ";
            int nRows;
            int nCols;
            cin >> nRows >> nCols;
            cin.ignore(10000, '\n');
            if (nRows >= 1  &&  nRows <= MAXROWS  &&  nCols >= 1  &&  nCols <= MAXCOLS)
            {
                setSize(nRows, nCols);
                break;
            }
            cout << "The numbers must be between 1 and 30." << endl;
        }
    char currentChar = '*';
    int currentMode = FG;
    for (;;)
        {
        cout << "Enter a command string (empty line to quit): ";
        string cmd;
        getline(cin, cmd);
        if (cmd == "")
            break;
        int position;
        int status = performCommands(cmd, currentChar, currentMode, position);
        switch (status)
        {
          case 0:
            draw();
            break;
          case 1:
            cout << "Syntax error at position " << position << endl;
            break;
          case 2:
            if (!isprint(currentChar))
                cout << "Current character is not printable" << endl;
            if (currentMode != FG  &&  currentMode != BG)
                cout << "Current mode is " << currentMode << ", not FG or BG" << endl;
            break;
          case 3:
            cout << "Cannot perform command at position " << position << endl;
            break;
          default:
              // It should be impossible to get here.
            cout << "performCommands returned " << status << "!" << endl;
        }
    }
}

bool preformOneCommand(string cmd, int& pos, int& r, int& c, char& plotChar, int& mode, int& badPos, int& hallDistance, int &vallDistance) {
    char action = toupper(cmd[pos]);
    int distance = 0;
    bool isNegative = false;
    if (action == 'C') {
        clearGrid();
        pos++;
        r = 1;
        c = 1;
        plotChar = '*';
        mode = FG;
        return true;
    }

    else if (action == 'H') {
        pos++; 
        if (cmd[pos] == '-') {
            isNegative = true;
            pos++;
            if (isdigit(cmd[pos])) {
                distance = cmd[pos] - '0';
                pos++;
                    if (isdigit(cmd[pos])) {
                        distance*= 10;
                        distance+=cmd[pos] - '0';
                        distance*=-1;
                        hallDistance+=distance;
                        if (hallDistance >= getCols() || hallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, HORIZ, plotChar, mode);
                        pos++;
                        c+=distance;
                    }
                    else {
                        distance*= -1;
                        hallDistance+=distance;
                         if (hallDistance >= getCols() || hallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, HORIZ, plotChar, mode);
                        c+=distance;
                    }
            }
        }
        else if (isdigit(cmd[pos])) {
                distance = cmd[pos] - '0';
                pos++;
                    if (isdigit(cmd[pos])) {
                        distance*= 10;
                        distance+=cmd[pos] - '0';
                        hallDistance+=distance;
                        cout << hallDistance << endl;
                         if (hallDistance >= getCols() || hallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, HORIZ, plotChar, mode);
                        pos++;
                        c+=distance;
                    }
                    else {
                        // cout << distance << endl;
                        hallDistance+=distance;
                        // cout << hallDistance << endl;
                         if (hallDistance >= getCols() || hallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;

                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, HORIZ, plotChar, mode);
                        c+=distance;
                    }
            }
            // pos++;
        // if (pos++ != cmd.size()-1) {
        //     if (!isdigit(cmd[pos++])) {
        //         return false;
        //     }
        // }
    return true;
    }
    else if (action == 'V') {
        pos++;
        if (cmd[pos] == '-') {
            isNegative = true;
            pos++;
            if (isdigit(cmd[pos])) {
                distance = cmd[pos] - '0';
                pos++;
                    if (isdigit(cmd[pos])) {
                        // cout <<"HI" << endl;
                        distance*= 10;
                        distance+=cmd[pos] - '0';
                        distance*=-1;
                        vallDistance+=distance;
                         if (vallDistance >= getRows() || vallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, VERT, plotChar, mode);
                        pos++;
                        r+=distance;
                        
                    }
                    else {
                        distance*= -1;
                        vallDistance+=distance;
                         if (vallDistance >= getRows() || vallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, VERT, plotChar, mode);
                        r+=distance;
                    }
            }
        }
        else if (isdigit(cmd[pos])) {
                distance = cmd[pos] - '0';
                pos++;
                    if (isdigit(cmd[pos])) {
                        // cout <<"HI" << endl;
                        distance*= 10;
                        distance+=cmd[pos] - '0';
                        // cout << distance << endl;
                        // cout << cmd[pos] << endl;
                        // cout << pos << endl;
                        vallDistance+=distance;
                         if (vallDistance >= getRows() || vallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, VERT, plotChar, mode);
                        // cout << "HI" << endl;
                        pos++;
                        r+=distance;
                    }
                    else {
                       vallDistance+=distance;
                         if (vallDistance >= getCols() || vallDistance < 0) {
                            for (int i = cmd.size() - 1; i >= 0; --i) {
                                if (!isdigit(cmd[i]) && cmd[i] != '-') {
                                    pos = i;
                                    return false;
                                }
                            }
                        }
                        plotLine(r, c, distance, VERT, plotChar, mode);
                        r+=distance;
                    }
            }
        // if (pos++ != cmd.size()-1) {
        //     if (!isdigit(cmd[pos++])) {
        //         return false;
        //     }
        // }
        // pos++;
            return true;
}
    else if (action == 'F') {
        pos++;
        if (pos == cmd.size()) {
            return false;
        }
        // if (distance == 0) {
        //     plotChar = cmd[pos];
        //     return true;
        // }
            plotChar = cmd[pos];
        if (isprint(cmd[pos])) {
            mode = FG;
            // if (isNegative) {
            //     if (distance == 0) {
            //             plotChar = cmd[pos];
            //             pos++;
            //              if (distance == 0) {
            //                 pos++;
            //                 mode = FG;
            //             return true;
            //         }
            //         mode = FG;
            //             return true;
            //         }
            //     // plotLine(r,c,distance*-1,HORIZ, plotChar, mode);
            // }
            // else {
            //         cout << cmd[pos] << endl;
            //         cout << distance << endl;
            //         if (isprint(cmd[pos])) {
            //             if (distance == 0) {
            //                 plotChar = cmd[pos];
            //                 pos++;
            //                 mode = FG;
            //                 return true;
            //             }
            //         }
            //     // plotLine(r,c,distance,HORIZ, plotChar, FG);
            // }
        }
        pos++;
        return true;
    }
    else if (action == 'B') {
        pos++;
        if (pos == cmd.size()) {
            return false;
        }
        // char tempChar = plotChar;
        plotChar = cmd[pos];
        if (isprint(cmd[pos])) 
        {
            mode = BG;
            // if (isNegative) {
            //     if (distance == 0) {
            //             pos++;
            //             mode = BG;
            //             return true;
            //         }
                
                // plotLine(r,c,distance*-1,HORIZ, plotChar, BG);
            // }
            // else {
            //     cout << cmd[pos] << endl;
            //     if (isprint(cmd[pos])) {
            //         if (distance == 0) {
            //             pos++;
            //             mode = BG;
            //             return true;
            //         }
                // plotLine(r,c,distance,HORIZ, plotChar, BG);
            }
            // plotChar = tempChar;        
        pos++;
        return true;
    }
    // badPos = pos;
    return false;
}

bool syntaxError (string cmd, int& pos) {
    while (pos != cmd.size()) {
        switch (toupper(cmd[pos])) {
            case 'C':
                pos++;
                break;
            case 'F':
            case 'B':
                pos++;
                // if (pos == cmd.size() && isprint(cmd[pos])) {
                // pos++;
                // }
                // else {
                //     return false;
                // }
                if (pos == cmd.size()|| !isprint(cmd[pos])) {
                    return false;
                }
                pos++;
                break;
            case 'H':
            case 'V':
                pos++;
                if (pos == cmd.size()) {
                    return false;
                }
                if (cmd[pos] == '-') {
                    pos++;
                    if (pos == cmd.size()) {
                    return false;
                    }
                }
                if (!isdigit(cmd[pos])) { // first digit
                    return false;
                }
                pos++;
                // cout << endl;
                // cout << "pos: " << pos << endl;
                // cout << "size: " << cmd.size() << endl;

                if (pos == cmd.size()-1 && isdigit(cmd[pos])) {
                    pos++;
                }
                break;
            default:
                if (isdigit(cmd[pos])) {
                    pos++;
                    break;
                }
                return false;
        }    
    }
    return true;
}

int performCommands(string commandString, char& plotChar, int& mode, int& badPos) {
    if (!isprint(plotChar) || (mode != FG && mode != BG)) {
        return 2;
    }
    int pos = 0;
    if (!syntaxError(commandString, pos)) {
            badPos = pos;
            return 1;
        }
    int r = 1;
    int c = 1;
        pos = 0;
    int hallDistance = 0;
    int vallDistance = 0;
        //H4H4H4H4
        //V10V02
        //H03H-04
        //V3V-4
        // cout << pos << endl;
    while (pos != commandString.size()) {
    if (!preformOneCommand(commandString, pos, r, c, plotChar, mode, badPos, hallDistance, vallDistance)) {
        // cout << badPos << endl;
        badPos = pos;
        return 3;
        }
    }
    return 0;

}

bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg) {
    if (c+distance > getCols() && r+distance > getRows()) {
        return false;
    }
    
    if (distance == 0) {
        if ((dir == HORIZ || dir == VERT) && (fgbg == FG || fgbg == BG) && (r <= getRows() && c <= getCols() && r >=0 && c >= 0) && isprint(plotChar)) {
            if (fgbg == FG) {
                setChar(r, c, plotChar);
                return true;
            }
            else if (getChar(r, c) == ' ') {
                setChar(r,c, plotChar);
                return true;
            }
            }
    }
    if (distance > 0) {
        if ((dir == HORIZ || dir == VERT) && (fgbg == FG || fgbg == BG) && (r <= getRows() && c <= getCols() && r >=0 && c >= 0) && isprint(plotChar)) {
            if (dir == HORIZ) {
                for (int i = 0; i <= distance && c+i < getCols(); ++i) {
                    if (c+i < 0) {
                        continue;
                    }
                    if (fgbg == FG) {
                        setChar(r, c+i, plotChar);
                    }
                    else if (getChar(r, c+i) == ' ') {
                        setChar(r, c+i, plotChar);
                    }
                }
            }
            else{
                // cout << "HI" << endl;

                for (int i = 0; i <= distance && r+i < getRows(); ++i) {
                    // cout << "HI" << endl;
                    if (r+i < 0) {
                        continue;
                    }
                    if (fgbg == FG) {
                        setChar(r+i, c, plotChar);
                    }
                    else if (getChar(r+i, c) == ' ') {
                        setChar(r+i, c, plotChar);
                    }                  
                }
            }
            return true;
        }
        return false;
    }

    if (distance < 0) {
        if ((dir == HORIZ || dir == VERT) && (fgbg == FG || fgbg == BG) && (r <= getRows() && c <= getCols() && r >=0 && c >= 0) && isprint(plotChar)) {
            if (dir == HORIZ) {
                
                for (int i = 0; i <= (distance*-1) && c-i > 0; ++i) {
                    if (c-i < 0) {
                        continue;
                    }
                    if (fgbg == FG) {
                        setChar(r, c-i, plotChar);
                    }
                    else if (getChar(r, c-i) == ' ') {
                        setChar(r, c-i, plotChar);
                    }
                }
            }
            else{
                for (int i = 0; i <= (distance*-1) && r-i > 0; ++i) {
                    if (r-i < 0) {
                        continue;
                    }
                    if (fgbg == FG) {
                        setChar(r-i, c, plotChar);
                    }
                    else if (getChar(r-i, c) == ' ') {
                        setChar(r-i, c, plotChar);
                    }
                }
            }
            return true;
        }
        return false;
    }
    return false;
}

void plotHorizontalLine(int r, int c, int distance, char ch) {

    if (distance < 0) {
        return;
    }
    if (distance == 0) {
        setChar(r, c, ch);
        return;
    }

    for (int i = 0; i <= distance && c+i < getCols(); ++i) {
        if (c+i <= 0) {
            continue;
        }
        setChar(r, c+i, ch);
    }
       
}

void plotVerticalLine(int r, int c, int distance, char ch) {
    if (distance < 0) {
        return;
    }
    if (distance == 0) {
        setChar(r, c, ch);
        return;
    }

    for (int i = 0; i <= distance && r+i < getRows(); ++i) {
        if (r+i <= 0) {
            continue;
        }
        setChar(r+i, c, ch);
    }
}

void plotRectangle(int r, int c, int height, int width, char ch) {
    if (height < 0 || width < 0) {
        return;
    }

    plotHorizontalLine(r, c, width, ch);
    plotVerticalLine(r, c, height, ch);
    plotHorizontalLine(r + height, c, width, ch);
    plotVerticalLine(r, c+width, height, ch);
}

// void clearBoard() {
//     for (int i = 0; i < getRows(); ++i) {
//         for (int j = 0; j < getCols(); ++j) {
//             setChar(i,j,' ');
//         }
//     }