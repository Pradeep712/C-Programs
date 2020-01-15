#include<graphics.h>
#include<dos.h>

void main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
for(i=0;i<=360;++i)
{
circle(300,200,80);
pieslice(300,200,0,i,80);
outtextxy(200,320,"Loading....Please Wait!");
delay(20);
}
closegraph();
}