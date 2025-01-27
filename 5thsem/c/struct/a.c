#include<stdio.h>

struct student{
    int reg;
    char name[80];
    float cgpa;
}; 

int main(){
    struct student students[3];
    
    for(int i=0; i<3; i++){
	scanf("%d %s %f",&students[i].reg,students[i].name, &students[i].cgpa);
    }
    printf("-----------------------------------------------------------------\n");
    printf("| Regd\t| Name\t\t| CGPA\t| Address\t\t| Size\t|\n");
    for(int i=0; i<3; i++){
	    printf("| %d\t| %s\t| %.2f\t| %p\t| %lu\t|\n",students[i].reg, students[i].name, students[i].cgpa, &students[i], sizeof(students[i]));
    }
    printf("-----------------------------------------------------------------\n");

   
    return 0;

}
