/**
 * @file memu.cpp
 * @author kangjinci (you@domain.com)
 * @brief  菜单目录
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
// 展示菜单
void showMemu() {
	printf("----------------------------------------------\n");
	printf("*************"); std::cout << "欢迎来到学生管理系统";  printf("*************\n");
	printf("你可以做出以下选择\n");
	printf("\t\t0. 展示所有学生成绩\n");
	printf("\t\t1. 添加学生信息\n");
	printf("\t\t2. 删除学生信息\n");
	printf("\t\t3. 更改学生信息\n");
	printf("\t\t4. 查看学生信息\n");
	printf("\t\t5. 退出\n");
	printf("************************************************\n");
}