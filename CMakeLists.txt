cmake_minimum_required(VERSION 2.8)
project(subject_system C)

set(CMAKE_C_STANDARD 99)

#windows配置
#set(INC_DIR D:\\lib-6.1.11\\include)
#set(LINK_DIR D:\\lib-6.1.11\\lib)
#include_directories(${INC_DIR})  #include文件夹位置
#link_directories(${LINK_DIR}) #lib文件夹位置
#link_libraries(libmysql)  #lib下dll文件


#linux下mysql
set(INC_DIR /usr/include/mysql)
set(LINK_DIR /usr/lib64/mysql)
include_directories(${INC_DIR})  #include文件夹位置
link_directories(${LINK_DIR}) #lib文件夹位置
link_libraries(mysqlclient)  #lib下so文件

#linux下gtk+
include_directories(/usr/include/gtk-2.0
                    /usr/lib64/gtk-2.0/include
                    /usr/include/atk-1.0
                    /usr/include/cairo
                    /usr/include/gdk-pixbuf-2.0
                    /usr/include/pango-1.0
                    /usr/include/fribidi
                    /usr/include/glib-2.0
                    /usr/lib64/glib-2.0/include
                    /usr/include/harfbuzz
                    /usr/include/freetype2
                    /usr/include/libpng15
                    /usr/include/uuid
                    /usr/include/pixman-1
                    /usr/include/libdrm)  #include文件夹位置
#link_directories(/usr/lib64) #lib文件夹位置
link_libraries( gtk-x11-2.0
                atk-1.0
                gio-2.0
                pangoft2-1.0
                pangocairo-1.0
                gdk_pixbuf-2.0
                cairo -lpango-1.0
                fontconfig
                gobject-2.0
                glib-2.0
                freetype
        )  #lib下so文件



add_executable(subject_system main.c
        mysql_app/mysql_app/mysql_app.c mysql_app/mysql_app/mysql_app.h
        mysql_app/student/student.c mysql_app/student/student.h
        mysql_app/teacher/teacher.c mysql_app/teacher/teacher.h
        mysql_app/course/course.c mysql_app/course/course.h
        mysql_app/sc/sc.c mysql_app/sc/sc.h
        gtk_app/mainWindow/mainWindow.c gtk_app/mainWindow/mainWindow.h
        gtk_app/loginWindow/loginWindow.c gtk_app/loginWindow/loginWindow.h
        gtk_app/registerWindow/registerWindow.c gtk_app/registerWindow/registerWindow.h
        gtk_app/teacher/teacherWindow.h gtk_app/teacher/teacherWindow.c
        gtk_app/teacher/teacherGradeWindow.c gtk_app/teacher/teacherGradeWindow.h
        gtk_app/root/rootWindow.c gtk_app/root/rootWindow.h
        gtk_app/root/rootStudentWindow.c gtk_app/root/rootStudentWindow.h
        gtk_app/root/rootTeacherWindow.c gtk_app/root/rootTeacherWindow.h
        gtk_app/root/addWindow.c gtk_app/root/addWindow.h
        gtk_app/root/rootCourseWindow.c gtk_app/root/rootCourseWindow.h gtk_app/root/addCourseWindow.c gtk_app/root/addCourseWindow.h gtk_app/student/studentWindow.c gtk_app/student/studentWindow.h gtk_app/student/addScWindow.c gtk_app/student/addScWindow.h)
#主要配置第一个参数为项目名
target_link_libraries(subject_system mysqlclient)