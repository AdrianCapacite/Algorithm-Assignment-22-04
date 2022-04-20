/*
    Algorithms and Design and Problems Assignment - assignment
    Program contains details of 4 teams of employees and their details and line certifications
    Data structure:
        4 arrays represent 4 teams of 4 employees::
            Each employee contains details: employee id, first name, surname and line
        A separate array contains the line certifications of each employee
            The line certifications consists of: employee id, line certification
                The line certification has 3 bits:
                    Bit 0: Line 1
                    Bit 1: Line 2
                    Bit 2: Line 3
        
    Functions
        1. Combines the 4 teams of employees into one array and sorts the array by surname using modified merge sort
        2. Prints a list of employees certified for all 3 lines
        3. Search employees by surname

    Data:
        Teams:
            Cols:
                employeeID,firstName,surname,line
            Team 1:
                8,Hanae,Mejia,1
                3,Evan,Underwood,1
                7,Jenette,David,3
                1,Quin,Knight,2
                4,Gannon,Mueller,3
                19,Merrill,Gilmore,2
            Team 2:
                14,Shellie,Soto,1
                23,Carson,Ayala,1
                5,Orla,Wyatt,1
                11,Neville,Berg,1
                10,Macy,Cotton,2
                6,Emi,Stafford,0
            Team 3:
                20,Austin,William,1
                2,Dana,Stephenson,0
                22,Amery,Bridges,1
                18,Mollie,Hester,1
                24,Brent,Molina,2
                15,Bradley,Ortiz,0
            Team 4:
                17,Maia,Mccullough,3
                16,India,Calhoun,2
                12,Nathaniel,Solis,3
                13,Drake,Leach,1
                9,May,Bowers,1
                21,Maxine,Marquez,2

        Certifications:
            Cols:
                employeeID,line
            Employees:
                8,3
                3,7
                7,4
                1,5
                4,5
                19,5
                14,3
                23,7
                5,0
                11,1
                10,4
                6,3
                20,2
                2,2
                22,5
                18,2
                24,7
                15,2
                17,2
                16,7
                12,4
                13,0
                9,6
                21,1

    Author: Adrian Thomas Capacite
    Date: 13 / 04 / 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEAM_SIZE 6     // Number of employees in each team
#define TEAM_COUNT 4    // Number of teams

/* Struct templates */
typedef char STRING30[30];
typedef struct
{
    int employeeID;
    STRING30 firstName;
    STRING30 surname;
    int line;
} EMPLOYEE;
typedef struct
{
    int employeeID;
    int line;
} CERTIFICATION;

/* Function prototypes */
// Options functions
void PrintEmployeeList(EMPLOYEE *employeeList, int size);
void PrintCertified(EMPLOYEE *employeeList, int size);
void SearchEmployeesBySurname(EMPLOYEE *employeeList, int size);

// Utility functions
void SortEmployeesBy();
void MergeTeams(EMPLOYEE *employeeList, EMPLOYEE *teamList[], int teamSize, int teamCount);


/* Global varables prefix: g_*/
// 4 Teams of 6 employees
EMPLOYEE g_team1[TEAM_SIZE] = {
    {8, "Hanae", "Mejia", 1},
    {3, "Evan", "Underwood", 1},
    {7, "Jenette", "David", 3},
    {1, "Quin", "Knight", 2},
    {4, "Gannon", "Mueller", 3},
    {19, "Merrill", "Gilmore", 2}
};
EMPLOYEE g_team2[TEAM_SIZE] = {
    {14, "Shellie", "Soto", 1},
    {23, "Carson", "Ayala", 1},
    {5, "Orla", "Wyatt", 1},
    {11, "Neville", "Berg", 1},
    {10, "Macy", "Cotton", 2},
    {6, "Emi", "Stafford", 0}
};
EMPLOYEE g_team3[TEAM_SIZE] = {
    {20, "Austin", "William", 1},
    {2, "Dana", "Stephenson", 0},
    {22, "Amery", "Bridges", 1},
    {18, "Mollie", "Hester", 1},
    {24, "Brent", "Molina", 2},
    {15, "Bradley", "Ortiz", 0}
};
EMPLOYEE g_team4[TEAM_SIZE] = {
    {17, "Maia", "Mccullough", 3},
    {16, "India", "Calhoun", 2},
    {12, "Nathaniel", "Solis", 3},
    {13, "Drake", "Leach", 1},
    {9, "May", "Bowers", 1},
    {21, "Maxine", "Marquez", 2}
};
    
// Certifications
CERTIFICATION g_certifications[20] = {
    {9, 4},
    {4, 0},
    {5, 3},
    {8, 4},
    {13, 7},
    {3, 1},
    {1, 5},
    {10, 1},
    {6, 4},
    {7, 2},
    {16, 0},
    {11, 6},
    {15, 2},
    {12, 3},
    {2, 5},
    {14, 1}
};

