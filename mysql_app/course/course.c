//
// Created by fanb on 2022/6/1.
//

#include "course.h"
#include "../mysql_app/mysql_app.h"
#include <stdio.h>

// 查看所有课程
int queryCourse(struct course *cou){
    int len = selectCourse("select * from course",cou);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",cou[i].cno,cou[i].cname,cou[i].tno);
    }
    return len;
}

// 根据老师搜索课程
int queryCourseByTno(struct course *cou,char *tno){
    char sql[100];
    sprintf(sql,"select * from course where tno='%s'",tno);
    printf("%s\n",sql);
    int len = selectCourse(sql,cou);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",cou[i].cno,cou[i].cname,cou[i].tno);
    }
    return len;
}
// 添加课程
int addCourse(struct course cou){
    char sql[100];
    sprintf(sql,"insert into course values('%s','%s','%s')",cou.cno,cou.cname,cou.tno);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}
// 删除课程
int deleteCourse(char *cno){
    char sql[100];
    sprintf(sql,"delete from course where cno='%s'",cno);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}