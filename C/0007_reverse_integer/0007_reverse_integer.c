int reverse(int x) {
    int res = 0;
    while (x != 0) {
        // if this is true, then res * 10 + x % 10 must over INT_MAX
        if (res != 0 && (INT_MAX / res < 10) && (INT_MAX / res > -10))
            return 0;
        res = res * 10 + x % 10;
        x = x / 10;
    }
    
    return res;
}