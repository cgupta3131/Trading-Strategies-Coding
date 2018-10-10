#include<bits/stdc++.h>

using namespace std;


int HighestHigh(int *high, int j)
{
	

}



int main()
{	
	int day;
	cin >> day;

	int *high = new int[day+1];
	int *low = new int[day+1];
	int *HighestHigh = new int[day+1];
	int *LowestLow = new int[day+1];
	int *Close = new int[day+1];
	int *oscillator = new int[day+1];


	for(int i=1;i<=day;i++)
		cin >> high[i] >> low[i] >> HighestHigh[i] >> LowestLow[i] >> Close[i];


	for(int i=14;i<=day;i++)
	{
		for(int j=i-13;j<i;j++)
		{



		}	
	}



	return 0 ; 

}

