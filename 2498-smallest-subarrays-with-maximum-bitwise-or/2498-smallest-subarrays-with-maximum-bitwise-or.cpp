class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>ans(nums.size(),1); 
        vector<int> bit(32,-1);
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int b=0;b<32;b++)
            {
                if(nums[i]>>b&1) //checking if bit is set
                {
                    bit[b]=i;
                }
            }
            int maxDistance = i; //ab set bit se check krenge ki kaha maxDistance pe bit phirse
            //set hai, logic is set ke baad dobara set milne pe maxOr hi milega, farthest mtlb
            //closest hi hoga
            for(int b=0;b<32;b++)
            {
                if(bit[b]!=-1) maxDistance=max(maxDistance,bit[b]);
            }
            ans[i]=maxDistance-i+1;
        }    
        return ans;     
    }
};