EMPLOYEE g_employees[TEAM_SIZE * TEAM_COUNT];

int main()
{
    /*
        Program flow:
        Print title
            Program loop
                Print menu
                Get menu option
                    1. Print employee list 
                        Merge sort each team in order of surname
                        Merge teams to employees
                        Print employee list
                    2. Print certified employees (option 1 must be selected first)
                        Create a list of certs for all 3 lines (value: 7)
                        For each cert, take the employee id and find the employee in the employees list 
                            Print the employee name
                    3. Search employees by surname (option 1 must be selected first)
                            Use binary search to find the employee
                            print the employeeID, firstName, surname, line
                    4. Exit
    */    
    // Variables

    int userInput = 0;
    
    PrintTitle();
    
    // Program loop
    while (userInput != 4)
    {

        PrintMenu();
        printf("> ");
        scanf("%d", &userInput);
        while (getchar() != '\n');
        switch (userInput)
        {
            case 1:
            {
                EMPLOYEE *teams[4] = {g_team1, g_team2, g_team3, g_team4}; // Put the 4 teams of employees into one array
                MergeTeams(g_employees, teams, TEAM_SIZE, TEAM_COUNT); // Merge the 4 teams into one array
                // PrintEmployeeList(g_employees, TEAM_SIZE * TEAM_COUNT);
                break;

            }
            case 2:
                // PrintEmployeesCertifiedForAllLines(g_employees, TEAM_SIZE * TEAM_COUNT);
                break;
            case 3:
                // SearchEmployeesBySurname(g_employees, TEAM_SIZE * TEAM_COUNT);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input, please try again\n");
                break;
        }
    }
}
    

// int main()
// {
//     // Combine the 4 teams of employees into one array
//     EMPLOYEE *teams[4] = {g_team1, g_team2, g_team3, g_team4}; // Put the 4 teams of employees into one array
//     for (int i = 0; i < 4; i++)
//     {
//         // Each team
//         for (int j = 0; j < 4; j++)
//         {
//             // Each employee
//             g_employees[i + j * 4].employeeID = teams[i][j].employeeID;
//             strncpy(g_employees[i + j * 4].firstName, teams[i][j].firstName, sizeof(teams[i][j].firstName));
//             strncpy(g_employees[i + j * 4].surname, teams[i][j].surname, sizeof(teams[i][j].surname));
//             g_employees[i + j * 4].line = teams[i][j].line;
//         }
//     }

//     // Print all employees
//     printf("\nEmployees:\n");
//     for (int i = 0; i < 16; i++)
//     {
//         printf("%3d,%30s,%30s,%d\n", g_employees[i].employeeID, g_employees[i].firstName, g_employees[i].surname, g_employees[i].line);
//     }

//     // Sort employees by surname using insertion sort by moving the pointers 
//     for (int i = 1; i < 16; i++)
//     {
//         EMPLOYEE key = g_employees[i];
//         int j = i - 1;
//         while (j >= 0 && strcmp(g_employees[j].surname, key.surname) > 0)
//         {
//             g_employees[j + 1] = g_employees[j];
//             j--;
//         }
//         g_employees[j + 1] = key;
//     }

//     // Print all employees
//     printf("\nEmployees:\n");
//     for (int i = 0; i < 16; i++)
//     {
//         printf("%3d,%30s,%30s,%d\n", g_employees[i].employeeID, g_employees[i].firstName, g_employees[i].surname, g_employees[i].line);
//     }

//     return 0;
// }

/* Menu functions */

// Print the title
void PrintTitle()
{
    printf("\n================================================================\n");
    printf("\n%*s%s\n", (int)((64 - strlen("Employee Certification Database")) / 2), "", "Employee Certification Program");
    printf("\n================================================================\n");
}
void PrintMenu()
{
    printf("\n================================================================\n");
    printf("\n%*s%s\n", (int)((64 - strlen("==== Main Menu ====")) / 2), "", "==== Main Menu ====");
    printf("(1) Print all employees\n");
    printf("(2) Print all employees certified for all lines\n");
    printf("(3) Search employees by surname\n");
    printf("(4) Quit\n");
}

/* Utility functions */
void MergeTeams(EMPLOYEE *employees, EMPLOYEE **teams, int teamSize, int teamCount)
{
    for (int i = 0; i < teamCount; i++)
    {
        // Each team
        for (int j = 0; j < teamSize; j++)
        {
            // Each employee
            employees[i + j * 4].employeeID = teams[i][j].employeeID;
            strncpy(employees[i + j * 4].firstName, teams[i][j].firstName, sizeof(teams[i][j].firstName));
            strncpy(employees[i + j * 4].surname, teams[i][j].surname, sizeof(teams[i][j].surname));
            employees[i + j * 4].line = teams[i][j].line;
        }
    }
}