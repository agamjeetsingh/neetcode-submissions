struct Node {
    vector<Node*> children = vector<Node*>(26);
    bool endsAt;
};

class PrefixTree {
public:
    PrefixTree() {
        
    }

    Node* root = new Node();
    
    void insert(string word) {
        Node* curr = root;
        for (char c: word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->endsAt = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c: word) {
            if (!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
        }
        return curr->endsAt;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c: prefix) {
            if (!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};
