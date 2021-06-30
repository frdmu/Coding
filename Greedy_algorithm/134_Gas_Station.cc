// https://leetcode-cn.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> index(n, 0);
        for (int i = 0; i < n; i++) {
            if (gas[i] >= cost[i])
                index[i] = 1;
        } 
        for (int i = 0; i < n; i++) {
            if (index[i]) {
                // entry
                int j = i, cnt = 0, next = gas[i];
                while (cnt < n) {
                    if (next - cost[j] < 0) break; 
                    next = next - cost[j] + gas[(j+1)%n];
                    cnt++;
                    j = (j+1) % n;
                } 
                if (cnt == n)
                    return i;
            }
        }

        return -1;
    }
};
