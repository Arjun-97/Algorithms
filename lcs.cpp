#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string& x, string& y, int i, int j, vector<vector<int>>& c) {
    if (i == 0 || j == 0) {
        return 0; 
    }
    else if (c[i][j] != -1) {
        return c[i][j];
    }

    else {
    	if (x[i-1] == y[j-1]) {
        	c[i][j] = LCS(x, y, i - 1, j - 1, c) + 1; 
    	} 
    	else {
        	c[i][j] = max(LCS(x, y, i - 1, j, c), LCS(x, y, i, j - 1, c)); 
    	}
    }

    return c[i][j];
}

int main() {
    string a = "ABCBDAB";
    string b = "BDCABA";
    string lcs = "";
    int m = a.length();
    int n = b.length();
    
    vector<vector<int>> c(m+1, vector<int>(n+1, -1));

    int lcsLength = LCS(a, b, m, n, c);
    cout << "Length of LCS: " << lcsLength << endl;
    while (m > 0 && n > 0) {
    	if (a[m - 1] == b[n - 1]) {
        	lcs = a[m - 1] + lcs;
            m--;
            n--;
        } 
        else if (c[m - 1][n] > c[m][n - 1]) {
            m--;
        } 
        else {
            n--;
        }
    }
    cout << "String: " << lcs << endl;
    return 0;
}
