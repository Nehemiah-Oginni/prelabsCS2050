#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int empID, jobType; 
float salary;
} Employee;


Employee * readEmployeeArray(FILE *fp);
void setEmpSalary(Employee *, int empID, float salary, int *ec);
float getEmpSalary(Employee *, int empID, int *ec);
void setEmpJobType(Employee *, int empID, int job, int *ec);
int getEmpJobType(Employee *, int empID, int *ec);

int main (void)
{
    
}