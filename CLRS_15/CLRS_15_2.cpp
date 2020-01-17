#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void matrix_chain_order(vector<vector<int>>& m, vector<vector<int>>& s, vector<int> p)
{
	int n = p.size() - 1;
	int j = 0;
	int q = INT_MIN;
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j -1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print_optimal_parents(vector<vector<int>>& s, int i, int j) {
	if (i == j) {
		printf("A%d", i);
	}
	else {
		cout << "( ";
		print_optimal_parents(s, i, s[i][j]);
		print_optimal_parents(s, s[i][j] + 1, j);
		cout << " )";
	}
}

void matrix_chain_multiply() {

}

int lookup_chain(vector<vector<int>>& m, vector<int> p, int i, int j); // CLRS_15_3_RECURSIVE-MATRIX-CHAIN
int memoized_matrix_chain(vector<vector<int>>& m, vector<int> p) {
	int n = p.size() - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			m[i][j] = INT_MAX;
		}
	}
	return lookup_chain(m, p, 1, n);
}
int lookup_chain(vector<vector<int>>& m, vector<int> p, int i, int j) {
	int q;
	if (m[i][j] < INT_MAX)
		return m[i][j];
	if (i == j)
		m[i][j] = 0;
	else {
		for (int k = i; k <= j - 1; k++) {
			q = lookup_chain(m, p, i, k) + lookup_chain(m, p, k + 1, j) + p[i - 1] * p[k] * p[j];
			if (q < m[i][j])
				m[i][j] = q;
		}
	}
	return m[i][j];
}

int main()
{
	int n = 6;
	vector<int> p = {30,35,15,5,10,20,25};
	vector<vector<int>> m(n+1, vector<int>(n+1));
	vector<vector<int>> s(n+1,vector<int>(n+1));
	matrix_chain_order(m, s, p);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%5d", m[i][j]);
		}
		cout << "\n";
	}
	cout << "\n------------------------------\n";
	cout << "\nbot_up_matrix_chain_최적 결과 비용 : " << m[1][n] << "\n";
	print_optimal_parents(s,1,n);
	cout << "\n------------------------------\n";
	memoized_matrix_chain(m, p);
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			printf("%5d", m[i][j]);
		}
		cout << "\n";
	}
	cout << "\n------------------------------\n";
	cout << "memo_matrix_chain_최적 결과 비용 : " << m[1][n]<<"\n";
	return 0;
}