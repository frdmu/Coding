// https://leetcode-cn.com/problems/top-k-frequent-elements/
class Solution {
public:
    struct cmp {
        bool operator() (pair<int, int> pair1, pair<int, int> pair2) {
            return pair1.second > pair2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto item : nums) {
            map[item]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }

        vector<int> ans(k);
        for (int i = k-1; i >= 0; i--) {
            ans[i] = que.top().first;
            que.pop();
        }

        return ans;
    }
};
