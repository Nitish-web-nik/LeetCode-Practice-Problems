class LRUCache {
private:
    // Doubly linked list node structure
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // Most recently used
    Node* tail; // Least recently used
    
    // Helper function to remove a node from the list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Helper function to add node to the front (MRU position)
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // Initialize dummy head and tail nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Remove from current position
            removeNode(node);
            // Add to front (MRU position)
            addToFront(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update value and move to front
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } else {
            // New key
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);
            
            // Check capacity
            if (cache.size() > capacity) {
                // Remove LRU (tail->prev)
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};
