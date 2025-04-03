#include "common.h"
#include <sstream>  // 用于 std::istringstream
#include <stdexcept>  // 用于 std::invalid_argument

char readMenuSelection(int options) {
    string str;
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || str[0] - '0' < 1 || str[0] - '0' > options) {
            cout << "输入错误：请重新选择：";
        } else {
            break;
        }
    }
    return str[0];
}

char readQuitConfirm() {
    string str;
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || (toupper(str[0]) != 'Y' && toupper(str[0]) != 'N')) {
            cout << "输入错误：请重新选择：";
        } else {
            break;
        }
    }
    return toupper(str[0]);
}

int readAmount() {
    int amount;
    string str;
    while (true) {
        getline(cin, str);
        // 使用 std::istringstream 替代 stoi
        std::istringstream iss(str);
        if (iss >> amount) {  // 如果成功转换为整数
            break;
        } else {
            cout << "输入错误：请输入数字：";
        }
    }
    return amount;
}
