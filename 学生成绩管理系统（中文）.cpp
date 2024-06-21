#include <stdio.h> 
#define MAX_STUDENTS 50 
struct Student {
char name[50]; 
int id; 
char className[50];
float mathMarks;
float englishMarks; 
float computerMarks; 
float totalMarks; };
struct Student students[MAX_STUDENTS];//����һ���洢ѧ����Ϣ������
int num_students = 0;//���ٵ�ǰ�洢�������е�ѧ������
void addStudent() { 
if(num_students < MAX_STUDENTS) { 
printf("����ѧ������: ");
scanf("%s", students[num_students].name); 
printf("����ѧ��ѧ��: "); 
scanf("%d", &students[num_students].id); 
printf("����ѧ���༶: "); 
scanf("%s", students[num_students].className); 
printf("������ѧ�ɼ�: "); 
scanf("%f", &students[num_students].mathMarks); 
printf("����Ӣ��ɼ�: "); 
scanf("%f", &students[num_students].englishMarks); 
printf("���������ɼ�: "); 
scanf("%f", &students[num_students].computerMarks); 
students[num_students].totalMarks=students[num_students].mathMarks+students[num_students].englishMarks+students[num_students].computerMarks; 
num_students++;} 
else { printf("�޷���������ѧ��\n"); } }
void deleteStudentByStudentID(int studentID) {
int index = -1;
for (int i = 0; i < num_students; i++) {
if (students[i].id == studentID) {
index = i;
break;}}
if (index != -1) {
for (int j = index; j < num_students - 1; j++) {
students[j] = students[j + 1];}// ����һ��ѧ����Ϣ�Ƶ���ǰλ��
num_students--; // ����ѧ������
printf("ѧ��Ϊ%d��ѧ����Ϣ��ɾ��\n", studentID);
} else {printf("ѧ��Ϊ%d��ѧ��δ�ҵ�\n", studentID);}}
void calculateAverageTotalMarks() { 
if (num_students == 0) { 
printf("ѧ����δ���\n"); 
} else { 
for (int i = 0; i < num_students; i++) { 
printf("ѧ��: %s\n", students[i].name); 
printf("�ܳɼ�: %.2f\n", students[i].totalMarks); 
printf("ƽ���ɼ�: %.2f\n", students[i].totalMarks / 3); } } }
int main(){
int choice; 
do { printf("1. ���ѧ��\n");
printf("2. ɾ��ѧ��\n"); 
printf("3. ����ƽ���ɼ����ܳɼ�\n"); 
printf("4. �˳�\n"); 
printf("�������ѡ��: "); 
scanf("%d", &choice); 
switch(choice) { 
case 1: addStudent(); break;
case 2: {
int studentID;
printf("����Ҫɾ���ĵ�ѧ��ѧ��: ");
scanf("%d", &studentID);
deleteStudentByStudentID(studentID);break;}
case 3: calculateAverageTotalMarks(); break; 
case 4: break;
default: 
printf("������\n"); } 
} while (choice != 4); 
return 0; }

