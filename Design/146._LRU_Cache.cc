// https://leetcode-cn.com/problems/lru-cache/
class LRUCache {
public:
    int max_num;
    unordered_map<int, pair<int, list<int>::iterator> > mp; 
    list<int> lst; 
    
    LRUCache(int capacity) {
        max_num = capacity;
    }
    
    int get(int key) {
        if (mp.count(key) == 0)
            return -1;
        int val = mp[key].first;
        list<int> :: iterator it = mp[key].second;
        lst.erase(it);
        lst.push_front(key);
        mp[key].second = lst.begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if (mp.count(key) != 0) {
            mp[key].first = value;
            list<int> :: iterator it = mp[key].second;
            lst.erase(it);
            lst.push_front(key);
            mp[key].second = lst.begin();
        } else {
            if (mp.size() == max_num) {
                int tmp_key = lst.back(); 
                mp.erase(tmp_key);
                lst.pop_back();
            } 
            lst.push_front(key);
            list<int> :: iterator it = lst.begin(); 
            mp[key] = make_pair(value, it);
        }
    }
};
