#include <stdio.h>
#include <stdlib.h>
int Setuplist()
{
    int i,length;
    printf("请输入所建顺序表的表长:");
    scanf("%d",&length);
    int a[50];
    if(length>50){
        (void*)malloc(2*length*sizeof(int));
    }
    printf("请输入顺序表元素:");
    for(i=0;i<length;i++){
        scanf("%d",&a[i]);
    }
    printf("顺序表为:");
    for(i=0;i<length;i++){
        printf("%d ",&a[i]);
    }
    a[length]=-1;


}
int main()
{
    Setuplist();
    return 0;
}