1class Solution {
2public:
3    vector<long long> pref;
4    long long manacher(vector<long long> &arr){
5        long long r=0;
6        long long c=0;
7        long long n = arr.size();
8        vector<long long> p(n, 0);
9        long long maxsum = 0;
10
11        for(long long i=1; i<n-1; i++){
12            if(i<r){
13                long long mirror = c - (i-c); 
14                p[i] = min(r-i, p[mirror]);
15            }
16            while(arr[i+p[i]+1] == arr[i-p[i]-1]){
17                p[i]++;
18            }
19            if(i+p[i]>r){
20                r = i+p[i];
21                c = i;
22            }
23
24            long long left = i-p[i];
25            long long right = i+p[i];
26            if(left%2 == 1){
27                left++;
28            }
29            if(right%2 == 1){
30                right--;
31            }
32            left = max(0LL, (left - 2))/2;
33            right = max(0LL, (right - 2))/2;
34            
35            maxsum = max(maxsum, pref[right]-(left-1>=0?pref[left-1]:0));
36        }
37        
38        return maxsum;
39    }
40
41    long long getSum(vector<int>& nums) {
42        pref.resize(nums.size(), 0);
43        for(long long i=0; i<nums.size(); i++){
44            pref[i] = (i-1>=0?pref[i-1]:0) + nums[i];
45        }
46        vector<long long> arr;
47        arr.push_back(-2);
48
49        for(long long i=0; i<nums.size(); i++){
50            arr.push_back(-1);
51            arr.push_back(nums[i]);
52        }
53        arr.push_back(-1);
54        arr.push_back(-3);
55
56        return manacher(arr);
57    }
58};