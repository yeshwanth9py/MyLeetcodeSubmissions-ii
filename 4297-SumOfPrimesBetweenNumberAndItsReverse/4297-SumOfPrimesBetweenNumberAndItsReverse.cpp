// Last updated: 6/17/2026, 2:15:24 PM
class Solution {
public:
    int rev(int num){
        int ans = 0;
        while(num){
            ans = ans*10 + num%10;
            num = num/10;
        }
        return ans;
    }

    bool isprim(int num){
        if(num <= 1) return 0;
        for(int i=2; i*i<=num; i++){
            if(num%i == 0) return 0;
        }
        return 1;
    }
    int sumOfPrimesInRange(int n) {
        int n2 = rev(n);
        int n1 = min(n2, n);
        n2 = max(n2, n);
        int ans = 0;
        for(int i=n1; i<=n2; i++){
            if(isprim(i)){
                ans += i;
            }
        }

        return ans;
    }
};