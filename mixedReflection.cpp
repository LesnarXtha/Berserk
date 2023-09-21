#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define n 3

void draw();
void rotate(float theta);
void reflect();
void translate(int c);

int x[100],y[100],fixedx=150,fixedy=140,c,ch;
float fixedtheta=-120.0f; 

int main(){
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"");
	
	
	
	printf("Enter co-ordinates:");
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}		

	printf("Reflection of a triangle:\n\t1,About a line y=x\n\t2,About a line y=mx +c\n\t3,Exit");
	printf("Enter choice:");
	scanf("%d",&ch);
	do{
	
	switch(ch){
	
	case 1: 
	{
	rotate(fixedtheta);
	draw();
	rotate(-(fixedtheta));

	reflect();
	
	rotate(fixedtheta);

	draw();
	getch();
	closegraph();
	break;
	}
	
	
	case 2:
	{
	printf("Enter y-intercept:");
	scanf("%d",&c);	
		
	translate(c);
	rotate(fixedtheta);
	draw();
	
	translate(-c);
	
	rotate(-(fixedtheta));

	reflect();
	
	rotate(fixedtheta);

	translate(c);
	draw();
	getch();
	closegraph();
	break;
	}
	
	case 3:
		printf("Exiting the program...\n");
		break;
		
	default:
	printf("Invalid Value");
	}
	
}while(ch!=3);

return 0;
}
void draw(){
	for(int i=0;i<n;i++){
		line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
		delay(200);
	}
}

void rotate(float theta){
	for(int i=0;i<n;i++){
	int new_x=fixedx+(x[i]-fixedx)*cos(theta)-(y[i]-fixedy)*sin(theta);
	int new_y=fixedy+(x[i]-fixedx)*sin(theta)+(y[i]-fixedy)*cos(theta);
	x[i]=new_x;
	y[i]=new_y;
	}
}
void reflect(){
	for(int i=0;i<n;i++){
		
	x[i]=x[i];
	y[i]=getmaxy()-y[i];
	}
}

void translate(int c){
	for(int i=0;i<n;i++){
	x[i]+=0;
	y[i]+=c;
	}	
}

