#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	// (a) bst
	//set of probability for search key
	vector<float> p1 = {0,0.15,0.10,0.05,0.10,0.20};
	/*for (int i = 0; i < p.size(); i++)
		printf(" %0.2f ",p[i]);*/
	//set of probability for search dummy key
	vector<float> q1 = { 0.05,0.10,0.05,0.05,0.05,0.10 };
	vector<int> kdepth1 = { 0,1,0,2,1,2 };
	vector<int> ddepth1 = { 2,2,3,3,3,3 };
	// the expected search cost node by node
	float sum = 0.00;
	for (int i = 0; i < q1.size(); i++) {
		sum += (float)p1[i] * (kdepth1[i] + 1) + (float)q1[i] * (ddepth1[i] + 1);
	}
	printf("Total expected cost1 : %0.2f\n", sum);

	//(b) bst
	vector<float> p2 = { 0,0.15,0.10,0.05,0.10,0.20 };
	vector<float> q2 = { 0.05,0.10,0.05,0.05,0.05,0.10 };
	vector<int> kdepth2 = { 0,1,0,3,2,1 };
	vector<int> ddepth2 = { 2,2,4,4,3,2 };
	sum = 0.00;
	for (int i = 0; i < q2.size(); i++) {
		sum += (float)p2[i] * (kdepth2[i] + 1) + (float)q2[i] * (ddepth2[i] + 1);
	}
	printf("Total expected cost2 : %0.2f\n", sum);





	return 0;
}