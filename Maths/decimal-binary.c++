// #include<iostream>
// #include <algorithm>
// using namespace std;

// string decToBin(int n) {
//     string bin = " ";
//     while (n > 0) {
//         int bit = n%2;
//         bin.push_back('0' + bit);
//         n /= 2;
//     }

//     reverse(bin.begin(), bin.end());
//     return bin;
// }

// int main () {
//     cout << "Enter a decimal number: " ;
//     int n; 
//     cin >> n;
//     cout << decToBin(n) << endl;
//     return 0;
// }



//using built in function
#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;

string decToBin(int n) {
    int len = (int)(log2(n));
    return bitset<64>(n).to_string().substr(64 - len - 1);
}

int main(){
    cout << "Enter a decimal number: " ;
    int n; 
    cin >> n;
    cout << decToBin(n) << endl;
    return 0;
}