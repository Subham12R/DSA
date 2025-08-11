#include <iostream>
using namespace std;

// int gcd(int a, int b) {
//    int result = min(a, b);
//    while(result > 0) {
//     if(a % result == 0 && b % result == 0) {
//         return result;
//     }
//     result--;   
//    }
//    return result;
// }

// int main(){
//     int a, b;
//     cin >> a >> b;
//     cout << gcd(a, b) << endl;
//     return 0;
// }

int gcd (int a, int b){
    if(b == 0)
    return a;
    if(a == 0)
    return b;
    if(a > b)
    return gcd(a-b, b);
    return gcd(a, b-a);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}