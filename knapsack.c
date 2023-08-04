#include <stdio.h>


int max (int x, int y)
{

   if(x>=y) return x ;
   else return y ;
}
// m is the capacity and n is the no of items

int knapsack(int m,int W[],int val[],int n)
{
	int i, w;
	int k[n+1][m+1];
	
	for(i =0 ;i<=n;i++)
	{
		
	for(w =0 ;w<=m;w++)
	{	
		if(i==0|| w==0) 
		k[i][w] = 0 ;
		
		else if (W[i-1]<=w)
		k[i][w] = max(k[i-1][w] , val[i-1] +k[i-1][w-W[i-1]]);
		
		else 
		k[i][w] = k[i-1][w] ;
	}
	
	}
	
	return k[n][m] ;
}


int main()
{
	int res =0 ;
	int m ,n;
	printf("enter the capacity of bag: ");
	scanf("%d",&m) ;
	printf("enter the number of  items present : ");
	scanf("%d",&n) ;
	int w[n] , val[n] ;
	printf("enter the weights   : ");
	for(int i =0 ;i<n;i++)
	{
		scanf("%d",&w[i]) ;
	
	}
	printf("enter the profits   : ");
	for(int i =0 ;i<n;i++)
	{
		scanf("%d",&val[i]) ;
	
	}
	res = knapsack(m,w,val,n) ;
	printf("the final and best profit is %d : ",res);
}
	
	
	
	
