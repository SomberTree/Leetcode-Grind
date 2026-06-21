class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        for (auto& u: units) sort(u.begin(), u.end());

        long long sinkcap = INT_MAX;
        int sinki = -1;

        long long ans = 0;
        for (int i=0; i<m; i++) ans += units[i][0];
        if (n == 1) return ans;

        int mincapi = -1;
        int mincap = INT_MAX;
        for (int i=0; i<m; i++) {
            if ((sinkcap > units[i][1]) || (sinkcap == units[i][1] && units[sinki][0] > units[i][0])) {
                sinkcap = units[i][1];
                sinki = i;
            }
            if (mincap > units[i][0]) {
                mincap = units[i][0];
                mincapi = i;
            }  
        }

        long long delta = 0;
        for (int i=0; i<m; i++) {
            if (i == sinki) {
                delta -= max(0, units[sinki][0] - mincap);
                continue;
            }
            delta += units[i][1] - units[i][0];
        }

        return ans + delta;
    }
};