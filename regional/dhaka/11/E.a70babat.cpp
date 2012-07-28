#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <set>
#include <complex>
#include <iomanip>
#include <queue>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define show(x) cerr << "#" << #x << ": " << x << endl
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAX_N = 100 * 1000 + 10;
const int MAX_K = 50 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;
const int TWOREV = 500 * 1000 * 1000 + 4;

long long strling[MAX_N][MAX_K];
long long perm[MAX_N];
long long rev_pow[MAX_K];

int main(){
	strling[2][1] = 1;
	for(int i = 3; i < MAX_N; i++){
		for(int j = 1; j < MAX_K; j++){
			strling[i][j] = strling[i - 2][j - 1] + strling[i - 1][j];
			strling[i][j] *= (i - 1);
			strling[i][j] %= MOD;
		}
	}
	
	perm[0] = 1;
	FOR(i, MAX_N - 1){
		perm[i + 1] = perm[i] * (i + 1);
		perm[i + 1] %= MOD;
	}
	
	rev_pow[0] = 1;
	FOR(i, MAX_K - 1){
		rev_pow[i + 1] = rev_pow[i] * TWOREV;
		rev_pow[i + 1] %= MOD;
	}
	
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		int n, k;
		cin >> n >> k;
		
		long long res = perm[n] * strling[n][k];
		res %= MOD;
		res *= rev_pow[k];
		res %= MOD;
		cout << "Case " << test << ": " << res << endl;
	}
	
	return 0;
}

