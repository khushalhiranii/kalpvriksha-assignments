#include<stdio.h>
#include<stdlib.h>


int solve(int base, int power, int M){

    if(power==0) return 1;

    int sol = solve(base, power/2, M);

    if(power%2==0){
        return (sol * sol)%M;
    }else{
        return ((sol * sol)*base)%M;
    }
}

int main(){

    int base,power,mod_value;
    scanf("%d%d%d", &base, &power, &mod_value);

    printf("answer is : %d", solve(base, power, mod_value));

    return 0;
}