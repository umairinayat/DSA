#include<iostream>

using namespace std;


void permutation(char s[], int l, int h){
    int i;
    if(l==h)
    {
        cout<<s<<endl;
    }
    else
    {
       for (int i = l; i < h; i++)
       {
        swap(s[l], s[i]);
        permutation(s, l+1, h);
        swap(s[l], s[i]);
       }
       
    }

}
int main() {
    char s[]="ABC";
    permutation(s,0, 3);

    cout << endl ;
    return 0;
}