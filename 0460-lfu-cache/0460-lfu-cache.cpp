#include <bits/stdc++.h>
using namespace std;

struct node {
    int key, value, cnt;
    node *next;
    node *prev;
    node(int key1, int value1) {
        key = key1;
        value = value1;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    int size;
    node *head;
    node *tail;
    
    List() {
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void add(node *Nnode) {
        node *temp = head->next;
        Nnode->next = temp;
        Nnode->prev = head;
        head->next = Nnode;
        temp->prev = Nnode;
        size++;
    }

    void removeNode(node *delnode) {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, node*> keyNode;
    map<int, List*> freqMap;
    int maxSize;
    int freq;
    int curr;
    
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        freq = 0;
        curr = 0;
    }

    void updateFreq(node *Nnode) {
        keyNode.erase(Nnode->key);
        freqMap[Nnode->cnt]->removeNode(Nnode);
        
        if (Nnode->cnt == freq && freqMap[Nnode->cnt]->size == 0) {
            freq++;
        }

        List *nextHigh;
        if (freqMap.find(Nnode->cnt + 1) != freqMap.end()) {
            nextHigh = freqMap[Nnode->cnt + 1];
        } else {
            nextHigh = new List();
        }

        Nnode->cnt += 1;
        nextHigh->add(Nnode);
        freqMap[Nnode->cnt] = nextHigh;
        keyNode[Nnode->key] = Nnode;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            node *Nnode = keyNode[key];
            int val = Nnode->value;
            updateFreq(Nnode);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSize == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            node *Nnode = keyNode[key];
            Nnode->value = value;
            updateFreq(Nnode);
        } else {
            if (curr == maxSize) {
                List *list = freqMap[freq];
                keyNode.erase(list->tail->prev->key);
                freqMap[freq]->removeNode(list->tail->prev);
                curr--;
            }
            curr++;
            freq = 1;
            List *listf;
            
            if (freqMap.find(freq) != freqMap.end()) {
                listf = freqMap[freq];
            } else {
                listf = new List();
            }

            node *Nnode = new node(key, value);
            listf->add(Nnode);
            keyNode[key] = Nnode;
            freqMap[freq] = listf;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
