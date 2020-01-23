/*Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd
mississippi

Output:
gksforgk
acac
mpie*/
#include<iostream>
#include<string>
using namespace std;
void remm(string & s ,int count ,int cur,char nxt,int start)
{
   if(nxt == s[cur])
   {
     count++;
     if(start == 0 && s[0] != s[1]) 
     {
       start = cur;
     }
   } 
   if(count!=0 && nxt != s[cur] || count!=0 && cur == s.size() -1)
   {
     s.erase(start , count+1);
    // cout<<"start "<<start<<" current "<<count<<endl;
     cur = cur - (count+1);
    // cout<<"string is "<<s<<endl;
     start = 0;
     count = 0;
   }
   if(cur == s.size())
   {
     for(int i = 0 ; i < s.size() ; i++){
       if(s[i] == s[i+1]){remm(s , 0 , i , s[i+1] , 0);}
     }
     return;
   } 
   else
   {
   cur++;
   remm(s,count,cur , s[cur+1] , start);
   }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s , n;
        cin>>s;
        char a = s[1];
        remm(s , 0 ,0,a,0);
        cout<<s<<endl;
    }
}
