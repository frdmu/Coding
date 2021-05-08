// https://leetcode-cn.com/problems/sliding-window-maximum/
// Solution: Monotonous queue
class Solution {
public:
    class Myqueue {
    public:
        deque<int> que;
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        } 
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            } 
        }
        int front() {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;
        vector<int> ans;
        
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        ans.push_back(que.front());
        int n = nums.size();
        for (int i = k; i < n; i++) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            ans.push_back(que.front());
        }

        return ans;
    }
};
