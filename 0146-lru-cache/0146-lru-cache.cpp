// class LRUCache {
// list<pair<int, int>> dll;
// unordered_map<int, list<pair<int, int>>::iterator> m;
// int capacity;
// public:
//     LRUCache(int _capacity) {
//         capacity = _capacity;
//     }

//     int get(int key) {
//         if(m.count(key) == 0) return -1;
//         auto itr = m[key];
//         auto item = *itr;
//         dll.erase(itr);
//         dll.push_front(item);
//         m[key] = dll.begin();
//         return item.second;
//     }

//     void put(int key, int value) {
//         if(m.count(key) == 1) {
//             // If key exists, update value for that key
//             auto itr = m[key];
//             dll.erase(itr);
//             dll.push_front({key, value});
//             m[key] = dll.begin();
//         } else {
//             if(dll.size() >= capacity) {
//                 // Evict LRU
//                 auto item = dll.back();
//                 dll.pop_back();
//                 m.erase(item.first);
//             }
//             // Insert new key, val
//             dll.push_front({key, value});
//             m[key] = dll.begin();
//         }
//     }
// };
class Node {
public:
    Node *prev, *next;
    pair<int, int> val;
    Node(pair<int, int> value) {
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
int capacity;
int currSize = 0; 
Node *start = new Node({-1,-1}), *end = new Node({-1, -1});
unordered_map<int, Node*> mp;
    
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        start->next = end;
        end->prev = start;
    }
    void addNode(Node* newNode) {
        newNode->next = end;
        newNode->prev = end->prev;
        end->prev->next = newNode;
        end->prev = newNode;
        mp[newNode->val.first] = newNode;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // mp.erase(node->val.first);
    }
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node *curr = mp[key];
        removeNode(curr);
        addNode(curr);
        return curr->val.second;
    }

    void put(int key, int value) {
        if(mp.count(key)) {
            Node *curr = mp[key];
            removeNode(curr);
            curr->val.second = value;
            addNode(curr);
            
        } else {
            if(currSize == capacity) {
                mp.erase(start->next->val.first);
                removeNode(start->next);
                currSize--;
            }
            Node *newNode = new Node({ key, value });
            addNode(newNode);
            currSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */