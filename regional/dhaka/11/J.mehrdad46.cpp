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
const int maxN = 100 + 10;
int n, m, value[maxN];
vector <int> graph[maxN];
int main(){
	int t;
	cin >> t;
	FOR (counter, t){
		cin >> n >> m;
		FOR (I, n){
			cin >> value[I];
			graph[I].clear();
		}
		FOR (I, m){
			int u, v;
			cin >> u >> v;
			graph[u].PB(v);
		}
		int u = 0, sum = 0;
		while (true){
			sum += value[u];
			int maxi = 0, next = -1;
			FOR (I, SZ(graph[u]))
				if (value[graph[u][I]] > maxi){
					maxi = value[graph[u][I]];
					next = graph[u][I];
				}
			if (next == -1)
				break;
			u = next;
		}
		cout << "Case " << counter + 1 << ": " << sum << " " << u << endl;
	}
	return 0;
}
