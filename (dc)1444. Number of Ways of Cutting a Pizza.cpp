//https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/
class Solution {
    private:
    static constexpr int kMod = 1'000'000'007;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> prefix;

    public:
    int ways(vector<string>& pizza, int k) {
        const int M = pizza.size();
        const int N = pizza[0].size();
        // dp[m][n][k] := # of ways to cut pizza[m:M][n:N] w/ k cuts
        dp.resize(M, vector<vector<int>>(N, vector<int>(k, -1)));
        prefix.resize(M + 1, vector<int>(N + 1));

        for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            prefix[i + 1][j + 1] = (pizza[i][j] == 'A') + prefix[i][j + 1] +
                                prefix[i + 1][j] - prefix[i][j];

        return ways(0, 0, k - 1, M, N);
    }

    int ways(int m, int n, int k, const int M, const int N) {
        if (k == 0)
        return 1;
        if (dp[m][n][k] >= 0)
        return dp[m][n][k];

        dp[m][n][k] = 0;

        for (int i = m + 1; i < M; ++i)  // Cut horizontally
        if (hasApple(m, i, n, N) && hasApple(i, M, n, N))
            dp[m][n][k] = (dp[m][n][k] + ways(i, n, k - 1, M, N)) % kMod;

        for (int j = n + 1; j < N; ++j)  // Cut vertically
        if (hasApple(m, M, n, j) && hasApple(m, M, j, N))
            dp[m][n][k] = (dp[m][n][k] + ways(m, j, k - 1, M, N)) % kMod;

        return dp[m][n][k];
    }
    // HasApple of pizza[row1..row2)[col1..col2)
    bool hasApple(int row1, int row2, int col1, int col2) {
        return (prefix[row2][col2] - prefix[row1][col2] - prefix[row2][col1] +
                prefix[row1][col1]) > 0;
    };
};


//The code defines a class Solution which has a private static constexpr integer kMod that is equal to 1'000'000'007. 
//The class also has two vectors of vectors: dp and prefix.
//The public function ways takes in a vector of strings pizza and an integer k. The function first initializes dp and prefix vectors with appropriate sizes. 
//The prefix vector has extra +1 at both dimensions, since each element in prefix is defined as the sum of elements up to that point. Then, the ways function is called with m=0, n=0, and k-1.
//The private function ways takes in m, n, k, and constants M and N. The function first checks if k is 0 or if the corresponding element in dp is not equal to -1, in which case the function returns 1 or the cached result, respectively. 
//Otherwise, the function sets dp[m][n][k] to 0 and computes the number of ways to cut the pizza horizontally and vertically by checking if there are apples in the corresponding slices. 
//The function then caches this result and returns it.
//The private function hasApple takes in row1, row2, col1, and col2 and returns a boolean indicating whether there are any apples in the corresponding slice of the pizza.
//This code is a possible implementation for a problem involving cutting a rectangular pizza multiple times with a limited number of cuts, and counting the total number of ways to cut the pizza such that each resulting slice has at least one apple.

