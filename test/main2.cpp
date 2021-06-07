#include <unordered_map>
#include <memory>
#include <fstream>
#include <cstring>
#include <functional>

#include "Student.hpp"
#include "Skiplist.hpp"
#include "util.h"
#include "Timer.h"

std::unordered_map<std::string, long> nameToID;
std::unordered_map<long, Student*> mp;
std::set<Student*, cmp> st;

long getId() {                                  // 输入学号或姓名
    std::string item;
    std::cin >> item;
    long id = ags::stol(item);
    if (id == 0) {
        if (nameToID.count(item)) {
            id = nameToID[item]; 
        } else {
	        return 0;
        }
    }
    return id;
}

// 从文件中读取信息，存入红黑树和哈希表中
void ReadFile(const char *filePath) {
    Timer t;
    std::ifstream stream(filePath);
    if (stream) {
        std::string line;
        long id;
        std::string name;
        double score;
        while (stream >> id >> name >> score) {
            auto s = new Student(id, name, score);
            // sl.insert(s);
            mp[s->get_id()] = s; 
            st.insert(s);
        }
        stream.close();
    } else {
        std::cout << "Not Found this File!" << std::endl;
        exit(1);
    }
}

// 释放内存
void release() {
    for (auto [_, y] : mp) {
        delete y;
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Please input FileName!" << std::endl;
        return 1;
    }

    const char *FileName = argv[1];
    char s[20] = "../txt/";
    const char* filePath = strcat(s, FileName);

    ReadFile(filePath);
    
    bool stop = false;

    while (!stop) {
        showMemu();
        printf("请输入你的选择!\n");
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 0: {
                showList(st);
                break;
            }
            case 1: {
                printf("请输入学生姓名，学号以及成绩:\n");
                std::string name;
                long id;
                double score;
                std::cin >> name >> id >> score;
                Timer t;
                auto s = new Student(id, name, score);
                nameToID[name] = id;
                addStudent(st, s);
                mp[s->get_id()] = s;
                break;
            }
            case 2: {
                printf("请输入要删除的学生的学号或姓名:\n");
                long id = getId();
                Timer t;
                if (!mp.count(id)) {
                    printf("没有这个学生!\n");
				    break;
                }
                auto s = mp[id];
                delStudent(st, s);
                mp.erase(id);
                nameToID.erase(s->getName());
                delete s;
                break;
            }
            case 3: {
                printf("请输入你要修改的学生的学号或姓名：\n");
                long id = getId();
                if (id == 0) {
                    printf("没有这个学生!\n");
				    break;
                }
                if (!mp.count(id)) {
                    printf("没有这个学生!\n");
				    break;
                }
                printf("请问要修改的是姓名还是成绩\n");
                printf("修改姓名: 0\n");
                printf("修改成绩: 1\n");
                printf("都修改: 2\n");
                int ch;
                std::cin >> ch;
                if (ch < 0 || ch > 2) {
                    printf("错误选择\n");
                    break;
                }
                auto s = mp[id];
                delStudent(st, s);
                std::function<void()> func[3];
                func[0] = [&]() {
                    printf("请输入新的姓名: \n");
                    std::string newName;
                    std::cin >> newName; 
                    nameToID.erase(s->getName());
                    nameToID[newName] = s->get_id();
                    s->changeName(newName);
                };
                func[1] = [&]() {
                    printf("请输入新的成绩: \n");
                    double newScore;
                    std::cin >> newScore;
                    s->changeScore(newScore);
                };
                func[2] = [&]() {
                    printf("请输入新的姓名以及成绩: \n");
                    std::string newName;
                    double newScore;
                    std::cin >> newName >> newScore;
                    nameToID.erase(s->getName());
                    nameToID[newName] = s->get_id();
                    s->changeName(newName);
                    s->changeScore(newScore);
                };
                func[ch]();
                addStudent(st, s);
                break;
            }
            case 4: {
                printf("请输入要查看学生的学号或姓名: \n");
			    long id = getId();
                Timer t;
                if (!mp.count(id)) {
                    printf("没有这个学生!\n");
				    break;
                }
			    auto s = mp[id];
			    std::cout << *s << std::endl;
                break;
            }
            case 5: {
                stop = true;
                break;
            }
            default: {
                printf("请重新输入你的选择\n");
                break;
            }
        }
    }

    release();

    return 0;
}