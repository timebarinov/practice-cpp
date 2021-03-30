int reverse(int x) {
    string s = to_string(x);
    if (s[0] == '-') {
        std::reverse(s.begin() + 1, s.end());
    } else {
        std::reverse(s.begin(), s.end());
    }    
    auto xs = stol(s);
    if (xs > INT_MAX || xs < INT_MIN) {
        return 0;
    }
    return xs;
}
// reverse int
int reverse(int x) {
    int new_x = 0;
    while (x % 10 != 0 || x / 10 != 0) {
        if (abs(new_x) > INT_MAX / 10) return 0;
        new_x = new_x * 10 + x % 10;
        x /= 10;
    }
    return new_x;
}
