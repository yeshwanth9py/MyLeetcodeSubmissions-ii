1struct Unionfind{
2    vector<int> par;
3    vector<int> sz;
4    Unionfind(int n){
5        par.resize(n, 0);
6        sz.resize(n, 1);
7        for(int i=0; i<n; i++){
8            par[i] = i;
9        }
10    }
11
12    int find(int x){
13        cout<<x<<" ";
14        if(par[x] == x) return x;
15        return par[x] = find(par[x]);
16    }
17
18    void merge(int x, int y){
19        x = find(x);
20        y = find(y);
21        if(x == y) return;
22        if(sz[y]>=sz[x]) swap(x, y);
23        sz[x] += sz[y];
24        par[y] = x;
25    }
26};
27
28class Solution {
29public:
30    bool equationsPossible(vector<string>& eq) {
31        sort(eq.begin(), eq.end(), [&](string &a, string &b){
32            // cout<<a[1]<<" "<<b[1]<<endl;
33            if(a[1] != b[1]){
34                if(a[1] == '!') return false;
35                return true;
36            }
37            return a[0]<b[0];
38        });
39
40        Unionfind uf(26);
41
42        for(auto el: eq){
43            int a = el[0]-'a';
44            int b = el[3]-'a';
45            if(el[1] == '!'){
46                if(uf.find(a) == uf.find(b)) return 0;
47            }else{
48                uf.merge(a, b);
49            }
50        }
51
52        return 1;
53    }
54};
55
56
57