/**
 * @file Skiplist.h
 * @author kangjinci (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <time.h>
#include <vector>
#include <map>
#include <climits>
#include <stdlib.h>
#include <memory>
#include <iostream>

const int HALF_RAND_MAX = RAND_MAX / 2;
const int MAX_LEVEL = 16;


template <typename T>
struct SkiplistNode {
    T* val;
    std::vector<SkiplistNode<T>*> next;
public:
    SkiplistNode(T* val, int size = MAX_LEVEL) : val(val), next(size) {}
};


template <typename T>
class Skiplist {
    static int random_level() {
        int level = 1;
        while (rand() < HALF_RAND_MAX && level < MAX_LEVEL) {
            ++level;
        }
        return level;
    }

    std::vector<SkiplistNode<T>*> __serch(T* target) {
        auto cur = head;
        std::vector<SkiplistNode<T>*> prev(MAX_LEVEL);
        for (int i = maxlevel - 1; i >= 0; --i) {
            while (cur->next[i] && (*(cur->next[i]->val) < *target) ) {
                cur = cur->next[i];
            }
            prev[i] = cur;
        }
        return prev;
    }
private:
    SkiplistNode<T>* head;
    int maxlevel = 1;
public:
    Skiplist() : head(new SkiplistNode<T>(new T()))  {    }
    
    bool find(T* target) {
        SkiplistNode<T>* pre = __serch(target)[0];
        return pre->next[0] && pre->next[0]->val == target;
    }
    
    void insert(T* num) {
        auto prev = __serch(num);
        int level =  random_level();
        if (level > maxlevel) {
            for (int i = maxlevel; i < level; ++i) {
                prev[i] = head;
            }
            maxlevel = level;
        }
        SkiplistNode<T>* cur = new SkiplistNode<T>(num, level);
        for (int i = level - 1; i >= 0; --i) {
            cur->next[i] = prev[i]->next[i];
            prev[i]->next[i] = cur;
        }
    }
    
    bool erase(T* num) {
        auto prev = __serch(num);
        if (!prev[0]->next[0] || prev[0]->next[0]->val != num) {
            return false;
        }
        SkiplistNode<T>* del = prev[0]->next[0];
        for (int i = 0; i < maxlevel; ++i) {
            if (prev[i]->next[i] == del)
                prev[i]->next[i] = del->next[i];
        }
        delete del;
        while (maxlevel > 1 && !head->next[maxlevel - 1]) {
            maxlevel--;
        }
        return true;
    }
    void println() const {
        auto temp = head->next[0];
        while (temp) {
            std::cout << *(temp->val) << '\n';
            temp = temp->next[0];
        }
    }
    ~Skiplist() {
        delete head->val;
        auto temp = head;
        while (temp) {
            auto ne = temp->next[0];
            delete temp;
            temp = ne;
        }
    }
};