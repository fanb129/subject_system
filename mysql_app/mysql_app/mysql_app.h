//
// Created by fanb on 2022/5/31.
//

#ifndef TEST_MYSQL_APP_H
#define TEST_MYSQL_APP_H
#include "../student/student.h"
#include "../teacher/teacher.h"
#include "../course/course.h"
#include "../sc/sc.h"
// 初始化连接数据库
int initDB(const char *hostname, const char *username, const char *password,const char *dbname);
// 断开数据库
void closeDB();

// 执行有返回数据的sql 查
int openDB(const char *sql);
// 执行没有返回数据的sql 增删改
int execDB(const char *sql);

// student查询
int selectStudent(const char *sql, struct student *stu);

// teacher查询
int selectTeacher(const char *sql, struct teacher *tea);

// course查询
int selectCourse(const char *sql,struct course *cou);

// sc查询
int selectSc(const char *sql,struct sc *sc);


#endif //TEST_MYSQL_APP_H
