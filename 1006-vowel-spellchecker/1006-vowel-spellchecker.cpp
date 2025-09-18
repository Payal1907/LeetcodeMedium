class Solution {
public:
    unordered_set<string> exact;
    unordered_map<string,string> caseMp;
    unordered_map<string,string> vowelMp;
    string devowel(string& s)
    {
        string ans;
        for(char& c: s)
        {
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') ans.push_back('*');
            else ans.push_back(c);
        }
        return ans;
    }
    string lower(string& s)
    {
        string ans;
        for(char c : s)
        {
            ans.push_back(tolower(c));
        }
        return ans;
    }
    string checkMatch(string& query)
    {
        if(exact.count(query)) return query;
        string l = lower(query);
        if(caseMp.count(l)) return caseMp[l];
        string v = devowel(l);
        if(vowelMp.count(v)) return vowelMp[v];
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    exact.clear();
    caseMp.clear();
    vowelMp.clear();
    vector<string> ans;
    for(string word : wordlist)
    {
        exact.insert(word);
        string l = lower(word);
        if(caseMp.find(l)==caseMp.end()) caseMp[l]=word;
        string v = devowel(l);
        if(vowelMp.find(v)==vowelMp.end()) vowelMp[v]=word;
    }
    for(string& query : queries)
    {
        ans.push_back(checkMatch(query));
    }

    return ans;

    }
};