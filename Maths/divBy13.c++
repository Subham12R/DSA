#include <iostream>
using namespace std;

// bool divBy13(string &s){
//     int num = stoi(s);
//     return (num % 13 == 0);
// }

//String modulu
 
bool divBy13(string &s){
    int rem = 0;
    for(char ch: s){
        rem = (rem * 10 + (ch - '0')) % 13;
    }
    return rem == 0;
}

int main(){
    string s;
    cin >> s;
    bool isDivisible = divBy13(s);

    if(isDivisible){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}

