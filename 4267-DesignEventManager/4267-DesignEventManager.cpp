// Last updated: 6/17/2026, 2:15:59 PM
struct Cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        if(a.first != b.first){
            return a.first>b.first;
        }else{
            return a.second<b.second;
        }
    }
};

class EventManager {
public:
    unordered_map<int, int> ump; //event pri
    multiset<pair<int, int>, Cmp> ms; //pr, eve;
    EventManager(vector<vector<int>>& events) {
        for(auto el: events){
            ump[el[0]] = el[1];
            ms.insert({el[1], el[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int opr = -1;
        if(ump.find(eventId) != ump.end()){
            opr = ump[eventId];
        }
        if(ms.find({opr, eventId}) != ms.end()){
            ms.erase(ms.find({opr, eventId}));
        }
        ms.insert({newPriority, eventId});
        ump[eventId] = newPriority;
    }
    
    int pollHighest() {
        if(ms.size() == 0) return -1;
        auto tel = *ms.begin();
        int ans = tel.second;
        ms.erase(tel);
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */