#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <complex>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i, n) for (int i=0; i<(n); i++)
#define SZ(x) (int)x.size()
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef complex <double> Point;
const int inf = 1 << 30;
const int maxN = 1000 + 10;
char table[maxN][maxN];
int n, m;
int abs2(int x){
	return max(x, -x);
}
int solve(int initial[], int goal[], int len){
	int x[maxN];
	int result = 0;
	x[0] = 0;
	FOR (K, len)
		x[(K + 1) % len] = x[K] + initial[K] - goal[K];
	
	nth_element(x, x + len / 2, x + len);
	int xx = x[len / 2];
	FOR (I, len)
		result += abs2(x[I] - xx);
	return result;
}
int main(){
	int t;
	cin >> t;
	for (int counter=1; counter<=t; counter++){
		cout << "Case " << counter << ": ";
		cin >> n >> m;
		FOR (I, n)
			cin >> table[I];
		int sum = 0;
		FOR (I, n)
			FOR (K, m)
				sum += table[I][K] == '1';
		bool canRow = (sum % n == 0), canCol = (sum % m == 0);
		int init[maxN], goal[maxN], answer1 = 0, answer2 = 0;
		if (canRow){
			FOR (I, n){
				init[I] = 0;
				goal[I] = sum / n;
				FOR (K, m)
					init[I] += table[I][K] == '1';
			}
			answer1 = solve(init, goal, n);
		}
		if (canCol){
			FOR (I, m){
				init[I] = 0;
				goal[I] = sum / m;
				FOR (K, n)
					init[I] += table[K][I] == '1';
			}
			answer2 = solve(init, goal, m);
		}
		if (!canRow && !canCol)
			cout << "impossible" << endl;
		if (canRow && !canCol)
			cout << "row " << answer1 << endl;
		if (!canRow && canCol)
			cout << "column " << answer2 << endl;
		if (canRow && canCol)
			cout << "both " << answer1 + answer2 << endl;
	}
	return 0;
}
