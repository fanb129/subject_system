//
// Created by fanb on 2022/6/1.
//

#ifndef SUBJECT_SYSTEM_TEACHER_H
#define SUBJECT_SYSTEM_TEACHER_H

struct teacher{
    char *tno;
    char *tname;
    char *tsex;
    char *password;
};

// 教师登录
int loginTeacher(char *tno,char *password);

// 查看所有教师
int queryTeacher(struct teacher *tea);

//根据tno搜索教师
int queryTeacherByTno(struct teacher *tea,char *tno);

//根据tname搜索教师
int queryTeacherByTname(struct teacher *tea,char *tname);

//添加教师
int addTeacher(struct teacher tea);

//删除教师
int deleteTeacher(char *tno);
#endif //SUBJECT_SYSTEM_TEACHER_H
