#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,m,n;
		long sum1=0,sum2=0;
		cin>>m>>n;
		vector<string> s;
		string str;
		for(i=0;i<m;i++)
		{
			cin>>str;
			s.push_back(str);
		}
		char a[m][n],b[m][n];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i%2==0 && j%2==0 || i%2==1 && j%2==1){
					if(s[i][j]=='G')
						sum1+=3;
					else
						sum2+=5;
				}
				else
				{
					if(s[i][j]=='R')
						sum1+=5;
					else
						sum2+=3;
				}
			}
		}
		cout<<min(sum1,sum2)<<endl;
	}
	return 0;
} 
