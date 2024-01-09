#include <iostream>

using namespace std;

bool reversestring(string &str, int i, int j)
{
    if (i >= j)
    {
        return false;
    }

    if (str[i] != str[j])
    {
        return false;
        i++;
        j--;
    }
    else
    {
        i++;
        j--;

        reversestring(str, i, j);
    }
}

int main()
{
    string str = "i am the one who can ecknow everything";

    int j = str.length() - 1;

    int i = 0;
    bool pl = reversestring(str, i, j);
    if (pl)
    {
        cout << "h";
    }
    else
    {
        cout << "no";
    }
    cout << endl;
    return 0;
}