#include <stdio.h>
#include <stdlib.h>
#include "PolynomialADT.h"

typedef int ChoiceType;
typedef PolyPtr (*OpFuncPtr)(PolyPtr, PolyPtr);

#define EXIT     0
#define INPUT    1
#define ADD      2
#define SUB      3
#define MUL      4
#define OUTPUT   5
#define UNKNOWN -1

#ifdef linux
    #define ClearScreen() system("clear")
#else
    #define ClearScreen() system("cls")
#endif

void        buffClear   ();
OpFuncPtr   operate     (ChoiceType op);
ChoiceType  promptInput ();

void buffClear()
{
    char ch;
    do {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}

OpFuncPtr operate(ChoiceType op)
{
    switch (op)
    {
        case ADD:
            return &addPoly;
            break;
        case SUB:
            return &subPoly;
            break;
        case MUL:
            return &mulPoly;
            break;
        default:
            return NULL;
            break;
    }
}

ChoiceType promptInput()
{
    printf("\n��ѡ�������\n");
    printf("-----------------------\n\n");
    printf("    1 - ����ʽ����\n");
    printf("    2 - ����ʽ���\n");
    printf("    3 - ����ʽ���\n");
    printf("    4 - ����ʽ���\n");
    printf("    5 - ����ʽ���\n");
    printf("    0 - �˳�����\n");
    printf("-----------------------\n");

    char input;
    do {
        input = getchar();
    } while(input == '\n');

    buffClear();    // ��ջ�����

    if (input >= '0' && input <= '5')   // �����Ч������Χ
        return (ChoiceType)(input - '0');
    else
        return UNKNOWN;

}

int main()
{
    PolyPtr poly1, poly2, result;
    ChoiceType choice;

    poly1  = NULL;
    poly2  = NULL;
    result = NULL;

    while (1)
    {
        choice = promptInput();
        ClearScreen();
        switch (choice)
        {
            case EXIT:
            exit(0);

            case INPUT:
            printf("�������һ������ʽ��\n\n");
            poly1 = inputPolynomial();
            printf("\n������ڶ�������ʽ��\n\n");
            poly2 = inputPolynomial();

            break;

            case OUTPUT:
            if (poly1 == NULL || poly2 == NULL)
            {
                printf("�����������ʽ��\n");
                break;
            }
            else if (result == NULL)
            {
                printf("���ȶԶ���ʽ�������㣡\n");
                break;
            }
            else
            {
                printf("�������ʽ��\n");
                printPolynomial(result);
                break;
            }

            case ADD: case SUB: case MUL:
            if (poly1 == NULL || poly2 == NULL)
            {
                printf("�����������ʽ��\n");
                break;
            }
            else
            {
                poly1  = sortPolynomial(poly1); // ͬ�����ϲ����������X����
                poly2  = sortPolynomial(poly2);
                result = operate(choice) (poly1, poly2);
                printf("���������.\n");
                break;
            }

            default:
            printf("��Ч������������ѡ��.\n");
            break;
        }
    }
}
