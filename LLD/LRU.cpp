#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = prev = nullptr;
    }
};

class LRUCache {
    unordered_map<int, Node*> mpp;  // key -> Node*
    int cap;
    Node* head;
    Node* tail;

    // insert node right after head
    void insertHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    // delete the given node
    void deleteNode(Node* node) {
        Node* prevno = node->prev;
        Node* nextno = node->next;
        prevno->next = nextno;
        nextno->prev = prevno;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);  // dummy head
        tail = new Node(-1, -1);  // dummy tail
        head->next = tail;  
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            int value = node->val;
            // move node to front (most recent)
            deleteNode(node);
            insertHead(node);
            return value;
        }
        return -1; // not found
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            // update existing node
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertHead(node);
        } else {
            if (mpp.size() == cap) {
                // remove least recently used (node before tail)
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            insertHead(node);
            mpp[key] = node;
        }
    }
};
