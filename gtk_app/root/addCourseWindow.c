//
// Created by fanb on 2022/6/6.
//

#include "addCourseWindow.h"
#include "rootCourseWindow.h"
#include "../../mysql_app/course/course.h"


GtkWidget  *addCno;
GtkWidget  *addCname;
GtkWidget *addTno;

// 返回上一级回调函数
void addCourseBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(addCourseWindow);
    gtk_widget_show_all(rootCourseWindow);
}
// 添加course回调函数
void doaddCourse(GtkWidget *widget,gpointer data){
    const char *getCno = gtk_entry_get_text(GTK_ENTRY(addCno));
    const char *getCname = gtk_entry_get_text(GTK_ENTRY(addCname));
    const char *getTno = gtk_entry_get_text(GTK_ENTRY(addTno));
    char cno[100];
    char cname[100];
    char tno[100];
    gint rs;
    strcpy(cno,getCno);
    strcpy(cname,getCname);
    strcpy(tno,getTno);

    struct course cou = {cno,cname,tno};
    rs = addCourse(cou);
    if(rs == 0){
        printf("add success\n");
        gtk_widget_hide_all(addCourseWindow);
        rootCourseWindowInit();
        gtk_widget_show_all(rootCourseWindow);
    }

}
void addCourseWindowInit(){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    char *title = "addCourse";

    addCourseWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addCourseWindow),title);
    gtk_widget_set_usize(addCourseWindow,500,500);
    g_signal_connect(GTK_OBJECT(addCourseWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(addCourseWindow),vbox);


    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("cno:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addCno = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addCno),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, addCno, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("cname:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addCname = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addCname),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, addCname, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);

    // 性别sex
    hbox = gtk_hbox_new(FALSE,0);
    label = gtk_label_new("tno:");
    gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);
    addTno = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(addTno),TRUE);
    gtk_box_pack_start((GtkBox *) hbox, addTno, FALSE, FALSE, 5);
    gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);



    button = gtk_button_new_with_label("add");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(doaddCourse),"entry");

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(addCourseBack),"entry");
}




