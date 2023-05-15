#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    
    int result = lcs(s1, s2);
    
    cout << "Length of Longest Common Subsequence: " << result << endl;
    
    return 0;
}

/**
 * @brief Longest common subsequence between two strings
 * This program uses a 2D array to store the results of subproblems, and 
 * fills in the array using a bottom-up approach. 
 * 
 * The program has a time complexity of O(mn), 
 * where m and n are the lengths of the input strings. 
 * 
 * This is an efficient approach for finding the length of the longest common subsequence between two strings.
 * 
 */
