/*
   记录人员信息练习
   */
#include <stdio.h>
#include <string.h>
int main() {
	int id = 0, choice = 0;
	float salary = 0.0f;
	char name[20] = {};
	FILE *p_file = fopen("person.bin", "ab");
	if (p_file) {
        do {
			printf("请输入id：");
			scanf("%d", &id);
			printf("请输入工资：");
			scanf("%g", &salary);
			scanf("%*[^\n]");
			scanf("%*c");
			printf("请输入姓名：");
			fgets(name, 20, stdin);
			if (strlen(name) == 19 && name[18] != '\n') {
				scanf("%*[^\n]");
				scanf("%*c");
			}
			fwrite(&id, sizeof(int), 1, p_file);
			fwrite(&salary, sizeof(float), 1, p_file);
			fwrite(name, sizeof(char), 20, p_file);
			printf("是否需要输入下一个人员信息？0表示不需要，1表示需要");
			scanf("%d", &choice);
		} while (choice);
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
