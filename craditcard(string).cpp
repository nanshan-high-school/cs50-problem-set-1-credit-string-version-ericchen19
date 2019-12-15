#include <iostream>
using namespace std;

int main() {
    string numstr;
    cout << "請輸入欲檢查的卡號：";
    cin >> numstr;
    int i = 0;
    int num[i];
    int len = numstr.length();
    int evensum = 0;
    int oddsum = 0;
    bool even = false;
    if (len == 16) {
        even = !even;
    }
    for (i = 0; numstr[i] != '\0'; i++) {
        num[i] = numstr[i] - '0';
        if (even) {
            int now = num[i] * 2;
            evensum = evensum + (now % 10) + (now / 10);
        } else {
            oddsum = oddsum + num[i];
        }
        even = !even;
    }
    int checksum = evensum + oddsum;
    if (checksum % 10 != 0) {
        cout << "錯誤卡號1";
        return 0;
    }
    if (len == 15 && num[0] == 3 && num[1] >= 4 && num[1] <= 7) {
        cout << "卡號正確，此卡為American Express";
    } else if (len == 16 && num[0] == 5 && num[1] >= 1 && num[5] <= 5) {
        cout << "卡號正確，此卡為MasterCard";
    } else if (len == 16 && num[0] == 4) {
        cout << "卡號正確，此卡為Visa";
    } else if (len == 13 && num[0] == 4) {
        cout << "卡號正確，此卡為Visa";
    } else {
        cout << "錯誤卡號2";
    }
    // return 0
}
