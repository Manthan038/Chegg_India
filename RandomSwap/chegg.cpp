#include<bits/stdc++.h>
using namespace std;

void inputNumbers(int *First_number,int *Second_number)
{  
    
	srand(time(0));/// random seed from current time;
	
	*First_number=10000+rand()%10001;   /// random numebr between 10000 to 20000 inclusive 
	*Second_number =10000+rand()%10001;  // second random numebr between 10000 to 20000 inclusive 
	
}
void swapNumbers(int &first,int &second)
{
	int temp;    // swapping with help of temp variable 
	temp=first;
	first=second;
	second=temp;
}

int MaxNumbers(int first,int second)
{   
	if(first>second)return first;    // give the max value
	                                 // but it will return the second value when both are same
	                                 // as in question that output should be value to any random number 
	else return second;
}
int  main()
{    int First_number,Second_number;
	inputNumbers(&First_number,&Second_number);
	cout<<"Two random number between (10,000 - 20,000): \n";
	cout<<"Original values :\n";
	cout<<"First Number = "<<First_number<<"\t\tSecond Number = "<<Second_number<<endl;
	
	
    cout<<"Swapping values :\n";
    swapNumbers(First_number,Second_number); // swaping the numbers
	cout<<"First Number = "<<First_number<<"\t\tSecond Number = "<<Second_number<<endl;
	int maxValue=MaxNumbers(First_number,Second_number);
	cout<<"Lasger value= "<<maxValue;
}
