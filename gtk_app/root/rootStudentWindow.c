//
// Created by fanb on 2022/6/6.
//

#include "rootStudentWindow.h"
#include "../../mysql_app/student/student.h"
#include "rootWindow.h"
#include "addWindow.h"
#include "../util/toutf8.h"

char rootSno[100][100];
//root删除学生
void rootStudentDelete(GtkWidget *widget,gpointer data){
    char sno1[100];
    strcpy(sno1,(char *)data);
    int rs = deleteStudent(sno1);
    if(rs == 0){
        printf("delete success\n");
        gtk_widget_hide_all(rootStudentWindow);
        rootStudentWindowInit();
        gtk_widget_show_all(rootStudentWindow);
    }
}
// 返回界面回调函数
void rootStudentBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(rootStudentWindow);
    gtk_widget_show_all(rootWindow);
}
// root添加学生回调函数
void addStudentWindow(GtkWidget *widget,gpointer data){
    addWindowInit();
    gtk_widget_hide_all(rootStudentWindow);
    gtk_widget_show_all(addWindow);
}

void rootStudentWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子
    
    char *title = "rootStudent";
    struct student stu[100] = {};
    int len = queryStudent(stu);
    int i;

    rootStudentWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(rootStudentWindow),title);
    gtk_widget_set_usize(rootStudentWindow,500,500);
    g_signal_connect(GTK_OBJECT(rootStudentWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(rootStudentWindow),vbox);

    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s\t%s",i+1, toUtf8(stu[i].sno), toUtf8(stu[i].sname), toUtf8(stu[i].sex));
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("delete");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(rootSno[i],stu[i].sno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootStudentDelete),rootSno[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("addStudent");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(addStudentWindow),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootStudentBack),"entry");

}
