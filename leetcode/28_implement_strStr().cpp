class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.empty()){
            int check = haystack.find(needle);
            if(check != string::npos){
                return check;
            }
            return -1;
        }
        return 0;
    }
};