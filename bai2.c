#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 50
struct Stack
{
    char A[NMAX];
    int front;
};

void init(struct Stack *stack)
{
    stack->front = -1;
}

void push(struct Stack *stack, const int value)
{
    if (stack->front == NMAX - 1)
    {
        printf("Ngan xep day!\n");
        return;
    }
    ++(stack->front);
    stack->A[stack->front] = value;
}

char pop(struct Stack *stack)
{
    if (stack->front == -1)
    {
        return '\0';
    }

    char val = stack->A[stack->front];
    --(stack->front);
    return val;
}

char top(struct Stack *stack)
{
    if (stack->front == -1)
    {
        return -1;
    }

    return stack->A[stack->front];
}

int main()
{
    char *expr = "{[a + b(c + d) - (e + f) h] - 10}";
    int len_expr = strlen(expr);
    char *ngoac_mo = "{[(<";
    char *ngoac_dong = "}])>";
    int n_ngoac = strlen(ngoac_mo);

    struct Stack s;
    init(&s);

    for (int i = 0; i < len_expr; ++i)
    {
        int la_ngoac_mo = 0;
        for (int j = 0; j < n_ngoac; ++j)
        {
            if (expr[i] == ngoac_mo[j])
            {
                la_ngoac_mo = 1;
                break;
            }
        }
        if (la_ngoac_mo > 0)
        {
            push(&s, expr[i]);
            continue;
        }

        int la_ngoac_dong = 0;
        int vi_tri = -1;
        for (int j = 0; j < n_ngoac; ++j)
        {
            if (expr[i] == ngoac_dong[j])
            {
                la_ngoac_dong = 1;
                vi_tri = j;
                break;
            }
        }
        if (la_ngoac_dong > 0)
        {
            if (s.front == -1)
            {
                printf("Bieu thuc co ngoac KHONG phu hop (thua ngoac dong '%c' tai vi tri %d)\n", expr[i], i);
                return 0;
            }

            char val = pop(&s);

            if (val != ngoac_mo[vi_tri])
            {
                printf("Bieu thuc co ngoac KHONG phu hop (ngoac '%c' khong khop voi '%c' tai vi tri %d)\n",
                       val, expr[i], i);
                return 0;
            }
            continue;
        }
    }

    if (s.front == -1)
    {
        printf("Bieu thuc co ngoac phu hop\n");
    }
    else
    {
        printf("Bieu thuc co ngoac KHONG phu hop (con thieu ngoac dong)\n");
    }

    return 0;
}