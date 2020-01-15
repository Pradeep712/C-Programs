//implementation of John H. Conway's Game of Life cellular automaton program

/*
Initial population map is generated using random numbers with the dimension of the map prompted from the user. The rules state that for any presently alive cell, it must have 2 or 3 existing immediately adjacent live neighbors to continue living into the next iteration or generation, otherwise it will die of loneliness (if less than 2 living adjacent neighbors) or overcrowding (if 4 or more adjacent living neighbors). On the other hand, a presently dead or vacant cell will have life in the next iteration/generation if it has exactly 3 adjacent live neighbors in the present iteration. The program will display the results of eac iteration and wait for the user to press a key to continue to the next iteration/generation. The existing population map both in 1s and 0s as well as "#" and " " are displayed along with the count of existing live adjacent neighbors for each cell. The program will terminate if either the user presses the ESC (escape) key, stagnation (the population map no longer changes) or extinction (no cells remain alive) occurs. Program lines are commented at key points to document algorithm steps.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
 
/* Count number of surrounding cells that are still alive */
int surroundcount(int* q,int n,int i, int j)
{
if(i==0)
if(j==0)
return *(q+1)+*(q+n+1)+*(q+n);
else
if(j<n-1)
return *(q+j+1)+*(q+n+j+1)+*(q+n+j)+*(q+n+j-1)+*(q+j-1);
else
return *(q+j-1)+*(q+n+j-1)+*(q+n+j);
else
if(i==n-1)
if(j==0)
return *(q+(n-2)*n)+*(q+(n-2)*n+1)+*(q+(n-1)*n+1);
else
if(j<n-1)
return *(q+(n-1)*n+j-1)+*(q+(n-2)*n+j-1)+*(q+(n-2)*n+j)+*(q+(n-2)*n+j+1)+*(q+(n-1)*n+j+1);
else
return *(q+(n-2)*n+n-1)+*(q+(n-2)*n+n-2)+*(q+(n-1)*n+n-2);
else
if(j==0)
return *(q+(i-1)*n)+*(q+(i-1)*n+1)+*(q+i*n+1)+*(q+(i+1)*n+1)+*(q+(i+1)*n);
else
if(j<n-1)
return *(q+(i-1)*n+j-1)+*(q+(i-1)*n+j)+*(q+(i-1)*n+j+1)+*(q+i*n+j+1)+*(q+(i+1)*n+j+1)+*(q+(i+1)*n+j)+*(q+(i+1)*n+j-1)+*(q+i*n+j-1);
else
return *(q+(i-1)*n+n-1)+*(q+(i-1)*n+n-2)+*(q+i*n+n-2)+*(q+(i+1)*n+n-2)+*(q+(i+1)*n+n-1);
}
 
/*Check for population extinction (zero remaining alive */
int notextinct(int* q, int n)
{
int i,j,k;
k=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
k+=*(q+i*n+j);
return k;
}
 
/* Check for stagnation, no change in population after two consecutive iterations */
int stagnant(int* q,int* r,int n)
{
int i,j,k;
k=1;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(*(q+i*n+j)!=(*(r+i*n+j))) {
k=0;
break;
}
return k;
}
 
void main(void)
{
int i,j,k,n,s,iter,*curr,*next,*count;
s=0;
randomize();
for(i=0;i<random(random(100));i++)
randomize();
system("color 1E");
printf("\nConway's Life Game Simulation\nBy Gerardo V. Lozada, MS, PEE, 2013\n\nEnter number of rows and columns, n: ");
scanf("%d",&n);
/* Allocate storage for population map */
curr=(int*)calloc(n*n,sizeof(int));
next=(int*)calloc(n*n,sizeof(int));
count=(int*)calloc(n*n,sizeof(int));
/* Generate initial population layout using random numbers */
for(i=0;i<n;i++)
for(j=0;j<n;j++)
*(curr+i*n+j)=random(2);
/* Initialize iteration counter */
iter=0;
do {
printf("\nIter=%d\n\n",iter);
for(i=0;i<n;i++) {
for(j=0;j<n;j++)
printf("%d",*(curr+i*n+j));
printf("\n");
}
printf("\nPopulation Distribution\n");
for(i=0;i<n;i++) {
for(j=0;j<n;j++) {
if(*(curr+i*n+j)==1)
printf("#");
else
printf(" ");
/* Count the surrounding population */
*(count+i*n+j)=k=surroundcount(curr,n,i,j);
/* Update the map for the next iteraton using John H. Conway's Rules - 2 or 3 adjoining live cells to
sustain an existing live cell, 3 to generate life from an empty cell. Anything less is too "lonely" or
barren to support life, anything more is overcrowding and will kill any existing live cell*/
*(next+i*n+j)=0;
if(k==3)
*(next+i*n+j)=1;
if((k==2)&&(*(curr+i*n+j)==1))
*(next+i*n+j)=1;
}
printf("\n");
}
printf("\nNeighbor Count Matrix:\n");
for(i=0;i<n;i++) {
for(j=0;j<n;j++)
printf("%d",*(count+i*n+j));
printf("\n");
}
/* Check for population extinction and stagnation */
k=notextinct(curr,n);
s+=stagnant(curr,next,n);
/* Update population map */
for(i=0;i<n;i++)
for(j=0;j<n;j++)
*(curr+i*n+j)=*(next+i*n+j);
/* Update iteration counter */
iter++;
} while((getch()!=27)&&k&&(s<2));
/* Exit program if ESC was pressed or the population has become extinct or stagnant */
if(!k)
printf("\nPopulation Extinct.\n");
if(s>=2)
printf("\nPopulation Stagnant.\n");
printf("\nDanke schon!\n");
}