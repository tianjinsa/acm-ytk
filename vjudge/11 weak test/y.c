#include <stdio.h>
#include <string.h>
char in[12]={0};
int a;
void pri(char ac,char bc,char cc)
{
    printf("%c",ac);
    for(int i=0;i<a;i++){
        printf("%c",bc);
    }
    printf("%c",cc);
}
void sss(int cen,int x)
{
    if(x){
        printf(" ");
    }
    if(cen==0){
        if(in[x]=='1'||in[x]=='4'){
            pri(' ',' ',' ');
        }
        else{
            pri(' ','-',' ');
        }
    }
    else if(0<cen&&cen<=a){
        if(in[x]=='1'||in[x]=='2'||in[x]=='3'||in[x]=='7'){
            pri(' ',' ','|');
        }
        else if(in[x]=='5'||in[x]=='6'){
            pri('|',' ',' ');
        }
        else{
            pri('|',' ','|');
        }
    }
    else if(cen==a+1){
        if(in[x]=='1'||in[x]=='7'||in[x]=='0'){
            pri(' ',' ',' ');
        }
        else{
            pri(' ','-',' ');
        }
    }
    else if(a+2<=cen&&cen<=2*a+1){
        if(in[x]=='2'){
            pri('|',' ',' ');
        }
        else if(in[x]=='6'||in[x]=='8'||in[x]=='0'){
            pri('|',' ','|');
        }
        else{
            pri(' ',' ','|');
        }
    }
    else if(cen==2*a+2){
        if(in[x]=='1'||in[x]=='4'||in[x]=='7'){
            pri(' ',' ',' ');
        }
        else{
            pri(' ','-',' ');
        }
    }
}
int main() {
    while (scanf("%d ", &a) != EOF && a != 0) {
        if(in[0]!=0){
            printf("\n");
        }
        fgets(in, sizeof(in), stdin);
        int len=strlen(in)-1;
        for(int i=0;i<2*a+3;i++) {
            for(int q=0;q<len;q++){
                sss(i,q);
            }
            printf("\n");
        }
    }
    return 0;
}