// find length of last word
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        while(ss>>word){}
        return word.length();
        
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int result = 0;
        while (n > 0 ){
            //двигаемся по буквам и считаем их
            if(s[--n] != ' '){
                result++;
            }
            // если добрались до пробела выходим
            else if (result > 0) {
                return result;
            }
        }
        //иначе посчитали буквы и вернули результат
        return result;
        
    }
};