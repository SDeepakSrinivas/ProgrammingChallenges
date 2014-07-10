/*
 * JollyJumpers.cpp
 *
 *  Created on: Jul 10, 2014
 *      Author: SDS
 */

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{

		int n;
		while(cin>>n)
		{
		int flag[n-1];
		for(int i=0;i<n-1;i++)
			flag[i]=0;
		int a,b;
		cin>>a;
		for(int i=1;i<n;i++)
		{
			cin>>b;
			flag[abs(b-a)-1]=1;
			a=b;
		}
		int ff=1;
		for(int i=0;i<n-1;i++)
			if(flag[i]!=1)
				ff=0;
		if(ff==0)
			cout<<"Not jolly\n";
		else
			cout<<"Jolly\n";

		}
	return 0;
}

