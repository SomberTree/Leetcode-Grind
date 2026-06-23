class Solution {
    string handle_normal(string& path, int i) {
        string dir;
        for (int j=i; j<path.size() && path[j] != '/'; j++) {
            dir.push_back(path[j]);
        }

        return dir;
    }
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> dirs;
        for (int i=0; i<path.size(); i++) {
            while (i<n && path[i] == '/') i++;
            string dir;

            if (i+2<n && path[i] == '.' && path[i+1] == '.' && path[i+2] != '/') {
                dir = handle_normal(path, i);
                dirs.push_back(dir);
                i += dir.size();
            } else if ((i+1<n && path[i] == '.' && path[i+1] == '.')|| (i+2 < n && path[i] == '.' && path[i+1] == '.' && path[i+2] == '/')) {
                // handle_double_period(dirs);
                if (!dirs.empty()) dirs.pop_back();
            } else if ((i+1 == n && path[i] == '.') || (i+1<n && path[i] == '.' && path[i+1] == '/')) {
                continue;
            } else if (i<n){
                dir = handle_normal(path, i);
                dirs.push_back(dir);
                i += dir.size();
            }
        }

        string ans;
        for (const auto& dir:dirs) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};