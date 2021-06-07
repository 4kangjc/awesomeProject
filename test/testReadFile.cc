/**
 * @file testReadFile.cc
 * @author kangjinci (you@domain.com)
 * @brief  测试读取文件
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Student.hpp"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <optional>
#include <iostream>
#include <cstring>
#include <vector>

void ReadFile(const char *filePath) {
    std::ifstream stream(filePath);
    if (stream) {
        std::string line;
        while (std::getline(stream, line)) {
            std::cout << line << std::endl;
            std::vector<std::string> vec;
            boost::split(vec, line, boost::is_any_of(" "));
            for (const auto &ss : vec) {
                std::cout << ss << std::endl;
            }
        }
        stream.close();
    } else {
        std::cout << "Not Found this File!" << std::endl;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    
    ReadFile("s.txt");

    return 0;
}