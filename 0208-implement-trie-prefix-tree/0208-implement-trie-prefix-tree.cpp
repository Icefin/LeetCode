class Trie {
	public :
		Trie() {
			us_prefix = std::unordered_set<std::string>();
			us_word = std::unordered_set<std::string>();
		}

		void insert(std::string word) {
			us_word.insert(word);
			while (!word.empty()) {
                if (us_prefix.find(word) != us_prefix.end())
                    return;
				us_prefix.insert(word);
                word.pop_back();
			}
		}

		bool search(std::string word) {
			return (us_word.find(word) != us_word.end());
		}

		bool startsWith(std::string prefix) {
			return (us_prefix.find(prefix) != us_prefix.end());
		}

	private :
		std::unordered_set<std::string> us_prefix;
		std::unordered_set<std::string> us_word;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */