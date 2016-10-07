#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

// 集合类型定义，用数组保存集合元素，用length表示集合当前元素数量
typedef struct {
	int length;
	int elem[MAXSIZE];
} SET;

// 从小到大顺序
int cmp_set_elem(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// 集合的特点是没有重复元素。本函数当集合s中不存在v时，才将v插入到集合中，并保持集合的升序排列
void insert_if_not_exists(SET *s, int v) {
	if (!bsearch(&v, &s->elem, s->length, sizeof(int), cmp_set_elem)) { //当前集合中没有v
		s->elem[s->length] = v; //保存到最后一个位置
		s->length++;
		qsort(s->elem, s->length, sizeof(int), cmp_set_elem); // 插入新元素后，用qsort排序，保持递增。
	}
	// 下面一段代码是不用bsearch和qsort手工实现集合元素的插入，可以把上面的代码注释掉，用下面的直接实现。

	/*int j;
	int left, right, mid, in_set;
	left = 0; right = a->length - 1;
	in_set = 0;

	// 找插入的位置
	while (left <= right) {
		mid = (left + right) / 2;
		if (s->elem[mid] == v) { // v在集合s中已经存在
			in_set = 1;
			break;
		}
		if (s->elem[mid] > v)
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (!in_set) { // 不存在，则在当前位置插入。需要把当前位置到集合最后一个元素都往后移动一个位置
		for (j = s->length; j > left; j--) 
			s->elem[j] = s->elem[j-1];

		s->elem[left] = v;
		s->length++;
	}*/
}

// 打印集合
void print_set(SET *s) {
	int i;
	printf("{");
	for (i = 0; i < s->length-1; i++) 
		printf("%d,", s->elem[i]);
	if (s->length > 0)
		printf("%d", s->elem[s->length-1]);
	printf("}\n");
}

// 求集合a和b的交集，结果保存于c中
void set_intersect(SET *a, SET *b, SET *c) {
	int i;
	SET *p;

	c->length = 0;
	for (i = 0; i < a->length; i++) {
		// 对于集合a的每个元素，在集合b中查找是否存在，如果存在就保存到c中。注意bsearch只能用在排序好的数组上
		if (bsearch(&a->elem[i], b->elem, b->length, sizeof(int), cmp_set_elem)) {
			c->elem[c->length] = a->elem[i];
			c->length++;
		}
	}
}

// 求集合a和b的并集，结果保存于c中
void set_union(SET *a, SET *b, SET *c) {
	int i;
	SET *p;

	// 并集至少包括a的所有元素
	for (i = 0; i < a->length; i++)
		c->elem[i] = a->elem[i];

	c->length = a->length;

	for (i = 0; i < b->length; i++) {
		// 对于集合b的每个元素，在集合a中查找是否存在，如果不存在就保存到c的末尾，避免重复插入元素
		if (!bsearch(&b->elem[i], a->elem, a->length, sizeof(int), cmp_set_elem)) {
			c->elem[c->length] = b->elem[i];
			c->length++;
		}
	}
	// 需要对c重新排序
	qsort(c->elem, c->length, sizeof(int), cmp_set_elem);
}

// 求集合a和b的差集，结果保存于c中
void set_difference(SET *a, SET *b, SET *c) {
	int i;
	
	c->length = 0;
	for (i = 0; i < a->length; i++) {
		// 对于集合a的每个元素，在集合b中查找是否存在，如果不存在就保存到c中
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