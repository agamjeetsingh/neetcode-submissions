struct Node {
    vector<Node*> children = vector<Node*>(26);
    bool endsAt;
};

class WordDictionary {
public:
    WordDictionary() {
        
    }

    Node* root = new Node();
    
    void addWord(string word) {
        Node* curr = root;
        for (char c: word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->endsAt = true;
    }

    bool search(string word, Node* node, int start) {
        if (word.size() <= start) return true;
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && search(word, node->children[i], start + 1)) return true;
            }
        } else if (node->children[word[start] - 'a'] && search(word, node->children[word[start] - 'a'], start + 1)) return true;
        return false;
    }
    
    bool search(string word) {
        return search(word, root, 0);
    }
};
