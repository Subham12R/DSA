#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    pair<int, int> searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) return {i, j};
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return {-1, -1};
    }
};

int main(){
    vector<vector<int>> matrix = {{1,4,5}, {2,5,8}, {3,6,9}};
    int target = 5;
    Solution s1;
    pair<int, int> p = s1.searchMatrix(matrix, target);
    cout << p.first << " " << p.second << endl;
     if (p.first == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: (" << p.first << ", " << p.second << ")" << endl;
    return 0;
}