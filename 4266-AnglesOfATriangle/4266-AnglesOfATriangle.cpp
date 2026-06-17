// Last updated: 6/17/2026, 2:16:00 PM
class Solution {
public:
    
    vector<double> internalAngles(vector<int>& s) {
        int a = s[0];
        int b = s[1];
        int c = s[2];
        if(a+b<=c || b+c<=a || a+c<=b) return {};
        double a1 = acos(1.0*(1.0*b*b + 1.0*c*c - (1.0*a*a))/(2.0*b*c));
        double a2 = acos(1.0*(1.0*a*a + 1.0*c*c - (1.0*b*b))/(2.0*a*c));
        double a3 = acos(1.0*(1.0*a*a + 1.0*b*b - (1.0*c*c))/(2.0*a*b));

        const double PI = acos(-1);
        a1 = (1.0*a1*180)/(PI);
        a2 = (1.0*a2*180)/(PI);
        a3 = (1.0*a3*180)/(PI);
        
        vector<double> ans;
        ans.push_back(a1);
        ans.push_back(a2);
        ans.push_back(a3);
        sort(ans.begin(), ans.end());
        return ans;
    }
};