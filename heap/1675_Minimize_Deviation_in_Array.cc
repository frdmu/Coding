// https://leetcode-cn.com/leetbook/read/bytedance-c01/eigcei/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minNum = INT_MAX, res = INT_MAX;
    
        // transform all the odd number to be the even number, and put them into pq 
        for (auto i : nums) {
            int mutate = (i & 1) ? i * 2 : i;
            pq.push(mutate);
            minNum = min(minNum, mutate); 
        }
        // decrease the largest even number until the largest number becomes a odd number
        res = min(res, pq.top()-minNum);
        while (!(pq.top() & 1)) {
            int largest = pq.top();
            pq.pop();
            minNum = min(minNum, largest / 2);
            pq.push(largest / 2);
            res = min(res, pq.top()-minNum);
        }
        return res;
    }
};