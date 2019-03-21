#include <iostream>
#include <string.h>

using namespace std;

int cashe[10 + 1][10 + 1];

int Combination(int n, int r) {

	if (n == r || r == 0)
		return 1;

	if (cashe[n][r] >= 0)
		return cashe[n][r];

	return cashe[n][r] = Combination(n - 1, r) + Combination(n - 1, r - 1);
}


int main() {
	memset(cashe, -1, sizeof(cashe));

	int n, k;

	cin >> n >> k;

	cout << Combination(n, k) << endl;
}

