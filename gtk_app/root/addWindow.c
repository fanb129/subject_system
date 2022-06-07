//
// Created by fanb on 2022/6/6.
//

#include "addWindow.h"
#include "../../mysql_app/student/student.h"
#include "../../mysql_app/teacher/teacher.h"
#include "rootWindow.h"

GtkWidget  *addNo;
GtkWidget  *addPassword;
GtkWidget *addName;
GtkWidget *addSex;
// 注册回调函数
void doadd(GtkWidget *widget,gpointer data){
    const char *getGno = gtk_entry_get_text(GTK_ENTRY(addNo));
    const char *getGname = gtk_entry_get_text(GTK_ENTRY(addName));
    const char *getGsex = gtk_entry_get_text(GTK_ENTRY(addSex));
    const char *getGpassword = gtk_entry_get_text(GTK_ENTRY(addPassword));
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
            printf("add success\n");
            gtk_widget_hide_all(addWindow);
            gtk_widget_show_all(rootWindow);
        }
    }else if(no[0] == 't'){ // 教师注册
        struct teacher tea = {no,name,sex,password};
        rs = addTeacher(tea);
        if(rs == 0){
            printf("add success\n");
            gtk_widget_hide_all(addWindow);
            gtk_widget_show_all(rootWindow);
        }
    }else{
        printf("error\n");
    }
}

// 返回上一级回调函数
void addBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(addWindow);
    gtk_widget_show_all(rootWindow);
}

// 注册窗口
void addWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = "add";

    addWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addWindow),title);
    gtk_widget_set_usize(addWindow,400,400);
    g_signal_connect(GTK_OBJECT(addWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(addWindow),vbox);


    // 账号no
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("no:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addNo = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addNo),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, addNo, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 姓名name
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("name:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addName = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addName),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, addName, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 性别sex
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("sex:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addSex = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addSex),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, addSex, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 密码password
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("password:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addPassword = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addPassword),FALSE);
    gtk_box_pack_start((GtkBox *) hbox, addPassword, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    button = gtk_button_new_with_label("add");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(doadd),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(addBack),"entry");
}