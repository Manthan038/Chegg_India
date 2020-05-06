#Probability of being infected 
# Probability of being infected when he first time go outside the home
prb=zeros(10,1);
prbC=(1/5)*(1/20); #20% x 5%
prb(1,1)=prb;   
for i=2:1:10;
   prb(i,1)=prb(i-1,1)+((1-prbC)^(i-1))*prbC;
endfor;

NumberOfSimulation=20;  # as per question number of simulation 100,000
A=zeros(2*NumberOfSimulation,4);
for k=1:2:20;
   for i=1:1:10;
     A(k,1)=(k+1)/2;
     A(k+1,1)=(k+1)/2;
     randomNumber=randi(100);
     Y=~mod(randi(randomNumber*5),randomNumber);    #probability is 20%
     if (Y);
        A(k,2)=Y;      # infacted person were haveing infection or not
        A(k+1,2)=Y;

              #without mast
         A(k,4)=Y;
               #for Using Mask
      A(k+1,3)=1;
      infected_with_mask=~mod(randi(100),20);   # because probability is 5% (5 chances out of 100)
      A(k+1,4)=infected_with_mask || A(k+1,4);
      endif;
    endfor;
endfor;
prb

#fist column is for nth person who go outside the house;
#Second column is for person was silent spreader whome nth person meet
# third column is for nth person used Mask or not
#fourth column shows finally nth person get infected or not
A
