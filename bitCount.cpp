#include <cstdio>
#include <cstdlib>
#include <ctime>

const int n = 10000000;
typedef long long ll;
typedef long long LL;

const int _bitCount_len  = 16;
const int _bitCount_len2 = _bitCount_len << 1;
const int _bitCount_len3 = _bitCount_len * 3;

char _bitCount_m[1 << _bitCount_len];
int bitCount(LL _a)
{
	static bool _f;
	if(!_f)
	{
		_bitCount_m[0] = 0;
		for(int _i = 1; _i < (1 << _bitCount_len); ++_i)
			_bitCount_m[_i] = _bitCount_m[_i & (_i - 1)] + 1;
		_f = true;
	}
	return _bitCount_m[_a & 0xFFFF] + _bitCount_m[(_a >> _bitCount_len) & 0xFFFF] + _bitCount_m[(_a >> _bitCount_len2) & 0xFFFF] + _bitCount_m[(_a >> _bitCount_len3) & 0xFFFF];
}

int countLoglog(ll x) {
  x = (x & 0x5555555555555555ll) + ((x & 0xAAAAAAAAAAAAAAAAll) >> 1);
  x = (x & 0x3333333333333333ll) + ((x & 0xCCCCCCCCCCCCCCCCll) >> 2);
  x = (x & 0x0F0F0F0F0F0F0F0Fll) + ((x & 0xF0F0F0F0F0F0F0F0ll) >> 4);
  x = (x & 0x00FF00FF00FF00FFll) + ((x & 0xFF00FF00FF00FF00ll) >> 8);
  x = (x & 0x0000FFFF0000FFFFll) + ((x & 0xFFFF0000FFFF0000ll) >> 16);
  x = (x & 0x00000000FFFFFFFFll) + ((x & 0xFFFFFFFF00000000ll) >> 32);
  return x;
}

int countSimple(ll x) {
  int a = 0;
  for (; x; x &= x-1) ++a;
  return a;
}

ll data[n];
int main() {
  srand(time(0));

  printf("Filling in... ");
  for (int i = 0; i < n; i++) data[i] = ((ll)rand() << 48) | ((ll)rand() << 32) | ((ll)rand() << 16) | (ll)rand();
  printf("OK\n");

  time_t stime; int sum;

  printf("Counting with __builtin_popcount... ");
  stime = clock();
  sum = 0;
  for (int i = 0; i < n; i++) sum += __builtin_popcountll(data[i]);
  printf("OK, sum=%d, time=%.3lf\n", sum, (double)(clock() - stime) / CLOCKS_PER_SEC);

  printf("Counting with countPrecalc... ");
  stime = clock();
  sum = 0;
  for (int i = 0; i < n; i++) sum += bitCount(data[i]);
  printf("OK, sum=%d, time=%.3lf\n", sum, (double)(clock() - stime) / CLOCKS_PER_SEC);

  printf("Counting with countLoglog... ");
  stime = clock();
  sum = 0;
  for (int i = 0; i < n; i++) sum += countLoglog(data[i]);
  printf("OK, sum=%d, time=%.3lf\n", sum, (double)(clock() - stime) / CLOCKS_PER_SEC);

  printf("Counting with countSimple... ");
  stime = clock();
  sum = 0;
  for (int i = 0; i < n; i++) sum += countSimple(data[i]);
  printf("OK, sum=%d, time=%.3lf\n", sum, (double)(clock() - stime) / CLOCKS_PER_SEC);

  return 0;
}
