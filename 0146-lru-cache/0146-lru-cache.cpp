class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    Node* head = new Node(-1, -1); // dummy head node
    Node* tail = new Node(-1, -1); // dummy tail node
    int cap; // it is capacity
    //in order to store the location of each node
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        cap = capacity;
        //linking the dummy nodes
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* newNode) {
        Node* curr = head->next;
        newNode->next = curr;
        newNode->prev = head;
        head->next = newNode;
        curr->prev = newNode;
    }

    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key1) {
        // check if map doesnot have key
        if (mpp.find(key1) != mpp.end()) { // if it has key already
        Node* resnode = mpp[key1];
        //storing the value of node
        int res = resnode->val;
        //deleting it in order to get it again (restoring the address of key)
        mpp.erase(key1);
        deleteNode(resnode);
        insertAfterHead(resnode);
        mpp[key1] = head->next;
        return res;
        }
        return -1;
    }

    void put(int key1, int value) {
        //if value already exists in map reupdate it with new value
        if(mpp.find(key1) != mpp.end()){
            Node*existingNode = mpp[key1];
            mpp.erase(key1);
            deleteNode(existingNode);
        }
        //if capacity of cache is reached delete the node before the tail
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertAfterHead(new Node(key1, value));
        mpp[key1] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */