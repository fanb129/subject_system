//
// Created by fanb on 2022/6/7.
//

#include "toutf8.h"
#include <gtk/gtk.h>

char *toUtf8(char *c){
    return g_locale_to_utf8(c,-1,NULL,NULL,NULL);
}