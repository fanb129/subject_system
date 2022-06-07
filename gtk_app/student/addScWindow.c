//
// Created by fanb on 2022/6/6.
//

#include "addScWindow.h"
#include "../../mysql_app/sc/sc.h"
#include "studentWindow.h"
#include "../../mysql_app/course/course.h"

char title1[100];
char cno[100][100];
void addScBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(addScWindow);
    gtk_widget_show_all(studentWindow);
}
void doAddSc(GtkWidget *widget,gpointer data){
    char cno1[100];
    struct sc sc = {title1,cno1,"null"};
    int rs = addSc(sc);
    if(rs == 0){
        printf("add sc success\n");
    }
}

void addScWindowInit(char *sno){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    strcpy(title1,sno);
    struct course cou[100] = {};
    int len = queryCourse(cou);
    int i;

    addScWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addScWindow),title1);
    gtk_widget_set_usize(addScWindow,400,400);
    g_signal_connect(GTK_OBJECT(addScWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(addScWindow),vbox);

    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s\t%s",i+1,cou[i].cno,cou[i].cname,cou[i].tno);
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("select");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(cno[i],cou[i].cno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(doAddSc),cno[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(addScBack),"entry");
}