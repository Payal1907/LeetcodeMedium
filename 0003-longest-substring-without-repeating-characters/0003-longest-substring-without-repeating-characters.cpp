class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n == 0) return 0;

    unordered_set<char> set;
    int left = 0, right = 0, maxi = 0;

    while (right < n) {
        if (!set.count(s[right])) {
            set.insert(s[right]);
            maxi = max(maxi, right - left + 1);
            right++;
        }
        else
        {set.erase(s[left]);
        left++;
        }
    }
    return maxi;
    }
};