class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    // Hash map to store key -> count
    unordered_map<string, Node*> mp;
    // Head and tail pointers for the doubly linked list
    Node *head, *tail;

    void addNode(Node* prevNode, int count) {
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if (prevNode == tail) {
            tail = newNode;
        }
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
        if (tail == node) {
            tail = node->prev;
        }
        delete node;
    }

public:
    AllOne() {
        // Initialize head and tail dummy nodes for the doubly linked list
        head = new Node(0);
        tail = head;
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            // not Exists
            if (head->next == nullptr || head->next->count != 1) {
                addNode(head, 1);
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        } else { // key is there in the map
            // increase freq
            Node* currNode = mp[key];
            int currCount = currNode->count;
            if (currNode->next == nullptr ||
                currNode->next->count != currCount + 1) {
                addNode(currNode, currCount + 1);
            }
            currNode->next->keys.insert(key);
            mp[key] = currNode->next;
            currNode->keys.erase(key);
            if (currNode->keys.empty()) {
                removeNode(currNode);
            }
        }
    }

    void dec(string key) {
        Node* currNode = mp[key];
        int currCount = currNode->count;

        if (currCount == 1) {
            mp.erase(key);
        } else {
            if (currNode->prev->count != currCount - 1) {
                addNode(currNode->prev, currCount - 1);
            }
            currNode->prev->keys.insert(key);
            mp[key] = currNode->prev;
        }
        currNode->keys.erase(key);
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }

    string getMaxKey() {
        if(tail == head) {
            return "";
        }
        return *tail->keys.begin();
    }

    string getMinKey() {
        if(head->next == nullptr){
            return "";
        }
        return *head->next->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */