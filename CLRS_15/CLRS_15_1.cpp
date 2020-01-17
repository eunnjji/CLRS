#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int cut_rod(int p[], int n) {
    if (n == 0) // n : length n 
        return 0;
    int q = INT_MIN; // 최대 수익
    int r;
    for (int i = 1; i <= n; i++)
    {
        int cost = p[i - 1] + cut_rod(p, n - i);
        if (cost > q)
            q = cost;
    }
    return q;
}
int bottom_up_cut_rod(int p[],int n) {
    int r[11] = { 0, };
    int tot;
    for (int j = 1; j < n+1; j++) {
        tot = INT_MIN;
        for (int i = 1; i < j+1; i++) {
            tot = max(tot, p[i] + r[j - i]);
        }
        r[j] = tot;
    }
    return r[n];
}
int memoize_cut_rod_aux(int p[], int n, int r[]) {
    int tot;
    if (r[n] >= 0) {
        return r[n];
    }
    if (n == 0)
        tot = 0;
    else {
        tot = INT_MIN;
        for (int i = 1; i <= n; i++) {
            tot = max(tot, p[i] + memoize_cut_rod_aux(p, n - i, r));
        }
        r[n] = tot;
    }
    
    return tot;
}

int memoize_cut_rod(int p[], int n) {
    int r[11];
    for (int i = 0; i < n + 1; i++) {
        r[i] = INT_MIN;
    }
    r[0] = 0;
    return memoize_cut_rod_aux(p, n, r);
}
int r[11], s[11];

int extended_bottom_up_cut_rod(int p[], int n) {
    for (int i = 0; i < 11; i++) {
        r[i] = 0; s[i] = 0;
    }
    int tot;
    tot = INT_MIN;
    for (int j = 1; j < n + 1; j++) {
        tot = INT_MIN;
        for (int i = 0; i < j; i++) {
            if (tot < p[i] + r[j - i - 1]) {
                tot = p[i] + r[j - i - 1];
                s[j] = i + 1;
            }
        }
        r[j] = tot;
    }
    return tot;
}
void print_cut_rod_solution(int p[], int n) {
    int tot = extended_bottom_up_cut_rod(p, n);
    cout << "max : " << tot << "\n";
    while (n > 0) {
        cout << s[n]<<"\n";
        n = n - s[n];
    }
}

int main()
{
    int length;
    cin >> length;
    int price[10] = { 1,5,8,9,10,17,17,20,24,30 };
    cout <<  cut_rod(price, length) <<"\n";
    //cout << bottom_up_cut_rod(price, length) << "\n";
    //cout << memoize_cut_rod(price, length) << "\n";
    int r[11], s[11];
    print_cut_rod_solution(price,length);
    return 0;
}

//[reference] https://www.techiedelight.com/rot-cutting/