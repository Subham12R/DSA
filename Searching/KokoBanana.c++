#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;

        while(low<=high){
            int mid = low + (high - low) / 2;
            int hours = 0;
            for (int pile: piles){
                hours += ceil((double)pile / mid);
            }
            if (hours <= h){
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main(){
    vector <int> piles = {3,6,7,11};
    int h = 8;
    Solution s1;
    cout << s1.minEatingSpeed(piles, h) << endl;
    return 0;
}