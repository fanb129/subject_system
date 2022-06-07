//
// Created by fanb on 2022/6/1.
//

#include "student.h"
#include <string.h>
#include <stdio.h>
#include "../mysql_app/mysql_app.h"

// 登录
int loginStudent(char *sno,char *password){
    char sql[100];
    sprintf(sql,"select * from student where sno='%s'",sno);
    printf("%s\n",sql);
    struct student stu[1] = {};
    selectStudent(sql,stu);
    int rs = strcmp(password,stu[0].password);
    return rs;
}

// 查看所有学生
int queryStudent(struct student *stu){
//    struct student stu[100] = {};
    int len = selectStudent("select * from student", stu);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",stu[i].sno,stu[i].sname,stu[i].sex);
    }
    return len;
}

// 根据sno搜索学生
int queryStudentBySno(struct student *stu,char *sno){
    char sql[100];
    sprintf(sql,"select * from student where sno='%s'",sno);
    printf("%s\n",sql);
//    struct student stu[1] = {};
    int len = selectStudent(sql,stu);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",stu[i].sno,stu[i].sname,stu[i].sex);
    }
    return len;
}

// 根据名字搜索学生
int queryStudentBySname(struct student *stu,char *sname){
    char sql[100];
    sprintf(sql,"select * from student where sname='%s'",sname);
    printf("%s\n",sql);
//    struct student stu[1] = {};
    int len = selectStudent(sql,stu);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",stu[i].sno,stu[i].sname,stu[i].sex);
    }
    return len;
}

// 注册添加
int addStudent(struct student stu){
    char sql[100];
    sprintf(sql,"insert into student values('%s','%s','%s','%s')",stu.sno,stu.sname,stu.sex,stu.password);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}

// 删除学生
int deleteStudent(char *sno){
    char sql[100];
    sprintf(sql,"delete from student where sno='%s'",sno);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}