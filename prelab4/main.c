#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int empID, jobType; 
float salary;
} Employee;


Employee * readEmployeeArray(FILE *fp);
Employee * getEmployeeByID(Employee *, int empID);
void setEmpSalary(Employee *, int empID, float salary, int *ec);
float getEmpSalary(Employee *, int empID, int *ec);
void setEmpJobType(Employee *, int empID, int job, int *ec);
int getEmpJobType(Employee *, int empID, int *ec);


//strlen() returns length of string
//strcpy(A,B) coppies B into A
//strcat(A,B) adds B to the end of A

/*
get_row_length(Employee * var)
{
    return *(((int*)var)-1)
}



/* int main(void)
{
    FILE *fp;
    fp = NULL;
    fp = fopen("employee.txt", "r");
    Employee* workers = readEmployeeArray(fp);


} */

int main(void) {
    FILE *fp = fopen("employee.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    
    Employee* workers = readEmployeeArray(fp);
    fclose(fp);

    if (!workers) {
        printf("Error reading employee data.\n");
        return 1;
    }

    // Testing the functions
    int ec;
    printf("\nTesting functions:\n");

    int testEmpID = 101;  // Change to an existing ID from the file for testing
    float newSalary = 75000.0;

    setEmpSalary(workers,testEmpID, newSalary, &ec);
    if (ec) {
        printf("Salary updated successfully for Employee ID %d.\n", testEmpID);
    } else {
        printf("Failed to update salary for Employee ID %d.\n", testEmpID);
    }

    float salary = getEmpSalary(workers, testEmpID, &ec);
    if (ec) {
        printf("New Salary of Employee ID %d: %.2f\n", testEmpID, salary);
    } else {
        printf("Failed to retrieve salary for Employee ID %d.\n", testEmpID);
    }

    free(workers);
    return 0;
}



Employee * readEmployeeArray(FILE *fp)
{
    // Return NULL if file opening fails
    if(fp == NULL)
    {
        return NULL;
    }
    int workerCount;

    fscanf(fp,"%d ",&workerCount);

    

    Employee* array = malloc(sizeof(int) + sizeof(Employee) * workerCount);

    // Store number of rows (5) 
    ((int*)array)[0] = workerCount;
    // Move pointer past
    (int*)array++;


    int empID, jobType;
    float salary;
    Employee myEmployee;

    for(int i=0; !feof(fp); i++)
    {
        
        fscanf(fp,"%d %d %f", &myEmployee.empID, &myEmployee.jobType, &myEmployee.salary);

        array[i].empID = myEmployee.empID;
        array[i].jobType = myEmployee.jobType;
        array[i].salary = myEmployee.salary;
    }

    for(int i=0; i< workerCount ; i++)
    {
    printf("array index %d contains ID: %d, jobType: %d and salary: %f\n", i, array[i].empID, array[i].jobType, array[i].salary);
    }

}
Employee * getEmployeeByID(Employee * Employees, int empID)
{
    //Employee searchVar;

    for(int i=0; i<5; i++)
    {
        if(Employees[i].empID == empID)
        {
            return &Employees[i];
        }
    }
    return 0;

}
void setEmpSalary(Employee * worker, int empID, float salary, int *ec)
{
    getEmployeeByID(worker, empID)->salary = salary;
}
float getEmpSalary(Employee * worker, int empID, int *ec)
{
    return getEmployeeByID(worker, empID)->salary;
}
void setEmpJobType(Employee * worker, int empID, int job, int *ec)
{
    getEmployeeByID(worker, empID)->jobType = job;
}
int getEmpJobType(Employee * worker, int empID, int *ec)
{
    return getEmployeeByID(worker, empID)->jobType;
}



/* void setEmpSalary(Employee *worker, int empID, float salary, int *ec) {
    Employee *emp = getEmployeeByID(worker, empID); // Retrieve employee by ID

    if (emp) {  Check if the employee exists
        emp->salary = salary;
        *ec = 1;  Success
    } else {
        *ec = 0;  Failure (employee not found)
    }
} */
