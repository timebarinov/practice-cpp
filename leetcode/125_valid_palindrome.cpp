// check valid string
bool isValid(string s) {
  vector<char> bracketMatch;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
        bracketMatch.push_back(s[i]);
      }
      if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
        if(bracketMatch.empty()) { return 0; }
        char tempBrack = bracketMatch.back();
        bracketMatch.pop_back();
        if (s[i] == ')' && tempBrack != '(') {
          return false;
        }
        if (s[i] == '}' && tempBrack != '{') {
          return false;
        }
        if (s[i] == ']' && tempBrack != '[') {
          return false;
        }
      }
    }
  return (bracketMatch.empty());
}