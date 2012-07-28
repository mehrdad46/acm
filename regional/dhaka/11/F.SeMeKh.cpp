#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <valarray>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cassert>

#define show(x) cerr << "# " << #x << " = " << x << endl

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> point;

int main()
{
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		cout << "Case " << T + 1 << ": ";
		int l, w, h;
		cin >> l >> w >> h;
		if(l > 20 || w > 20 || h > 20)
			cout << "bad";
		else
			cout << "good";
		cout << endl;
	}
	return 0;
}
