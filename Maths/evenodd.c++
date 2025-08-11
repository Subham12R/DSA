#include <iostream>
using namespace std;

//using standard input
// int main()
// {
//     int n;
//     cin >> n;
//     if (n % 2 == 0)
//     {
//         cout << "Even";
//     }
//     else
//     {
//         cout << "Odd";
//     }
//     return 0;
// }

// using bitwise operator

int main(){
    int n;
    cin >> n;
    if(n & 1){
        cout << "Odd";
    }
    else{
        cout << "Even"; 
    }
    return 0;
}