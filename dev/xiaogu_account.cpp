#include "common.h"
#include "account_item.h"
#include <vector>

int main() {
    vector<AccountItem> items;
    loadDataFromFile(items);

    bool quit = false;
    while (!quit) {
        showMainMenu();
        char key = readMenuSelection(3);

        switch (key) {
            case '1':
                showAccountingMenu();
                accounting(items);
                break;
            case '2':
                showQueryMenu();
                query(items);
                break;
            case '3':
                cout << "ȷ���˳�?(Y/N): ";
                if (readQuitConfirm() == 'Y') {
                    quit = true;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
