#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name, emp_number;
    char emp_code, employee_type, category, toy_category;
    double fixed_salary, overtime_salary, salary;
    int overtime_hours, hours_worked, toys_assembled;

    cout << "Enter employee name: ";
    getline(cin, name);
    cout << "Enter employee number: ";
    getline(cin,emp_number);
    cout << "Enter employee code (G, K, or S): ";
    cin >> emp_code;

    if (emp_code == 'G') 
        {
            cout << "Enter employee type (P for manager or B for non-manager): ";
            cin >> employee_type;

            cout << "Enter fixed salary amount: ";
            cin >> fixed_salary;

            if (employee_type == 'B') 
            {
                cout << "Enter overtime hours worked: ";
                cin >> overtime_hours;

                if (overtime_hours > 20)
                {
                    cout << "Excessive overtime hours. Overtime claims capped at 20 hours." << endl;
                    overtime_hours = 20;
                }

                if (overtime_hours <= 10) overtime_salary = overtime_hours * 15;
                else overtime_salary = (10 * 15) + ((overtime_hours - 10) * 12);

                salary = fixed_salary + overtime_salary;
            } 
            else salary = fixed_salary;

        } 
    else if (emp_code == 'K')
        {
            cout << "Enter category (B for Recovery, S for Maintenance): ";
            cin >> category;

            cout << "Enter number of hours worked: ";
            cin >> hours_worked;

            if (category == 'B') 
            {
                if (hours_worked > 100) 
                {
                cout << "Maximum hours for recovery work is 100. Excess hours rejected." << endl;
                hours_worked = 100;
                }
                salary = hours_worked * 20; 
            }
                else if (category == 'S')
                {
                    if (hours_worked > 100) 
                    {
                    cout << "Maximum hours for maintenance work is 100. Excess hours rejected." << endl;
                    hours_worked = 100;
                    }

                    if (hours_worked <= 50) salary = hours_worked * 10;
                    else salary = (50 * 10) + ((hours_worked - 50) * 5);
               }
            
        }

    else if (emp_code == 'S')
        {
            cout << "Enter toy category (B for Large, S for Medium, K for Small): ";
            cin >> toy_category;

            cout << "Enter number of toys assembled: ";
            cin >> toys_assembled;

            if (toy_category == 'B') salary = toys_assembled * 8;
            else if (toy_category == 'S') salary = toys_assembled * 5;
            else if (toy_category == 'K') salary = toys_assembled * 2;
        }

        else 
        {
            cout << "Invalid employee code. Please enter a valid code (G, K, or S)." << endl;
            return 0;
        }
 
        cout << "Employee Name: " << name << endl;
        cout << "Employee Number: " << emp_number << endl;
        cout << "Total Income for the Month: RM" << salary << endl;

        return 0;
}
