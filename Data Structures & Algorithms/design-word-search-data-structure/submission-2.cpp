struct Node {
    vector<Node*> children{26};
    bool endsAt;
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* head = root;

        for (char c: word) {
            if (!head->children[c - 'a']) {
                head->children[c - 'a'] = new Node();
            }

            head = head->children[c - 'a'];
        }

        head->endsAt = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }

    bool search(string word, int start, Node* root) {
        if (!root) return false;
        Node* head = root;

        for (int i = start; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (!head->children[c - 'a']) {
                    return false;
                }

                head = head->children[c - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (search(word, i + 1, head->children[j])) {
                        return true;
                    }
                }
                return false;
            }
        }

        return head->endsAt;
    }

    Node* root = new Node();
};
