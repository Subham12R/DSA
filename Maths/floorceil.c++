#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


vector<int> floorCeil(int a, int b){
   int floorVal = floor((double)a/b);
   int ceilVal = ceil((double)a/b);
   return {floorVal, ceilVal};
}

int main(){
    int a = -7, b = 2;
    vector<int> ans = floorCeil(a, b);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;

}