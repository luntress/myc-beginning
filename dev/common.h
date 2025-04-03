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

// �˵���ʾ����
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();

// �����ȡ����
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();

#endif // COMMON_H
