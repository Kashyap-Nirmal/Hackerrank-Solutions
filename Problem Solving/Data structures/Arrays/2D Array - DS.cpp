/*
	https://www.hackerrank.com/challenges/2d-array/problem
	Done
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max_=INT_MIN,i=0,j=0,k=0,l=0,i_=0,j_=0,sum=0;
    for(l=0;l<16;l++){
        sum=0;
        i=i_;j=j_;
        for(k=0;k<9;k++){            
            if(k%3==0 && k!=0){
                i++;
                j=j_;
            }
            if(k==3 || k==5){
                j++;
                continue;
            }                            
            else{
                if(i<6&&j<6)
                    sum+=arr[i][j];
			/*                
                else
                    cout<<"Error in indexes"<<i;
			*/
            }                
			//cout<<i<<" "<<j<<" "<<k<<" "<<sum<<"\n";
            j++;                
        }            
        max_=max(max_,sum);     
		//cout<<"\n"<<max_<<" "<<sum<<"\n";       
        j_++;
        if(4*(i_+1)-1==l){
            i_++;
            j_=0;
        }
    }
    return max_;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}