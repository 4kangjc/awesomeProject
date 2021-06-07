/**
 * @file Student.hpp
 * @author kangjinci (you@domain.com)
 * @brief 学生类的基本实现
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <string>
#include <iostream>

class Student {
private:
    long m_id;
    std::string m_name;
    double m_score;
public:
    Student(long id = 0, const std::string& name = "", double score = 0) : m_id(id), m_name(name), m_score(score) {}
    ~Student() = default;
    bool operator<(const Student& rhs) const {
        if (m_score != rhs.m_score) {
            return m_score < rhs.m_score;
        }
        return m_id < rhs.m_id;
    }
    bool operator>(const Student& rhs) const {
        if (m_score != rhs.m_score) {
            return m_score > rhs.m_score;
        }
        return m_id > rhs.m_id;
    }
    bool operator==(const Student& rhs) const {
        return m_id == rhs.m_id;
    }
    bool operator!=(const Student& rhs) const {
        return !(*this == rhs);
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& lhs);
    void println() const {
        std::cout << *this << std::endl;
    }
    long get_id() const {
        return m_id;
    }
    const std::string& getName() const {
        return m_name;
    }
    void changeName(const std::string& name) {
        m_name = name;
    }
    void changeScore(double score) {
        m_score = score;
    }
};

std::ostream& operator<<(std::ostream& os, const Student& lhs) {
    os << "学号: " << lhs.m_id << "\t名字: " << lhs.m_name << "\t成绩: " << lhs.m_score;
    return os;
}