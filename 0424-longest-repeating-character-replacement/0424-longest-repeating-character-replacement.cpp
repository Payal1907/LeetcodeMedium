class Solution {
public:
    int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int maxFreq = 0;
    int left = 0;
    int maxi = 0;
    for (int right = 0; right < s.size(); right++) {
        char current = s[right];
        freq[current - 'A']++;
        maxFreq = max(maxFreq, freq[current - 'A']);
        // Shrink window if >k
        while (right - left + 1 - maxFreq > k) {
        freq[s[left] - 'A']--;
        left++;
    }
     maxi = max(maxi, right - left + 1);
    }
    return maxi;
    }
};