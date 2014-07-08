/*
 * 3nplus1.cpp
 *
 *  Created on: Jul 8, 2014
 *      Author: SDS
 */

#include<iostream>
using namespace std;

long int cycle_length(long int num)
{
	long int len=1;
	while(num!=1)
	{
		if(num%2==0)
			num/=2;
		else
			num=(num*3+1);
	len++;
	}
	return len;
}

long int max_cycle_length(long int n1,long int n2)
{
	long int max=0;
	for(long int i=n1;i<=n2;i++)
		if(cycle_length(i)>max)
			max=cycle_length(i);
	return max;
}

int main()
{
	long int n1,n2;
	while(cin>>n1)
	{
		cin>>n2;
		if(n2>=n1)
			cout<<n1<<" "<<n2<<" "<<max_cycle_length(n1,n2)<<"\n";
		else if(n1>n2)
			cout<<n1<<" "<<n2<<" "<<max_cycle_length(n2,n1)<<"\n";

	}
	return 0;
}



