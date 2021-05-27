// https://leetcode-cn.com/problems/reconstruct-itinerary/
class Solution {
public:
    unordered_map<string, map<string, int> > targets;
    vector<string> ans;
    bool backtracing(int ticketNum) {
        if (ans.size() == ticketNum+1) {
            return true;
        }
        for (pair<const string, int> &target : targets[ans.back()]) {
            if (target.second > 0) {
                ans.push_back(target.first);
                target.second--;
                if (backtracing(ticketNum)) return true;
                ans.pop_back();
                target.second++;
            }
        }
        return false;
    } 
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        ans.push_back("JFK");
        backtracing(tickets.size());
        return ans;
    }
};
