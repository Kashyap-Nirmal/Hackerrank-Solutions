/*	
	https://www.hackerrank.com/challenges/the-time-in-words/problem
	190721
	Done (Saw test cases.)
	Used reference (for inspiration).
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    //Inspiration:https://www.geeksforgeeks.org/convert-number-to-words/
    string single_digits[]= { "zero", "one", "two",   "three", "four","five", "six",    
    "seven", "eight", "nine","ten","eleven", "tweleve"};
 
    string two_digits[]= { "ten","eleven", "twelve","thirteen",      
    "fourteen", "quarter", "sixteen","seventeen", "eighteen", "nineteen" };
 
    string tens_multiple[] = { "","","twenty"};
    
    string time,t,t1,t2;
    t2=single_digits[h];
    if(m==0)
    {
        t1="o' clock";
        t=""; 
        time=t2+" "+t1+" ";
        return time;       
    }
    else if(m<30)
        t1="past";
    else if(m==30)
    {
        t1="past";
        t="half";
    }        
    else if(m>30)  
    {
        t1="to";    
        m=60-m;
        t2=single_digits[h+1];
    }      
    if(m>=1 && m<=9)
        t=single_digits[m];        
    else if(m>=10 && m<=19)
        t=two_digits[m%10];                
    else if(m>=20 && m<30)
        t=tens_multiple[m/10]+" "+single_digits[m%10];    
    if(m==1)
        time=t+" minute "+t1+" "+t2;
    else if(m!=15 && m!=30)
        time=t+" minutes "+t1+" "+t2;    
    else
        time=t+" "+t1+" "+t2;    
    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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