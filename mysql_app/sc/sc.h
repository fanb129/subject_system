//
// Created by fanb on 2022/6/1.
//

#ifndef SUBJECT_SYSTEM_SC_H
#define SUBJECT_SYSTEM_SC_H

struct sc{
    char *sno;
    char *cno;
    char *grade;
};

// 根据sno查询sc
int queryScBySno(struct sc *sc,char *sno);

// 根据cno查询sc
int queryScByCno(struct sc *sc,char *cno);

int addSc(struct sc sc);

int deleteSc(char *sno,char *cno);

int changeGrade(char *sno,char *cno,char *grade);

#endif //SUBJECT_SYSTEM_SC_H
