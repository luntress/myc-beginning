#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define INCOME "shouru"
#define EXPAND "zhichu"
#define FILENAME "D:\\data\\accountBook.txt"

using namespace std;

// 菜单显示函数
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();

// 输入读取函数
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();

#endif // COMMON_H
