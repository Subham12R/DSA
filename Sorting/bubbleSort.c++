#include <iostream>
#include <vector>
using namespace std;

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(vector<int>&arr, int n){
    int i, j;
    bool swapped;
    for(i = 0; i < n; i++ ){
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false){
        break;
        }
        }   
    
}

void printArray(vector<int>&arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}