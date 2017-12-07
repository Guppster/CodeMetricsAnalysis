
    #include <iostream>
    #include <cstdio>
    
    #define rep(i,n) for(int i=0; i<n; i++)
    
    using namespace std;
    void mergeSort(int f, int l);
    int n;
    int a[1000000];
    int main()
    {
        
        scanf("%d",&n);
        rep(i,n)
           scanf("%d",&a[i]);
        mergeSort(0,n-1);
        rep(i,n)
                printf("%d\n",a[i]);
        system("pause");
        return 0;
    }
    void mergeSort(int f,int l)
    {
         if(f==l)
                return;
         int mid =(f+l)/2;
         mergeSort(f, mid);
         mergeSort(mid+1, l);
         
         
         int * tmp=new int[l-f+1];
         int i=0,li=f,ri=mid+1;
         while((li<=mid)&&(ri<=l))
         {
              if(a[li]<a[ri])
              {
                 tmp[i++]=a[li++];
              }
              else
              {
                 tmp[i++]=a[ri++];
              }
         }
         if(li<=mid)
         {
              for(int j=li;j<=mid;j++)
                 tmp[i++]=a[j];
         }
         if(ri<=l)
         {
              for(int j=ri;j<=l;j++)
                 tmp[i++]=a[j];
         }
         int t=0;
         for(int i=f;i<=l;i++)
         {
              a[i]=tmp[t++];
         }
         
    }
    

