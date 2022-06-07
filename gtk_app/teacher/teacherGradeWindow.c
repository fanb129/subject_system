//
// Created by fanb on 2022/6/6.
//

#include "teacherGradeWindow.h"
#include "teacherWindow.h"
#include "../../mysql_app/sc/sc.h"
char title[100];
char sno[100][100];
GtkWidget *gradeTxt;
void teacherGradeBack(GtkWidget *widget,gpointer data){
    gtk_widget_hide_all(teacherGradeWindow);
    gtk_widget_show_all(teacherWindow);
}

void changeGradeWindow(GtkWidget *widget,gpointer data){
    const char *getGrade = gtk_entry_get_text(GTK_ENTRY(gradeTxt));
    char sno1[100];
    char grade[100];
    strcpy(grade,getGrade);
    strcpy(sno1,(char *)data);
    int rs = changeGrade(sno1,title,grade);
    if(rs == 0){
        printf("grade success\n");
    }
}

void teacherGradeWindowInit(char *cno){
    GtkWidget *button;
    GtkWidget *vbox; //横向盒子
    GtkWidget *label;
    GtkWidget *hbox; //横向盒子

    strcpy(title,cno);
    struct sc sc[100] = {};
    int len = queryScByCno(sc,title);
    int i;

    teacherGradeWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(teacherGradeWindow),title);
    gtk_widget_set_usize(teacherGradeWindow,400,400);
    g_signal_connect(GTK_OBJECT(teacherGradeWindow),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
    vbox =  gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(teacherGradeWindow),vbox);

    for(i = 0;i < len;i++){
        hbox = gtk_hbox_new(FALSE,0);
        char content[100];
        sprintf(content,"%d\t%s\t%s",i+1,sc[i].sno,sc[i].grade);
        label = gtk_label_new(content);
        gtk_box_pack_start((GtkBox *) hbox, label, FALSE, FALSE, 5);

        gradeTxt = gtk_entry_new();
        gtk_entry_set_visibility(GTK_ENTRY(gradeTxt),TRUE);
        gtk_box_pack_start((GtkBox *) hbox, gradeTxt, FALSE, FALSE, 5);

        button = gtk_button_new_with_label("changeGrade");
        gtk_box_pack_start((GtkBox *) hbox, button, FALSE, FALSE, 5);
        strcpy(sno[i],sc[i].sno);
        g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(changeGradeWindow),sno[i]);

        gtk_box_pack_start((GtkBox *) vbox, hbox, FALSE, FALSE, 5);
    }

    button = gtk_button_new_with_label("back");
    gtk_box_pack_start((GtkBox *) vbox, button, FALSE, FALSE, 5);
    g_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(teacherGradeBack),"entry");
}
