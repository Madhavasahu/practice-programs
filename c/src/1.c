#include <stdio.h>

int main(){
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    for (i=0;i<3;i++)
    {
        for(j=i;j<3;j++)
        {
            for(k=j;k<3;k++)
            {
                count++;
                printf("i %d j %d k %d\n",i,j,k);
                if ((i==0 || i==1 || i==2) && (j==2 && k==2))
                    printf("%d\n",count);
            }    
        }
    }
    printf("%d\n",count);
    return 0;
}
