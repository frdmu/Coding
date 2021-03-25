// https://leetcode-cn.com/leetbook/read/bytedance-c01/ohu4e2/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false; 
        map<int, set<int> > mp;
        int len = stones.size();

        for (int i = 0; i < len; i++) {
            mp[stones[i]].insert(0);
        }
        mp[stones[1]].insert(1);
        
        for (int i = 1; i < len-1; i++) {
            set<int> tmp_set = mp[stones[i]];
            auto it = tmp_set.begin();
            for (it++; it != tmp_set.end(); it++) {
                int j = *it;
                if (j - 1 > 0 && mp.count(stones[i]+j-1) != 0) {
                        mp[stones[i]+j-1].insert(j-1);
                }
                if (mp.count(stones[i]+j) != 0) {
                        mp[stones[i]+j].insert(j);
                }
                if (mp.count(stones[i]+j+1) != 0) {
                        mp[stones[i]+j+1].insert(j+1);
                }
            }
        }
    
        return mp[stones[len-1]].size() != 1 ? true: false;
    }
};