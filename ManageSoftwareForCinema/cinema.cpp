#include<bits/stdc++.h> // that will automatically include all librarys
using namespace std;

void SeatBooking(int *cinema,int row,int col,int total_col)  // it will book the ticket or seat in cinema 
{
	if((cinema+(row-1)*total_col)[col-1]==1)     // here i use col-1 and row-1 because indexing always start from 0
	                                             // hence if you want to book seant number 1st row and 1st columns it will be booked 0th row and 0th column in actual array;
	                                             //here i have not check boundry condition like if you want a book seat number that is not the cinema or out of range then it will 
	                                             // abort the process plz ignore it..
	                                             // but i have implemented all featured that was mentioned in question
	cout<<"Sorry, seat not available\n";
	else
	{
	      (cinema+(row-1)*total_col)[col-1]=1;
		cout<<"Congratulation... youe seat hase been booked\n";
		
	}
}


void SeatAnalysis(int *cinema,int row,int col)      // it will show hou many seat is vacant and filled
{   
     int vacant=0,fill=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if ((cinema+i*col)[j]==0)
			vacant++;
			else
			fill++;
		}
	}
	cout<<"Total number of Vacant seats are "<<vacant<<endl;
	cout<<"Total number of Fill seats are "<<fill<<endl;
}




void RowLeastOccupancy(int *cinema,int row, int col)  //show the row which have least occupancy 
{  int least_row,fill,least_row_val=999999;
	for(int i=0;i<row;i++)
	{
	   
	   for(int j=0;j<col;j++)
	   {
	   	if((cinema+i*col)[j]==1)
	   	fill++;
	   }
	   if (fill<least_row_val)
	   {
	   	least_row_val=fill;
	   	least_row=i+1;
	   }
	   fill=0;
	}
	cout<<"Least occupied row is "<<least_row<<endl;
}




void ColumnLeastOccupancy(int *cinema,int row, int col)  // show the column which have least occupancy
{  int least_col,fill,least_col_val=999999;
	for(int i=0;i<row;i++)
	{
	   
	   for(int j=0;j<col;j++)
	   {
	   	if((cinema+j*col)[i]==1)
	   	fill++;
	   }
	   if (fill<least_col_val)
	   {
	   	least_col_val=fill;
	   	least_col=i+1;
	   }
	   fill=0;
	}
	cout<<"Least occupied column is "<<least_col<<endl;
}



void DisplayCinema(int *cinema,int row,int col)     // display the all seats of cinema
{
cout<<"Note: 1 for filled seat and 0 for vacant seat................................................\n\n";
for(int i=0;i<row;i++)
   {
	for(int j=0;j<col;j++)
	{
		cout<<(cinema+i*col)[j]<<" ";
	}
	cout<<"\n";
	}	
}


void Options()   // it will just show the option to perform the operation
{
	cout<<"Enter 1 for Book the seat.\n";
	cout<<"Enter 2 for show the number of vacant and filled seat\n";
	cout<<"Enter 3 for find the row having least occupancy\n";
	cout<<"Enter 4 for find the column having least occupancy\n";
	cout<<"Enter 5 for the Display the cinema \n";
	cout<<"Enter 0 for exit\n";
}


int main()
{
	int row,col;
	cout<<"Enter number of Rows and Colums for Cinema\n";
	cin>>row>>col;
	int cinema[row][col];  //
    memset(cinema,0,sizeof(cinema));
    while(true)  // finite loop 
    {
    	Options();
    	int op;
    	cin>>op;
    	if(op<0 and op>5)
    	{
    		cout<<"Plz enter valid number\n";
    		continue;
		}
		if(op==1)
		{                            // we can also take one another input from user that how many ticker you want to book and then take an array and store all rows and columns
		                            // values these funtion run in loop
		                            // but it was not asked in the question that's why i hadn't do;
			cout<<"Enter number for Row and Column for Booking the ticket\n";
             int ticket_row,ticket_col;
            cin>>ticket_row>>ticket_col;
            SeatBooking((int*)cinema,ticket_row,ticket_col,col);
		}
		else if(op==2)
		{
		  SeatAnalysis((int*)cinema,row,col);	
		}
		else if(op==3)
		{
		RowLeastOccupancy((int*)cinema,row,col);	
		}
		else if(op==4)
		{
		  ColumnLeastOccupancy((int*)cinema,row, col);	
		}
		else if(op==5)
		{
			DisplayCinema((int*)cinema,row,col);
		}
		else
		break;   // it will break the loop
	} 
}
