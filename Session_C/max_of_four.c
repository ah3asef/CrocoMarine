#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int  arr[]){
    int test;
    test = arr[0];
    for(int i = 0 ; i < 4 ; i++){
       if(test <= arr[i]){
         test = arr[i];
       }
    }
    return test;
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int  arr [] = {a,b,c,d};
    int ans = max_of_four(arr);
    printf("%d", ans);
    
    return 0;
}