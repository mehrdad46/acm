#include <iostream>

#define show(x) cerr << "# " << #x << " = " << x << endl

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
using namespace std;


struct bignum {
	const static int MAXL = 100; // FIXME

	const static int BASE = 1e9;
	const static int LB = 9; // = log10(BASE)
	
	int c[MAXL];
	int sz, ln;
	// sz = Size in 4*bytes (sz < MAXL)
	// ln = Length of the number when written in base 10
	
	bignum()
	{
		sz = ln = 0;
	}

	inline int block(int ind) const
	{
		return c[ind];
	}

	inline int size() const
	{
		return ln;
	}

	inline void add(const bignum &a, const bignum &b)
	{
		sz = ln = 0;
		int car = 0;
		for(int i = 0; i < a.sz || i < b.sz || car; i++)
		{
			int d = 0;
			d += car;
			if(i < a.sz)
				d += a.block(i);
			if(i < b.sz)
				d += b.block(i);
			car = d / BASE;
			d %= BASE;
			c[sz++] = d;
		}

		int t = c[sz - 1];
		for(ln = 0; t; t /= 10)
			ln++;
		if(sz)
			ln += (sz - 1) * 9;
	}

	inline int operator [](int ind) const
	{
		const static int P[] = 
			{1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
		ind = ln - ind - 1;
		int t = c[ind / 9];
		t /= P[ind % 9];
		t %= 10;
		return t;
	}
	
	inline to_string() const
	{
		stirng r = "";
		FOR(i, SZ(b))
			r += b[i] + '0';
		return r;
	}

	friend inline ostream& operator << (ostream &o, const bignum &b)
	{
		return o << b.to_string();
	}
};

int main()
{
	return 0;
}

