#include <iostream>

using namespace std;

void reversestring(string &str, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    reversestring(str, i, j);
}


int main()
{
    string str = "i am the one who can ecknow everything";

    int j = str.length() - 1;
    cout << "Before reverse " << endl;
    cout << str << endl;
    int i = 0;
    reversestring(str, i, j);
    cout << "After" << endl;

    cout << str << endl;
    cout << endl;
    return 0;
}