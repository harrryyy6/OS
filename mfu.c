#include<stdio.h>
struct frmnode
{
int pno;
int freq;
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

int get_mfu_frame()
{
int fno,max_idx = 0;
int max_freq = frames[0].freq;
for(fno = 1; fno< n; fno++)
{
if(frames[fno].freq > max_freq)
{
max_freq = frames[fno].freq;
max_idx = fno;
}
}
return max_idx;
}
//2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8
//3,1,2,3,4,2,3,0,3,1,3
int main()
{
int p_req[] = {2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8};
int size = sizeof(p_req) / sizeof(int);
int page_faults = 0,i,j,fno;
printf("\n Total References : %d \n",size);
printf("ENter Number of Frames :- ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
frames[i].pno = -1;
frames[i].freq = 0;
}

printf("\n%-10s","Page NO.");
printf("%-7s","F1");
printf("%-7s","F2");
printf("%-7s","F3");
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
	   j = get_mfu_frame();
	frames[j].pno = p_req[i];
	frames[j].freq = 1;
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
        frames[j].freq++;
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
