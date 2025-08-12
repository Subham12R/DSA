#include <iostream>
#include <vector>
using namespace std;    



void insertionSort(vector<int>&arr, int n) {
    int i, key, j;
    for(i = 0; i<n ; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printArray(vector<int>&arr, int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}