#include<stdio.h>
struct frmnode
{
int pno;
int count;
}frames[20];

int n;
int gtime;


int page_found(int pno)
{
  int fno;
  for(fno = 0; fno < n; fno++)
    {
       if(frames[fno].pno == pno)
          return fno;
    }
  return -1;
}


int get_free_frame()
{
   int fno;
   for(fno = 0; fno < n; fno++)
     {
        if(frames[fno].pno == -1)
           return fno;
     }
   return -1;
}


int get_lru_frame()
{
   int fno,min_idx=0;
   int min_count = frames[0].count;
   for(fno = 1; fno < n; fno++)
   {
   if(frames[fno].count < min_count)
   {
   min_count = frames[fno].count;
   min_idx = fno;
   }
   }
   return min_idx;
}

int main()
{
   int p_req[] = {12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
   int size = sizeof(p_req)/4;
   int page_faults = 0,i,j,fno;
   printf("\nTotal Refrences : %d\n",size);
   printf("Enter Number of frames : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
    {  frames[i].pno = -1;
       frames[i].count = -1;
    }
    printf("\n%-6s","\tString");
   printf("%-7s","  F1");
   printf("%-7s","  F2");
   printf("%-7s","   F3");
   printf("%-7s\n","Fault?");
   printf("================================================================\n");
   for(i=0;i<size;i++)
   {
     gtime++;
     j = page_found(p_req[i]);
     printf("\t%d\t",p_req[i]);
     if (j==-1)
        {
           page_faults++;
           j = get_free_frame();
           if(j==-1)
              j = get_lru_frame();
           frames[j].pno = p_req[i];
           frames[j].count = gtime;
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
        frames[j].count = gtime;
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
         
          /*
          int get_fifo_frame()
{
   static int fno = -1;
   fno = (fno + 1) % n;
   return fno;
}
*/
            
