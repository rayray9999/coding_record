#include <iostream>
#include <cstring>
using namespace std;

char s[20001];

// [begin, end]
bool isPalindrome(char const* begin, char const* end)
{
    while (begin < end && *begin == *end)
        ++begin, --end;
    return begin >= end;
}

int main()
{
    
    int n, len, l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        len = strlen(s);
        l = 0;
        r = len - 1;
        while (l < r && s[l] == s[r])
            ++l, --r;
        if (len > 1 && (l >= r || isPalindrome(s+l, s+r-1) || isPalindrome(s+l+1, s+r)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
