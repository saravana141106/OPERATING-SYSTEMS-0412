/* Lab program: 21_random_access_file */
#include <stdio.h>
struct Employee
{
int id;
char name[30];
float salary;
};
int main()
{
FILE *fp;
struct Employee e;
int n, i, record;
fp = fopen("employee.dat", "wb");
if (fp == NULL)
{
printf("File cannot be opened\n");
return 1;
}
printf("Enter number of employees: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
printf("\nEnter ID, Name and Salary: ");
scanf("%d %29s %f", &e.id, e.name, &e.salary);
fwrite(&e, sizeof(e), 1, fp);
}
fclose(fp);
fp = fopen("employee.dat", "rb");
printf("\nEnter record number to access: ");
scanf("%d", &record);
if (record < 1 || record > n)
{
printf("Invalid record number\n");
fclose(fp);
return 1;
}
fseek(fp, (record - 1) * sizeof(e), SEEK_SET);
fread(&e, sizeof(e), 1, fp);
printf("\nEmployee Details\n");
printf("ID: %d\n", e.id);
printf("Name: %s\n", e.name);
printf("Salary: %.2f\n", e.salary);
fclose(fp);
return 0;
}
