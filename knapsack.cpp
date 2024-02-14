#include <iostream>
using namespace std;

int main() {
	int n = 3, M = 20, a[3] = {0,1,2},select;
	float SW = 0, SV = 0, temp;
	float  x[3] = {0,0,0}, v[3] = {24,25,15}, w[3] = {18,15,20}, S[3] = {0,0,0};
	for(int i = 0; i < n; i++) {
		x[i] = v[i]/w[i];
		if(i > 0) {
			if(x[i-1] < x[i]) {
				temp = x[i];
				x[i] = x[i-1];
				x[i-1] = temp;
				temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		select = a[i];
		if(SW + w[select] <= M) {
			S[i] = x[i];
			SW = SW + w[select];
			SV = SV + v[select];
		}
		else {
			if(SW < M) {
				float t = (M-SW)/w[select];
				S[i] = t*x[i];
				SW = SW + t*w[select];
				SV = SV + t*v[select];
			}
		}
	}
	cout << "Profit gained: " << SV << endl;
	cout << "Total weight: " << SW << endl;
	cout << "Items are: " << endl;
	for(int i = 0; i < n; i++) {
		if(S[i] > 0)
		cout << S[i] << endl;
	}
	return 0;
}
