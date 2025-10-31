#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    // For each key, store vector of pairs (timestamp, value).
    unordered_map<string, vector<pair<int,string>>> mp;

public:
    TimeMap() { }

    void set(const string& key, const string& value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }

    string get(const string& key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";                 // no such key
        const auto &vec = it->second;
        int l = 0, r = (int)vec.size() - 1;
        int ansIndex = -1;

        // binary search for largest index with vec[idx].first <= timestamp
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= timestamp) {
                ansIndex = mid;
                l = mid + 1;   // try to find a later timestamp
            } else {
                r = mid - 1;
            }
        }

        if (ansIndex == -1) return "";
        return vec[ansIndex].second;
    }
};

// Example usage
int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << "\n";  // "bar"
    cout << timeMap.get("foo", 3) << "\n";  // "bar"
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << "\n";  // "bar2"
    cout << timeMap.get("foo", 5) << "\n";  // "bar2"
    return 0;
}
