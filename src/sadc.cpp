#include "Skiplist.hpp"
#include "Student.hpp"
#include "util.h"

#include <sstream>

void showList(const Skiplist<Student>& sl) {
    sl.println();
}

void addStudent(Skiplist<Student>& sl, Student* s) {
    sl.insert(s);
}

void delStudent(Skiplist<Student>& sl, Student* s) {
    sl.erase(s);
}


void showList(const std::set<Student*, cmp>& st) {
    for (auto s : st) {
        std::cout << *s << std::endl;
    }
}

void addStudent(std::set<Student*, cmp>& st, Student* s) {
    st.insert(s);
}

void delStudent(std::set<Student*, cmp>& st, Student* s) {
    st.erase(s);
}

namespace ags {
    long stol(const std::string& s) {
        long v = 0;
        std::stringstream ss(s);
        ss >> v;
        return v;
    }
}