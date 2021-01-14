// #10120. 「一本通 4.2 例 2」最敏捷的机器人
// 陈锋
#include <bits/stdc++.h>

int ri() {
  int ch = getchar(), x = 0, b = 1;
  while (!isdigit(ch)) {
    if (ch == '-') b = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * b;
}

void pi(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) pi(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;

template<typename RandomIt,
         int SZ,
         typename TCmp = less<typename iterator_traits<RandomIt>::value_type>>
struct RMQ {
  typedef typename iterator_traits<RandomIt>::value_type T;
  vector<T> D[SZ];
  int N, LG;
  TCmp cmp;
  void init(const RandomIt first, const RandomIt last) {
    int N = distance(first, last), LG = 1;
    assert(N > 0 && N < SZ);
    LG = ceil(log2(N));
    for (int i = 0; i < N; ++i)
      D[i].resize(LG), D[i][0] = first[i];
    for (int j = 1; (1 << j) <= N; j++)
      for (int i = 0; i + (1 << j) - 1 < N; i++)
        D[i][j] = min(D[i][j - 1], D[i + (1 << (j - 1))][j - 1], cmp);
  }

  const T& query(int L, int R) {
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1) k++; // 2^k >= (R-L+1)
    return min(D[L][k], D[R - (1 << k) + 1][k], cmp);
  }
};

typedef long long LL;
const int NN = 1e5 + 4;
RMQ<int*, NN, greater<int>> maxQ;
RMQ<int*, NN> minQ;
int A[NN];
int main() {
  int N, K;
  N = ri(), K = ri();
  for (int i = 0; i < N; i++) A[i] = ri();
  maxQ.init(A, A + N), minQ.init(A, A + N);
  for (int i = 0; i + K <= N; i++) {
    pi(maxQ.query(i, i + K - 1)), printf(" ");
    pi(minQ.query(i, i + K - 1)), puts("");
  }
  return 0;
}
