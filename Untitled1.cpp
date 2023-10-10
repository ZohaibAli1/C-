#include <stdio.h>

int main() {
    int num, digit;
    
    printf("Enter a number: ");
    
    scanf("%d", &num);
    
    printf("Digits of the number: ");
    
    //while na tab tak kam karna ha jab tak complete na ho
    
    while (num > 0) {
        // Extract the rightmost digit
        digit = num % 10;
        
        // Print out the digit with a space after it
        printf("%d ", digit);
        
        // Move on to the next digit
        num /= 10;
    }
    
    return 0;
}

