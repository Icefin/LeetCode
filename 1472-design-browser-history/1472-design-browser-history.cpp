class BrowserHistory {
public:
    vector<string> history;
    int currURL, lastURL;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currURL = 0;
        lastURL = 0;
    }
    
    void visit(string url) {
        currURL++;
        if (history.size() > currURL) {
            history[currURL] = url;
        }
        else {
            history.push_back(url);
        }
        lastURL = currURL;
    }
    
    string back(int steps) {
        currURL = max(0, currURL - steps);
        return history[currURL];
    }
    
    string forward(int steps) {
        currURL = min(lastURL, currURL + steps);
        return history[currURL];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */