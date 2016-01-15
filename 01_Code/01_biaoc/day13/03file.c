/*
   文件位置指针练习
   */
#include <stdio.h>
int main() {
	int id = 0, id1 = 0;
	float salary = 0.0f;
	char name[20] = {};
	printf("请指定一个id:");
	scanf("%d", &id1);
	FILE *p_file = fopen("person.bin", "rb");
	if (p_file) {
        while (fread(&id, sizeof(int), 1, p_file)) {
			if (id == id1) {
			    fread(&salary, sizeof(float), 1, p_file);
			    fread(name, sizeof(char), 20, p_file);
				printf("id是%d\n", id);
				printf("工资是%g\n", salary);
				printf("姓名是%s\n", name);
			}
			else {
				fseek(p_file, 24, SEEK_CUR);
			}
		}
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
