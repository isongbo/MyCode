/*
   人员信息管理练习
   */
#include <stdio.h>
int main() {
	int id = 0;
	float salary = 0.0f;
	char name[20] = {};
	FILE *p_file = fopen("person.bin", "rb");
	if (p_file) {
		while (fread(&id, sizeof(int), 1, p_file)) {
			fread(&salary, sizeof(float), 1, p_file);
			fread(name, sizeof(char), 20, p_file);
			printf("id是%d,工资是%g,姓名是%s\n", id, salary, name);
		}
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
