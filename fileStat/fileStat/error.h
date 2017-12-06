//
//  error.h
//  fileStat
//
//  Created by xtkj20170918 on 28/11/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef error_h
#define error_h

#include <stdio.h>

typedef enum
{
    ch_bool_true = 1,
    ch_bool_false = 0
}ch_bool_type;

/* 打印错误 */
void err_print(const char *description);

/* error print exit */
void err_print_exit(const char *desctiption);

#endif /* error_h */
