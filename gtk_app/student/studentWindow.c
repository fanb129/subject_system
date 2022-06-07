//
// Created by fanb on 2022/6/6.
//

#include "studentWindow.h"
#include "../../mysql_app/sc/sc.h"
#include "../mainWindow/mainWindow.h"
#include "addScWindow.h"

char cno[100][100];
char title[100];
// 返回上一级回调函数
void studentBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(studentWindow);
    gtk_widget_show_all(mainWindow);
}

void scDelete(GtkWidget *widget,gpointer data){
    char cno1[100];
    strcpy(cno1,(char *)data);
    int rs = deleteSc(title,cno1);
    if(rs == 0){
        printf("delete success\n");
    }
}

void changeAddScWindow(GtkWidget *widget,gpointer data){
    addScWindowInit(title);
    gtk_widget_hide_all(studentWindow);
    gtk_widget_show_all(addScWindow);
}


void studentWindowInit(char *sno){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    strcpy(title,sno);
    struct sc sc[100] = {};
    int len = queryScBySno(sc,title);
    int i;

    studentWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(studentWindow),title);
    gtk_widget_set_usize(studentWindow,400,400);
    g_signal_connect(GTK_OBJECT(studentWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(studentWindow),vbox);

    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s\t%s",i+1,sc[i].sno,sc[i].cno,sc[i].grade);
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("退选");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(cno[i],sc[i].cno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(scDelete),cno[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("选课");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeAddScWindow),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(studentBack),"entry");

}