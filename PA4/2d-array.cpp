#include <iostream>

using namespace std;

const int HEIGHT = 15;
const int WIDTH = 10;

void pass(int a[][5], int rows) {
    for (int i = 0; i < rows; ++i) {
        cout << endl;
        for (int j = 0; j < a[i][j]; ++j) {
            cout << a[i][j];
        }
    }
}

int main() {
    int arr[3][5] = {
                    {1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15}};

    pass(arr, 3);
    // pass(arr);
    // char board[HEIGHT][WIDTH];

    // for (int i = 0; i < HEIGHT; ++i) {
    //     // board[i] = '|';
    //     board[i][0] = '|';
    //     cout << endl;
    //     for (int j = 0; j == 0 || j == WIDTH-1; ++j) {
    //        board[i][j] = '-';
    //        cout << board[i][j];
    //     }
    // }

    // cout << arr[1,2][2,1] << endl;
    
}