#include<bits/stdc++.h>
using namespace std;
void FillRandom(int row,int col,float* Matrix1,float* Matrix2)
{
    srand(time(0));  // for random seed from time

    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            float random = ((float) rand()) / (float) RAND_MAX;  // generate random number between 0 and 1
            (Matrix1+i*col)[j]=random;
            float random1 = ((float) rand()) / (float) RAND_MAX;  // again random for 2nd matrix
            (Matrix2+i*col)[j]=random1;
        }
    }
    
}

void caluculateMeanAverageError(int row,int col,float* Matrix1,float* Matrix2)
{ 
    float total=0,m1,m2;
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            m1=(Matrix1+i*col)[j];
            m2=(Matrix2+i*col)[j];
            total+=abs(m1-m2);    // calculating the totale error
        }
    }
    float meanAvarageError=total/(float)(row*col);  // using the formula of MAE
    if(meanAvarageError<0.9)                // checking condition
    cout<<"Matrices are similar!!\n";
    else
    cout<<"Matrices are not similar!!\n";
}

int main()
{
    int row1,row2,col1,col2;
    cout<<"Enter Dimensions for Matrix:\n ";
    while(1) // for infinite loop
    { cout<<"Enter Row and columns for First Matrix : \n";
      cin>>row1>>col1;
      cout<<"Enter Row and Columns for second Matrix : \n";
      cin>>row2>>col2;
      if(row2==row1 and col2==col1)
      break;
      else
      cout<<"Please Enter same Dimensions for Matrices \n";
    }
    float Matrix1[row1][col1],Matrix2[row1][col1]; // defining the Matrices
    FillRandom(row1,col1,(float*)Matrix1,(float*)Matrix2);  // for assigning random values

    caluculateMeanAverageError(row1,col1,(float*)Matrix1,(float*)Matrix2);
}
