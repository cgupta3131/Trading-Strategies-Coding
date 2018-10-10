#include<bits/stdc++.h>
	
using namespace std;

int MONEY = 10000;
//For betterment, include spike value and flag!
int Buy_Shares(float &Money, float &Number_of_Shares, float Current_Price)
{
	float Share_Money = 1 * Money;
	int Number_of_Shares_to_Buy = Share_Money/Current_Price;
	Number_of_Shares += Number_of_Shares_to_Buy;
	Money -= Number_of_Shares_to_Buy*Current_Price;

	return Number_of_Shares_to_Buy;
}

int Sell_Shares(float &Money, float &Number_of_Shares, float Current_Price)
{	
	//9963.75, 30, 168.9

	float Temp_Money = (1.2*MONEY) - Money; 	
	float Share_Money;

	if(Temp_Money < 0) //I can afford to 
	{
		int Number_of_Shares_to_Sell = ceil(Number_of_Shares/2);
		Money += Number_of_Shares_to_Sell*Current_Price;
		Number_of_Shares -= Number_of_Shares_to_Sell;	

		return -1*Number_of_Shares_to_Sell;
	}

	Share_Money = 1*Temp_Money;


	int Number_of_Shares_to_Sell = max(1.0*Number_of_Shares, double( min( float(Share_Money/Current_Price) + 1, 
									Number_of_Shares ) ) ) ; 	


	Number_of_Shares -= Number_of_Shares_to_Sell;
	Money += Number_of_Shares_to_Sell * Current_Price;	

	return -1*Number_of_Shares_to_Sell;

}

float Typical_Price(float first, float second, float third)
{
	return (first+second+third)/3;

}


float Calculate_CCI(float *High, float *Low, float *Close, int index, int days)
{
	
	float sum =0;

	for(int i=index-days;i<=index-1;i++)
		sum += Typical_Price(High[i],Low[i],Close[i]);

	float SMA_Days = sum/days;
	float Current_Day_TP = Typical_Price(High[index],Low[index],Close[index]);

	float numerator = Current_Day_TP - SMA_Days;

	float Num_Deviation =0;
	for(int i=index-days;i<=index-1;i++)
		Num_Deviation += abs( SMA_Days - Typical_Price(High[i],Low[i],Close[i]) );

	Num_Deviation /= days;

	float denominator = Num_Deviation*0.015;

	return numerator/denominator;

}



int main()
{
	int days = 524;
	//Close Open High Low is Format for final.txt
	
	float *Close = new float[days+1];
	float *Open = new float[days+1];
	float *High = new float[days+1];
	float *Low = new float[days+1];

	for(int i=1;i<=days;i++)
		cin >> Close[i] >> Open[i] >> High[i] >> Low[i];

	bool signal = true; //true means buying

	float Money = MONEY;
	float Number_of_Shares = 0;

	float Previous_Daily_CCI = Calculate_CCI(High,Low,Close,10,3);
	int spike = 1;

	for(int i=11;i<=days;i++)
	{
		float Weekly_CCI = Calculate_CCI(High,Low,Close,i,10);
		float Daily_CCI = Calculate_CCI(High,Low,Close,i,3);

		if(Weekly_CCI > 100)
			signal = true;
		if(Weekly_CCI < -100)
			signal = false;
			
		if(Daily_CCI > 100)
			signal = true;
		if(Daily_CCI < -100)
			signal = false;

		if(Previous_Daily_CCI < -100 && (Daily_CCI - Previous_Daily_CCI) > spike)
			signal = true;
		if(Previous_Daily_CCI > 100 && (Daily_CCI - Previous_Daily_CCI) < -1*spike)
			signal = false;


		int buy_shares;
		int sell_shares;
		if(signal == true)
		{
			buy_shares = Buy_Shares(Money, Number_of_Shares, Close[i]);
			//cout << buy_shares << "\t" << Money+Number_of_Shares*Close[i] <<"\t\t" << Close[i] << "\t" << Number_of_Shares<< endl;
			//shares,money,closing price, number of shares
		}
		else
		{
			sell_shares = Sell_Shares(Money, Number_of_Shares, Close[i]);
			//cout << sell_shares << "\t" << Money+Number_of_Shares*Close[i] << "\t\t" << Close[i] <<  "\t" << Number_of_Shares << endl;
		}

		//cout << buy_shares << " " << sell_shares << " " << Close[i] << endl;
		//cout << buy_shares << " " << sell_shares << " " << Number_of_Shares << endl;
		cout << i << "th day: " << Money + Number_of_Shares*Close[i] << endl << endl;
		Previous_Daily_CCI = Daily_CCI;
	}

	return 0 ; 

}

