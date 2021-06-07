/**
 * @file testStudent.cc
 * @author kangjinci (you@domain.com)
 * @brief  测试Student类的基本使用
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Student.hpp"
#include <unordered_map>

int main() {
    Student s1(3200421149, "kjc", 99);
    std::cout << s1 << std::endl;
    Student s2(3200421148, "zqd", 98);
    std::cout << (s1 == s2) << std::endl;
    std::cout << (s1 > s2) << std::endl;
    s2.println();

    auto stu1 = new Student(0, "kjc", 00);
    auto stu2 = new Student(1, "sw", 01);
    auto stu3 = new Student(2, "zqd", 02);

    std::cout << *stu1 << std::endl;
    printf("\n");

    std::unordered_map<long, Student*> mp;

    mp[0] = stu1;
    mp[1] = stu2;
    mp[2] = stu3;

    for (auto [x, y] : mp) {
        std::cout << "key = " << x << " value = " << *y << std::endl;
    }

    for (auto [_, y] : mp) {
        delete y;
    }

    return 0;
}