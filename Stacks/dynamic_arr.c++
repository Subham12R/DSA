#include <iostream>
using namespace std;    


class  DynamicArray
{
private:
  int *arr;
  int capacity;
  int topIndex;

  void resize(){
    int newCapacity = capacity * 2;
    int *newArr = new int[newCapacity];
    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
  }
public:
   DynamicArray() {
       capacity = 2;
       arr = new int[capacity];
       topIndex = -1;
   }

   ~DynamicArray() {
       delete[] arr;
   }

   void push(int value) {
       if (topIndex + 1 == capacity) {
           resize();
       }
       arr[++topIndex] = value;
   }

   int pop() {
       if (topIndex == -1) {
           cerr << "Stack is empty!" << endl;
           return -1;  // Meaningful value indicating empty stack
       }
       return arr[topIndex--];
   }

   bool isEmpty() const {
       return topIndex == -1;
   }

   int peek() const {
       if (topIndex == -1) {
           cerr << "Stack is empty!" << endl;
           return -1; 
       }
       return arr[topIndex];
   }
};


int main(){
    DynamicArray stack;

   stack.push(10);
   stack.push(20);
   stack.push(30);

    cout << "Top element is: " << stack.peek() << endl; // 30
    cout << "Popped element is: " << stack.pop() << endl; // 30
    cout << "Popped element is: " << stack.pop() << endl; // 20
    cout << "Popped element is: " << stack.pop() << endl; // 10
    cout << "Popped element is: " << stack.pop() << endl; // Stack is empty!

    return 0;
}