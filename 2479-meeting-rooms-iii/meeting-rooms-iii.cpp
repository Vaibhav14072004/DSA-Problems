class Solution {
public:
    struct Meeting {
        long start, end;
        int room;
        Meeting(long start, long end, int room) : start(start), end(end), room(room) {}
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        auto cmpRooms = [](int a, int b) { return a > b; };
        priority_queue<int, vector<int>, decltype(cmpRooms)> rooms(cmpRooms);
        for(int i = 0; i < n; i++) {
            rooms.push(i);
        }

        auto cmpMeetings = [](const Meeting& a, const Meeting& b) {
            return (a.end == b.end) ? (a.room > b.room) : (a.end > b.end);
        };
        priority_queue<Meeting, vector<Meeting>, decltype(cmpMeetings)> occupied(cmpMeetings);

        vector<int> roomUtilization(n, 0);
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for(const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            while(!occupied.empty() && occupied.top().end <= start) {
                rooms.push(occupied.top().room);
                occupied.pop();
            }

            if(!rooms.empty()) {
                int room = rooms.top();
                rooms.pop();
                occupied.push(Meeting(start, end, room));
                roomUtilization[room] += 1; 
            } else {
                Meeting meeting = occupied.top();
                occupied.pop();
                long diff = meeting.end - start;
                occupied.push(Meeting(start + diff, end + diff, meeting.room));
                roomUtilization[meeting.room] += 1;
            }
        }

        int room = -1, maxValue = 0;
        for(int i = 0; i < n; i++) {
            if(maxValue < roomUtilization[i]) {
                maxValue = roomUtilization[i];
                room = i;
            }
        }

        return room;
    }
};
