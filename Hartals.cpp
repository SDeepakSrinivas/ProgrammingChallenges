//============================================================================

// Name        : Hartals.cpp
// Author      : SDS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int p;
		cin>>p;

		int h[p];
		for(int i=0;i<p;i++)
			cin>>h[i];

		int flag[n];
		for(int i=0;i<n;i++)
			flag[i]=0;

		for(int i=0;i<p;i++)
		{
			int har=h[i];
			while(har<=n+1)
			{
				if(((har%7)!=6)&&((har%7)!=0))
					flag[har]=1;
				har+=h[i];
			}
		}
		int count=0;
		for(int i=0;i<=n;i++)
			if(flag[i]==1)
				count++;

		cout<<count<<"\n";


	}
	return 0;
}
