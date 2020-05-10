#include<stdio.h>
#include<math.h>
/*Define the RHS of the first order differential equation here(Ex: dy/dx=f(x,y))  */
double f(double x, double y)
{
    return exp(-x)*sin(x);   // solution function ;
}
int main(){
    int i;
    double x,y,x0,y0,h,q1,q2,q3,q4;
    double a,b,a0,b0,r1,r2,r3,r4;
    double c,d,c0,d0,s1,s2,s3,s4;
    printf("Enter the initial condition for y: ");
    scanf("%lf",&y0);
    printf("Enter the initial condition for x: ");
    scanf("%lf",&x0);
    printf("Enter the value of x for which y is required: ");
    scanf("%lf",&x);
    a=c=x;b=d=y;a0=c0=x0;b0=d0=y0;     // same value copy for 3 defferent step width value
    r1=s1=q1;r2=s2=q2;r3=s3=q3;r4=s4=q4;
    printf("Enter the 1st step-width H : ");
    scanf("%lf",&h);
    printf("x\t\ty\t\tk1\t\tk2\t\tk3\t\tk4\t\tk_avg\n");
    printf("__________________________________________________________________________________________________________\n");
    //4th order Begin Runge-Kutta Routine method
    while((x-x0)>0.0000000001){
        q1=h*f(x0,y0);                 // define function   
        q2=h*f(x0+h/2.0,y0+q1/2.0);
        q3=h*f(x0+h/2.0,y0+q2/2.0);
        q4=h*f(x0+h,y0+q3);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",x0,y0,q1,q2,q3,q4,1/6.0*(q1+2*q2+2*q3+q4));
        y=y0+1/6.0*(q1+2*q2+2*q3+q4);
        y0=y;
        x0=x0+h;
    }
    printf("%lf\t%lf\n",x0,y0);
    printf("____________________________________________________________________________________________________________\n");
    printf("The value of y in 1st setp is %lf\n\n",y);
    
    // for second H value 
    
    printf("Enter the 2nd step-width H : ");
    scanf("%lf",&h);
    printf("x\t\ty\t\tk1\t\tk2\t\tk3\t\tk4\t\tk_avg\n");
    printf("__________________________________________________________________________________________________________\n");
    //4th order Begin Runge-Kutta Routine method
    while((a-a0)>0.0000000001){
        r1=h*f(a0,b0);                 // define function   
        r2=h*f(a0+h/2.0,b0+r1/2.0);
        r3=h*f(a0+h/2.0,b0+r2/2.0);
        r4=h*f(a0+h,b0+r3);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",a0,b0,r1,r2,r3,r4,1/6.0*(r1+2*r2+2*r3+r4));
        b=b0+1/6.0*(r1+2*r2+2*r3+r4);
        b0=b;
        a0=a0+h;
    }
    printf("%lf\t%lf\n",a0,b0);
    printf("____________________________________________________________________________________________________________\n");
    printf("The value of y in 2rd setp is %lf\n\n",b);
      
      /// for third value of H
    printf("Enter the 3st step-width H : ");
    scanf("%lf",&h);
    printf("x\ty\tk1\tk2\tk3\tk4\tk_avg\n");
    printf("__________________________________________________________________________________________________________\n");
    //4th order Begin Runge-Kutta Routine method
    while((c-c0)>0.0000000001){
        s1=h*f(c0,d0);                 // define function   
        s2=h*f(c0+h/2.0,d0+s1/2.0);
        s3=h*f(c0+h/2.0,d0+s2/2.0);
        s4=h*f(c0+h,d0+s3);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",c0,d0,s1,s2,s3,s4,1/6.0*(s1+2*s2+2*s3+s4));
        d=d0+1/6.0*(s1+2*s2+2*s3+s4);
        d0=d;
        c0=c0+h;
    }
    printf("%lf\t%lf\n",c0,d0);
    printf("____________________________________________________________________________________________________________\n");
    printf("The value of y in 3rd setp is %lf\n\n",d);
}
