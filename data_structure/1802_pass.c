#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

// 本题中栈的元素是char，这里typedef定义一下，栈可以用于其它类型，如int，改成 typedef int ELEM_TYPE
typedef char ELEM_TYPE;

typedef struct {
    ELEM_TYPE a[N]; // 用数组保存栈的元素，固定大小，但是简单
    int top; // 栈顶位置。栈空时为0，栈满时为N
} STACK;


// init_stack初始化栈。只需将栈顶位置设置一下就ok
STACK* init_stack(STACK *p) {
    p->top=0;
    return p;
}

// 判断栈是否为空
int is_empty(STACK *p) {
    if(p->top<=0)
        return 1;
    else
        return 0;
}

// 判断栈是否满了
int is_full(STACK *p) {
    if(p->top >= N)
        return 1;
    else
        return 0;
}

// 取栈顶元素
ELEM_TYPE top(STACK *p) {
    return p->a[p->top - 1]; // 栈顶位置top
}

// 栈的push入栈操作。在栈的top出存放元素后，top增加
int push(STACK *p,int x) {
    if(is_full(p)) {
        printf("顺序栈已满！/n");
        exit(1);
    }
    
    p->a[p->top]=x; 
    p->top++;
    return 1;
}

// 栈的pop出栈操作
ELEM_TYPE pop(STACK *p) {
    if(is_empty(p)) {
        printf(" 顺序栈为空！/n");
        exit(1);
    }
    p->top--;
    return p->a[p->top];
}

// 本函数判断出栈序列pa的当前位置pos_a的数字，是否能通过对固定序列（即'123456...'）入栈出栈操作而得到，能得到则返回pos_b，表示可以继续判断下一个位置。
// pos_b表示固定序列1234...已经尚未入栈元素的位置。比如 4 4321输入的情况，pa="4321",pb="1234", 第一次pos_a和pos_b都是0，指向开头
// 判断pa第一个元素4, 将pb中小于等于4的元素按序入栈。然后判断栈顶，如果==4则表示可以继续判断下一位置。如果!=4则非法
int stack_can_pop(STACK *tran, char *pa, int pos_a, char *pb, int pos_b, int n) {
    int i = pos_b;
    while (pos_b < n && pb[pos_b] <= pa[pos_a]) { // 将顺序入栈序列pb”1234“中<=当前出栈序列元素pa的所有元素逐个入栈。
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

    STACK tran;//声明全局栈
    char a[N+1];//声明一个数组用于存放原火车顺序
    char b[N+1];//声明一个数组用于存放输出的出栈的火车

    scanf("%d",&k);
    
    for(i=0;i<k;i++) {
		memset(a, 0, N+1); //清0
		memset(b, 0, N+1); //清0
        scanf("%d",&n);
        scanf(" ");
        
        for(j=0;j<n;j++) {
            scanf("%c",&a[j]);
            b[j] = '0' + j + 1; 
        }

		init_stack(&tran); // 每次用栈前都要初始化一下
        j = 0;
        pos = 0;
        
		// 挨个判断出栈序列的元素是否能通过入栈出栈方式得到
        while(j < n && (pos = stack_can_pop(&tran, a, j, b, pos, n)) > 0)
            j++;
            
        if (j < n) // j<n表示pa出栈序列中还没结束 就返回-1，表示无法得到结果
            printf("no\n");
        else
            printf("yes\n");

    }
}