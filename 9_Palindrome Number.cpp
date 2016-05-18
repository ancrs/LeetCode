Determine whether an integer is a palindrome. Do this without extra space.





bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x < 10) return true;
    int y = 0;
    int tmp = x;
    while(tmp)
    {
        y = y * 10 + (tmp % 10);
        tmp /= 10;
    }

    return x == y;
}