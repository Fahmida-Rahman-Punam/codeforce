#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    int age;
    char position[50];
    float basicSalary;
    int attendance;
    float bonus;
    float deduction;
};

void addEmployee();
void viewEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
void recordAttendance();
void calculateSalary();
int employeeExists(int id);   

int main()
{
    int choice;

    while(1)
    {
        printf("\n====================================");
        printf("\n EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n====================================");

        printf("\n1. Add Employee");
        printf("\n2. View Employees");
        printf("\n3. Search Employee");
        printf("\n4. Update Employee");
        printf("\n5. Delete Employee");
        printf("\n6. Record Attendance");
        printf("\n7. Calculate Salary");
        printf("\n8. Exit");

        printf("\n\nEnter your choice: ");

        
        if(scanf("%d",&choice) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");
            while(getchar() != '\n');   // clear the leftover bad input
            continue;
        }

        switch(choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                viewEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                updateEmployee();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                recordAttendance();
                break;

            case 7:
                calculateSalary();
                break;

            case 8:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}


int employeeExists(int id)
{
    FILE *fp;
    struct Employee emp;

    fp = fopen("employee.dat","rb");

    if(fp == NULL)
        return 0;  

    while(fread(&emp,sizeof(emp),1,fp))
    {
        if(emp.id == id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void addEmployee()
{
    FILE *fp;
    struct Employee emp;

    printf("\nEnter Employee ID: ");
    scanf("%d",&emp.id);

   
    if(employeeExists(emp.id))
    {
        printf("\nAn employee with this ID already exists!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %49[^\n]",emp.name);       

    printf("Enter Age: ");
    scanf("%d",&emp.age);

    printf("Enter Position: ");
    scanf(" %49[^\n]",emp.position);

    printf("Enter Basic Salary: ");
    scanf("%f",&emp.basicSalary);

    emp.attendance = 0;
    emp.bonus = 0;
    emp.deduction = 0;


    fp = fopen("employee.dat","ab");

    if(fp==NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    fwrite(&emp,sizeof(emp),1,fp);
    fclose(fp);

    printf("\nEmployee Added Successfully!\n");
}

void viewEmployees()
{
    FILE *fp;
    struct Employee emp;

    fp = fopen("employee.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo Employee Record Found!\n");
        return;
    }

    printf("\n===============================");
    printf("\nEmployee List");
    printf("\n===============================\n");

    while(fread(&emp,sizeof(emp),1,fp))
    {
        printf("\nEmployee ID : %d",emp.id);
        printf("\nName        : %s",emp.name);
        printf("\nAge         : %d",emp.age);
        printf("\nPosition    : %s",emp.position);
        printf("\nSalary      : %.2f",emp.basicSalary);
        printf("\nAttendance  : %d",emp.attendance);
        printf("\nBonus       : %.2f",emp.bonus);
        printf("\nDeduction   : %.2f",emp.deduction);
        printf("\n---------------------------------\n");
    }

    fclose(fp);
}

void searchEmployee()
{
    FILE *fp;
    struct Employee emp;
    int id, found = 0;

    fp = fopen("employee.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo employee record found!\n");
        return;
    }

    printf("\nEnter Employee ID to Search: ");
    scanf("%d", &id);

    while(fread(&emp, sizeof(emp), 1, fp))
    {
        if(emp.id == id)
        {
            found = 1;

            printf("\nEmployee Found");
            printf("\n------------------------");
            printf("\nID          : %d", emp.id);
            printf("\nName        : %s", emp.name);
            printf("\nAge         : %d", emp.age);
            printf("\nPosition    : %s", emp.position);
            printf("\nSalary      : %.2f", emp.basicSalary);
            printf("\nAttendance  : %d", emp.attendance);
            printf("\nBonus       : %.2f", emp.bonus);
            printf("\nDeduction   : %.2f", emp.deduction);
            printf("\n");
            break;
        }
    }

    if(!found)
        printf("\nEmployee Not Found!\n");

    fclose(fp);
}

void updateEmployee()
{
    FILE *fp;
    FILE *temp;
    struct Employee emp;
    int id;
    int found = 0;

    
    fp = fopen("employee.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo employee record found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    printf("\nEnter Employee ID to Update: ");
    scanf("%d",&id);

    while(fread(&emp,sizeof(emp),1,fp))
    {
        if(emp.id==id)
        {
            found=1;

            printf("\nEnter New Name: ");
            scanf(" %49[^\n]",emp.name);

            printf("Enter New Age: ");
            scanf("%d",&emp.age);

            printf("Enter New Position: ");
            scanf(" %49[^\n]",emp.position);

            printf("Enter New Basic Salary: ");
            scanf("%f",&emp.basicSalary);

            printf("\nEmployee Updated Successfully!\n");
        }

        fwrite(&emp,sizeof(emp),1,temp);
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat","employee.dat");

    if(!found)
        printf("\nEmployee ID Not Found!\n");
}

void deleteEmployee()
{
    FILE *fp;
    FILE *temp;
    struct Employee emp;
    int id;
    int found = 0;


    fp = fopen("employee.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo employee record found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    printf("\nEnter Employee ID to Delete: ");
    scanf("%d",&id);

    while(fread(&emp,sizeof(emp),1,fp))
    {
        if(emp.id==id)
        {
            found=1;
            continue;   
        }

        fwrite(&emp,sizeof(emp),1,temp);
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat","employee.dat");

    if(found)
        printf("\nEmployee Deleted Successfully!\n");
    else
        printf("\nEmployee ID Not Found!\n");
}

void recordAttendance()
{
    FILE *fp;
    FILE *temp;
    struct Employee emp;
    int id;
    int found = 0;
    int days;

   
    fp = fopen("employee.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Employee Record Found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    printf("\nEnter Employee ID: ");
    scanf("%d",&id);

    while(fread(&emp,sizeof(emp),1,fp))
    {
        if(emp.id == id)
        {
            found = 1;

           
            do
            {
                printf("Enter Attendance (0-30 days): ");
                scanf("%d",&days);

                if(days < 0 || days > 30)
                    printf("Invalid! Attendance must be between 0 and 30.\n");

            } while(days < 0 || days > 30);

            emp.attendance = days;

            printf("\nAttendance Updated Successfully!\n");
        }

        fwrite(&emp,sizeof(emp),1,temp);
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat","employee.dat");

    if(!found)
        printf("\nEmployee Not Found!\n");
}

void calculateSalary()
{
    FILE *fp;
    FILE *temp;
    struct Employee emp;
    int id;
    int found = 0;
    float bonus, deduction;

   
    fp = fopen("employee.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Employee Record Found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    printf("\nEnter Employee ID: ");
    scanf("%d",&id);

    while(fread(&emp,sizeof(emp),1,fp))
    {
        if(emp.id == id)
        {
            found = 1;

            do
            {
                printf("Enter Bonus: ");
                scanf("%f",&bonus);

                if(bonus < 0)
                    printf("Invalid! Bonus cannot be negative.\n");

            } while(bonus < 0);

           
            do
            {
                printf("Enter Deduction: ");
                scanf("%f",&deduction);

                if(deduction < 0)
                    printf("Invalid! Deduction cannot be negative.\n");

            } while(deduction < 0);

            emp.bonus = bonus;
            emp.deduction = deduction;

            float dailySalary = emp.basicSalary / 30;

            float finalSalary =
                (dailySalary * emp.attendance)
                + emp.bonus
                - emp.deduction;

            
            if(finalSalary < 0)
                finalSalary = 0;

            printf("\n========== Salary Report ==========\n");
            printf("Employee ID   : %d\n",emp.id);
            printf("Name          : %s\n",emp.name);
            printf("Position      : %s\n",emp.position);
            printf("Basic Salary  : %.2f\n",emp.basicSalary);
            printf("Attendance    : %d Days\n",emp.attendance);
            printf("Bonus         : %.2f\n",emp.bonus);
            printf("Deduction     : %.2f\n",emp.deduction);
            printf("----------------------------------\n");
            printf("Final Salary  : %.2f\n",finalSalary);
        }

        fwrite(&emp,sizeof(emp),1,temp);
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat","employee.dat");

    if(!found)
        printf("\nEmployee Not Found!\n");
}