#include <iostream>

using namespace std;

// int main()
//   {
//       int arr[3] = { 5, 10, 15 };
//       int* ptr = arr;

//       *ptr = 30;          // set arr[0] to 30
//       *(ptr+1) = 20;      // set arr[1] to 20
//       ptr += 2;
//       ptr[0] = 10;        // set arr[2] to 10

//     for (ptr = arr; ptr < arr + 3; ++ptr) {
//       cout << *ptr << endl;
//     }
//   }

// void computeCube(int n, int*& ncubed)
//   {
//     *ncubed = n * n * n;
//   }

// int main()
//   {
//     int x = 0;
//     int* ptr = &x;
//     computeCube(5, ptr);
//     cout << "Five cubed is " << *ptr << endl;
//   }

 // return true if two C strings are equal
// bool strequal(const char str1[], const char str2[])
// {
//     while (*str1 != '\0'  &&  *str2 != '\0')  // zero bytes at ends
//     {
//         if (*str1 != *str2)  // compare corresponding characters
//             return false;
//         str1++;            // advance to the next character
//         str2++;
//     }
//     return *str1 == *str2;   // both ended at same time?
// }

// int main()
// {
//     char a[15] = "Chen, G.";
//     char b[15] = "Chen, G.";

//     if (strequal(a,b))
//         cout << "They're the same person!\n";
// }

// int* nochange(int* p)
// {

//     for (int i = 0; i < 100; i++) {
//         cout << p[i] << ' ';
//     }
//     return p;
// }

// int* getPtrToArray(int& m)
// {
//     int anArray[100];
//     for (int j = 0; j < 100; j++)
//         anArray[j] = 100-j;
//     m = 100;
//     return nochange(anArray);
// }

// void f()
// {
//     int junk[100];
//     for (int k = 0; k < 100; k++)
//         junk[k] = 123400000 + k;
//     junk[50]++;
// }

// int main()
// {
//     int n;
//     int* ptr = getPtrToArray(n);
//     f();
//     // for (int i = 0; i < 3; i++)
//     //     cout << ptr[i] << ' ';
//     // for (int i = n-3; i < n; i++)
//     //     cout << ptr[i] << ' ';
//     cout << endl;
// }
      

// int main() {
//     int idk = 1000;
//     int *p;
//     p = &idk;
//     *p = 5;
//     cout << *p << endl;
// }

const char* findTheChar(const char* str, char chr)
{
    for (int k = 0; (str + k)!= 0; k++)
        if (*(str + k) == chr)
            return str+k;

    return nullptr;
}

int main() {

}