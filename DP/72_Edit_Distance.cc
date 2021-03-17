// https://leetcode-cn.com/leetbook/read/bytedance-c01/oh8qxi/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(); 
        int l2 = word2.size();  
        vector<vector<int> > dp(l1+1, vector<int>(l2+1));
        for (int i = 0; i <= l2; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= l1; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (word1[i-1] != word2[j-1])
					// for example:
					// horse -> ros when i = 3, j = 5
				    // word1 = "ros", word2 = "horse"
					// word1[3-1] = 's', word2[5-1] = 'e'
					// word1[2] != word2[4]
					// there are 3 cases from horse to ros
					// case 1: horse -->ro, and then add s; ie dp[i-1][j] + 1
					// case 2: hors -->ro, and then replace e with s; ie dp[i-1][j-1] + 1
					// case 3: hors -->ros, and then delete e; ie dp[i][j-1] + 1
					// so dp[i][j] = min(dp[i-1][j] + 1, dp[i-1][j-1] + 1, dp[i][j-1] + 1);
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j], dp[i][j-1]) + 1);
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[l1][l2];
    }
};