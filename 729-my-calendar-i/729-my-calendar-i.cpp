class MyCalendar {
public:
    vector<pair<int,int>> calender;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ans = true;
        if(calender.size() == 0) {
            calender.push_back({start,end});
            return ans;
        }
            
        for(int i = 0; i < calender.size(); i++) {
            pair<int,int> b = calender[i];
            if((start > b.first && start >= b.second) || (end <= b.first && end < b.second))
                continue;
            else {
                ans = false;
                break;
            }
        }
        if(ans) {
            calender.push_back({start,end});
            return ans;
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */