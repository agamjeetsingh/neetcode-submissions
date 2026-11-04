struct Node {
    vector<Node*> children{26};
    bool endsAt = false;
};

class PrefixTree {
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
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
        Node* head = root;
        for (char c: word) {
            if (!head->children[c - 'a']) return false;
            head = head->children[c - 'a'];
        }
        return head->endsAt;
    }
    
    bool startsWith(string prefix) {
        Node* head = root;
        for (char c: prefix) {
            if (!head->children[c - 'a']) return false;
            head = head->children[c - 'a'];
        }
        return true;
    }

private:
    Node* root = new Node();
};
