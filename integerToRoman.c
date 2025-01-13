#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* intToRoman(int num) {
    int value[7] = {1, 5, 10, 50, 100, 500, 1000};
    char roman[] = "IVXLCDM";
    
    char *ans = (char *)malloc(100 * sizeof(char));
    ans[0] = '\0';

    for (int i = 6; i >= 0; i -= 2) {
        if (num >= value[i]) {
            int count = num / value[i];
            num %= value[i];

            if (count == 9) {
                strncat(ans, &roman[i], 1);
                strncat(ans, &roman[i + 2], 1);
            } else if (count == 4) {
                strncat(ans, &roman[i], 1);
                strncat(ans, &roman[i + 1], 1);
            } else {
                if (count >= 5) {
                    strncat(ans, &roman[i + 1], 1);
                    count -= 5;
                }
                for (int j = 0; j < count; j++) {
                    strncat(ans, &roman[i], 1);
                }
            }
        }
    }

    return ans;
}


int main(){
    int n;
    scanf("%d", &n);
    char *ans = (char *)malloc(n * sizeof(char));
    
    ans = intToRoman(n);
    printf("%s", ans);
    return 0;
}