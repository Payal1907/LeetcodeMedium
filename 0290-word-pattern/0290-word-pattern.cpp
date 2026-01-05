class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                words.push_back(word);
                word.clear();
            }
            else word+=s[i];
        }
        for(auto word : words) cout<<word;
        words.push_back(word);
        if(words.size()!=pattern.size()) return false;
        unordered_map<string,char> w2c;
        //pehle tune ek map leke check kiya, pr tune vice versa me check nai kiya
        //isliye 2 maps chahiye ab
        unordered_map<char,string> c2w;
        for(int i=0;i<pattern.size();i++){
            string word = words[i];
            char ch = pattern[i];
            if(w2c.count(word) && w2c[word]!=ch) return false;
            if(c2w.count(ch) && c2w[ch]!=word) return false;
            w2c[word]=ch;
            c2w[ch]=word;
        }
        //for bijection
        //counter - pattern = "abba", words = ["dog", "dog", "dog", "dog"] 
        return true;
    }
};