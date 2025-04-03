#include "common.h"

void showMainMenu() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << "============欢迎使用小谷记账薄===========" << endl;
    cout << "*************  1.记账     **************" << endl;
    cout << "*************  2.查询     **************" << endl;
    cout << "*************  3.退出     **************" << endl;
    cout << "\n请选择（1-3）：";
}

void showAccountingMenu() {
    cout << "-----------------------------------------" << endl;
    cout << "============选择记账种类===========" << endl;
    cout << "*************  1.收入     **************" << endl;
    cout << "*************  2.支出     **************" << endl;
    cout << "*************  3.返回主页 **************" << endl;
    cout << "\n请选择（1-3）：";
}

void showQueryMenu() {
    cout << "-----------------------------------------" << endl;
    cout << "============选择查询条件===========" << endl;
    cout << "*************  1.统计所有 **************" << endl;
    cout << "*************  2.统计收入 **************" << endl;
    cout << "*************  3.统计支出 **************" << endl;
    cout << "*************  4.返回主页 **************" << endl;
    cout << "\n请选择（1-4）：";
}
