#Chegg 
# Golden ration search for minimum value 
N=100;  # numeber of iteration 
f=@(x) x^4+2*x^3+8*x^2+5^x;
err=0.01;  #result accuracy
xl=-2.5;   # lower side
xu=1.5;    #upper side

for i=1:N 
d=0.5*(sqrt(5)-1)*(xu-xl);
x1=xl+d;
x2=xu-d;
if f(x1)>f(x2)
xl=x2;
else
 xu=x1;
end

end
FF =f(x1);
disp(['Opttimal(Minimum) Value:' num2str(FF)])
