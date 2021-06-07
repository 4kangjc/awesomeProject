#pragma once
#include <unordered_map>



struct DoubleNode {
    int key, value;
    DoubleNode* prev, *next;
    DoubleNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    DoubleNode() = default;
};

class LRUCache {
private:
    int len;
    int cap;
    DoubleNode* head, *tail;
    std::unordered_map<int, DoubleNode*> cache;
private:
    void removeNode(DoubleNode* node);
    void addToHead(DoubleNode* node);
    void moveToHead(DoubleNode* node);
    DoubleNode* removeTail();

public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    ~LRUCache();
};