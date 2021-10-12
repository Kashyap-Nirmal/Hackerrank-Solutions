/*
	https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
	120721
	Solution
	Interview Prep Kit
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {
    int count = 0,i;
    for (i = 0; i < c.size() - 1; i++) {
        if (c[i] == 0) i++;
        count++;
    }
    return count;
    
    /*
		My code. Didnt work.
    unsigned int i=0,j=0,j1=c.size();
    for(i=0;i<pow(2,c.size()-2);i++)
    {
        for(i=1;i<c.size()-1;i++)    
        {
            if(c[i]==1)
                continue;
            else if((i-j)==1 | (i-j)==2)
            {
                j++;
                //cout<<"EI "<<i<<" "<<j<<"\n";                
            }                            
            else
            {                                
                //cout<<"E "<<i<<" "<<j<<" "<<c[i]<<" "<<c[j]<<"\n";
                break;                
            }
        }
        j=min(j,j1);    
        j1=j;            
    }    
    return j+1; 
    */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}