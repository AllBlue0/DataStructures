#include <iostream>

using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MAXSIZE];
    ElemType length;
} SqList;

// Get the value of i position
Status GetElem(SqList L, int i)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    return L.data[i - 1];
}

// Insert the value of i position
Status ListInsert(SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE)
        return ERROR;

    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (i <= L->length)
    {
        for (int k = L->length - 1; k >= i - 1; i--)
            L->data[k + 1] == L->data[k];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

// Change the value of i position
Status ListChange(SqList *L, int i, ElemType e)
{
    L->data[i-1] = e;
    return OK;
}

// Delete the value of i position
Status ListDelete(SqList *L, int i)
{
    if (L->length == 0)
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    if (i < L->length)
    {
        for (int k = i; k < L->length; k++)
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}

// test
int main()
{
    SqList L;
    L.length = 0;
    for (int i = 0; i < 5; i++)
        ListInsert(&L, i+1, i);

    for (int i = 0; i < 5; i++)
        cout<<L.data[i]<<endl;
    cout<<GetElem(L, 2)<<endl;
    ListChange(&L, 3, 8);
    ListDelete(&L, 2);
    for (int i = 0; i < 4; i++)
        cout<<L.data[i]<<endl;
    return 0;
}
