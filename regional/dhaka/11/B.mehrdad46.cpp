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
const int N = 10, maxN = 10 + 2, X = 100 + 2;
int n, number[maxN], display[1 << N];
bool canBuild[1 << N][X];
int main(){
	FOR (mask, 1 << N){
		int power = 1;
		FOR (I, N)
			if ((mask >> I) & 1){
				display[mask] += power * I;
				power *= 10;
			}
		FOR (I, X){
			 FOR (K, I + 1){
			 	int x[] = {K, I - K};
				bool isOK = true;
				int tmp = mask;
				FOR (M, 2){
					while (x[M]){
						int digit = x[M] % 10;
						isOK &= (tmp >> digit & 1);
						tmp &= ~(1 << digit);
						x[M] /= 10;
					}
				}
				canBuild[mask][I] |= isOK;
			 }
		}
	}
	for (int counter=1; ; counter++){
		cin >> n;
		if (!n)
			break;
		FOR (I, n)
			cin >> number[I];
		int answer = -1;
		FOR (mask, 1 << N){
			bool isOK = true;
			FOR (I, n)
				isOK &= canBuild[mask][number[I]];
			if (isOK && (answer == -1 || display[mask] < answer))
				answer = display[mask];
		}
		cout << "Case " << counter << ": " << answer << endl;
	}
	return 0;
}
