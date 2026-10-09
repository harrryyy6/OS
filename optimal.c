#include<stdio.h>
struct frmnode
{
int pno;
}frames[20];

int n;
int page_found(int pno)
{
int fno;
for(fno = 0; fno < n; fno ++)
{
if (frames[fno].pno == pno)
return fno;
}
return -1;
}

int get_free_frame()
{
int fno;
for(fno = 0; fno < n; fno ++)
{
if(frames[fno].pno == -1)
return fno;
}
return -1;
}

int next_use (int p_req[], int size, int from, int pno)
{
int k;
for(k=from; k<size;k++)
{
if(p_req[k] == pno)
return k;
}
return 9999;
}

int get_optimal_frame(int p_req[], int size, int cur_pos)
{
int fno,long_idx = 0;
int long_use = next_use(p_req,size,cur_pos+1,frames[0].pno);
for(fno = 1; fno < n; fno ++)
{
int use = next_use(p_req,size,cur_pos+1,frames[fno].pno);
if(use > long_use)
{
 long_use = use;
 long_idx = fno;
 }
 }
 return long_idx;
 }


int main()
{
//7,2,8,4,5,8,4,7,6,1,3,7
//2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8
int p_req[] = {12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
int size = sizeof(p_req) / sizeof(int);
int page_faults = 0,i,j,fno;
printf("\n Total References : %d \n",size);
printf("ENter Number of Frames :- ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
frames[i].pno = -1;
}

printf("\n%-10s","Page NO.");
printf("%-7s","F1");
printf("%-7s","F2");
printf("%-7s","F3");
printf("%-7s","F4");
printf("%-7s\n","Fault?");
printf("==========================================================\n");
for(i=0;i<size;i++)
{
j = page_found(p_req[i]);
if(j==-1)
{
	page_faults++;
	j = get_free_frame();
	if(j==-1)
	   j = get_optimal_frame(p_req,size,i);
	frames[j].pno = p_req[i];
	printf("%-10d",p_req[i]);
	for(fno = 0; fno < n; fno++)
           {
              if(frames[fno].pno == -1)
                  printf("%-7s", "-");
              else
                  printf("%-7d", frames[fno].pno);
            }
          printf("%-7s\n", "YES");
         }
     else 
     {
        printf("%-10d",p_req[i]);
        for (fno = 0; fno < n; fno++)
          {
              if (frames[fno].pno == -1)
          	  printf("%-7s", "-");
              else
                  printf("%-7d", frames[fno].pno);
          }
         printf("%-7s\n", "NO");
     }
   }
     
     printf("\n Total Number of Page Faults : %d \n", page_faults);
     return 0;
 }
