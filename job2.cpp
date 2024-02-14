#include <iostream>
using namespace std;

void jobSequence(int D[], int J[], int P[], int S[], int n, int k) {
	int temp[k][3];
	for(int i = 0; i < k; i++) {
		temp[i][0] = J[i];
		temp[i][1] = P[i];
		temp[i][2] = D[i];
	}
	for(int j = 1; j < k; j++) {
		int Key = temp[j][1];
		int Key2 = temp[j][0];
		int Key3 = temp[j][2];
		int i = j - 1;
		while(i >= 0 && temp[i][1] < Key) {
			temp[i+1][0] = temp[i][0];
			temp[i + 1][1] = temp[i][1];
			temp[i+1][2] = temp[i][2];
			i = i - 1;
		}
		temp[i+1][1] = Key;
		temp[i+1][0] = Key2;
		temp[i+1][2] = Key3;
	}
	int selected[n][3] = {};
	int a = 0;
	for(int l = 0; l < k; l++) {
		if(temp[l][2] == selected[a-1][2]) {
			continue;
		}
		else {
			selected[a][0] = temp[l][0];
			selected[a][1] = temp[l][1];
			selected[a][2] = temp[l][2];
			a++;
		}
	}
	for(int m = 0; m < n; m++) {
		S[m] = selected[selected[m][2]-1][0];
	}
}

int main() {
	int J[] = {1,2,3,4,5,6,7,8,9,10};
	int P[] = {8,8,7,5,5,5,4,3,2,1};
	int D[] = {3,5,4,2,3,2,1,1,1,1};
	int S[] = {}; 
	int k = 10, n = 5,sum=0;
	jobSequence(D,J,P,S,n,k);
	cout << "The sequence of jobs is:\n";
	for(int i = 0; i < n; i++) {
		cout << "Job " << S[i] << ": " << P[S[i]-1] << endl;
		sum += P[S[i] - 1];
	}
	cout << "Total profit: " << sum;
}
