#include "function.h"
#include <stdio.h>
#include <string.h>
//Logic ham
void printMenu(){
	printf("\t***Student Management System using C***\n");
	printf("CHOOSE YOUR ROLE\n");
	printf("========================\n");
	printf("[1] Admin.\n");
	printf("[2] Student.\n");
	printf("[3] System.\n");
	printf("[0] Exit the program.\n");
	printf("========================\n");
	printf("ENTER THE CHOICE\n");
}

void printMenustudent(){
	printf("\n\t***Student Management System using C***\n");
	printf("STUDENT MENU\n");
	printf("========================\n");
	printf("[1] Add a new student.\n");
	printf("[2] Show all students.\n");
	printf("[3] Edit a student.\n");
	printf("[4] Search a student.\n");
	printf("[5] Delete a student.\n");
	printf("[6] Sap xep.\n"); 
	printf("[0] Exit the program.\n");
	printf("========================\n");
	printf("ENTER THE CHOICE\n");
}

struct Student students[50];

void showAll(struct Student students[50], int n){
	   	printf("|====|============|====================|====================|==============|\n");
	    printf("| ID |  No.Course |       Name         |      Email         |    Phone     |\n");
	    printf("|====|============|====================|====================|==============|\n");
	int i;
    for (i = 0; i < n; i++) {
        printf("| %-2s | %-10s | %-18s | %-18s | %-12d |\n",
            students[i].ID, students[i].numberOfCourse, students[i].Name,
		    students[i].Email, students[i].Phone);
    }
    	printf("|====|============|====================|====================|==============|\n");
}
void addStudent(struct Student *std) {
    fflush(stdin);
    printf("Nhap ID: ");
    fgets(std->ID, sizeof(std->ID), stdin);
    std->ID[strcspn(std->ID, "\n")] = '\0';
    printf("Nhap ma lop hoc: ");
    fgets(std->numberOfCourse, sizeof(std->numberOfCourse), stdin);
    std->numberOfCourse[strcspn(std->numberOfCourse, "\n")] = '\0';
    printf("Nhap ten: ");
    fgets(std->Name, sizeof(std->Name), stdin);
    std->Name[strcspn(std->Name, "\n")] = '\0';
    printf("Nhap email: ");
    fgets(std->Email, sizeof(std->Email), stdin);
    std->Email[strcspn(std->Email, "\n")] = '\0';
    printf("Nhap so dien thoai: ");
    fgets(std->Phone, sizeof(std->Phone), stdin);
    std->Phone[strcspn(std->Phone, "\n")] = '\0';
    printf("Da them sinh vien thanh cong\n");
}
void editInformation() {
    char ID[100];
    int i; 
    printf("\nNhap ID muon sua: ");
    scanf("%s", ID);

    int found = -1;
    int n = 3; 
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].ID, ID) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Sinh vien voi ID %s khong tim thay.\n", ID);
        return;
    }

    struct Student *student = &students[found];
    printf("\nSua thong tin sinh vien %s\n", student-> Name);
    printf("Ma lop hoc: ", student->numberOfCourse);
    scanf("%d", &student->numberOfCourse);
    getchar();

    printf("Ten: ", student->Name);
    getchar(); 
    fgets(student->Name, sizeof(student->Name), stdin);
    student->Name[strcspn(student->Name, "\n")] = '\0';


    printf("Email: ", student->Email);
    scanf("%s", student->Email);

    printf("So dien thoai: ", student->Phone);
    scanf("%s", student->Phone);
    printf("Student information updated successfully.\n");

}
void sort_Student_i_or_d(struct Student students[100],int n){
	struct Student temp;
	int check = 0;
	char choice;
	do{
		printf("Chon cach muon sap xep : \n");
		printf("\n\t\t[1]. Increase\n");
		printf("\t\t[2]. Decrease\n");
		printf("\n\tLua chon cua ban : ");
	    //while(getchar() != '\n');
	    //getchar();
	    fflush(stdin);
		scanf("%c", &choice);
	}
	while(choice != '1' && choice != '2');
	check = (choice == '1'? 1 : 0);
	int a, b; 
	for(a=0;a<n-1;a++){
		for(b=a+1;b<n;b++){
			if(check ? strcmp(students[a].Name, students[b].Name)>0:
			           strcmp(students[a].Name,students[b].Name)<0){
					   temp = students[a];
					   students[a]=students[b];
					   students[b]=temp;
			}
		}
	}
	printf("\nDanh sach sau khi sap xep: \n");
	printf("|====|============|====================|====================|==============|\n");
	printf("| ID |  No.Course |       Name         |      Email         |    Phone     |\n");
	printf("|====|============|====================|====================|==============|\n");
	int i;
    for(i = 0; i < n; i++){
       printf("| %-2s | %-10s | %-18s | %-18s | %-12d |\n",
            students[i].ID, students[i].numberOfCourse, students[i].Name,
		    students[i].Email, students[i].Phone);
    }
    printf("|====|============|====================|====================|==============|\n");
    back_or_exit();
}
void back_or_exit(){
	char choice;
	printf("\tGo back (b) or Exit (0) ?: ");
	getchar();
	scanf("%c", &choice);
	if (choice == '0'){
		printf("Exiting program\n");
		exit(0);
	} else if(choice == 'b'){
		printMenustudent();
	} else {
		printf("Invalid choice");
	}
}


