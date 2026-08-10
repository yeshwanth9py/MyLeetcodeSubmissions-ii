#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>
#include <array>
#include <functional>
#include <bitset>
using namespace std;

void baseIO(string s = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int subcount = 32;

#define ll long long
#define db long double
#define all(x) (x).begin(), (x).end()

struct Info {
    ll ans = 0;
    int pref = 0;
    int suff = 0;

    int mx1 = -1e9;
    int mn1 = 1e9;

    int sz = 0;

    Info() {

    }

    Info(int x) {
        pref = 1;
        suff = 1;
        sz = 1;

        if (x == 1) {
            mx1 = 0;
            mn1 = 0;
        }
    }

    Info(ll a, int b, int c, int d, int e, int f) {
        ans = a;
        pref = b;
        suff = c;
        mx1 = d;
        mn1 = e;
        sz = f;
    }
};

class Segtree {
public:
    int n;
    vector<Info> tree;
    Info neutral = Info();

    Info merge(const Info &a, const Info &b) {
        ll nans = a.ans + b.ans;

        if (a.mx1 >= 0) {
            nans += 1LL * a.mx1 * b.sz;
        }
        if (b.mn1 < b.sz) {
            nans += 1LL * a.sz * (b.sz - b.mn1 - 1);
        }
        if (a.mx1 >= 0 && b.mn1 < b.sz) {
            nans -= 1LL * a.mx1 * (b.sz - b.mn1 - 1);
        }

        int nmx1 = a.mx1;
        if (b.mx1 >= 0) nmx1 = b.mx1 + a.sz;

        int nmn1 = b.mn1 + a.sz;
        if (a.mn1 < a.sz) nmn1 = a.mn1;

        return {
            nans,
            (a.pref != a.sz ? a.pref : a.sz + b.pref),
            (b.suff != b.sz ? b.suff : b.sz + a.suff),
            nmx1,
            nmn1,
            a.sz + b.sz
        };
    }

    void init(int N) {
        n = N;
        tree.resize(4 * n);
    }

    template<typename T>
    void build(int C, int L, int R, const vector<T>& a) {
        if (L + 1 == R) {
            tree[C] = Info(a[L]);
            return;
        }

        int M = (L + R) / 2;
        build(2 * C, L, M, a);
        build(2 * C + 1, M, R, a);

        tree[C] = merge(tree[2 * C], tree[2 * C + 1]);
    }

    void update(int C, int L, int R, int i, const Info &v) {
        if (i < L || i >= R) return;
        if (L + 1 == R) {
            tree[C] = v;
            return;
        }

        int M = (L + R) / 2;
        update(2 * C, L, M, i, v);
        update(2 * C + 1, M, R, i, v);

        tree[C] = merge(tree[2 * C], tree[2 * C + 1]);
    }

    Info query(int C, int L, int R, int l, int r) {
        if (l <= L && R <= r) return tree[C];
        if (l >= R || L >= r) return neutral;

        int M = (L + R) / 2;
        return merge(query(2 * C, L, M, l, r), query(2 * C + 1, M, R, l, r));
    }

    template<typename T>
    void build(const vector<T>& a) {
        build(1, 0, n, a);
    }

    void update(int i, const Info &v) {
        update(1, 0, n, i, v);
    }

    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};

class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> peak(n);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak[i] = 1;
            }
        }

        Segtree seg;
        seg.init(n);
        seg.build(peak);

        vector<ll> ans;
        for (auto &v : queries) {
            if (v[0] == 1) {
                ans.push_back(seg.query(v[1], v[2] + 1).ans);
            } else {
                if (0 < v[1] && v[1] < n - 1) {
                    int ispeak = (v[2] > nums[v[1] - 1] && v[2] > nums[v[1] + 1]);
                    seg.update(v[1], ispeak);
                }

                if (1 < v[1]) {
                    int ispeak = (nums[v[1] - 1] > nums[v[1] - 2] && nums[v[1] - 1] > v[2]);
                    seg.update(v[1] - 1, ispeak);
                }

                if (v[1] < n - 2) {
                    int ispeak = (nums[v[1] + 1] > v[2] && nums[v[1] + 1] > nums[v[1] + 2]);
                    seg.update(v[1] + 1, ispeak);
                }

                nums[v[1]] = v[2];
            }
        }

        return ans;
    }
};