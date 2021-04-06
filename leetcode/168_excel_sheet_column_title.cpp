class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s; 
        while (columnNumber) {
            int n = (columnNumber-1) % 26; 
            s = (char)('A' + n) + s; 
            columnNumber = (columnNumber-1)/26; 
        }
        return s; 
    }
};

class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(!columnNumber) return "";
        return convertToTitle((columnNumber - 1) / 26) + (char) ((columnNumber - 1) % 26 + 'A');
    }
};