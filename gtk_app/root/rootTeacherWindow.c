//
// Created by fanb on 2022/6/6.
//

#include "rootTeacherWindow.h"
#include "../../mysql_app/teacher/teacher.h"
#include "rootWindow.h"
#include "addWindow.h"
#include <string.h>

char tno[100][100];
void rootTeacherDelete(GtkWidget *widget,gpointer data){
    char tno1[100];
    strcpy(tno1,(char *)data);
    int rs = deleteTeacher(tno1);
    if(rs == 0){
        printf("delete success\n");
    }
}

void rootTeacherBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(rootTeacherWindow);
    gtk_widget_show_all(rootWindow);
}

void addTeacherWindow(GtkWidget *widget,gpointer data){
    addWindowInit();
    gtk_widget_hide_all(rootTeacherWindow);
    gtk_widget_show_all(addWindow);
}

void rootTeacherWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = "rootTeacher";
    struct teacher tea[100] = {};
    int len = queryTeacher(tea);
    int i;

    rootTeacherWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(rootTeacherWindow),title);
    gtk_widget_set_usize(rootTeacherWindow,400,400);
    g_signal_connect(GTK_OBJECT(rootTeacherWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(rootTeacherWindow),vbox);

    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s\t%s",i+1,tea[i].tno,tea[i].tname,tea[i].tsex);
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("delete");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(tno[i],tea[i].tno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootTeacherDelete),tno[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("addTeacher");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(addTeacherWindow),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootTeacherBack),"entry");
}