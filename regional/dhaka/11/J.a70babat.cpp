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

const int MAX_N = 100 + 10;

int n;
int val[MAX_N];
bool adj[MAX_N][MAX_N];

int main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		int m;
		cin >> n >> m;
		FOR(i, n)
			cin >> val[i];
		memset(adj, 0, sizeof adj);
		FOR(i, m){
			int u, v;
			cin >> u >> v;
			adj[u][v] = true;
		}
		int pos = 0;
		int sum = val[0];
		while(true){
			int next = -1;
			FOR(i, n)
				if(adj[pos][i] && (next == -1 || val[next] < val[i]))
					next = i;
			if(next != -1){
				sum += val[next];
				pos = next;
			}else	break;
		}
		cout << "Case " << test << ": " << sum << " " << pos << endl;
	}
	return 0;
}

