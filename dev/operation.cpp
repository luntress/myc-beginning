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

    cout << "\n���������";
    item.amount = readAmount();
    cout << "\n��ע��";
    cin.ignore(); // ���������
    getline(cin, item.detail);
    items.push_back(item);
    insertIntoFile(item);

    cout << "\n--------------------���˳ɹ�------------------" << endl;
    cout << "\n��ص����˵�" << endl;
    string line;
    getline(cin, line);
}

void expand(vector<AccountItem>& items) {
    AccountItem item;
    item.itemType = EXPAND;

    cout << "\n����֧����";
    item.amount = readAmount();
    cout << "\n��ע��";
    cin.ignore(); // ���������
    getline(cin, item.detail);
    items.push_back(item);
    insertIntoFile(item);

    cout << "\n--------------------���˳ɹ�------------------" << endl;
    cout << "\n��ص����˵�" << endl;
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
    // ʹ�ô�ͳ��������� auto ��Χѭ��
    for (vector<AccountItem>::const_iterator it = items.begin(); it != items.end(); ++it) {
        printItem(*it);  // ͨ�������õ���������Ԫ��
        total += it->amount;
    }
    cout << "�ܼƽ�" << total << endl;
    string line;
    getline(cin, line);
}

void queryItems(const vector<AccountItem>& items, const string& itemType) {
    int total = 0;
    // ʹ�ô�ͳ��������� auto ��Χѭ��
    for (vector<AccountItem>::const_iterator it = items.begin(); it != items.end(); ++it) {
        if (it->itemType == itemType) {
            printItem(*it);
            total += it->amount;
        }
    }
    cout << ((itemType == INCOME) ? "�����ܼƣ�" : "֧���ܼƣ�") << total << endl;
    string line;
    getline(cin, line);
}
void printItem(const AccountItem& item) {
    cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}
