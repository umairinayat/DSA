#include<iostream>

using namespace std;
void permutation(char s[], int k){
    static int  A[10]={0};
    static char result[10];
    int i=0;
    if (s[k]=='\0')
    {
        result[k]='\0';
        cout<<result<<endl;
    }
    

    for ( i = 0; s[i]!='\0'; i++)
    {
        if (A[i]==0)
        {
            result[k]=s[i];
            A[i]=1;
            permutation(s, k+1);
            A[i]=0;
        }
        
    }
    
}
int main() {
    char s[]="ABC";
    permutation(s,0);

    cout << endl ;
    return 0;
}