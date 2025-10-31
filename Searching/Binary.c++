#include <iostream>
#include <vector>
using namespace std;

class BinarySearch {
    public: 
    int binarySearch(vector<int> & arr, int x) {
        int l = 0;
        int r = arr.size() - 1;
        while (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) 
                return mid;
            else if (arr[mid] > x) 
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

};

int main() {
    vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 10;
    BinarySearch bs;
    int result = bs.binarySearch(arr, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}