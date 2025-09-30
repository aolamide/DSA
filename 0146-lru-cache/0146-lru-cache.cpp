struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int cap;
    Node *head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveNodeToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node* n = cache[key];
        moveNodeToFront(n);
        return n->val;
    }
    
    void put(int key, int value) {
        //if key already exists
        if(cache.count(key)) {
            Node* n = cache[key];
            n->val = value;
            moveNodeToFront(n);
        } else {
            //check capacity
            if(cache.size() >= cap) {
                //remove last node
                Node* lastNode = tail->prev;
                removeNode(lastNode);
                cache.erase(lastNode->key);
            }
            //new node
            Node* newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */