class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        build(nums,0,0,n-1);
    }
    void build(vector<int>& nums, int node, int start, int end){
        if(start==end){
            tree[node]=nums[start];
        }
        else{
            int mid = start+(end-start)/2;
            build(nums,2*node+1,start,mid);
            build(nums,2*node+2,mid+1,end);
            tree[node]=tree[2*node+1]+tree[2*node+2];
        }
    }

    int query(int node, int start, int end, int l, int r){
        if(r<start || l>end) return 0;
        if(l <= start && r >= end) return tree[node];
        int mid = start+(end-start)/2;
        int left = query(2*node+1,start,mid,l,r);
        int right = query(2*node+2,mid+1,end,l,r);
        return left+right;
    } 

    void updateVal(int node, int start, int end, int idx, int val){
        if(start==end) tree[node]=val;
        else{
            int mid = start+(end-start)/2;
            if(idx<=mid){
                updateVal(2*node+1,start,mid,idx,val);
            }
            else{
                updateVal(2*node+2,mid+1,end,idx,val);
            }
            tree[node]=tree[2*node+1]+tree[2*node+2];
        }
    }
    void update(int idx, int val) {
        updateVal(0,0,n-1,idx,val);    
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */