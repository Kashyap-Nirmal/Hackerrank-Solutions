/*
	https://www.hackerrank.com/challenges/drawing-book/problem
	Done [Many tries. Unlocked hidden test case]
	140721
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {    
    int cnt=0,i=0,l=0,r=1,l1=n-1,r1=n; 
    if(n%2==0)
        l1=r1;
    if(l==p | r==p | l1==p | r1==p)
        return 0;
    for(i=0;i<p;i++)
    {        
        l+=2;
        r+=2;
        if(l1==r1)
        {
            //For test case 6,5
            l1-=2;
            r1-=1;            
        }         
        else
        {
            l1-=2;
            r1-=2;        
        }   
        cnt++;    
        if(l==p | r==p | l1==p | r1==p)
            break;   
    }
    /*
        Attempted
    if(p==n-1 && n%2!=0 | p==n)
        return 0; 
    if(p<n/2)
        cnt+=ceil((p-1)/2.0);
    else 
        cnt+=ceil((n-p)/2.0);
    */
    return cnt;    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}