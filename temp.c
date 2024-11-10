#include <stdio.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&b,&a)!=EOF)
    {
        int n=1,aa=4;
        for(int i=0;i<a-1;i++){
            if(i%2){
                n+=aa;
                aa+=4;
            }
            else{
                n+=1;
            }
        }
        aa=2+2*((a+1)%2);
        for(int i=0;i<b-1;i++){
            if(a%2){
                if(i%2){
                    n+=a*2-1;
                }
                else{
                    n+=aa;
                    aa+=4;
                }
                
            }
            else{
                if(i%2){
                    n+=aa;
                    aa+=4;
                }
                else{
                    n+=a*2-1;
                }
            }
        }
        printf("%d\n",n);
    }
    return 0;
}