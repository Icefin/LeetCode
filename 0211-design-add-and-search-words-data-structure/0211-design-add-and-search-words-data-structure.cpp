class WordDictionary {
public:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEnd;
    
        TrieNode() {
            isEnd = false;
        }
    };
    
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return (dfs_search(root, word, 0));
    }

    bool dfs_search(TrieNode* node, string& word, int index) {
        if (index == word.length()) {
            return (node->isEnd);
        }
        char c = word[index];
        if (c == '.') {
            for (auto& p : node->children) {
                if (dfs_search(p.second, word, index + 1)) return (true);
            }
            return (false);
        } 
        else {
            if (node->children.find(c) == node->children.end()) return (false);
            TrieNode* child = node->children[c];
            return (dfs_search(child, word, index + 1));
        }
    }
    
private :
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */