//
// Created by fanb on 2022/6/1.
//

#include "teacher.h"
#include <stdio.h>
#include <string.h>
#include "../mysql_app/mysql_app.h"

// 教师登录
int loginTeacher(char *tno, char *password){
    char sql[100];
    sprintf(sql,"select * from teacher where tno='%s'",tno);
    printf("%s\n",sql);
    struct teacher tea[1] = {};
    selectTeacher(sql, tea);
    int rs = strcmp(password,tea[0].password);
    return rs;
}

// 查看所有教师
int queryTeacher(struct teacher *tea){
//    struct teacher tea[100] = {};
    int len = selectTeacher("select * from teacher",tea);
    int i;
    for(i = 0; i < 0;i++){
        printf("%s\t%s\t%s\n",tea[i].tno,tea[i].tname,tea[i].tsex);
    }
    return len;
}

//根据tno搜索教师
int queryTeacherByTno(struct teacher *tea,char *tno){
    char sql[100];
    sprintf(sql,"select * from teacher where tno='%s'",tno);
    printf("%s\n",sql);
//    struct teacher tea[1] = {};
    int len = selectTeacher(sql,tea);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",tea[i].tno,tea[i].tname,tea[i].tsex);
    }
}

//根据tname搜索教师
int queryTeacherByTname(struct teacher *tea,char *tname){
    char sql[100];
    sprintf(sql,"select * from teacher where tname='%s'",tname);
    printf("%s\n",sql);
//    struct teacher tea[100] = {};
    int len;
    len = selectTeacher(sql,tea);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",tea[i].tno,tea[i].tname,tea[i].tsex);
    }
    return len;
}

// 教师注册
int addTeacher(struct teacher tea){
    char sql[100];
    sprintf(sql,"insert into teacher values('%s','%s','%s','%s')",tea.tno,tea.tname,tea.tsex,tea.password);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}

//删除教师
int deleteTeacher(char *tno){
    char sql[100];
    sprintf(sql,"delete from teacher where tno='%s'",tno);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}