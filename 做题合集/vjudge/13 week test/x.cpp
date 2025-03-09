#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    char hm[][10] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    char td[][10] ={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    printf("%d\n",n);
    for (int i=0;i<n;++i){
        int day,year;
        char m[10];
        scanf("%d. %s %d",&day,m,&year);
        int month=0;
        for (;month<19;month++){
            if (strcmp(hm[month],m)==0){
                break;
            }
        }
        int alld=year*365+month*20+day;
        int ty=alld/260;
        int tdnn=alld%13+1;
        int tdn=alld%20;
        printf("%d %s %d\n",tdnn,td[tdn],ty);
    }
    return 0;
}