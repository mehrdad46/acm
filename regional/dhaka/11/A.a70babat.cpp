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

const int MAX_N = 1000 + 10;

int n, m;
char tab[MAX_N][MAX_N];
int degr[MAX_N];
int degc[MAX_N];

int solve(int num[], int n, int val){
	int ans = MAX_N * MAX_N * MAX_N;
	FOR(i, n){
		int cur = 0;
		int sum = 0;
		FOR(j, n){
			cur += abs(j * val - sum);
			sum += num[j];
		}
		ans = min(ans, cur);
		FOR(j, n - 1)
			swap(num[j], num[j + 1]);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		scanf("%d %d", &n, &m);
		FOR(i, n)
			scanf(" %s", tab[i]);
		int tot = 0;
		memset(degr, 0, sizeof degr);
		memset(degc, 0, sizeof degc);
		FOR(i, n)
			FOR(j, m)
				if(tab[i][j] == '1'){
					degr[i]++;
					degc[j]++;
					tot++;
				}
		if(!(tot % n) && !(tot % m))
			printf("Case %d: both %d\n", test, solve(degr, n, tot / n) + solve(degc, m, tot / m));
		if((tot % n) && !(tot % m))
			printf("Case %d: column %d\n", test, solve(degc, m, tot / m));
		if(!(tot % n) && (tot % m))
			printf("Case %d: row %d\n", test, solve(degr, n, tot / n));
		if((tot % n) && (tot % m)){
			printf("Case %d: impossible\n", test);
		}
	}
	return 0;
}
