//
// Created by fanb on 2022/6/6.
//

#include "rootWindow.h"
#include "rootStudentWindow.h"
#include "rootTeacherWindow.h"
#include "../mainWindow/mainWindow.h"
#include "rootCourseWindow.h"

void changeStudent(GtkWidget *widget,gpointer data){
    rootStudentWindowInit();
    gtk_widget_hide_all(rootWindow);
    gtk_widget_show_all(rootStudentWindow);
}
void changeTeacher(GtkWidget *widget,gpointer data){
    rootTeacherWindowInit();
    gtk_widget_hide_all(rootWindow);
    gtk_widget_show_all(rootTeacherWindow);
}

void rootWindowBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(rootWindow);
    gtk_widget_show_all(mainWindow);
}

void changeCourse(GtkWidget *widget,gpointer data){
    rootCourseWindowInit();
    gtk_widget_hide_all(rootWindow);
    gtk_widget_show_all(rootCourseWindow);
}

void rootWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox;
    char *title = "root";
    //主界面Windows的创建
    rootWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(rootWindow),title);
    gtk_widget_set_usize(rootWindow,500,500);
    g_signal_connect(GTK_OBJECT(rootWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);

    button = gtk_button_new_with_label("student");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeStudent),"entry");

    button = gtk_button_new_with_label("teacher");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeTeacher),"entry");

    button = gtk_button_new_with_label("course");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeCourse),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(rootWindowBack),"entry");

    gtk_container_add(GTK_CONTAINER(rootWindow),vbox);
}