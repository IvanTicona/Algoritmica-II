#include <bits/stdc++.h>
using namespace std;

// Recursive function to find minimum edit distance between two strings
int minDisRec(string& s1, string& s2, int m, int n, 
                            vector<vector<int>>& memo) {
    if (m == 0) return n;

    if (n == 0) return m;

    if (memo[m][n] != -1) return memo[m][n];

    if (s1[m - 1] == s2[n - 1]) {
        memo[m][n] = minDisRec(s1, s2, m - 1, n - 1, memo);
    } else {
        memo[m][n] = 1 + min({
            minDisRec(s1, s2, m, n - 1, memo),    // Insert
            minDisRec(s1, s2, m - 1, n, memo),    // Remove
            minDisRec(s1, s2, m - 1, n - 1, memo) // Replace
        });
    }

    return memo[m][n]; // Return the computed minimum distance
}

// Function to initialize memoization table and start the recursive function
int minDis(string& s1, string& s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return minDisRec(s1, s2, m, n, memo);
}

// Main function to execute the program
int main() {
    string s1 = "GEEXSFRGEEKKS"; // First string
    string s2 = "GEEKSFORGEEKS"; // Second string

    cout << minDis(s1, s2);
    return 0;
}