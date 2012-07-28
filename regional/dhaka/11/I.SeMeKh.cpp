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

const int MAXR = 200 + 10, MAXC = MAXR;
const int MAXA = 3 * MAXR * MAXC;

int dd[4][2] = {{+1, +1}, {+1, -1}, {-1, -1}, {-1, +1}};
int r, c;
int t[MAXR][MAXC];
int ccp;
int col[MAXR][MAXC];
double area[MAXA];

bool can(int rr, int cc, int nr, int nc)
{
	if(rr < 0 || rr > 2 * r || cc < 0 || cc > 2 *c ||
			nr < 0 || nr > 2 * r || nc < 0 || nc > 2 * c)
		return false;
	int RR = rr / 2, CC = cc / 2;
	if(t[RR][CC] == 0)
		return rr + cc == nr + nc;
	else
		return rr - cc == nr - nc;
}

void dfs(int rr, int cc, int cp)
{
	if(col[rr][cc])
		return ;
	col[rr][cc] = cp;
	FOR(i, 4)
	{
		int nr = rr + dd[i][0], nc = cc + dd[i][1];
		bool go;
		if(rr % 2)
			go = can(rr, cc, nr, nc);
		else
			go = can(nr, nc, rr, cc);
		if(go)
			dfs(nr, nc, cp);
	}
}

void calc_area()
{
	const double P = acos(-1) / 4;
	FOR(rr, r)
		FOR(cc, c)
		{
			area[col[2 * rr + 1][2 * cc + 1]] += 4 - 2 * P;
			if(t[rr][cc] == 0)
			{
				area[col[2 * rr][2 * cc]] += P;
				area[col[2 * rr + 2][2 * cc + 2]] += P;
			}
			else
			{
				area[col[2 * rr + 2][2 * cc]] += P;
				area[col[2 * rr][2 * cc + 2]] += P;
			}
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(4);

	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		ccp = 0;
		memset(col, 0, sizeof col);
		memset(t, 0, sizeof t);
		memset(area, 0, sizeof area);


		cin >> r >> c;
		FOR(rr, r)
			FOR(cc, c)
			{
				char c;
				cin >> c;
				t[rr][cc] = c - '0';
			}

		FOR(rr, 2 * r + 1)
			FOR(cc, 2 * c + 1)
			{
				if((cc + rr) % 2)
					continue ;
				if(!col[rr][cc])
					dfs(rr, cc, ++ccp);
			}
		calc_area();

		cout << "Case " << T + 1 << ":" << endl;
		
		int q;
		cin >> q;
		while(q--)
		{
			int x, y;
			double out = 0;
			cin >> x >> y;
			if((x + y) % 2 == 0)
				out = area[col[x][y]];
			cout << out << endl;
		}
	}
	return 0;
}

