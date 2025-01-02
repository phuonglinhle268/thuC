#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int totalStudents = 0;
int totalCourse = 0;
int exist(const char *value, char type, const char *studentID);
struct Student students[50] = {
	{"1", "2", "Le Van A", "jshfn@gmail.com", "12345"},
	{"2", "3", "Le Van B", "ksdsl@gmail.com", "23456"},
	{"3", "4", "Le Van C", "sncsd@gmail.com", "34567"}
};
int n = 3;
struct Course courses[50];

int main(int argc, char *argv[]) {
	int choice;
	int option; 
	do{
		printMenu();
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				break;
			case 2:
				do{
					system("cls");
					printMenustudent();
					printf("Nhap lua chon: ");
					scanf("%d", &option);
					switch(option){
						case 1:
							system("cls");
						    addStudent(students);
							back_or_exit();		
		    				break;
						case 2:
							system("cls");
						    showAll(students,n);
							back_or_exit();						
							break;
						case 3:
							system("cls");
							editInformation();
							back_or_exit();	
							break;
						case 4:
							break;
						case 6:
						    system("cls");
                    	    sort_Student_i_or_d(students,n);
                    	    break; 
						case 7:
						    printf("EXIT THE PROGRAM\n");
							break;
						default:
						    printf("Lua chon khong hop le. Chon lai\n"); 
					}
				} while (option != 8);
				break;
			case 3:
				break;
			case 4:
				printf("EXIT YOUR CHOICE\n");
				break;
			default:
				printf("Lua chon khong hop li. Hay chon lai\n");
		}
	} while (choice != 5);
	return 0; 
}
