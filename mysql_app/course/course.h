//
// Created by fanb on 2022/6/1.
//

#ifndef SUBJECT_SYSTEM_COURSE_H
#define SUBJECT_SYSTEM_COURSE_H

struct course{
    char *cno;
    char *cname;
    char *tno;
};

// 查看所有课程
int queryCourse(struct course *cou);

// 根据老师搜索课程
int queryCourseByTno(struct course *cou,char *tno);

int addCourse(struct course cou);

int deleteCourse(char *cno);
#endif //SUBJECT_SYSTEM_COURSE_H
