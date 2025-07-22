class Solution {
public:
// yayyy tu notebook dekh apni, poora din sochke kuch to milta hai good
    int maxArea(vector<int>& height) {
    int maxi = INT_MIN;
    int left = 0, right = height.size()-1;
    while(left<=right)
    {
        maxi = max(maxi,min(height[left],height[right])*(right-left));
        if(height[left]<height[right]) left++;
        else right--;
    }
    return maxi;
        
    }
};