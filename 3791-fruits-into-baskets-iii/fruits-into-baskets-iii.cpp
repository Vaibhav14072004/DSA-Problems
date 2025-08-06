class SegmentTree {
private:
    vector<int> seg;
public:
    SegmentTree (int n) {
        seg.resize(4*n);
    }
    void build(int start, int end, int ind, vector<int>& f){
        if(start==end){
            seg[ind]=start;
            return ;
        }
        int mid=(start+end)/2;
        build(start, mid, 2*ind+1, f);
        build(mid+1, end, 2*ind+2, f);
        if(f[seg[2*ind+1]]>=f[seg[2*ind+2]]) seg[ind]=seg[2*ind+1];
        else seg[ind]=seg[2*ind+2];
        return ;
    }
    int query(int start, int end, int ind, vector<int>& f, int k){
        if(start==end){
            return seg[ind];
        }
        int mid=(start+end)/2;
        int leftIndex=-1, rightIndex=-1;
        if(f[seg[2*ind+1]]>=k) leftIndex=query(start, mid, 2*ind+1, f, k);
        else if(f[seg[2*ind+2]]>=k) rightIndex=query(mid+1, end, 2*ind+2, f, k);
        if(leftIndex==-1 && rightIndex==-1) return -1;
        else if(leftIndex!=-1 && f[leftIndex]>=k) return leftIndex;
        return rightIndex;
    }
    void update(int start, int end, int ind, int k, vector<int>& f){
        if(start==end){
            seg[ind]=start;
            return ;
        }
        int mid=(start+end)/2;
        if(k<=mid){
            update(start, mid, 2*ind+1, k, f);
            if(f[seg[2*ind+1]]>=f[seg[2*ind+2]]) seg[ind]=seg[2*ind+1];
            else seg[ind]=seg[2*ind+2];
        }
        else {
            update(mid+1, end, 2*ind+2, k, f);
            if(f[seg[2*ind+1]]>=f[seg[2*ind+2]]) seg[ind]=seg[2*ind+1];
            else seg[ind]=seg[2*ind+2];
        }
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n=f.size();
        int ans=0;
        SegmentTree* segTree = new SegmentTree(n);
        segTree->build(0, n-1, 0, b);
        for(auto fruit: f){
            int index=segTree->query(0, n-1, 0, b, fruit);
            if(index!=-1 && b[index]>=fruit){
                b[index]=-1;
                segTree->update(0, n-1, 0, index, b);
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};