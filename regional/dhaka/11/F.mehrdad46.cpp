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
int main(){
	int t;
	cin >> t;
	int counter = 0;
	while (t --){
		counter ++;
		int a[3];
		FOR (I, 3)
			cin >> a[I];
		bool result = false;
		do{
			bool isOK = true;
			FOR (I, 3)
				isOK &= a[I] <= 20;
			result |= isOK;
		} while (next_permutation(a, a + 3));
		cout << "Case " << counter << ": " << (result ? "good" : "bad") << endl;
	}
	return 0;
}
