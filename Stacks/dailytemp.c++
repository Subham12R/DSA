#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st; 
        for (int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                result[index] = i - index;
            }
            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution s1;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = s1.dailyTemperatures(temperatures);
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
    return 0;
}