/*
	https://www.hackerrank.com/challenges/ctci-merge-sort/problem	
	020921
	Striver's SDE Sheet Day 2
	Soln Rushabh
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
void merge(vector<int> &arr, long long l, long long m, long long r, long long &ans){
    long long temp = 0;
    vector<int> left, right;
    for(int i=l; i<=m; i++){
        left.push_back(arr[i]);
    }
    for(int j=m+1; j<=r; j++){
        right.push_back(arr[j]);
    }
    long long i = 0, j = 0, k = l, n = left.size(), p = right.size();
    while(i < n && j < p){
        if(left[i] > right[j]){
            temp += ((m - l) - i + 1);
            arr[k] = right[j++];
        } else {
            arr[k] = left[i++];
        }
        k++;
    }
    while(i < n){
        arr[k++] = left[i++];
    }
    while(j < p){
        arr[k++] = right[j++];
    }
    ans += temp;
}

void count_inv(vector<int> &arr, long long l, long long r, long long &ans){
    if(l == r) return;
    long long mid = l + (r - l) / 2;
    count_inv(arr, l, mid, ans);
    count_inv(arr, mid + 1, r, ans);
    merge(arr, l, mid, r, ans);
}

long countInversions(vector<int> arr) {
    long long ans = 0, n = arr.size();
    count_inv(arr, 0, n-1, ans);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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