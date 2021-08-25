#include<stdio.h>
int read(int [3][3]);
int hill(int [3][3],int [3][1]);
int main()
{
    int key[3][3];
    read(key);
    printf("\nenter the text : ");
    fflush(stdin);
    char text[3][1];
    for(int s=0;s<3;s++)
    {
        scanf("%c",&text[s][0]);
    }
    int c[3][1];
    for(int p=0;p<3;p++)
    {
        c[p][0]=text[p][0];
        c[p][0]=c[p][0]-97;
    }
    printf("\n");
    hill(key,c);
    return 0;
}
int read(int key[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("\nenter the element of the 3x3 key matrix : ");
            scanf("%d",&key[i][j]);
        }
    }
}
int hill(int key[3][3],int c[3][1])
{
    int result[3][1]={0,0,0};
    for(int x=0;x<3;x++)
    {
        int var=0;
        while(var<3)
        {
            result[x][0]=(key[x][var]*c[var][0])+result[x][0];
            var++;
        }
        result[x][0]=result[x][0]%26;
    }
    char final_result[3][1];
    printf("the encrypted text is : ");
    for(int e=0;e<3;e++)
    {
        final_result[e][0]=result[e][0]+97;
        printf("%c",final_result[e][0]);
    }
}