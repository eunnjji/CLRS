#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <tuple>
using namespace std;
#define MAXSIZE 1000

int m, n;
int c[MAXSIZE][MAXSIZE];
int b[MAXSIZE][MAXSIZE]; // 0 : ���ʴ밢�� ��, 1:��, 2:����

void lcs_length(string x, string y) {
    for (int i = 0; i < m + 1; i++) {
        c[i][0] = 0;
    }
    for (int i = 0; i < n + 1; i++) {
        c[0][i] = 0;
    }
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0; // ���� �밢�� ǥ��
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1; // �� ǥ��
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2; // ���� ǥ��
            }
            for (int i = 0; i < m + 1; i++) { // ����
                for (int j = 0; j < n + 1; j++) { // ����  ��
                    cout << c[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }

}
void printTB() {
    for (int i = 0; i < m + 1; i++) { // ����
        for (int j = 0; j < n + 1; j++) { // ����  ��
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}
void print_LCS(string x, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 0) {
        print_LCS(x, i - 1, j - 1);
        cout << " [" << x[i-1] << "] ";
    }
    else if (b[i][j] == 1) {
        print_LCS(x, i - 1, j);
    }
    else {
        print_LCS(x, i, j - 1);
    }
}


int main()
{
    string x, y;

    cin >> x;
    cin >> y;
    m = x.length();
    n = y.length();
    //for (int i = 0; i < m + 1; i++) { // ����
    //    for (int j = 0; j < n + 1; j++) { // ����  ��
    //        //c[i][j] = 0;
    //        b[i][j] = -1;
    //    }
    //    cout << "\n";
    //}

    lcs_length(x, y);
    printTB();
    print_LCS(x, m, n);
}