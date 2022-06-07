//
// Created by fanb on 2022/6/2.
//

#ifndef SUBJECT_SYSTEM_LOGINWINDOW_H
#define SUBJECT_SYSTEM_LOGINWINDOW_H
#include <gtk/gtk.h>

GtkWidget *loginWindow;

// 登录回调函数
void login(GtkWidget *widget,gpointer data);

// 登录窗口
void loginWindowInit();
#endif //SUBJECT_SYSTEM_LOGINWINDOW_H
