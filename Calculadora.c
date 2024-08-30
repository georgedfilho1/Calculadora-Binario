#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decimalParaBinario(int num) {
    printf("Convertendo %d para base 2:\n", num);
    int binario[32];
    int i = 0;
    while(num > 0) {
        binario[i] = num % 2;
        printf("Passo %d: %d %% 2 = %d, Quociente = %d\n", i + 1, num, binario[i], num / 2);
        num = num / 2;
        i++;
    }
    printf("Resultado em binário: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void decimalParaOctal(int num) {
    printf("Convertendo %d para base 8:\n", num);
    int octal[32];
    int i = 0;
    while(num > 0) {
        octal[i] = num % 8;
        printf("Passo %d: %d %% 8 = %d, Quociente = %d\n", i + 1, num, octal[i], num / 8);
        num = num / 8;
        i++;
    }
    printf("Resultado em octal: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decimalParaHexadecimal(int num) {
    printf("Convertendo %d para base 16:\n", num);
    char hexadecimal[32];
    int i = 0;
    while(num > 0) {
        int temp = num % 16;
        if(temp < 10) {
            hexadecimal[i] = temp + 48; 
        } else {
            hexadecimal[i] = temp + 55; 
        }
        printf("Passo %d: %d %% 16 = %d (%c), Quociente = %d\n", i + 1, num, temp, hexadecimal[i], num / 16);
        num = num / 16;
        i++;
    }
    printf("Resultado em hexadecimal: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void decimalParaBCD(int num) {
    printf("Convertendo %d para BCD:\n", num);
    int digito, i = 0;
    while(num > 0) {
        digito = num % 10;
        printf("Dígito %d: %d\n", i + 1, digito);
        printf("BCD: ");
        for(int j = 3; j >= 0; j--) {
            printf("%d", (digito >> j) & 1);
        }
        printf("\n");
        num = num / 10;
        i++;
    }
}
void decToComplement2(int n) {
    unsigned short complement = (unsigned short)n;

    printf("Convertendo %d para complemento a 2 com 16 bits...\n", n);
    printf("Binário sem sinal: ");
    for(int i = 15; i >= 0; i--) {
        printf("%d", (complement >> i) & 1);
    }
    printf("\n");

    if (n < 0) {
        complement = ~(-n) + 1;
        printf("Complemento a 2: ");
        for(int i = 15; i >= 0; i--) {
            printf("%d", (complement >> i) & 1);
        }
        printf("\n");
    }
}

int main() {
    int num;
    printf("Digite um número em base 10: ");
    scanf("%d", &num);
    decimalParaBinario(num);
    printf("\n");
    decimalParaOctal(num);
    printf("\n");
    decimalParaHexadecimal(num);
    printf("\n");
    decimalParaBCD(num);
    printf("\n");
    decToComplement2(num);
    printf("\n");
    return 0;
}
