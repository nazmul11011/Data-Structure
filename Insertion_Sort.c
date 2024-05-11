#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i,j,item;

    for (i = 1; i < n; i++){
        item=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>item){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=item;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}