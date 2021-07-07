// https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> mp;
        set<string> food;
        set<int> table; 
        for (auto order : orders) {
            mp[stoi(order[1])][order[2]]++;
            food.insert(order[2]);
            table.insert(stoi(order[1]));
        }

        vector<vector<string>> res;
        vector<string> title;
        title.push_back("Table");
        for (auto it = food.begin(); it != food.end(); it++) {
            title.push_back(*it);
        }
        res.push_back(title);
        for (auto it = table.begin(); it != table.end(); it++) {
            vector<string> tmp;
            tmp.push_back(to_string(*it));
            for (auto i = food.begin(); i != food.end(); i++) {
                tmp.push_back(to_string(mp[*it][*i]));    
            }
            res.push_back(tmp);
        }

        return res; 
    }
};
