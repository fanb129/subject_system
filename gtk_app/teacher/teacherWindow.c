//
// Created by fanb on 2022/6/3.
//

#include "teacherWindow.h"
#include "../mainWindow/mainWindow.h"
#include "../../mysql_app/course/course.h"
#include "teacherGradeWindow.h"
#include <string.h>

char data[100][100];
char cno[100];
//进入成绩登记界面
void teacherGrade(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(teacherWindow);

    strcpy(cno,(char *)data);
    printf("%s\n",cno);
    teacherGradeWindowInit(cno);
    gtk_widget_show_all(teacherGradeWindow);
}

// 返回上一级回调函数
void teacherBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(teacherWindow);
    gtk_widget_show_all(mainWindow);
}

void teacherWindowInit(char *tno){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = tno;
    struct course cou[100] = {};
    int len = queryCourseByTno(cou,title);
    int i;

    teacherWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(teacherWindow),title);
    gtk_widget_set_usize(teacherWindow,400,400);
    g_signal_connect(GTK_OBJECT(teacherWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(teacherWindow),vbox);


    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s",i+1,cou[i].cno,cou[i].cname);
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("grade");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(data[i],cou[i].cno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(teacherGrade),data[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(teacherBack),"entry");

}
