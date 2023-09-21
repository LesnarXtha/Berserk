#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

void draw();
void pivot();
void rotate(float x);

int n,x[100],y[100],i,rx,ry,fixedx,fixedy,angle;


int main(){
	
int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode,"");

	printf("Enter number of sides of polygon:");
	scanf("%d",&n);
	printf("Enter co-ordinates:");
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}		
	
	setcolor(RED);
	draw();
	pivot();
	
	printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);

    angle = angle * M_PI / 180.0f;
	rotate(angle);
	
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

void pivot(){
	printf("Enter the pivot point coordinates (px py)\n (0, 0) for origin: ");
    scanf("%d %d", &fixedx, &fixedy);
    putpixel(fixedx,fixedy, WHITE);
}

void rotate(float theta){
	for(i=0;i<n;i++){
	int new_x=fixedx+(x[i]-fixedx)*cos(theta)-(y[i]-fixedy)*sin(theta);
	int new_y=fixedy+(x[i]-fixedx)*sin(theta)+(y[i]-fixedy)*cos(theta);
	x[i]=new_x;
	y[i]=new_y;
	}
}
