//
// Created by fanb on 2022/6/2.
//

#include "mainWindow.h"
#include <gtk/gtk.h>
#include "../loginWindow/loginWindow.h"
#include "../registerWindow/registerWindow.h"
#include <string.h>

// 登录注册页面切换
void changeLogin(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(mainWindow);
    gtk_widget_show_all(loginWindow);
}
void changeRegister(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(mainWindow);
    gtk_widget_show_all(registerWindow);
}
void mainWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox;
    char *title = "subject_system";
    //主界面Windows的创建
    mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(mainWindow),title);
    gtk_widget_set_usize(mainWindow,500,500);
    g_signal_connect(GTK_OBJECT(mainWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);

    // 登录按钮
    button = gtk_button_new_with_label("login");

    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeLogin),"entry");
    //gtk_widget_show(button);

    // 注册按钮
    button = gtk_button_new_with_label("register");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeRegister),"entry");
    //gtk_widget_show(button);

    gtk_container_add(GTK_CONTAINER(mainWindow),vbox);
    //gtk_widget_show(box);
    //gtk_widget_show_all(mainWindow);
    //gtk_main();

}