class Solution {
public:
    vector<int> prefixMax(vector<int> arr)
    {
        vector<int> prefix(arr.size(),-1);
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            prefix[i]=std::max(prefix[i-1],arr[i]);
        }
        return prefix;
    }
    vector<int> suffixMax(vector<int> arr)
    {
        vector<int> suffix(arr.size(),-1);
        suffix[arr.size()-1]=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            suffix[i]=std::max(suffix[i+1],arr[i]);
        }
        return suffix;
    }
    int trap(vector<int>& height) {
        int total=0;
        vector<int> leftMax = prefixMax(height);
        vector<int> rightMax = suffixMax(height);
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i]<leftMax[i] && height[i]<rightMax[i])
            {
                total+=min(leftMax[i],rightMax[i])-height[i];
            }
        }
    return total;
    }
};