
    #include<stdio.h>
    int main()
    { 
    long long int a[1000000],t,i,j,k;
    scanf("%lld\n",&t);
    for(i=0;i<t;i++)
    scanf("%lld\n",&a[i]);
    for(i=0;i<t;i++)
    {
    for(j=i+1;j<t;j++)
       {
    if(a[i]>a[j])
    	{
    k=a[i];
    a[i]=a[j];
    a[j]=k;
    	}
        }
    }		
    		
    for(i=0;i<t;i++)
    printf("%lld\n",a[i]);
    return 0;
    } 
    

