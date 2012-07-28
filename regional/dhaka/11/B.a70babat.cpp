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

const int MAX_N = 100 + 2;
const int MAX_T = 1000 + 10;

bool can[MAX_T][MAX_N];
int mark[10];

bool fcan(vector<int> a){
	bool can = true;
	for(int i = 0; i < SZ(a); i++){
		int tmp = a[i];
		while(tmp){
			if(!mark[tmp % 10]--)
				can = false;
			tmp /= 10;
		}
	}
	for(int i = 0; i < SZ(a); i++){
		int tmp = a[i];
		while(tmp){
			mark[tmp % 10]++;
			tmp /= 10;
		}
	}
	return can;
}

int main(){
	FOR(i, (1 << 10)){
		FOR(j, 10)
			mark[j] = ((i & (1 << j)) > 0);
		for(int j = 1; j <= 100; j++){
			if(fcan(vector<int>(1, j)))
				can[i][j] = true;
			for(int k = 1; !can[i][j] && k <= j - 1; k++){
				vector<int> a;
				a.PB(k);
				a.PB(j - k);
				if(fcan(a))
					can[i][j] = true;
			}
		}
	}
	int test = 1;
	while(true){
		int n;
		cin >> n;
		if(!n)
			break;
		vector<int> num;
		FOR(i, n){
			int a;
			cin >> a;
			num.PB(a);
		}
		cout << "Case " << test++ << ": ";
		long long ans = 9876543210;
		FOR(i, (1 << 10)){
			bool res = true;
			FOR(j, n)
				if(!can[i][num[j]])
					res = false;
			if(res){
				long long cur = 0;
				for(int j = 9; j >= 0; j--)
					if(i & (1 << j))
						cur = cur * 10 + j;
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
