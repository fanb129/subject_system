//
// Created by fanb on 2022/6/3.
//

#include "registerWindow.h"
#include "../../mysql_app/student/student.h"
#include "../../mysql_app/teacher/teacher.h"
#include "../mainWindow/mainWindow.h"
#include "../loginWindow/loginWindow.h"

GtkWidget  *registerNo;
GtkWidget  *registerPassword;
GtkWidget *registerName;
GtkWidget *registerSex;
// 注册回调函数
void doregister(GtkWidget *widget,gpointer data){
    const char *getGno = gtk_entry_get_text(GTK_ENTRY(registerNo));
    const char *getGname = gtk_entry_get_text(GTK_ENTRY(registerName));
    const char *getGsex = gtk_entry_get_text(GTK_ENTRY(registerSex));
    const char *getGpassword = gtk_entry_get_text(GTK_ENTRY(registerPassword));
    char no[100];
    char name[100];
    char sex[100];
    char password[100];
    gint rs;
    strcpy(no,getGno);
    strcpy(name,getGname);
    strcpy(sex,getGsex);
    strcpy(password,getGpassword);
    if(no[0] == 's'){ // 学生注册
        struct student stu = {no,name,sex,password};
        rs = addStudent(stu);
        if(rs == 0){
            printf("register success\n");
            gtk_widget_hide_all(registerWindow);
            gtk_widget_show_all(loginWindow);
        }
    }else if(no[0] == 't'){ // 教师注册
        struct teacher tea = {no,name,sex,password};
        rs = addTeacher(tea);
        if(rs == 0){
            printf("register success\n");
            gtk_widget_hide_all(registerWindow);
            gtk_widget_show_all(loginWindow);
        }
    }else{
        printf("error\n");
    }
}

// 返回上一级回调函数
void registerBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(registerWindow);
    gtk_widget_show_all(mainWindow);
}

// 注册窗口
void registerWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = "register";

    registerWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(registerWindow),title);
    gtk_widget_set_usize(registerWindow,400,400);
    g_signal_connect(GTK_OBJECT(registerWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(registerWindow),vbox);


    // 账号no
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("no:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    registerNo = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(registerNo),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, registerNo, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 姓名name
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("name:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    registerName = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(registerName),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, registerName, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 性别sex
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("sex:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    registerSex = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(registerSex),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, registerSex, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 密码password
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("password:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    registerPassword = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(registerPassword),FALSE);
    gtk_box_pack_start((GtkBox *) hbox, registerPassword, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    button = gtk_button_new_with_label("register");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(doregister),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(registerBack),"entry");
}
