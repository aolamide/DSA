struct Node {
    Node *prev, *next;
    string val;
    Node(string page) : val(page), prev(nullptr), next(nullptr) {};
};

class BrowserHistory {
private:
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* tmp = new Node(url);
        curr->next = tmp;
        tmp->prev = curr;
        
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps > 0 && curr->prev) {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps > 0 && curr->next) {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */