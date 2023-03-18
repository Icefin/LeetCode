class BrowserHistory {
    class HistoryNode {
        public :
            HistoryNode(string url) {
                this->url = url;                
            }
        
            string url;
            HistoryNode* next = nullptr;
            HistoryNode* prev = nullptr;
    };
public:
    HistoryNode* curr;
    
    BrowserHistory(string homepage) {
        curr = new HistoryNode(homepage);
    }
    
    void visit(string url) {
        curr->next = new HistoryNode(url);
        curr->next->prev  = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while (steps != 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (steps != 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */