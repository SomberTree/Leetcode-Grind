class Solution {
public:
    using ll = long long;
    string longestDupSubstring(string s) {
        int n = s.size();
        ll p1 = 31;
        ll p2 = 57;
        ll m = 1e9+9;

        vector<ll> p1_pow(n);
        vector<ll> p2_pow(n);
        p1_pow[0] = 1;
        p2_pow[0] = 1;
        for (int i=1; i<n; i++) {
            p1_pow[i] = (p1_pow[i-1]*p1)%m;
            p2_pow[i] = (p2_pow[i-1]*p2)%m;
        }


        vector<ll> h1(n+1);
        vector<ll> h2(n+1);
        
        for (int i=0; i<n; i++) {
            h1[i+1] = (h1[i] + (s[i] - 'a' + 1) * p1_pow[i])%m;
            h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p2_pow[i])%m;
        }

        int low=1, high=n-1;
        int ansi = -1;
        int anslen = 0;
        while (high >= low) {
            int mid = (high+low)/2;
            
            // check if a substring of length mid is being repeated or not
            unordered_set<ll> hs;
            bool found = false;
            for (int i=0; i<=n-mid; i++) {
                ll curr_h1 = (h1[i+mid] - h1[i] + m) % m;
                curr_h1 = (curr_h1*p1_pow[n-i-1]) % m;

                ll curr_h2 = (h2[i+mid] - h2[i] + m) % m;
                curr_h2 = (curr_h2*p2_pow[n-i-1]) % m;

                ll combined_h = (curr_h1 << 32) | curr_h2;

                if (hs.count(combined_h)) {
                    if (anslen < mid) {
                        anslen = mid;
                        ansi = i;
                        found = true;
                        break;
                    }
                } else {
                    hs.insert(combined_h);
                }
            }

            if (found) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return anslen == 0 ? "" : s.substr(ansi, anslen);
    } 
};