#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

// �������Ͷ��壬�����鱣�漯��Ԫ�أ���length��ʾ���ϵ�ǰԪ������
typedef struct {
	int length;
	int elem[MAXSIZE];
} SET;

// ��С����˳��
int cmp_set_elem(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// ���ϵ��ص���û���ظ�Ԫ�ء�������������s�в�����vʱ���Ž�v���뵽�����У������ּ��ϵ���������
void insert_if_not_exists(SET *s, int v) {
	if (!bsearch(&v, &s->elem, s->length, sizeof(int), cmp_set_elem)) { //��ǰ������û��v
		s->elem[s->length] = v; //���浽���һ��λ��
		s->length++;
		qsort(s->elem, s->length, sizeof(int), cmp_set_elem); // ������Ԫ�غ���qsort���򣬱��ֵ�����
	}
	// ����һ�δ����ǲ���bsearch��qsort�ֹ�ʵ�ּ���Ԫ�صĲ��룬���԰�����Ĵ���ע�͵����������ֱ��ʵ�֡�

	/*int j;
	int left, right, mid, in_set;
	left = 0; right = a->length - 1;
	in_set = 0;

	// �Ҳ����λ��
	while (left <= right) {
		mid = (left + right) / 2;
		if (s->elem[mid] == v) { // v�ڼ���s���Ѿ�����
			in_set = 1;
			break;
		}
		if (s->elem[mid] > v)
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (!in_set) { // �����ڣ����ڵ�ǰλ�ò��롣��Ҫ�ѵ�ǰλ�õ��������һ��Ԫ�ض������ƶ�һ��λ��
		for (j = s->length; j > left; j--) 
			s->elem[j] = s->elem[j-1];

		s->elem[left] = v;
		s->length++;
	}*/
}

// ��ӡ����
void print_set(SET *s) {
	int i;
	printf("{");
	for (i = 0; i < s->length-1; i++) 
		printf("%d,", s->elem[i]);
	if (s->length > 0)
		printf("%d", s->elem[s->length-1]);
	printf("}\n");
}

// �󼯺�a��b�Ľ��������������c��
void set_intersect(SET *a, SET *b, SET *c) {
	int i;
	SET *p;

	c->length = 0;
	for (i = 0; i < a->length; i++) {
		// ���ڼ���a��ÿ��Ԫ�أ��ڼ���b�в����Ƿ���ڣ�������ھͱ��浽c�С�ע��bsearchֻ����������õ�������
		if (bsearch(&a->elem[i], b->elem, b->length, sizeof(int), cmp_set_elem)) {
			c->elem[c->length] = a->elem[i];
			c->length++;
		}
	}
}

// �󼯺�a��b�Ĳ��������������c��
void set_union(SET *a, SET *b, SET *c) {
	int i;
	SET *p;

	// �������ٰ���a������Ԫ��
	for (i = 0; i < a->length; i++)
		c->elem[i] = a->elem[i];

	c->length = a->length;

	for (i = 0; i < b->length; i++) {
		// ���ڼ���b��ÿ��Ԫ�أ��ڼ���a�в����Ƿ���ڣ���������ھͱ��浽c��ĩβ�������ظ�����Ԫ��
		if (!bsearch(&b->elem[i], a->elem, a->length, sizeof(int), cmp_set_elem)) {
			c->elem[c->length] = b->elem[i];
			c->length++;
		}
	}
	// ��Ҫ��c��������
	qsort(c->elem, c->length, sizeof(int), cmp_set_elem);
}

// �󼯺�a��b�Ĳ�����������c��
void set_difference(SET *a, SET *b, SET *c) {
	int i;
	
	c->length = 0;
	for (i = 0; i < a->length; i++) {
		// ���ڼ���a��ÿ��Ԫ�أ��ڼ���b�в����Ƿ���ڣ���������ھͱ��浽c��
		if (!bsearch(&a->elem[i], b->elem, b->length, sizeof(int), cmp_set_elem)) {
			c->elem[c->length] = a->elem[i];
			c->length++;
		}
	}
}

int main() {
	int i, j, k;
	int v, len_a, len_b;

	SET a, b, c;
	a.length = b.length = c.length = 0;

	scanf("%d%d", &len_a, &len_b);

	for (i = 0; i < len_a; i++) {
		scanf("%d", &v);
		insert_if_not_exists(&a, v);
	}
	for (i = 0; i < len_b; i++) {
		scanf("%d", &v);
		insert_if_not_exists(&b, v);
	}

	//print_set(&a);
	//print_set(&b);

	set_intersect(&a, &b, &c);
	print_set(&c);

	set_union(&a, &b, &c);
	print_set(&c);

	set_difference(&a, &b, &c);
	print_set(&c);

	return 0;
}