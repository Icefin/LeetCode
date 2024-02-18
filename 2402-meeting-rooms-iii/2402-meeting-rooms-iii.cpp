class Solution {
private:
    struct RoomState {
        bool isUsing = false;
        long long  finishTime = 0;
    };
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), 
             [](vector<int>& first, vector<int>& second) -> bool { return first[0] < second[0]; });
        
        vector<int> cnt(n, 0);
        vector<RoomState> rooms(n);
        for (int i = 0; i < meetings.size(); ++i) {
            // meetings[i]의 시작시간보다 빨리 끝나는 방을 모두 해제
            for (int j = 0; j < n; ++j) {
                if (rooms[j].finishTime <= meetings[i][0])
                    rooms[j].isUsing = false;
            }
            bool isAssigned = false;
            // 빈 방이 있다면 빈 방들 중 가장 번호가 낮은 방 부여
            for (int j = 0; j < n; ++j) {
                if (rooms[j].isUsing == false) {
                    rooms[j].isUsing = true;
                    rooms[j].finishTime = meetings[i][1];
                    isAssigned = true;
                    cnt[j]++;
                    break;
                }
            }
            // 빈 방이 없다면 방들 중 끝나는 시간이 가장 빠른 방 부여
            if (isAssigned == false) {
                int idx = 0;
                long long minFin = rooms[0].finishTime;
                for (int j = 1; j < n; ++j) {
                    if (rooms[j].finishTime < minFin) {
                        idx = j;
                        minFin = rooms[j].finishTime;
                    }
                }
                
                rooms[idx].finishTime += (meetings[i][1] - meetings[i][0]);
                cnt[idx]++;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[res] < cnt[i])
                res = i;
        }
        return res;
    }
};