//Linked List all operations - create, add @ pos, remove, reverse list etc.,
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ESC 27
#define DISPOFFX 50
#define DISPOFFY 2
#define ENDOFX 80
#define ENDOFY 25
#define SPACING 1
#define INTLENGHT 6
#define MIN 0
#define MAX 1
#define TRUE 1
#define FALSE 0
#define ASCENDING 1
#define DESCENDING 2
struct linked_list
{
int data;
struct linked_list *link;
}*start;
typedef struct linked_list node;
int count=0,*posa=NULL;
struct display_flags
{
unsigned int disp_list:1;
unsigned int anim:1;
unsigned int delay_time:12;
unsigned int spacing:2;
}flag;
int srch(int);
int check(int);
int bubble(void);
int selection(void);
int insertion(void);
int posof(int,int);
void add(void);
void del(void);
void sort(int);
void swap(int);
void disp(void);
void move(void);
void flush(int);
void rotate(void);
void options(void);
void reverse(void);
node * gotopos(int);
void main(void)
{
char choice;
flag.disp_list = TRUE;
flag.anim = TRUE;
flag.delay_time = 0;
flag.spacing = 1;
while(1)
{
clrscr();
fflush(stdin);
posa = (int *) realloc(posa,count * sizeof(int));
flush(0);
disp();
printf("\n 1. Add Element");
printf("\n 2. Delete Element");
printf("\n 3. Search Element");
printf("\n 4. Swap Elements");
printf("\n 5. Sort the list");
printf("\n 6. Reverse the list");
printf("\n 7. Rotate list");
printf("\n 8. Move element");
printf("\n 9. List display options");
printf("\n\n Enter your choice.\n Press ESC to exit.");
switch(getch())
{
case '1': add(); getch(); continue;
case '2':
{
if(start==NULL)
{
printf("\n\n List already empty.");
}
else if(start->link == NULL)
{
printf("\n\n Element %d was deleted from position %d.",start->data,1);
free(start);
start = NULL;
count--;
disp();
}
else
{
printf("\n\n 1. Specify element");
printf("\n 2. Specify positions");
printf("\n 3. Discard duplicates");
printf("\n 4. Delete list");
printf("\n ESC to cancel.\n Enter your choice.");
switch(getch())
{
case '1': if(srch(1)) del(); break;
case '2': del(); break;
case '3': if(srch(2)) del(); getch(); break;
case '4': flush(1); del(); break;
case ESC: continue;
default : printf("\n Invalid choice."); getch(); break;
}
}
disp();
getch();
continue;
}
case '3': srch(0); getch(); continue;
case '4':
{
if(start==NULL) printf("\n\n List is empty!");
else if(start->link == NULL) printf("\n\n There exists only one element in the list.");
else if((start->link)->link == NULL)
{
posa[0] = 2;
posa[1] = 1;
posa[2] = 0;
swap(0);
}
else
{
printf("\n\n 1. Specify elements");
printf("\n 2. Specify positions");
printf("\n Enter your choice.\n ESC to cancel.");
switch(getch())
{
case '1':
{
if(srch(3))
{
if(srch(4)) swap(0);
}
break;
}
case '2': flush(2); swap(0); break;
case ESC: continue;
default : printf("\n Invalid choice!"); getch(); break;
}
}
getch();
continue;
}
case '5':
{
if(start == NULL) printf("\n\n List is empty!");
else if(start->link == NULL) printf("\n\n There exists only one element in the list.");
else
{
printf("\n\n 1. Bubble sort");
printf("\n 2. Selection sort");
printf("\n 3. Insertion sort");
printf("\n Enter yor choice.\n ESC to cancel.");
switch(getch())
{
case '1': if(!bubble()) continue; break;
case '2': if(!selection()) continue; break;
case '3': if(!insertion()) continue; break;
case ESC: continue;
default : printf("\n\n Invalid choice!"); break;
}
}
getch();
break;
}
case '6': reverse(); getch(); continue;
case '7': rotate(); getch(); continue;
case '8':
{
if(start == NULL) printf("\n\n List is empty!");
else if(start->link == NULL) printf("\n\n There exists only one element in the list.");
else if((start->link)->link == NULL)
{
posa[0] = 2;
posa[1] = 1;
posa[2] = 0;
swap(3);
printf("\n\n Elements moved.");
}
else
{
printf("\n\n 1. Specify element");
printf("\n 2. Specify position");
printf("\n Enter your choice.\n ESC to cancel.");
switch(getch())
{
case '1':
{
if(srch(5))
{
move();
printf(" Element moved.");
}
break;
}
case '2':
{
flush(4);
move();
printf(" Element moved.");
break;
}
case ESC: continue;
default : printf("\n\n Invalid choice!"); break;
}
}
disp();
getch();
continue;
}
case '9': options(); continue;
case ESC: exit(0);
default : printf("\n\n Invalid choice!"); getch(); continue;
}
}
}
void add(void)
{
int n,pos;
node *next,*temp,*temp2;
next = (node *) malloc(sizeof(node));
if(next==NULL) printf("\n\n No free space left!\n Close some running applications and try again.");
else
{
printf("\n\n Enter element: ");
scanf("%d",&next->data);
next->link = NULL;
fflush(stdin);
if(start==NULL)
{
start=next;
pos=1;
count++;
}
else
{
printf(" Enter the position of element to be added\n (Max: %d, '0' to add to end,\n -ve value to add to end): ",count+1);
scanf("%d",&pos);
while(pos>count+1)
{
if(count>1) printf(" Invalid position.\n Enter a number between 1 - %d\n '0' to cancel: ",count+1);
else if(count==1) printf(" Invalid position.\n Enter 1 or 2\n '0' to cancel: ");
scanf("%d",&pos);
}
if(pos==0) pos=count+1;
for(n=2,temp=start ; temp != NULL ; temp = temp->link,n++)
{
if(pos<0)
{
free(next);
break;
}
else if(pos==1)
{
next->link = start;
start = next;
count++;
break;
}
else if(pos==n)
{
temp2 = temp->link;
temp->link = next;
next->link = temp2;
count++;
break;
}
}
}
if(pos>0) printf(" Element %d was added successfully\n at position %d.",next->data,pos);
else printf(" Addition of element cancelled.");
disp();
}
}
int srch(int f)
{
int dat,dat2,i,j,cnt=0;
node *next;
if(start==NULL) printf("\n\n List's already empty!");
else if(start->link ==NULL) printf("\n\n There exist's only one element in the list.");
else
{
if(f==0) printf("\n\n Enter element to be searched: ");
else if(f==1) printf("\n\n Enter element to be deleted: ");
else if(f==2) printf("\n\n Enter element of which duplicates\n are to be removed: ");
else if(f==3) printf("\n\n Enter the first element to be swapped: ");
else if(f==4) printf("\n\n Enter the second element to be swapped: ");
else if(f==5) printf("\n\n Enter the element to be moved: ");
scanf("%d",&dat);
for(i=1,next=start ; next!=NULL ; next = next->link,i++)
{
if(dat == next->data)
{
posa[cnt++] = i;
printf("\n Element %d was found at position %d.",dat,i);
}
}
posa[cnt]=0;
if(f==5)
{
if(cnt==1)
{
printf("\n Enter the position to which the element is to be moved: ");
scanf("%d",&posa[1]);
posa[1] = check(posa[1]);
}
else
{
printf("Enter the position of element to be moved: ");
scanf("%d",&dat);
posa[0] = check(posa[0]);
printf("\n Enter the position to which the element is to be moved: ");
scanf("%d",&posa[1]);
posa[1] = check(posa[1]);
}
}
else if(f==3 || f==4)
{
if(cnt==1)
{
if(f==3) dat2 = posa[0];
else if(f==4)
{
posa[1] = dat2;
posa[2] = 0;
sort(0);
 
}
}
else
{
printf("\n Enter the position to be swapped: ");
scanf("%d",&dat);
if(f==3) dat2 = check(dat);
else if(f==4) dat = check(dat);
posa[0] = dat2;
posa[1] = dat;
posa[2] = 0;
sort(0);
}
}
else if(cnt==0) printf("\n Element %d was not found.",dat);
else if(f==1)
{
printf("\n %d element(s) found.",cnt);
if(cnt>1)
{
printf("\n Press Enter to delete all %ds.",dat);
printf("\n Any other key to select specific elements.");
if(getch() != 13) flush(0);
}
}
else if(f==2)
{
sort(1);
if(--cnt == 0) printf("\n No duplicates were found.");
else printf("\n %d duplicate(s) found.",cnt);
}
}
return(cnt);
}
void del(void)
{
int dat,i,f=0,delf=0,j,cnt;
node *next,*temp,*temp2;
cnt = count;
for(i=0;i<count;i++)
{
if( posa[i] != 0 )
{
delf=1;
break;
}
}
if(delf == 0) flush(3);
sort(0);
putchar('\n');
for(j=0;j<cnt;j++)
{
if(posa[j]==0) break;
for(i=1,next=start ; next!=NULL ; i++)
{
if(posa[j] == i)
{
f=1;
dat = next->data;
temp2 = next;
if(start == next) start = next->link;
else temp->link = next->link;
next = next->link;
free(temp2);
printf("\n Element %d was deleted from position %d.",dat,i);
count--;
if(flag.anim==TRUE)
{
disp();
delay(flag.delay_time);
}
break;
}
else
{
temp = next;
next = next->link;
}
}
}
if(f==0) printf("\n No element was deleted.");
disp();
}
void flush(int f)
{
int i=0;
if(f==1 || f==0)
{
while(i<count)
{
if(f==0) posa[i++] = 0;
else posa[i++] = i+1;
}
}
else if(f==2)
{
 
printf("\n\n Enter the positions of two elements\n to swap: ");
scanf("%d %d",&posa[0],&posa[1]);
while(posa[0] < 1 || posa[0] > count)
{
printf("\n Invalid position - %d. Try again: ",posa[0]);
scanf("%d",&posa[0]);
}
while(posa[1] < 1 || posa[1] > count)
{
printf("\n Invalid position - %d. Try again: ",posa[1]);
scanf("%d",&posa[1]);
}
posa[2]=0;
sort(0);
}
else if(f==3)
{
printf("\n\n Enter position of elements to delete\n (Zero to stop): ");
i=0;
do
{
scanf("%d",&posa[i++]);
while(posa[i-1]>count || posa[i-1]<0)
{
printf("\n %d - Invalid position! ",posa[i-1]);
scanf("%d",posa[i-1]);
}
}
while( (posa[i-1] != 0) && (i!=count) );
}
else if(f==4)
{
printf("\n\n Enter the position of element\n to be moved: ");
scanf("%d",&posa[0]);
while(posa[0]<1 || posa[0]>count)
{
printf("\n Invalid position! Try again: ");
scanf("%d",&posa[0]);
}
printf("\n Enter position to which element\n is to be moved: ");
scanf("%d",&posa[1]);
while(posa[1]<1 || posa[0]>count || posa[0]==posa[1])
{
if(posa[0]==posa[1]) printf("\n No effect of moving an element to its own position.");
else printf("\n Invalid position! Try again: ");
scanf("%d",&posa[1]);
}
}
}
int check(int dat)
{
int i,f=0;
while(f==0)
{
for(i=0;i<count;i++)
{
if(dat == posa[i])
{
f=1;
break;
}
}
if(f==0)
{
printf("\n Invalid Position! Try again: ");
scanf("%d",&dat);
}
}
return(dat);
}
void sort(int f)
{
int lp,ep,ci,i,temp;
ep = count-1;
for(i=0;i<count;i++)
{
if(posa[i] == 0) ep=i-1;
}
if(f==0)
{
for(ci=0;ci<ep;ci++)
{
lp=ci;
for(i=ci+1;i<=ep;i++) if(posa[lp] < posa[i]) lp=i;
temp = posa[ci];
posa[ci] = posa[lp];
posa[lp] = temp;
}
for(i=0 ; i<=ep ; i++)
{
for(ci=0;ci<i;ci++)
{
if(posa[ci] == posa[i])
{
for(lp=i;lp<ep;lp++) posa[lp] = posa[lp+1];
break;
}
}
}
}
else if(f==1) for(i=1;i<=ep;i++) posa[i] = posa[i+1];
}
void swap(int f)
{
int i;
node *t1,*t2,*pt1,*pt2,*next,*temp;
t1 = t2 = pt1 = pt2 = NULL;
if(posa[1] == 0) printf("\n No effect of swapping an element with itself.");
else
{
for(i=1,next=start ; next != NULL ; next = next->link, i++)
{
if(i == posa[0]) t1 = next;
if(i == posa[1]) t2 = next;
if(t1 == NULL) pt1 = next;
if(t2 == NULL) pt2 = next;
if((t1 != NULL) && (t2 != NULL)) break;
}
if( ((f == ASCENDING) && (t1->data < t2->data)) || ((f==DESCENDING) && (t1->data > t2->data)) || (f==0) || (f==3) )
{
if(posa[1] != 1)
{
temp = pt1->link;
pt1->link = pt2->link;
pt2->link = temp;
temp = t1->link;
t1->link = t2->link;
t2->link = temp;
}
else
{
temp = start;
start = pt1->link;
pt1->link = temp;
temp = t1->link;
t1->link = t2->link;
t2->link = temp;
}
if(flag.anim==TRUE)
{
disp();
delay(flag.delay_time);
}
if(f==0)
{
printf("\n The elements %d & %d have been swapped.\n",t1->data,t2->data);
printf("\n Elements | %*d | %*d",INTLENGHT,t1->data,INTLENGHT,t2->data);
printf("\n -------------------------------");
printf("\n Old positions | %*d | %*d",INTLENGHT,posa[0],INTLENGHT,posa[1]);
printf("\n New positions | %*d | %*d",INTLENGHT,posa[1],INTLENGHT,posa[0]);
disp();
}
}
}
}
void reverse(void)
{
int lb,m;
if(start == NULL) printf("\n\n List is empty!");
else if(start->link == NULL) printf("\n\n There exists only one element in the list.");
else
{
printf("\n\n Processing...");
for(m=count/2,lb=1 ; lb <= m ; lb++)
{
posa[0] = count - lb+1;
posa[1] = lb;
posa[2] = 0;
swap(3);
}
printf("Done!");
disp();
printf("\n\n The list has been reversed.");
}
}
int bubble(void)
{
char c;
int i,j;
printf("\n\n Bubble Sort the list in:");
printf("\n 1. Ascending order");
printf("\n 2. Descending order");
printf("\n Enter your choice.\n ESC to cancel.");
switch(c=getch(),c)
{
case '1':
case '2':
{
printf("\n\n Processing...");
for(i=count;i>=1;i--)
{
for(j=1;j<i;j++)
{
posa[0] = j+1;
posa[1] = j;
posa[2] = 0;
if(c=='1') swap(ASCENDING);
else if(c=='2') swap(DESCENDING);
}
}
printf("Done!");
if(c=='1') printf("\n\n The list has been sorted in\n ascending order using bubble sort.");
else if(c=='2') printf("\n\n The list has been sorted in\n descending order using bubble sort.");
break;
}
case ESC: break;
default : printf("\n\n Invalid choice!"); break;
}
disp();
return(ESC-c);
}
int selection(void)
{
char c;
int i;
printf("\n\n Selection Sort the list in:");
printf("\n 1. Ascending order");
printf("\n 2. Descending order");
printf("\n Enter your choice.\n ESC to cancel.");
switch(c=getch(),c)
{
case '1':
case '2':
{
printf("\n\n Processing...");
for(i=1;i<count;i++)
{
if(c=='1') posa[0] = posof(MIN,i);
else if(c=='2') posa[0] = posof(MAX,i);
posa[1] = i;
posa[2] = 0;
if(posa[0]!=posa[1]) swap(3);
}
printf("Done!");
if(c=='1') printf("\n\n The list has been sorted in\n ascending order using selection sort.");
else if(c=='2') printf("\n\n The list has been sorted in\n descending order using selection sort.");
break;
}
case ESC: break;
default : printf("\n\n Invalid choice!"); break;
}
disp();
return(ESC-c);
}
int insertion(void)
{
char c;
int i,j;
printf("\n\n Insertion Sort the list in:");
printf("\n 1. Ascending order");
printf("\n 2. Descending order");
printf("\n Enter your choice.\n ESC to cancel.");
switch(c=getch(),c)
{
case '1':
case '2':
{
printf("\n\n Processing...");
for(i=2;i<=count;i++)
{
for(j=i;j>1;j--)
{
posa[0] = j;
posa[1] = j-1;
posa[2] = 0;
if(c=='1') swap(ASCENDING);
else if(c=='2') swap(DESCENDING);
}
}
printf("Done!");
if(c=='1') printf("\n\n The list has been sorted in\n ascending order using insertion sort.");
else if(c=='2') printf("\n\n The list has been sorted in\n descending order using insertion sort.");
break;
}
case ESC: break;
default : printf("\n\n Invalid choice!"); break;
}
disp();
return(ESC-c);
}
int posof(int f,int lb)
{
int pos=0,i,element;
node *next;
if(start != NULL)
{
for(i=1,next = start ; next != NULL ; next = next->link,i++)
{
if(i==lb)
{
element = next->data;
pos=i;
}
if( (((element > next->data) && f==MIN) || ((element < next->data) && f==MAX)) && i>lb )
{
element = next->data;
pos = i;
}
}
}
return(pos);
}
void rotate(void)
{
int i,amt;
node *next;
if(start == NULL) printf("\n\n List is empty!");
else if(start->link == NULL) printf("\n\n There exists only one element in the list.");
else
{
printf("\n\n Rotate by how many elements?\n (+ve=right, -ve=left, 0=no effect): ");
scanf("%d",&amt);
amt %= count;
if(amt > 0)
{
for(i=1;i<=amt;i++)
{
posa[0] = count;
posa[1] = 1;
move();
}
printf("\n\n The list has been rotated in right\n direction by %d",amt);
}
else if(amt < 0)
{
for(i=1;i<=-amt;i++)
{
posa[0] = 1;
posa[1] = count;
move();
}
printf("\n\n The list has been rotated in left\n direction by %d",-amt);
}
else printf("\n The list has not been affected.");
}
disp();
}
node * gotopos(int pos)
{
int i;
node * next=NULL;
for(i=1,next=start ; next != NULL ; next = next->link,i++) if(pos == i) break;
return(next);
}
void move(void)
{
node *e1,*e2,*temp;
if(posa[0] == 1)
{
e2 = gotopos(posa[1]);
temp = start;
start = start->link;
e1 = e2->link;
e2->link = temp;
(e2->link)->link = e1;
}
else if(posa[1] == 1)
{
e2 = gotopos(posa[0]-1);
e1 = e2->link;
e2->link = (e2->link)->link;
temp = start;
start = e1;
e1->link = temp;
}
else
{
e1 = gotopos(posa[0]-1);
e2 = gotopos(posa[1]);
temp = e1->link;
e1->link = (e1->link)->link;
e1 = e2->link;
e2->link = temp;
temp->link = e1;
}
if(flag.anim==TRUE)
{
disp();
delay(flag.delay_time);
}
}
void options(void)
{
static int last;
unsigned int temp;
while(1)
{
clrscr();
if(flag.disp_list==TRUE) printf("\n\n\n D : [X] Display list");
else printf("\n\n\n D : [ ] Display list");
if(flag.anim==TRUE) printf("\n\n A : [X] Animate while processing (does slower processing)");
else printf("\n\n A : [ ] Animate while processing (does slower processing)");
printf("\n\n T : Animation scale = %-5u (Recommended range: 0-100)",flag.delay_time);
printf("\n\n S : Element Spacing in list = %-5u",flag.spacing);
printf("\n\n ESC : Back to main menu...");
switch(getch())
{
case 'd':
case 'D':
{
flag.disp_list = !flag.disp_list;
if(flag.disp_list==FALSE)
{
last = flag.anim;
flag.anim = FALSE;
}
else flag.anim = last;
continue;
}
case 'a':
case 'A': if(flag.disp_list==TRUE) flag.anim = !flag.anim; continue;
case 't':
case 'T':
{
gotoxy(28,8);
printf(" \b\b\b\b\b");
scanf("%u",&temp);
flag.delay_time = temp;
continue;
}
case 's':
case 'S':
{
gotoxy(36,10);
printf(" \b\b\b\b\b");
scanf("%u",&temp);
flag.spacing = temp;
continue;
}
case ESC: return;
}
}
}
void disp(void)
{
int i,j,x,y,n;
node *next;
x = wherex();
y = wherey();
for(i=DISPOFFX;i<=ENDOFX && flag.disp_list==TRUE;i++)
{
for(j=DISPOFFY;j<=ENDOFY-1;j++)
{
gotoxy(i,j);
putchar(' ');
}
}
gotoxy(DISPOFFX,DISPOFFY);
printf("Element Count: %-5d",count);
if(flag.disp_list==FALSE)
{
gotoxy(DISPOFFX,DISPOFFY+(1*SPACING));
printf("List Hidden!");
}
else if(flag.disp_list==TRUE)
{
gotoxy(DISPOFFX,DISPOFFY+(1*SPACING));
printf("START = 0x%04X",start);
if(start==NULL) printf(" (List Empty!)");
else
{
gotoxy(DISPOFFX,DISPOFFY+(2*SPACING));
printf("SR. | NODE | DATA ( LINK )");
gotoxy(DISPOFFX,DISPOFFY+(2*SPACING)+1);
printf("NO. | ADDR. | IN NODE ");
gotoxy(DISPOFFX,DISPOFFY+(2*SPACING)+2);
printf("------------------------------");
for(n=1,next=start ; next!=NULL ; next = next->link,n++)
{
gotoxy(DISPOFFX,DISPOFFY+(2*SPACING)+3+((n-1)*flag.spacing));
printf("%2d. | 0x%04X | %*d (0x%04X)",n,next,INTLENGHT,next->data,next->link);
}
}
}
gotoxy(x,y);
}