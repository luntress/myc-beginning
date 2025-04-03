#include "common.h"
#include "account_item.h"

void loadDataFromFile(vector<AccountItem>& items) {
    ifstream input(FILENAME);
    AccountItem item;
    while (input >> item.itemType >> item.amount >> item.detail) {
        items.push_back(item);
    }
    input.close();
}

void insertIntoFile(const AccountItem& item) {
    ofstream output(FILENAME, ios::out | ios::app);
    output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
    output.close();
}

void income(vector<AccountItem>& items) {
    AccountItem item;
    item.itemType = INCOME;

    cout << "\n本次收入金额：";
    item.amount = readAmount();
    cout << "\n备注：";
    cin.ignore(); // 清除缓冲区
    getline(cin, item.detail);
    items.push_back(item);
    insertIntoFile(item);

    cout << "\n--------------------记账成功------------------" << endl;
    cout << "\n请回到主菜单" << endl;
    string line;
    getline(cin, line);
}

void expand(vector<AccountItem>& items) {
    AccountItem item;
    item.itemType = EXPAND;

    cout << "\n本次支出金额：";
    item.amount = readAmount();
    cout << "\n备注：";
    cin.ignore(); // 清除缓冲区
    getline(cin, item.detail);
    items.push_back(item);
    insertIntoFile(item);

    cout << "\n--------------------记账成功------------------" << endl;
    cout << "\n请回到主菜单" << endl;
    string line;
    getline(cin, line);
}

void accounting(vector<AccountItem>& items) {
    char key = readMenuSelection(3);
    switch (key) {
        case '1':
            income(items);
            break;
        case '2':
            expand(items);
            break;
        case '3':
            break;
        default:
            break;
    }
}

void query(const vector<AccountItem>& items) {
    char key = readMenuSelection(4);
    switch (key) {
        case '1':
            queryItems(items);
            break;
        case '2':
            queryItems(items, INCOME);
            break;
        case '3':
            queryItems(items, EXPAND);
            break;
        case '4':
            break;
        default:
            break;
    }
}

void queryItems(const vector<AccountItem>& items) {
    int total = 0;
    // 使用传统迭代器替代 auto 范围循环
    for (vector<AccountItem>::const_iterator it = items.begin(); it != items.end(); ++it) {
        printItem(*it);  // 通过解引用迭代器访问元素
        total += it->amount;
    }
    cout << "总计金额：" << total << endl;
    string line;
    getline(cin, line);
}

void queryItems(const vector<AccountItem>& items, const string& itemType) {
    int total = 0;
    // 使用传统迭代器替代 auto 范围循环
    for (vector<AccountItem>::const_iterator it = items.begin(); it != items.end(); ++it) {
        if (it->itemType == itemType) {
            printItem(*it);
            total += it->amount;
        }
    }
    cout << ((itemType == INCOME) ? "收入总计：" : "支出总计：") << total << endl;
    string line;
    getline(cin, line);
}
void printItem(const AccountItem& item) {
    cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}
