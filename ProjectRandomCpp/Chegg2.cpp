#include<bits/stdc++.h>
using namespace std;
void menu()
{
	cout<<"Enter T for TV\n";
	cout<<"Enter R for Refrigerator\n";
	cout<<"Enter L for Laptop\n";
	cout<<"Enter M for Mobile\n";
	cout<<"Enter E to exit\n";	
}
int int_number_generator()
{ 
srand(time(0));
 return (rand()%100 +1); // this is will return a randome number between 1 to 100  
                         // you can change this limit as your wish	
}
double double_price_generator(int n)  // n will be code value for Tv and Rf , for Tv n=1 and rest value will for Rf
{
	double min_limit,max_limit;
	if(n==1)  // for TV
	{
		min_limit=300;
		max_limit=1000;
	}
	else // for Referigerator
	{
		min_limit=100;
		max_limit=500;
	}
	srand(time(0));

    double lower_bound = min_limit;
   double upper_bound = max_limit;
   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
   std::default_random_engine re;
   double Random_val = unif(re);
    return Random_val;            // it will generate double random number between min_limit and max_limit
	
}
double TV_price(int Tvs,double price)  //  for calculating the price of TV 
{
	return ((double)(Tvs)*price);
}
double Refrigerator_price(int Rfs,double price)

{
	//Tax amount (5.5%) for refrigerator 
	double tax=(price*(double)Rfs)*0.055;
	return (((double)Rfs*price)+tax);
}
double Laptop_price(int lp)
{
	return ((double)lp*1000);    // Laptop price is 1000 fixed 
}
double Mobile_price(int Mv)
{
	
	if (Mv<=10)
	return ((double)Mv*500);  // when number of Mobile is less than or equal to 10
	else
	return ((double)10*500 + (double)(Mv-10)*250);   // number of Mobile is greater than 10
}
int main()
{
 char choice;
 bool flag=false;
 double total_price;  // for total price
 menu();
 while(true)
     { 
 	    //menu();   // remove comment from here to print menu every time;
 	    cin>>choice;
 	    switch(choice)
 	    {
 	    	case 'T':{
 	    		int val=int_number_generator();
 	    		double price=double_price_generator(1);
 	    		double tv_pc=TV_price(val,price);
 	    		total_price+=tv_pc;
 	    		cout<<"Price of "<<val<<" TVs is "<<tv_pc<<endl;
				break;
			         }
		    case 'R':
		    	{
		    	int val=int_number_generator();
 	    		double price=double_price_generator(2);
 	    		double Rf_pc=Refrigerator_price(val,price);
 	    		total_price+=Rf_pc;
 	    		cout<<"Price of "<<val<<" Refrigerator's is "<<Rf_pc<<endl;
				 break;	
				}
			case 'L':
				{
					int val=int_number_generator();
 	    		double Lp_pc=Laptop_price(val);
 	    		total_price+=Lp_pc;
 	    		cout<<"Price of "<<val<<" Laptop's is "<<Lp_pc<<endl;
				 break;	
					
				}
			case 'M':
				{
				int val=int_number_generator();
 	    		double Mb_pc=Mobile_price(val);
 	    		total_price+=Mb_pc;
 	    		cout<<"Price of "<<val<<" Mobile's is "<<Mb_pc<<endl;
				 break;	
				}
			case 'E':
				{
					flag=true;
				break;
				}
			default :
				{
					cout<<"Wrong Entry\n";
				}
		}
		if(flag)break;
	 }
 cout<<"Total price of assests "<<round(total_price);	 
	 	
}
