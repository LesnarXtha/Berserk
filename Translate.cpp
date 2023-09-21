#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void draw();
void translate();

int n,x[100],y[100],i,tx,ty;


int main(){
	
int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode,"");

	printf("Enter number of sides of polygon:");
	scanf("%d",&n);
	printf("Enter co-ordinates:");
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}		
	printf("Enter the distance to be translated(in both x and y direction): ");
	scanf("%d%d",&tx,&ty);
		
	setcolor(RED);
	draw();
	
	translate();
	
	setcolor(YELLOW);
	draw();
	getch();
    closegraph();
	return 0;
}

void draw(){
	for(i=0;i<n;i++){
		line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
		delay(200);
	}
}

void translate(){
	for(i=0;i<n;i++){
	x[i]+=tx;
	y[i]+=ty;
	}	
}
	


