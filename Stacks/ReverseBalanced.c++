#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        auto isSign= [](string token){
            return(token == "+" ||token == "-" ||token == "*" ||token == "/" );
        };

        for(auto token: tokens){
            if(isSign(token)){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if(token == "+")st.push(num1 + num2);
                else if(token == "-")st.push(num1 - num2);
                else if(token == "*")st.push(num1 * num2);
                else if(token == "/")st.push(num1 / num2);
            }else{
                int num = stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};


int main(){
    Solution s1;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout<<s1.evalRPN(tokens)<<endl; // Output: 9
    return 0;
}