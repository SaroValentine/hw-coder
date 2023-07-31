#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    char c;
    getline(cin, str);
    cin >> c;

    bool is_word = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
    if (is_word && c >= 'a')
    {
        c -= 'a' - 'A';
    }
    int ans = 0;
    for (char t : str)
    {
        if (t == c)
        {
            ans++;
        }
        if (is_word && t == c + 'a' - 'A')
        {
            ans++;
        }
    }
    cout << ans << endl;
}