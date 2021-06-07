#pragma once
#include "Student.hpp"
#include "Skiplist.hpp"

#include <set>

void showMemu();
void showList(const Skiplist<Student>& sl);
void addStudent(Skiplist<Student>& sl, Student* s);
void delStudent(Skiplist<Student>& sl, Student* s);

struct cmp {
    bool operator()(Student* s1, Student* s2) const {
        return *s1 < *s2;
    }
};

void showList(const std::set<Student*, cmp>& st);
void addStudent(std::set<Student*, cmp>& st, Student* s);
void delStudent(std::set<Student*, cmp>& st, Student* s);

namespace ags {
    long stol(const std::string&);
}
