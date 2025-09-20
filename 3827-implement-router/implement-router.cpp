class Router {
public:
    queue<vector<int>> queue;//for doning thing in fifo oder
    unordered_map<int,vector<int>> dest_time;//store all the time_stamp in the required destination
    unordered_map<int,int> dest_time_remove;//store the offset or store how much time stamp is removed for required destination
    map<vector<int>,int> duplicates;//for track dupicates

    int size = 0;//use for maintain the size of queue <memoryLimit
    Router(int memoryLimit) {
        size = memoryLimit;
        
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source,destination,timestamp};
        if(duplicates.count(packet)){//checking duplicates
            return false;
        }

        if(queue.size() ==size){
            vector<int> res = queue.front();
            duplicates.erase(res);
            int dest = res[1];
            dest_time_remove[dest]+=1;
            queue.pop();
        }

        queue.push(packet);
        duplicates[packet]+=1;
        dest_time[destination].push_back(timestamp);
        return true;
        
    }
    
    vector<int> forwardPacket() {
        if(queue.empty()) return {};
        vector<int> res= queue.front();
        queue.pop();
        duplicates.erase(res);
        int dest = res[1];
        dest_time_remove[dest] +=1;
        return res;
        
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(dest_time.find(destination) == dest_time.end()){
            return 0;
        }

        auto &all_time = dest_time[destination];
        int dest_offset = dest_time_remove[destination];
        auto right = upper_bound(all_time.begin()+dest_offset,all_time.end(),endTime);
        auto left = lower_bound(all_time.begin()+dest_offset,all_time.end(),startTime);
        return int(right - left);
        
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */