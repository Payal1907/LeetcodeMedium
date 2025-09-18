class Solution {
public:
//dekh isme pehle to hmne conditional statements ke sath try kiya tha, but problem ye thi ki
//hr query ke liye sare word nai check kr paa rhe the hm kyuki break kr rhe the baar baar
//to ye better way hai ki hr type ke error ko hmne store kiya, aur jo case mil jaayege
//use return kr denge
//lower func hai, kyuki tolower() words only on character
//devowel is basically used ki vowels replace krne ke baad query aur word same hai ki nai wo check
//kr ske, isliye 3 maps for all three cases
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