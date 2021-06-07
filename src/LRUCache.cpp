#include "LRUCache.h"


void LRUCache::removeNode(DoubleNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::addToHead(DoubleNode* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void LRUCache::moveToHead(DoubleNode* node) {
    removeNode(node);
    addToHead(node);
}

DoubleNode* LRUCache::removeTail() {
    auto node = tail->prev;
    removeNode(node);
    return node;
}

LRUCache::LRUCache(int capacity) : len(0), cap(capacity), head(new DoubleNode()), tail(new DoubleNode()) {
    head->next = tail;
    tail->prev = head;
}

int LRUCache::get(int key) {
    if (cache.find(key) != cache.end()) {
        moveToHead(cache[key]);
        return cache[key]->value;
    }
    return -1;
}


void LRUCache::put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
        it->second->value = value;
        moveToHead(it->second);
    } else {
        DoubleNode* node = new DoubleNode(key, value);
        cache[key] = node;
        addToHead(node);
        ++len;
        if (len > cap) {
            auto removed = removeTail();
            cache.erase(removed->key);
            delete removed;
            --len;
        }
    }
}


LRUCache::~LRUCache() {
    while (head != tail) {
        auto temp = head;
        head = head->next;
        delete temp;
    }
}