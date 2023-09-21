#include<stdio.h>
#include<math.h>
#include<graphics.h>

void draw();
void scale();
void pivot();

int n,x[100],y[100],i,sx,sy,fixedx,fixedy;

int main(){
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	
	printf("Enter number of sides of polygon:");
	scanf("%d",&n);
	printf("Enter co-ordinates:");
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}		
	printf("Enter the factor to be scaled(in both x and y direction): ");
	scanf("%d%d",&sx,&sy);
	

	
	setcolor(RED);
	draw();
	
	pivot();
	scale();
	
	setcolor(YELLOW);
	draw();
	getch();
    closegraph();
	return 0;
}

void draw(){
	for(i=0;i<n;i++){
		line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
		delay(500);
	}
}
void pivot(){
	printf("Enter the pivot point coordinates (px py)\n (0, 0) for origin: ");
    scanf("%d %d", &fixedx, &fixedy);
        putpixel(fixedx,fixedy, WHITE);

}
void scale(){
	for(i=0;i<n;i++){
		x[i]=fixedx+(int)((float)(x[i]-fixedx)*sx); 
		y[i]=fixedy+(int)((float)(y[i]-fixedy)*sy); 
		}
}
