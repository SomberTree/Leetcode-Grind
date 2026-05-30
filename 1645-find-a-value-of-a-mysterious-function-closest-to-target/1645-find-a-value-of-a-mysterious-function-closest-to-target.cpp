class Solution {
    class SegTree {
    private:
        int n;
        vector<int> tree;

        void build(const vector<int>& arr, int start, int end, int node) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int mid = start + (end-start)/2;
            int left_child = 2*node+1;
            int right_child = 2*node+2;

            build(arr, start, mid, left_child);
            build(arr, mid+1, end, right_child);
            tree[node] = tree[left_child] & tree[right_child];
        }

        int query(int node, int start, int end, int l, int r) {
            if (l > r) return INT_MAX;
            if (l == start && r == end) return tree[node];

            int mid = start + (end - start)/2;
            int left_child = 2*node+1;
            int right_child = 2*node+2;
            
            return query(left_child, start, mid, l, min(r, mid)) & query(right_child, mid+1, end, max(l, mid+1), r);
        }
    public:
        SegTree(const vector<int>& arr) {
            n = arr.size();
            tree.assign(4*n, 0);
            build(arr, 0, n-1, 0);
        }    
        int query(int l, int r) {
            return query(0, 0, n-1, l, r);
        }
    };
public:
    int closestToTarget(vector<int>& arr, int target) {
        SegTree segtree(arr);
        int n = arr.size();
        int ans = INT_MAX;

        for (int i=0; i<n; i++) {
            int l = i;
            int low = l, high = n-1;
            int r1 = INT_MAX;

            while (high >= low) {
                int mid = low + (high-low)/2;
                int r = mid;
                int val = segtree.query(l,r);
                if (val > target) {
                    r1 = min(r1, val);
                    low = mid + 1;
                } else if (val == target) {
                    r1 = val;
                    break;
                } else high = mid-1;
            }

            low = l, high = n-1;
            int r2 = INT_MIN;

            while (high >= low) {
                int mid = low + (high-low)/2;
                int r = mid;
                int val = segtree.query(l,r);
                if (val < target) {
                    r2 = max(r2, val);
                    high = mid-1;                    
                } else if (val == target) {
                    r2 = val;
                    break;
                } else {
                   low = mid + 1;
                }
            }

            if (r1 != INT_MAX) {
                ans = min(ans, abs(r1-target));
            } 
            if (r2 != INT_MIN) {
                ans = min(ans, abs(r2-target));
            }
        }
        return ans;
    }
};