class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> m(n);
        int dp[1501][1501]{};
        int b[1501]{};

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) continue;

                if (items[j][0]%items[i][0] == 0) {
                    m[i]++;
                }
            }
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=budget; j++) {
                int p = items[i-1][1];
                int free = m[i-1];

                b[j] = j-p >= 0 ? max(dp[i-1][j-p]+1+free, b[j-p]+1) : 0;
                dp[i][j] = max(dp[i-1][j], b[j]);
            }
        }

        return dp[n][budget];
    }
};