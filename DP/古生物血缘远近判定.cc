// https://leetcode-cn.com/leetbook/read/bytedance-c01/eug83v/
#include <string.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int solve(string, string);

int main() {
    string word1, word2;
    cin >> word1; 
    word2 = word1.substr(word1.find(",")+1, word1.length());
    word1 = word1.substr(0, word1.find(","));
    cout << solve(word1, word2) << endl;
    return 0;
}

int solve(string word1, string word2) {
    int l1 = word1.length();
    int l2 = word2.length();
    vector<vector<int> > dp(l1+1, vector<int>(l2+1, 0));
    for (int j = 0; j <= l2; j++) {
        dp[0][j] = j;
    }
    for (int i = 0; i <= l1; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (word1[i-1] != word2[j-1]) 
                dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i][j-1], dp[i-1][j]) + 1);
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[l1][l2];
}
