// check palindrome
bool isPalindrome(int x) {
    if(x < 0) return false;
    long long y = 0, t = x;
    while (t) {
	    y = y * 10 + t % 10;
	    t /= 10;
    }
 return x == y;
}
