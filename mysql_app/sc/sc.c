//
// Created by fanb on 2022/6/1.
//

#include "sc.h"
#include "../mysql_app/mysql_app.h"
#include <stdio.h>


// 根据sno查询sc
int queryScBySno(struct sc *sc,char *sno){
    char sql[100];
    sprintf(sql,"select * from sc where sno='%s'",sno);
    printf("%s\n",sql);

    int len = selectSc(sql,sc);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",sc[i].sno,sc[i].cno,sc[i].grade);
    }
    return len;
}

// 根据cno查询sc
int queryScByCno(struct sc *sc,char *cno){
    char sql[100];
    sprintf(sql,"select * from sc where cno='%s'",cno);
    printf("%s\n",sql);

    int len = selectSc(sql,sc);
    int i;
    for(i = 0;i < len;i++){
        printf("%s\t%s\t%s\n",sc[i].sno,sc[i].cno,sc[i].grade);
    }
    return len;
}
// 添加选课
int addSc(struct sc sc){
    char sql[100];
    sprintf(sql,"insert into sc values('%s','%s','%s')",sc.sno,sc.cno,sc.grade);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}
//退选
int deleteSc(char *sno,char *cno){
    char sql[100];
    sprintf(sql,"delete from sc where sno='%s' and cno='%s'",sno,cno);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}
//登陆成绩
int changeGrade(char *sno,char *cno,char *grade){
    char sql[100];
    sprintf(sql,"update sc set grade='%s' where sno='%s' and cno='%s'",grade,sno,cno);
    printf("%s\n",sql);
    int res = execDB(sql);
    return res;
}
