/**
 * @file testSkiplish.cc
 * @author kangjinci (you@domain.com)
 * @brief 测试跳表的基本使用
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Skiplist.hpp"
#include "Student.hpp"
#include <memory>
#include <iostream>

int main() {
    Skiplist<int> sl;
    auto a = std::make_shared<int>(1);
    auto b = std::make_shared<int>(2);
    auto c = std::make_shared<int>(3);
    sl.insert(a.get());
    sl.insert(b.get());
    sl.insert(c.get());
    int* e = new int(0);
    std::cout << std::boolalpha;
    std::cout << sl.find(e) << std::endl;     // false
    int* d = new int(4);
    sl.insert(d);
    std::cout << sl.find(d) << std::endl;
    sl.println();
    std::cout << sl.find(a.get()) << std::endl;  // true
    sl.erase(e);
    sl.erase(a.get());
    std::cout << sl.find(a.get()) << std::endl; // false

    delete d;
    delete e;


    Skiplist<Student> stu;
    auto stu1 = new Student();
    auto stu2 = new Student(1, "kjc", 90);
    auto stu3 = new Student(2, "zqd", 100);
    stu.insert(stu1);
    stu.insert(stu2);
    stu.insert(stu3);

    stu.println();
     
    printf("-----------------------------\n");

    stu.erase(stu2);

    stu.println();

    delete stu1;
    delete stu2;
    delete stu3;


    return 0;
}