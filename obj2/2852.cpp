#include <stdio.h>

int main444() {
	int c;
	// max��¼��������������ĸ��total��¼������ĸ��������freq��¼26����ĸ���Գ��ֵĴ���
	int i, max, total, freq[26] = { 0 };

	max = 0; total = 0;
	//c=getchar(),c��������Ϊ����������getchar����ԭ�͵�Ҫ��
	while ((c = getchar()) != NULL) {
		if (c == '\n') // �����س��ͽ�����
			break;
		if (c == ' ' || c == '\t') //�����հ��ַ�������
			continue;

		total++; 
		freq[c-'a']++; //freq[0]��ʾa������freq[25]��ʾz
		if (freq[c-'a'] > max) // max�ȵ�ǰ��ĸ���ִ���С
			max = freq[c-'a'];
	}

	for (i = 0; i < 26; i++)
		if (max == freq[i]) {
			printf("%c %.2f\n", i+'a', (float)max / total);
			break;
		}

	return 0;
}