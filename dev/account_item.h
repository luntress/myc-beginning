#ifndef ACCOUNT_ITEM_H
#define ACCOUNT_ITEM_H

#include <vector>
#include <string>

struct AccountItem {
    std::string itemType;
    int amount;
    std::string detail;
};

// 文件操作函数
void loadDataFromFile(std::vector<AccountItem>& items);
void insertIntoFile(const AccountItem& item);

// 记账函数
void income(std::vector<AccountItem>& items);
void expand(std::vector<AccountItem>& items);
void accounting(std::vector<AccountItem>& items);

// 查询函数
void query(const std::vector<AccountItem>& items);
void queryItems(const std::vector<AccountItem>& items, const std::string& itemType);
void queryItems(const std::vector<AccountItem>& items);

// 打印函数
void printItem(const AccountItem& item);

#endif // ACCOUNT_ITEM_H
