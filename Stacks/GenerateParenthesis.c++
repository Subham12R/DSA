#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        cur.reserve(2 * n);
        backtrack(n, 0, 0, cur, res);
        return res;
    }

private:
    void backtrack(int n, int openUsed, int closeUsed, string &cur, vector<string> &res) {
        if ((int)cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (openUsed < n) {
            cur.push_back('(');
            backtrack(n, openUsed + 1, closeUsed, cur, res);
            cur.pop_back();
        }
        if (closeUsed < openUsed) {
            cur.push_back(')');
            backtrack(n, openUsed, closeUsed + 1, cur, res);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s1;
    int n = 3;
    vector<string> result = s1.generateParenthesis(n);
    for (const string &str : result) {
        cout << str << endl;
    }
    return 0;
}
