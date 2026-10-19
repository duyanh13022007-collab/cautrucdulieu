#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

void push(struct Node **front, const char c)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Khong du bo nho!\n");
        return;
    }
    p->data = c;
    p->next = *front;
    *front = p;
}

char pop(struct Node **front)
{
    if (*front == NULL)
    {
        return '\0';
    }

    struct Node *p = *front;
    char val = p->data;
    *front = p->next;
    free(p);
    return val;
}

char top(struct Node *front)
{
    if (front == NULL)
    {
        return '\0';
    }
    return front->data;
}

void in_ngan_xep(struct Node *front)
{
    printf("Ngan xep (dinh -> day): ");
    if (front == NULL)
    {
        printf("(rong)");
    }
    for (struct Node *p = front; p != NULL; p = p->next)
    {
        printf("%c ", p->data);
    }
    printf("\n");
}

int main()
{
    struct Node *front = NULL;
    char c;

    printf("Kiem tra ngan xep rong:\n");
    c = top(front);
    printf("top = %d \n", c);
    c = pop(&front);
    printf("pop = %d \n\n", c);

    printf("Push lan luot: A, B, C, D\n");
    push(&front, 'A');
    push(&front, 'B');
    push(&front, 'C');
    push(&front, 'D');
    in_ngan_xep(front);
    printf("top = %c\n\n", top(front));

    printf("Pop 2 lan:\n");
    printf("pop = %c\n", pop(&front));
    printf("pop = %c\n", pop(&front));
    in_ngan_xep(front);
    printf("top = %c\n\n", top(front));

    printf("Push them: E\n");
    push(&front, 'E');
    in_ngan_xep(front);
    printf("top = %c\n\n", top(front));

    printf("Pop het ngan xep:\n");
    while (top(front) != '\0')
    {
        printf("pop = %c\n", pop(&front));
    }
    in_ngan_xep(front);
    printf("pop khi rong = %d\n\n", pop(&front));

    printf("Push 3 phan tu roi thoat (giai phong bo nho): X, Y, Z\n");
    push(&front, 'X');
    push(&front, 'Y');
    push(&front, 'Z');
    in_ngan_xep(front);

    while (front != NULL)
    {
        pop(&front);
    }
    printf("Da giai phong bo nho, front = %s\n", front == NULL ? "NULL" : "khac NULL");

    return 0;
}