        for(int x:adj[i]){
            if(x==p) continue;
            f(f,x,i);
            for(int num=1;num<=50;num++){
                if(sub[x][num] > 0){
                    if(__gcd(nums[i],num)==1){
                        for(int node:m[num]){
                            ans[node]=i;
                            cout<<node<<" ";
                            m[num].erase(node);
                        }
                        if(m[num].empty()) m.erase(num);
                    }
                }
            }
            
        }

        for(int x:adj[i]){
            if(x==p) continue ;
            for(int num=1;num<=50;num++) sub[i][num]+=sub[x][num];
        }

        sub[i][nums[i]]++;
        m[nums[i]].insert(i);
    };
    f(f,0,-1);
    return ans ;
}