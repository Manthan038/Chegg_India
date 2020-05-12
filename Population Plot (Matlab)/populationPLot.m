t=1790:11:2100;  #date  from 1790 to 2100
y=(197273000)./(1+exp(-0.0313*(t-1913.25)));
title("Population growth in the United States");
xlabel("years");
ylabel("Population");
plot(t,y);
# calculate population of United state in 2050
t=2050;
z=(197273000)./(1+exp(-0.0313*(t-1913.25)));
disp("population will in 2050 of United States: ");
disp(ceil(z));
