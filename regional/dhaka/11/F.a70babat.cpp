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

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a > 20 || b > 20 || c > 20)
			cout << "Case " << i << ": bad" << endl;
		else
			cout << "Case " << i << ": good" << endl;
	}
	return 0;
}

