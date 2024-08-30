/**

 * Criado em 28 de Agosto 2024
 * Autor: George Pessoa 
 * Revisões de código:
 *     Questão 1 - 28/08/2024 17;30
 *     Questão 2 - 29/08/2024 19:00
 *     Questão 3 - 28/08/2024 16:30

**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decToBinary(int n);
void decToOctal(int n);
void decToHex(int n);
void decToBCD(int n);
void decToComplement2(int n);
void decToFloat(double n);
void decToDouble(double n);

int main() {
    int option;
    int num;
    double realNum;

    do {
        printf("\nCalculadora Programador Didática\n");
        printf("Escolha a conversão desejada:\n");
        printf("1. Base 10 para Base 2\n");
        printf("2. Base 10 para Base 8\n");
        printf("3. Base 10 para Base 16\n");
        printf("4. Base 10 para Código BCD\n");
        printf("5. Base 10 para Base com Sinal (Complemento a 2)\n");
        printf("6. Real em Decimal para Float\n");
        printf("7. Real em Decimal para Double\n");
        printf("8. Sair\n");
        printf("Opção: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Digite um número inteiro em base 10: ");
                scanf("%d", &num);
                decToBinary(num);
                break;
            case 2:
                printf("Digite um número inteiro em base 10: ");
                scanf("%d", &num);
                decToOctal(num);
                break;
            case 3:
                printf("Digite um número inteiro em base 10: ");
                scanf("%d", &num);
                decToHex(num);
                break;
            case 4:
                printf("Digite um número inteiro em base 10: ");
                scanf("%d", &num);
                decToBCD(num);
                break;
            case 5:
                printf("Digite um número inteiro em base 10: ");
                scanf("%d", &num);
                decToComplement2(num);
                break;
            case 6:
                printf("Digite um número real: ");
                scanf("%lf", &realNum);
                decToFloat(realNum);
                break;
            case 7:
                printf("Digite um número real: ");
                scanf("%lf", &realNum);
                decToDouble(realNum);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(option != 8);

    return 0;
}

void decToBinary(int n) {
    int binary[32];
    int i = 0;

    printf("Convertendo %d para binário \n", n);

    while(n > 0) {
        binary[i] = n % 2;
        printf("%d / 2 = %d, Resto = %d\n", n, n / 2, binary[i]);
        n = n / 2;
        i++;
    }

    printf("Resultado em binário: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}


void decToOctal(int n) {
    int octal[32];
    int i = 0;

    printf("Convertendo %d para octal \n", n);

    while(n > 0) {
        octal[i] = n % 8;
        printf("%d / 8 = %d, Resto = %d\n", n, n / 8, octal[i]);
        n = n / 8;
        i++;
    }

    printf("Resultado em octal: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decToHex(int n) {
    char hex[32];
    int i = 0;

    printf("Convertendo %d para hexadecimal \n", n);

    while(n > 0) {
        int temp = n % 16;

        if(temp < 10)
            hex[i] = temp + 48;
        else
            hex[i] = temp + 55;

        printf("%d / 16 = %d, Resto = %c\n", n, n / 16, hex[i]);
        n = n / 16;
        i++;
    }

    printf("Resultado em hexadecimal: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void decToBCD(int n) {
    printf("Convertendo %d para BCD \n", n);

    while(n > 0) {
        int digit = n % 10;
        printf("Dígito: %d, BCD: ", digit);
        for(int i = 3; i >= 0; i--) {
            printf("%d", (digit >> i) & 1);
        }
        printf("\n");
        n = n / 10;
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

void decToFloat(double n) {
    printf("Convertendo %f para formato float \n", n);

    union {
        float f;
        struct {
            unsigned int mantissa : 23;
            unsigned int exponent : 8;
            unsigned int sign : 1;
        } parts;
    } value;

    value.f = (float)n;

    printf("Sinal: %d\n", value.parts.sign);
    printf("Expoente (sem viés): %d\n", value.parts.exponent - 127);
    printf("Expoente (com viés): %d\n", value.parts.exponent);

    printf("Cálculo do binário (Sinal | Expoente | Fração):\n");
    printf("Sinal: %d\n", value.parts.sign);

    printf("Expoente: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value.parts.exponent >> i) & 1);
    }
    printf(" | Fração: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (value.parts.mantissa >> i) & 1);
    }
    printf("\n");

    printf("Resultado em binário: %d ", value.parts.sign);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value.parts.exponent >> i) & 1);
    }
    printf(" ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (value.parts.mantissa >> i) & 1);
    }
    printf("\n");
}

void decToDouble(double n) {
    printf("Convertendo %f para formato double\n", n);

    union {
        double d;
        struct {
            unsigned long long mantissa : 52;
            unsigned int exponent : 11;
            unsigned int sign : 1;
        } parts;
    } value;

    value.d = n;

    printf("Sinal: %d\n", value.parts.sign);
    printf("Expoente (sem viés): %d\n", value.parts.exponent - 1023);
    printf("Expoente (com viés): %d\n", value.parts.exponent);

    printf("Cálculo do binário (Sinal | Expoente | Fração):\n");
    printf("Sinal: %d\n", value.parts.sign);

    printf("Expoente: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (value.parts.exponent >> i) & 1);
    }
    printf(" | Fração: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (value.parts.mantissa >> i) & 1);
    }
    printf("\n");

    printf("Resultado em binário: %d ", value.parts.sign);
    for (int i = 10; i >= 0; i--) {
        printf("%d", (value.parts.exponent >> i) & 1);
    }
    printf(" ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (value.parts.mantissa >> i) & 1);
    }
    printf("\n");
}
