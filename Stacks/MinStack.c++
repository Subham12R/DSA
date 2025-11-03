// #include <iostream>
// #include <stack>
// using namespace std;

// class Stack{
//     stack<int> st;
//     stack<int> minSt;
//     public:
//     void push(int val){
        
//             st.push(val);
//             if(minSt.empty() || val <= minSt.top()){
//                 minSt.push(val);
//             }
        
//     }

//     int pop(){
//         if(st.empty()){
//             cout<<"Stack Underflow"<<endl;
//             return -1;
//         }
//         int poppedValue = st.top();
//         st.pop();

//         if(st.top() == minSt.top()){
//             minSt.pop();
//         }
//         return poppedValue;
//     }

//     int top(){
//         if(st.empty()){
//             cout<<"Stack is empty"<<endl;
//             return -1;
//         }
//         return st.top();
//     }

//     int getMin(){
//         return minSt.top();
//     }

//     bool isEmpty(){
//         return st.empty();
//     }

// };

// int main(){
//     Stack s;
//     s.push(10);
//     s.push(5);
//     s.push(20);
//     cout<<"Current Min: "<<s.getMin()<<endl; // Should print 5
//     s.pop();
//     cout<<"Top Element: "<<s.top()<<endl; // Should print 5
//     cout<<"Current Min: "<<s.getMin()<<endl; // Should print 5
//     s.pop();
//     cout<<"Current Min: "<<s.getMin()<<endl; // Should print 10
//     return 0;
// }

#include <iostream>
#include <stack>
using namespace std;


class Solution {
    stack<long long> st;
    long long min;

    public:
    Solution() {}

    void push(int val){
        if(st.empty()){
            st.push(val);
            min = val;
        }
        else{
            if(val >= min){
                st.push(val);
            }
            else{
                long long newVal = 2LL * val - min;
                st.push(newVal);
                min = val;
            }
        }
    }

    void pop(){
        if(st.empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        long long topVal = st.top();
        st.pop();
        if(topVal < min){
            min = 2LL * min - topVal;
        }
    }

    int top(){
        if(st.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        long long topVal = st.top();
        if(topVal >= min){
            return topVal;
        }
        else{
            return min;
        }
    }

    int getMin(){
        if(st.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return min;
    }

    bool isEmpty(){
        return st.empty();
    }
};

int main(){
    Solution s;
    s.push(10);
    s.push(5);
    s.push(20);
    cout<<"Current Min: "<<s.getMin()<<endl; // Should print 5
    s.pop();
    cout<<"Top Element: "<<s.top()<<endl; // Should print 5
    cout<<"Current Min: "<<s.getMin()<<endl; // Should print 5
    s.pop();
    cout<<"Current Min: "<<s.getMin()<<endl; // Should print 10
    return 0;
}