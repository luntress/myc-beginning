#include "common.h"
#include <sstream>  // ���� std::istringstream
#include <stdexcept>  // ���� std::invalid_argument

char readMenuSelection(int options) {
    string str;
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || str[0] - '0' < 1 || str[0] - '0' > options) {
            cout << "�������������ѡ��";
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
            cout << "�������������ѡ��";
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
        // ʹ�� std::istringstream ��� stoi
        std::istringstream iss(str);
        if (iss >> amount) {  // ����ɹ�ת��Ϊ����
            break;
        } else {
            cout << "����������������֣�";
        }
    }
    return amount;
}
