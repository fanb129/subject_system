//
// Created by fanb on 2022/6/2.
//

#include "loginWindow.h"
#include <stdio.h>
#include <string.h>
#include "../../mysql_app/teacher/teacher.h"
#include "../../mysql_app/student/student.h"
#include "../../mysql_app/mysql_app/mysql_app.h"
#include "../mainWindow/mainWindow.h"
#include "../teacher/teacherWindow.h"
#include "../root/rootWindow.h"
#include "../student/studentWindow.h"

GtkWidget  *loginNo;
GtkWidget  *loginPassword;

// 登录回调函数
void login(GtkWidget *widget,gpointer data){
    const char *getGno = gtk_entry_get_text(GTK_ENTRY(loginNo));
    const char *getGpassword = gtk_entry_get_text(GTK_ENTRY(loginPassword));
    char no[100];
    char password[100];
    gint rs;
    strcpy(no,getGno);
    strcpy(password,getGpassword);
    if(strcmp("root",no) == 0){ //管理员登录
        rs = loginTeacher(no,password);
        if(rs == 0){
            printf("login success\n");
            rootWindowInit();
            gtk_widget_hide_all(loginWindow);
            gtk_widget_show_all(rootWindow);
        }
    }else if(no[0] == 's'){ // 学生登录
        rs = loginStudent(no,password);
        if(rs == 0){
            printf("login success\n");
            studentWindowInit(no);
            gtk_widget_hide_all(loginWindow);
            gtk_widget_show_all(studentWindow);
        }
    }else if(no[0] == 't'){ // 教师登录
        rs = loginTeacher(no,password);
        if(rs == 0){
            printf("login success\n");
            teacherWindowInit(no);
            gtk_widget_hide_all(loginWindow);
            gtk_widget_show_all(teacherWindow);
        }
    }
}

// 返回上一级回调函数
void loginBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(loginWindow);
    gtk_widget_show_all(mainWindow);
}

// 登录窗口
void loginWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; // 纵向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = "login";

    loginWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(loginWindow),title);
    gtk_widget_set_usize(loginWindow,400,400);
    g_signal_connect(GTK_OBJECT(loginWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(loginWindow),vbox);

    // 账号no
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("no:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    loginNo = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(loginNo),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, loginNo, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 密码password
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("password:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    loginPassword = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(loginPassword),FALSE);
    gtk_box_pack_start((GtkBox *) hbox, loginPassword, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    button = gtk_button_new_with_label("login");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(login),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(loginBack),"entry");
}