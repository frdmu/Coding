// https://leetcode-cn.com/problems/sort-characters-by-frequency/
class Solution {
public:
    typedef struct{
        char ch;
        int frequency;
    }node;

    bool static cmp(node a, node b) {
        return a.frequency > b.frequency;
    }
    string frequencySort(string s) {
        map<char, int> mp;
        vector<node> vec; 
        string res;
        
        for (auto ch: s) {
            mp[ch]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vec.push_back({it->first, it->second});
        }
        sort(vec.begin(), vec.end(), cmp);
        for (auto e: vec) {
            for (int i = 0; i < e.frequency; i++) {
                res += e.ch;
            }
        }

        return res;
    }
};
