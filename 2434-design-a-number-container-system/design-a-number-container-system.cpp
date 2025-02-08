class NumberContainers {
public:
    map<int,int>mp;
    unordered_map<int,set<int>>vct;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        mp[index] = number;
        vct[number].insert(index);
    }
    
    int find(int number) {
        for(int i:vct[number]){
            if(mp[i] == number){
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */