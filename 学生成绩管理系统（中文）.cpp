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
struct Student students[MAX_STUDENTS];//定义一个存储学生信息的数组
int num_students = 0;//跟踪当前存储在数组中的学生数量
void addStudent() { 
if(num_students < MAX_STUDENTS) { 
printf("输入学生姓名: ");
scanf("%s", students[num_students].name); 
printf("输入学生学号: "); 
scanf("%d", &students[num_students].id); 
printf("输入学生班级: "); 
scanf("%s", students[num_students].className); 
printf("输入数学成绩: "); 
scanf("%f", &students[num_students].mathMarks); 
printf("输入英语成绩: "); 
scanf("%f", &students[num_students].englishMarks); 
printf("输入计算机成绩: "); 
scanf("%f", &students[num_students].computerMarks); 
students[num_students].totalMarks=students[num_students].mathMarks+students[num_students].englishMarks+students[num_students].computerMarks; 
num_students++;} 
else { printf("无法加入更多的学生\n"); } }
void deleteStudentByStudentID(int studentID) {
int index = -1;
for (int i = 0; i < num_students; i++) {
if (students[i].id == studentID) {
index = i;
break;}}
if (index != -1) {
for (int j = index; j < num_students - 1; j++) {
students[j] = students[j + 1];}// 将下一个学生信息移到当前位置
num_students--; // 更新学生数量
printf("学号为%d的学生信息已删除\n", studentID);
} else {printf("学号为%d的学生未找到\n", studentID);}}
void calculateAverageTotalMarks() { 
if (num_students == 0) { 
printf("学生还未添加\n"); 
} else { 
for (int i = 0; i < num_students; i++) { 
printf("学生: %s\n", students[i].name); 
printf("总成绩: %.2f\n", students[i].totalMarks); 
printf("平均成绩: %.2f\n", students[i].totalMarks / 3); } } }
int main(){
int choice; 
do { printf("1. 添加学生\n");
printf("2. 删除学生\n"); 
printf("3. 计算平均成绩和总成绩\n"); 
printf("4. 退出\n"); 
printf("输入你的选择: "); 
scanf("%d", &choice); 
switch(choice) { 
case 1: addStudent(); break;
case 2: {
int studentID;
printf("输入要删除的的学生学号: ");
scanf("%d", &studentID);
deleteStudentByStudentID(studentID);break;}
case 3: calculateAverageTotalMarks(); break; 
case 4: break;
default: 
printf("请重试\n"); } 
} while (choice != 4); 
return 0; }

