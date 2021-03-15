class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    int max_num;
    map<int, pair<int, list<int>::iterator> > mp;
    list<int> lst;
    
    void set(int key, int value) {
        if (mp.count(key) != 0) {
            mp[key].first = value;
            list<int> :: iterator it = mp[key].second;
            lst.erase(it);
            lst.push_front(key);     
            mp[key].second = lst.begin();
        } else {
            if (mp.size() == max_num) {
                int tmp_key = lst.back();
                lst.pop_back();
                mp.erase(tmp_key);
            }
            lst.push_front(key);
            list<int> :: iterator it = lst.begin(); 
            mp[key] = make_pair(value, it);
        } 
    }
	
    int get(int key) {
        if (mp.count(key) == 0)
            return -1;
        int val = mp[key].first;
        list<int> :: iterator it = mp[key].second;
        lst.erase(it);
        lst.push_front(key);
        return val;
    }
	
    vector<int> LRU(vector<vector<int> >& operators, int  k) {
        // write code here 
        max_num = k; 
        vector<int> ans;
        
        int len = operators.size();
        for (int i = 0; i < len; i++) {
            int func = operators[i][0];
            if (func == 1) {
                set(operators[i][1], operators[i][2]);    
            } else {
                ans.push_back(get(operators[i][1])); 
            }
        }
        
        return ans;
    }
};