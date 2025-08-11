#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// vector<int> factors(int n ){
//     vector<int> factors;

//     for(int i = 0; i <= n; i++){
//         if(n % i == 0){
//             factors.push_back(i);
//         }
//     }
//     return factors;
// }


//Expected approach
vector<int> factors(int n){
    vector<int> divisors;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
        if (n/i == i)
        {
            divisors.push_back(i);
        }   
        else{
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
        
    }
    }
    return divisors;
}
int main(){
    int n;
    cin >> n;
    vector<int> ans = factors(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}