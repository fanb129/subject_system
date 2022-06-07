//
// Created by fanb on 2022/5/31.
//

#include "mysql_app.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

MYSQL *connection = NULL;
MYSQL mysql;

// 初始化连接数据库
int initDB(const char *hostname, const char *username, const char *password,const char *dbname){
    mysql_init(&mysql); // 初始化MySQL
    if (connection){
        mysql_close(connection);
    }
    connection = mysql_real_connect(&mysql, hostname, username, password,dbname, 0, 0, 0); //连接到mysql

    if (connection == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return -1;//连接失败，返回-1
    }

    //printf("success connect to lib\n");
    return 0;

}
// 断开数据库
void closeDB(){
    if (connection)
    {
        mysql_close(connection);
        connection = NULL;
    }
}

// 执行有返回数据的sql 查
int openDB(const char *sql){
    mysql_query(connection, "set names utf8");
    int state = mysql_query(connection, sql);
    if(state != 0){
        printf("%s\n", mysql_error(connection));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(connection); // 得到查询寻结果
    if(result == (MYSQL_RES *)NULL){
        printf("%s\n", mysql_error(connection));
        return -1;
    }else{
        MYSQL_FIELD *sqlField;
        int iFieldCount = 0;
        while(1){ // 遍历所有字段
            sqlField = mysql_fetch_field(result);
            if(sqlField == NULL){
                break;
            }
            printf("%s\t",sqlField->name); // 字段名
            iFieldCount++;
        }
        printf("\n");

        MYSQL_ROW sqlRow;
        while(1){ // 遍历每一行
            sqlRow = mysql_fetch_row(result);
            if(sqlRow == NULL) break;
            int i;
            for(i = 0;i < iFieldCount;i++){
                if(sqlRow[i] == NULL){
                    printf("NULL\t");
                }else{
                    printf("%s\t",(const char *)sqlRow[i]);
                }
            }
            printf("\n");
        }
       // printf("query is ok,%u rows affected\n",(unsigned int ) mysql_affected_rows(connection));
        mysql_free_result(result);
    }
    return 0;
}

// 执行没有返回数据的sql 增删改
int execDB(const char *sql){
    mysql_query(connection, "set names utf8");
    int state = mysql_query(connection, sql);
    if(state != 0){
        printf("%s\n", mysql_error(connection));
        return -1;
    }
    //printf("query is ok,%u rows affected\n",(unsigned int) mysql_affected_rows(connection));
    return 0;
}

// student查询
int selectStudent(const char *sql,struct student *stu){
    mysql_query(connection, "set names utf8");
    int state = mysql_query(connection, sql);
    if(state != 0){
        printf("%s\n", mysql_error(connection));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(connection); // 得到查询寻结果
    int len = (int) mysql_affected_rows(connection);

    if(result == (MYSQL_RES *)NULL){
        printf("%s\n", mysql_error(connection));
        return -1;
    }else{
        MYSQL_ROW sqlRow;
        int j;
        for(j = 0;j < len;j++){ // 遍历每一行
            sqlRow = mysql_fetch_row(result);
            if(sqlRow == NULL) break;
            int i;
            for(i = 0;i < 4;i++){ // 将所有字段写入stu数组
                if(i == 0){
                    stu[j].sno = (char *)sqlRow[i];
                }else if(i == 1){
                    stu[j].sname = (char *)sqlRow[i];
                }else if(i ==2){
                    stu[j].sex = (char *)sqlRow[i];
                }else if(i == 3){
                    stu[j].password = (char *)sqlRow[i];
                }
            }
        }
        mysql_free_result(result);
    }
    return len;
}

// teacher查询
int selectTeacher(const char *sql,struct teacher *tea){
    mysql_query(connection, "set names utf8");
    int state = mysql_query(connection, sql);
    if(state != 0){
        printf("%s\n", mysql_error(connection));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(connection); // 得到查询寻结果
    int len = (int) mysql_affected_rows(connection);

    if(result == (MYSQL_RES *)NULL){
        printf("%s\n", mysql_error(connection));
        return -1;
    }else{
        MYSQL_ROW sqlRow;
        int j;
        for(j = 0;j < len;j++){ // 遍历每一行
            sqlRow = mysql_fetch_row(result);
            if(sqlRow == NULL) break;
            int i;
            for(i = 0;i < 4;i++){ // 将所有字段写入stu数组
                if(i == 0){
                    tea[j].tno = (char *)sqlRow[i];
                }else if(i == 1){
                    tea[j].tname = (char *)sqlRow[i];
                }else if(i ==2){
                    tea[j].tsex = (char *)sqlRow[i];
                }else if(i == 3){
                    tea[j].password = (char *)sqlRow[i];
                }
            }
        }
        mysql_free_result(result);
    }
    return len;
}

// course查询
int selectCourse(const char *sql,struct course *cou){
    mysql_query(connection,"set names utf8");
    int state = mysql_query(connection,sql);
    if(state != 0){
        printf("%s\n", mysql_error(connection));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(connection); // 得到查询寻结果
    int len = (int) mysql_affected_rows(connection);

    if(result == (MYSQL_RES *)NULL){
        printf("%s\n", mysql_error(connection));
        return -1;
    }else{
        MYSQL_ROW sqlRow;
        int j;
        for(j = 0;j < len;j++){
            sqlRow = mysql_fetch_row(result);
            if(sqlRow == NULL) break;
            int i;
            for(i = 0;i < 3;i++){
                if(i == 0){
                    cou[j].cno = (char *)sqlRow[i];
                }else if(i == 1){
                    cou[j].cname = (char *)sqlRow[i];
                }else if(i == 2){
                    cou[j].tno = (char *)sqlRow[i];
                }
            }
        }
        mysql_free_result(result);
    }
    return len;
}

// sc查询
int selectSc(const char *sql,struct sc *sc){
    mysql_query(connection,"set names utf8");
    int state = mysql_query(connection,sql);
    if(state != 0){
        printf("%s\n", mysql_error(connection));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(connection); // 得到查询寻结果
    int len = (int) mysql_affected_rows(connection);

    if(result == (MYSQL_RES *)NULL){
        printf("%s\n", mysql_error(connection));
        return -1;
    }else{
        MYSQL_ROW sqlRow;
        int j;
        for(j = 0;j < len;j++){
            sqlRow = mysql_fetch_row(result);
            if(sqlRow == NULL) break;
            int i;
            for(i = 0;i < 3;i++){
                if(i == 0){
                    sc[j].sno = (char *)sqlRow[i];
                }else if(i == 1){
                    sc[j].cno = (char *)sqlRow[i];
                }else if(i == 2){
                    sc[j].grade = (char *) sqlRow[i];
                }
            }
        }
        mysql_free_result(result);
    }
    return len;
}