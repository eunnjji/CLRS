#include "directaddress_TB.h"
#include "openaddress_HashTB.h"
using namespace std;

int main() {
	//DirectAddressTB A;
	//for (int i = 0; i < A.size; i += 2) {
	//	string str = "test" + to_string(i);
	//	Node tmp(i, str);
	//	//cout << tmp;
	//	A.insert(tmp);
	//}
	//cout << A;
	//cout << A.search(0).key << "|" << A.search(0).data << "\n";
	//cout << A.search(1).key << "|" << A.search(1).data << "\n";
	//A.deletion(Node(8, "test8"));
	//cout << A;

	openAddrHashTB B;
	int save_k[TB_SIZE];
	for (int i = 0; i < TB_SIZE; i++) {
		int k = rand() % 1000;
		int v = rand() % 1000;
		save_k[i] = k;
		cout << "idx: " << B.insert(k, v) << " in key (" << k << ") \n";
	}
	for (int i = 0; i < TB_SIZE; i++) {
		cout << save_k[i] << "\n";
	}
	//cout << B.search(827);
	//B.printTB();
}