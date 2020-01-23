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
void remm(string & s ,int count ,int cur,char nxt,int start) //passing string , counter for the length of current repeating sequence
 //nxt represents next char of string ,cur is index of cur char in string , start is the starting index of repeating terms
{
   if(nxt == s[cur])  // if next char is equal to cur char than 
   {
     count++;         //increase counter length of string 
     if(start == 0 && s[0] != s[1]) // if start is not set already and s[0] first char is not equal to second s[1] than start = cur;
     {
       start = cur;      //s[0]!=s[1] because if we do not do that s will become 1 and the firsr repeating char of string will not be removed
     }
   } 
   if(count!=0 && nxt != s[cur] || count!=0 && cur == s.size() -1)//if we have some value in counter it means that there are
    //some repeating char in it and in order to trace all repeating char we hace done that nxt != s[cur] because if we have aaa than
    //without the second condition (nxt!=s[cur]) we are going to delete only two a's
    // and if we have repeating char at the end of string and count != 0 so we have another condition
    //-1 because we can't acces the s[s.size()] because it do not exist
   {
     s.erase(start , count+1); 
    // cout<<"start "<<start<<" current "<<count<<endl;
     cur = cur - (count+1); //count+1 because if we have aaa than count will compare it two times for each pair and we going
    //to get the count = 2 but there are always 1 extra repeating character so +1;
    // cout<<"string is "<<s<<endl;
     start = 0; //resetting values for next call to detect next reccuring pair;
     count = 0;
   }
   if(cur == s.size())
   {
     for(int i = 0 ; i < s.size() ; i++){
       if(s[i] == s[i+1]){remm(s , 0 , i , s[i+1] , 0);}//if we reach the end of the string and we again traverse the whole string
      //in order to get sure that we have no repeating term in it after removing its initial repeating term
      //eg mississipie
      //in this after removing all term we get miiipie 
      //but actual answer is mpie
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
