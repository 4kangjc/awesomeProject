# awesomeProject 一个基于跳表的管理系统

## Introduction
大一大作业
## 编译
* 编译环境
*Linux Ubuntu 20.04*    
*gcc version 10.2.0   (最低 gcc 7.1)*  
*cmake version 3.16.3 (最低 cmake 3.8)*  

* 编译安装
```
git clone https://github.com/4kangjc/awesomeProject.git
cd awesomeProject && mkdir build
cd build && cmake ..
make
```

## 运行
* 建一个文件夹txt, 里面存放初始数据
* 在build目录或者bin目录下运行(build目录下`../bin/main s.txt`)
* 也可以基于红黑树(`../bin/main s.txt 1`)

# 技术要点
* 使用跳表，而非链表，提高了查找效率, 时间复杂度为O(logn), 与红黑树性能相当  
* 跳表的基本实现, 支持自定义类型, 要求有默认构造函数  
* 不依赖于除标准库以外的库, 支持跨平台(Linux os, Mac os, Window os)  
* 无内存泄露, 可用工具valgrind测试  
