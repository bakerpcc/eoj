#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50124

// 暴力按序比较. 算法时间复杂度：O(N^3)，空间复杂度O(1)
int longest_1(const char* str1, const char* str2) {
	int i, j;
    int size1 = strlen(str1);
	int size2 = strlen(str2);
    if (size1 == 0 || size2 == 0) return 0;

    // the start position of substring in original string
    int start1 = -1;
    int start2 = -1;
    // the longest length of common substring
    int longest = 0;

    // record how many comparisons the solution did;
    // it can be used to know which algorithm is better
    int comparisons = 0;

    for (i = 0; i < size1; ++i) {
        for (j = 0; j < size2; ++j) {
            // find longest length of prefix
            int length = 0;
            int m = i;
            int n = j;
            while(m < size1 && n < size2) {
                ++comparisons;
                if (str1[m] != str2[n]) break;

                ++length;
                ++m;
                ++n;
            }

            if (longest < length) {
                longest = length;
                start1 = i;
                start2 = j;
            }
        }
    }

    return longest;
}

// 算法时间复杂度：O(N*M)，空间复杂度O(N*M)
int longest_2(const char* str1, const char* str2) {
    int i, j;
    int size1 = strlen(str1);
	int size2 = strlen(str2);

	if (size1 == 0 || size2 == 0) return 0;

	int **table = (int **)malloc(size1 * sizeof(int *));
	for (i = 0; i < size1; i++) {
		table[i] = (int *)malloc(size2 * sizeof(int));
		for (j = 0; j < size2; j++)
			table[i][j] = 0;
	}
    // the start position of substring in original string
    int start1 = -1;
    int start2 = -1;
    // the longest length of common substring
    int longest = 0;

    // record how many comparisons the solution did;
    // it can be used to know which algorithm is better
    int comparisons = 0;
    for (int j = 0; j < size2; ++j) {
        ++comparisons;
        table[0][j] = (str1[0] == str2[j] ? 1 :0);
    }

    for (int i = 1; i < size1; ++i) {
        ++comparisons;
        table[i][0] = (str1[i] == str2[0] ? 1 :0);

        for (int j = 1; j < size2; ++j) {
            ++comparisons;
            if (str1[i] == str2[j]) {
                table[i][j] = table[i-1][j-1]+1;
            }
        }
    }

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (longest < table[i][j]) {
                longest = table[i][j];
                start1 = i-longest+1;
                start2 = j-longest+1;
            }
        }
    }

    return longest;
}


// 算法时间复杂度：O(N*M)，空间复杂度O(N)
int longest_3(const char* str1, const char* str2) {
    int i, j;
    int size1 = strlen(str1);
	int size2 = strlen(str2);

	if (size1 == 0 || size2 == 0) return 0;

	int **table = (int **)malloc(size1 * sizeof(int *));
	for (i = 0; i < size1; i++) {
		table[i] = (int *)malloc(size2 * sizeof(int));
		for (j = 0; j < size2; j++)
			table[i][j] = 0;
	}
    // the start position of substring in original string
    int start1 = -1;
    int start2 = -1;
    // the longest length of common substring
    int longest = 0;

    // record how many comparisons the solution did;
    // it can be used to know which algorithm is better
    int comparisons = 0;
    for (int j = 0; j < size2; ++j) {
        ++comparisons;
		if (str1[0] == str2[j]) {
			table[0][j] = 1;
			if (longest == 0) {
				longest = 1;
				start1 = 0;
				start2 = j;
			}
		}
    }

    for (int i = 1; i < size1; ++i) {
        int cur = ((i&1) == 1); //index for current working row
        int pre = ((i&1) == 0); //index for previous working row
        table[cur][0] = 0;
        if (str1[i] == str2[0]) {
            table[cur][0] = 1;
            if (longest == 0)
            {
                longest = 1;
                start1 = i;
                start2 = 0;
            }
        }

        for (int j = 1; j < size2; ++j) {
            ++comparisons;
            if (str1[i] == str2[j]) {
                table[cur][j] = table[pre][j-1]+1;
                if (longest < table[cur][j]) {
                    longest = table[cur][j];
                    start1 = i-longest+1;
                    start2 = j-longest+1;
                }
            }
            else {
                table[cur][j] = 0;
            }
        }
    }

    return longest;
}


int main() {
    char s1[MAXLEN+1], s2[MAXLEN+1];
	gets(s1);
	gets(s2);

	//printf("%d\n", longest_1(s1, s2));
	//printf("%d\n", longest_2(s1, s2));
	printf("%d\n", longest_3(s1, s2));
}