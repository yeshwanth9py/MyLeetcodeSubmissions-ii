1class Solution {
2public:
3    int mostBooked(int n, vector<vector<int>>& arr) {
4        priority_queue<long long, vector<long long>, greater<long long>> avail;
5        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> used;
6
7        for(long long i=0; i<n; i++) avail.push(i);
8
9        sort(arr.begin(), arr.end());
10
11        vector<long long> ans(n, 0);
12
13        for(auto m: arr){
14            long long s = m[0];
15            long long e = m[1];
16            while(!used.empty() && used.top().first<=s){
17                auto [et, rm] = used.top(); used.pop();
18                avail.push(rm);
19            }
20
21            if(avail.size()==0){
22                auto [et, rm] = used.top(); used.pop();
23                long long net = 1LL*et+1LL*(e-s);
24                used.push({net, rm});
25                // cout<<et<<" "<<rm<<", ";
26                ans[rm]++;
27            }else{
28                long long rm = avail.top(); avail.pop();
29                used.push({e, rm});
30                // cout<<s<<" "<<rm<<", ";
31                ans[rm]++;
32            }
33        }
34
35        long long asans = 0;
36        for(long long i=0; i<n; i++){
37            // cout<<ans[i]<<" ";
38            if(ans[asans]<ans[i]){
39                asans = i;
40            }
41        }
42        cout<<endl;
43        return asans;   
44
45    }
46};