// Last updated: 6/17/2026, 2:15:42 PM
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    struct Comp{
        bool operator()(const vector<int> &a, const vector<int> &b) const{
            if(a[0] != b[0]) return a[0]>b[0];
            return a[1]<b[1];
        }  
    };
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& s) {
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
        //{time, col, r, c}; short time , max col
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for(auto el: s){
            pq.push({0, el[2], el[0], el[1]});
            arr[el[0]][el[1]] = el[2];
        }
        while(!pq.empty()){
            auto tel = pq.top(); pq.pop();
            int r = tel[2];
            int c = tel[3];
            int col = tel[1];
            int tim = tel[0];
            // cout<<col<<" ";
            for(int i=0; i<4; i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                if(arr[nr][nc] == 0){
                    arr[nr][nc] = col;
                    pq.push({tim+1, col, nr, nc});
                }
            }
        }

        return arr;
    }
};