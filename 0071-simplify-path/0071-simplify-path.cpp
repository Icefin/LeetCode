class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/')
                continue;
            string directory = "";
            while (i < path.length() && path[i] != '/') {
                directory += path[i];
                i++;
            }
            if (directory == ".") {
                continue;
            }
            else if (directory == "..") {
                if (!directories.empty())
                    directories.pop_back();
            }
            else {
                directories.push_back(directory);
            }
        }
        string ans = "/";
        for (int i = 0; i < directories.size(); i++)
            ans += directories[i] + "/";
        if (ans.length() > 1)
            ans.pop_back();
        return ans;
    }
};