#include <iostream>
#include <stack>
using namespace std;

struct Queue {
    stack <int> input, output;

    void push(int data) {
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        cout << "The element pushed is: " << data << endl;
        input.push(data);
        while (!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int Pop() {
        if(input.empty()) {
            cout << "Queue Underflow" << endl;
            exit(0);
        }
        int val = input.top();
        input.pop();        
        return val;
    }
    int Top(){
        if(input.empty()) {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        return input.top();
    }
    int size(){
        return input.size();
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    cout << "Top element is: " << q.Top() << endl;
    cout << "Size of queue is: " << q.size() << endl;
    cout << q.Pop() << " popped from queue" << endl;
    cout << "Top element is: " << q.Top() << endl;
    cout << "Size of queue is: " << q.size() << endl;
    return 0;
}