class Solution {
public:

    string encode(vector<string>& arr) {
        string encoded_string = "";
        for(auto it: arr)
        {
            int size = it.size();
            string sz = to_string(size);
            sz += "/:";
            encoded_string += sz+it;
        }
        
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int n = s.size();
        int i = 0;
        while(i < n)
        {
            int delim_pos = s.find("/:", i);
        
            int size = stoi(s.substr(i, delim_pos - i));
        
            int word_start = delim_pos + 2;
        
            string word = s.substr(word_start, size);
            decoded_strs.push_back(word);
        
            i = word_start + size;
        }
        return decoded_strs;
    }
};
