class LRUCache {
public:
    class Node {
        public: 
            int key, val;
            Node* prev;
            Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*>um;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void deletenode(Node *existingnode) {
        Node *exisprev = existingnode -> prev;
        Node *exisnext = existingnode -> next;
        exisprev -> next = exisnext;
        exisnext -> prev = exisprev;
    }
    
    void addnode(Node *newnode) {
        Node *headnext = head -> next;
        head -> next = newnode;
        newnode -> next = headnext;
        headnext -> prev = newnode;
        newnode -> prev = head;
    }
    
    int get(int key_) {
        if(um.find(key_) != um.end()) {
            Node *getnode = um[key_];
            int resval = getnode -> val;
            um.erase(key_);
            deletenode(getnode);
            addnode(getnode);
            um[key_] = head -> next;
            return resval;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(um.find(key_) != um.end()) {
            Node *existingnode = um[key_];
            um.erase(key_);
            deletenode(existingnode);
        }
        if(um.size() == cap) {
            um.erase(tail -> prev -> key);
            deletenode(tail->prev);
        }
        addnode(new Node(key_, value));
        um[key_] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
