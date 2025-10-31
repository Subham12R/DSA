#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Found target
            if (nums[mid] == target)
                return mid;

            // Check if left half is sorted
            if (nums[l] <= nums[mid]) {
                // Target lies in left half
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Else right half must be sorted
            else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;  // not found
    }
};


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution s1;
    cout << s1.search(nums, target) << endl;
    return 0;
}