#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

// ������ջ��Ԫ����char������typedef����һ�£�ջ���������������ͣ���int���ĳ� typedef int ELEM_TYPE
typedef char ELEM_TYPE;

typedef struct {
    ELEM_TYPE a[N]; // �����鱣��ջ��Ԫ�أ��̶���С�����Ǽ�
    int top; // ջ��λ�á�ջ��ʱΪ0��ջ��ʱΪN
} STACK;


// init_stack��ʼ��ջ��ֻ�轫ջ��λ������һ�¾�ok
STACK* init_stack(STACK *p) {
    p->top=0;
    return p;
}

// �ж�ջ�Ƿ�Ϊ��
int is_empty(STACK *p) {
    if(p->top<=0)
        return 1;
    else
        return 0;
}

// �ж�ջ�Ƿ�����
int is_full(STACK *p) {
    if(p->top >= N)
        return 1;
    else
        return 0;
}

// ȡջ��Ԫ��
ELEM_TYPE top(STACK *p) {
    return p->a[p->top - 1]; // ջ��λ��top
}

// ջ��push��ջ��������ջ��top�����Ԫ�غ�top����
int push(STACK *p,int x) {
    if(is_full(p)) {
        printf("˳��ջ������/n");
        exit(1);
    }
    
    p->a[p->top]=x; 
    p->top++;
    return 1;
}

// ջ��pop��ջ����
ELEM_TYPE pop(STACK *p) {
    if(is_empty(p)) {
        printf(" ˳��ջΪ�գ�/n");
        exit(1);
    }
    p->top--;
    return p->a[p->top];
}

// �������жϳ�ջ����pa�ĵ�ǰλ��pos_a�����֣��Ƿ���ͨ���Թ̶����У���'123456...'����ջ��ջ�������õ����ܵõ��򷵻�pos_b����ʾ���Լ����ж���һ��λ�á�
// pos_b��ʾ�̶�����1234...�Ѿ���δ��ջԪ�ص�λ�á����� 4 4321����������pa="4321",pb="1234", ��һ��pos_a��pos_b����0��ָ��ͷ
// �ж�pa��һ��Ԫ��4, ��pb��С�ڵ���4��Ԫ�ذ�����ջ��Ȼ���ж�ջ�������==4���ʾ���Լ����ж���һλ�á����!=4��Ƿ�
int stack_can_pop(STACK *tran, char *pa, int pos_a, char *pb, int pos_b, int n) {
    int i = pos_b;
    while (pos_b < n && pb[pos_b] <= pa[pos_a]) { // ��˳����ջ����pb��1234����<=��ǰ��ջ����Ԫ��pa������Ԫ�������ջ��
        push(tran, pb[pos_b]);
        pos_b++;
    }
    
    if (top(tran) == pa[pos_a]) {
        pop(tran);
        return pos_b;
    }
    
    return -1;
}

int main() {
    int k,n;
    int i,j;
    int pos;

    STACK tran;//����ȫ��ջ
    char a[N+1];//����һ���������ڴ��ԭ��˳��
    char b[N+1];//����һ���������ڴ������ĳ�ջ�Ļ�

    scanf("%d",&k);
    
    for(i=0;i<k;i++) {
		memset(a, 0, N+1); //��0
		memset(b, 0, N+1); //��0
        scanf("%d",&n);
        scanf(" ");
        
        for(j=0;j<n;j++) {
            scanf("%c",&a[j]);
            b[j] = '0' + j + 1; 
        }

		init_stack(&tran); // ÿ����ջǰ��Ҫ��ʼ��һ��
        j = 0;
        pos = 0;
        
		// �����жϳ�ջ���е�Ԫ���Ƿ���ͨ����ջ��ջ��ʽ�õ�
        while(j < n && (pos = stack_can_pop(&tran, a, j, b, pos, n)) > 0)
            j++;
            
        if (j < n) // j<n��ʾpa��ջ�����л�û���� �ͷ���-1����ʾ�޷��õ����
            printf("no\n");
        else
            printf("yes\n");

    }
}