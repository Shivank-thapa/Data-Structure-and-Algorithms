#include <stdio.h>
#include <string.h>
#define LIMIT 35

int max(int a, int b) {
	if(a > b)
		return a;
	return b;
}

int lcsLength(char s1[], char s2[]) {
	int m = strlen(s1)-1;
	int n = strlen(s2)-1;
	int i,j;
	char LCS[m+1][n+1];

	for(i=0; i<=m; i++) {
		for(j=0; j<=n; j++) {
			if(i == 0 || j == 0)
				LCS[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
		
	return LCS[m][n];
}

int main(void) {
	char str1[LIMIT], str2[LIMIT];
	printf("Enter two strings: ");
	fgets(str1, LIMIT, stdin);
	fgets(str2, LIMIT, stdin);

	printf("%d\n",lcsLength(str1, str2));

	return 0;
}
