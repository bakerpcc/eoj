#include<stdio.h>

#include<stdlib.h>

#include<math.h>




#define G 9.8

#define N 17

int main() {

	 int n, i=0; float v[N + 1] = { 0 }; // v数组保存计算结果，最多17层

	 float h;

	 while(scanf("%d",&n)==1 && n > 0) {

		 h=(n<3) ? 5*(n-1)+1.75 : 3*(n-3)+10+1.75;

		 v[n] = sqrt(2*h/G);

	 }




	 for (i = N; i >= 1; i--)

		 if (v[i] > 0) printf("%.3f\n", v[i]);




	 return 0;

}