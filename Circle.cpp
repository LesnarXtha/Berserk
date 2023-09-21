#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void Draw(int x, int y, int xc, int yc){
	putpixel(x+xc,y+yc,2);
	putpixel(y+xc,x+yc,3);
	putpixel(-y+xc,x+yc,4);
	putpixel(-x+xc,y+yc,5);
	putpixel(x+xc,-y+yc,6);
	putpixel(y+xc,-x+yc,7);
	putpixel(-y+xc,-x+yc,8);
	putpixel(-x+xc,-y+yc,9);
	}
	int main(){
		int x, y, xc, yc, r;
		int p;
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode,"");
		printf("Enter radius::");
		scanf("%d", &r);
		printf("Enter the value of xc and yc::");
		scanf("%d %d", &xc, &yc );
		x=0;
		y=r;
		p=1-r;
		int k=0;
		while(x<y){
			if(p<0){x++;
			p=p+2*x+1;
			}
			
			else{
				x++;
				y--;
				p=p+2*x+1-2*y;
			}
				delay(100);
				Draw(x,y,xc,yc);
				k++;
		}
		getch();
		closegraph();
		return 0;
}
