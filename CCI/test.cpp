#include<bits/stdc++.h>

using namespace std;

int main()
{
	int days = 495;
	float shares = 0, money = 0, close = 0;

	int current_number_of_shares = 0;
	float Money = 10000;

	float sum = 0;
	for(int i=11;i<=days;i++)
	{	

		cout << "Before Trading : " << close << " " << Money << " " << current_number_of_shares << " " << Money + current_number_of_shares*close << endl;

		cin >> shares >> money >> close;
		Money += shares*close;
		current_number_of_shares += shares;
		cout << "After Trading : " << close << " " << Money << " " << current_number_of_shares << " " << Money + current_number_of_shares*close << endl;
		cout << endl;
		
	}

	return 0 ; 

}

