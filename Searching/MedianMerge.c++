#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           vector <int> merged;
           int i = 0, j = 0;
           int n1 = nums1.size(); 
           int n2 = nums2.size();
           while(i < n1 && j < n2){
                if(nums1[i] < nums2[j]){
                    merged.push_back(nums1[i++]);
                } else {
                    merged.push_back(nums2[j++]);
                }
           }

           while ( i < n1)merged.push_back(nums1[i++]);
           while ( j < n2)merged.push_back(nums2[j++]);

 
           int n = merged.size();
           if(n % 2 == 1)return merged[n/2];
           else return (merged[n/2] + merged[n/2 - 1]) / 2.00;
           
           
        }
};


int main(){
    vector<int> nums1 = {1,2}; 
    vector<int> nums2 = {3,4};
    
    Solution s1;
    cout << s1.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}