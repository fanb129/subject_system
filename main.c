#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include "mysql_app/mysql_app/mysql_app.h"
#include "mysql_app/student/student.h"
#include <gtk/gtk.h>
#include "gtk_app/mainWindow/mainWindow.h"
#include "gtk_app/loginWindow/loginWindow.h"
#include "gtk_app/registerWindow/registerWindow.h"



#define HOST "localhost"       // MySQL主机地址
#define USERNAME "root"             // 用户名
#define PASSWORD "123456"         // 密码
#define DATABASE "subject_system"   // 连接的数据库

int main(int argc,char *argv[]) {
    // 初始化连接数据库
    int rs = initDB(HOST, USERNAME,PASSWORD,DATABASE);
    if(rs != 0){
        printf("initDB err\n");
        return 1;
    }
    //初始化gtk
    gtk_init(&argc,&argv);
    mainWindowInit(); // 主窗口
    loginWindowInit(); // 登录窗口
    registerWindowInit(); // 注册窗口

    gtk_widget_show_all(mainWindow);
    gtk_main();

    // 断开数据库
    closeDB();
    //rs = loginStudent("s1001","123");
//    struct student stu = {"s1002","李四","女","123"};
//    rs = addStudent(stu);

    //rs = deleteStudent("s1002");
   // printf("%d",rs);
    return 0;
}
