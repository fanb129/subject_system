//
// Created by fanb on 2022/6/1.
//

#ifndef SUBJECT_SYSTEM_STUDENT_H
#define SUBJECT_SYSTEM_STUDENT_H

// 定义student结构体
struct student{
    char *sno;
    char *sname;
    char *sex;
    char *password;
};

// 登录
int loginStudent(char *sno,char *password);

// 查看所有学生
int queryStudent(struct student *stu);

// 根据sno搜索学生
int queryStudentBySno(struct student *stu,char *sno);

// 根据名字搜索学生
int queryStudentBySname(struct student *stu,char *sname);

// 注册添加
int addStudent(struct student stu);

// 删除学生
int deleteStudent(char *sno);

#endif //SUBJECT_SYSTEM_STUDENT_H
