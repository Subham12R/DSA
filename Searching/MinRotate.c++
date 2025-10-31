#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        if(nums[l] <= nums[r]) return nums[l];

        while (l <= r) {
            int mid = l + (r - l) / 2;

            
            if (mid < r && nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }

           
            if (mid > l && nums[mid] <= nums[mid - 1]) {
                return nums[mid];
            }
            
            if (nums[mid] >= nums[l]){
                l = mid + 1;
            } else {
                r = mid - 1;

            }
        }

        return -1;  
    }
};



int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution s1;
    cout << s1.findMin(nums) << endl;
    return 0;
}