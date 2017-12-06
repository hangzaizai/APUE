//
//  error.c
//  fileStat
//
//  Created by xtkj20170918 on 28/11/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "error.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void err_print(const char *description)
{
    printf("%s\n",description);
    printf("errno = %d error description = %s\n",errno,strerror(errno));
}

void err_print_exit(const char *desctiption)
{
    printf("%s\n",desctiption);
    printf("errno = %d error description = %s\n",errno,strerror(errno));
    exit(errno);
}
