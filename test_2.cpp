#include <stdio.h>
#include <cstring>

int main () {
	char str[1000];
	scanf("%[^\n]s", str);
	int len = strlen(str);
	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ') str[i] = '\0';// '\n'
	}
	//printf("%s", str);
	int pos = 0;
	while (pos < len) {
		pos += printf("%s", str + pos);
		pos += 1;
		printf("\n");
	}
	return 0;
}