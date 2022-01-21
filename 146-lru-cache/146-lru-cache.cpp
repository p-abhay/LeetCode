class Node {
public:
    int key;
    int value;
    Node * next;
    Node * prev;

    Node() {
        key = 0;
        value = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int k, int d) {
        key = k;
        value = d;
    }
};
class LRUCache {
public:
    Node *mru;
    Node *lru;
    map<int,Node*> mp;
    int cap;
    LRUCache(int capacity) {
        
        mru = new Node(-1,-1);
        lru = new Node(-1,-1);
        mru->next = lru;
        lru->prev = mru;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else
        {
            Node* node = mp[key];
            delete1(node);
            insert(node);
            return node->value;
        }
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            delete1(node);
        }
        if(cap == mp.size())
            delete1(lru->prev);
        
        //Node *node = new Node(key,value);
        insert(new Node(key,value));
    }
    
    void insert(Node *node)
    {
        mru->next->prev = node;
        node->next = mru->next;
        mru->next = node;
        node->prev = mru;
        
        mp[node->key] = node;
    }
    
    void delete1(Node *node)
    {
        mp.erase(node->key);
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */