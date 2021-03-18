// https://leetcode-cn.com/leetbook/read/bytedance-c01/euhjkm/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // stack stores the indexes of elements that smaller than current element, pop all the
        // indexes of elements that greater than current element;
        // pair<int, int> : <index, the sum of subarray ends with arr[index]>
        stack<pair<int, int> > stk; 
        int base = 1e9 + 7; 
        int size = arr.size();
        int ans = 0; 
        
        for (int i = 0; i < size; i++) {
            while (!stk.empty() && arr[stk.top().first] > arr[i]) 
                stk.pop();
            int tmp = stk.empty() ? (i+1)*arr[i] : stk.top().second + (i - stk.top().first)*arr[i];
            ans += tmp;
            ans %= base;
            stk.push({i, tmp});
        }

        return ans;
    }
};