t1=30;
t2=60;
t3=90;
d=5.2;

L1=5.7; 
L2=13;
L3=11.7;
t=2;

A1=[cosd(t1),0,sind(t1),0;sind(t1),0,cosd(t1),0;0,1,0,L1;0,0,0,1];
A2=[cosd(t2) -sind(t2) 0 L2*cosd(t2);sind(t2) cosd(t2) 0 L2*sind(t2);0 0 1 0;0 0 0 1];
A3=[cosd(t3) -sind(t3) 0 L3*cosd(t3);sind(t3) cosd(t3) 0 L3*sind(t3);0 0 1 t;0 0 0 1];

H=A1*A2*A3;

x=H(1,4);
y=H(2,4);
z=H(3,4);


theta1=atan2(y,x);                                  %-3.1024=-177.7544d--->-87.7544 degrees
xc=x-d*cosd(theta1);                                %0.0519=2.9737d--->162.0263 degrees
yc=y-d*sind(theta1);                                %2.6065=149.3414d--->316.3677 degrees

D=(xc^2+yc^2+(z-L1^2)-L2^2-L3^2)/(2*L2*L3);

theta3=atan2((1-D^2)^.5,D);
theta2=atan2(z-L1,(xc^2+yc^2)^.5)-atan2(L3*sin(theta3),L2+L3*cos(theta3));