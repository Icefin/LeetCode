/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ans;
        ans.push_back(startUrl);
        unordered_set<string> us_urls;
        us_urls.insert(startUrl);
        
        string startHostName = getHostName(startUrl);
        
        queue<string> q;
        q.push(startUrl);
        while(!q.empty()) {
            string curr = q.front(); q.pop();
            
            vector<string> tmp = htmlParser.getUrls(curr);
            for (int i = 0; i < tmp.size(); i++) {
                if (us_urls.find(tmp[i]) != us_urls.end())
                    continue ;
                string parseHostName = getHostName(tmp[i]);
                if (startHostName.compare((parseHostName)) == 0) {
                    q.push(tmp[i]);  
                    ans.push_back(tmp[i]);
                }
                us_urls.insert(tmp[i]);
            }
        }
        return (ans);
    }
    
private :
    string getHostName(string url) {
        int ptr;
        for (ptr = 7; ptr < url.length(); ptr++) {
            if (islower(url[ptr]) != 0 || isdigit(url[ptr]) != 0 || url[ptr] == '-' || url[ptr] == '.')
                continue;
            break;
        }
        string ans = url.substr(7, ptr - 7);
        return (ans);
    }
};