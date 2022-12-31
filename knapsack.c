#include<stdio.h>
struct item{
    int wt;
    int profit;
    float ratio;
};
struct item arr[20];
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap1(float *a, float *b) 
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int a)
{
    for(int i=0;i<a;i++){
   int min=i;
   int j;
   for(j=i+1;j<a;j++)  
   {
       if(arr[j].ratio<arr[min].ratio)
       {
        min=j;
       }
   }
   swap(&arr[i].profit,&arr[min].profit);
   swap(&arr[i].wt,&arr[min].wt);
   swap1(&arr[i].ratio,&arr[min].ratio);
}
}

int main()
{  
    int n;
    printf("Enter number of items : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         printf("Enter weight and profit for %d item :\n",i+1);
         scanf("%d%d",&arr[i].wt,&arr[i].profit);
    }
    for(int i=0;i<n;i++)
    {
          arr[i].ratio=((arr[i].profit)*1.0/arr[i].wt);
    }
    sort(n);
    printf("Enter total weight : \n");
    int totwt;
    scanf("%d",&totwt);
    float totprofit=0;int l;
    for(int i=n-1;i>=0;i--)
    {
        if(totwt>0&&arr[i].wt<=totwt)
        {
           l=i;
           totwt-=arr[i].wt;
           totprofit+=arr[i].profit;
        }
        else{
            break;
        }
    }
    if(totwt>0)
    {
        totprofit+=(totwt*1.0/arr[l-1].wt)*arr[l-1].profit;
    }
    
   printf("Ans is %f",totprofit);
    return 0;
}