//
// Created by fanb on 2022/6/6.
//

#include "rootCourseWindow.h"
#include "../../mysql_app/course/course.h"
#include "rootWindow.h"
#include "addCourseWindow.h"
char cno[100][100];
void rootCourseDelete(GtkWidget *widget,gpointer data){
    char cno1[100];
    strcpy(cno1,(char *)data);
    int rs = deleteCourse(cno1);
    if(rs == 0){
        printf("delete success\n");
        rootCourseWindowInit();
    }
}

void rootCourseBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(rootCourseWindow);
    gtk_widget_show_all(rootWindow);
}

void changeAddCourseWindow(GtkWidget *widget,gpointer data){
    addCourseWindowInit();
    gtk_widget_hide_all(rootCourseWindow);
    gtk_widget_show_all(addCourseWindow);
}

void rootCourseWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = "rootCourse";
    struct course cou[100] = {};
    int len = queryCourse(cou);
    int i;

    rootCourseWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(rootCourseWindow),title);
    gtk_widget_set_usize(rootCourseWindow,400,400);
    g_signal_connect(GTK_OBJECT(rootCourseWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(rootCourseWindow),vbox);

    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s\t%s",i+1,cou[i].cno,cou[i].cname,cou[i].tno);
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("delete");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(cno[i],cou[i].cno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootCourseDelete),cno[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("addCourse");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeAddCourseWindow),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootCourseBack),"entry");
}