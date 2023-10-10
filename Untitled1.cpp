#include <stdio.h>

int main() {
    int num, digit;
    
    printf("Enter a number: ");
    
    scanf("%d", &num);
    
    printf("Digits of the number: ");
    
    //while na tab tak kam karna ha jab tak complete na ho
    
    while (num > 0) {
        
        digit = num % 10;
        
        
        printf("%d ", digit);
        
        
        num /= 10;
    }
    
    return 0;
}

