#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT_SIZE 100

void parseExpression(const char *input, int numbers[], char operators[], int *numCount, int *opCount) {
    int i = 0, len = strlen(input), num = 0, isBuildingNumber = 0;

    *numCount = 0;
    *opCount = 0;

    while (i < len) {
        char ch = input[i];

        if (isspace(ch)) {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            isBuildingNumber = 1;
        } else if (strchr("+-*/", ch)) {
            if (isBuildingNumber) {
                numbers[(*numCount)++] = num;
                num = 0;
                isBuildingNumber = 0;
            }

            operators[(*opCount)++] = ch;
        } else {
            printf("Error: Unexpected character '%c' in the expression.\n", ch);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    if (isBuildingNumber) {
        numbers[(*numCount)++] = num;
    }
}

int operatorPrecedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}

int applyOperator(int left, int right, char operator) {
    switch (operator) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': 
            if (right == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            return left / right;
        default:
            printf("Error: Unsupported operator '%c'.\n", operator);
            exit(EXIT_FAILURE);
    }
}

int evaluateParsedExpression(int numbers[], char operators[], int numCount, int opCount) {
    for (int prec = 2; prec >= 1; prec--) {
        int i = 0;
        while (i < opCount) {
            if (operatorPrecedence(operators[i]) == prec) {
                numbers[i] = applyOperator(numbers[i], numbers[i + 1], operators[i]);

                for (int j = i + 1; j < numCount - 1; j++) {
                    numbers[j] = numbers[j + 1];
                }
                for (int j = i; j < opCount - 1; j++) {
                    operators[j] = operators[j + 1];
                }

                numCount--;
                opCount--;
            } else {
                i++;
            }
        }
    }

    return numbers[0];
}

int evaluateExpression(const char *input) {
    int numbers[MAX_INPUT_SIZE];
    char operators[MAX_INPUT_SIZE];
    int numCount, opCount;

    parseExpression(input, numbers, operators, &numCount, &opCount);

    return evaluateParsedExpression(numbers, operators, numCount, opCount);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter a mathematical expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    int result = evaluateExpression(input);
    printf("Result: %d\n", result);

    return 0;
}