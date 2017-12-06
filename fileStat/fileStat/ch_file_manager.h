//
//  ch_file_manager.h
//  fileStat
//
//  Created by xtkj20170918 on 28/11/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef ch_file_manager_h
#define ch_file_manager_h

#include <stdio.h>
#include "error.h"


typedef enum
{
    /* 普通文件 */
    regular_file,
    /*  目录文件 */
    directory_file,
    /* 字符设备文件 */
    character_file,
    /* 块设备文件 */
    block_file,
    /* FIFO文件 */
    fifo_file,
    /* 链接符号文件 */
    link_file,
    /* 套接字文件 */
    socket_file,
    /* 未知文件 */
    un_known_file
}ch_file_type;



/*
 打开文件的方式
 */
typedef enum
{
    /* 只读 */
    read_only = 0x001,
    /* 只写 */
    write_only = 0x010,
    /* 可读写 */
    read_write = 0x100,
    
}ch_open_style;

/*
 进程的实际用户id文件访问权限类型
 */
typedef enum
{
    /* 进程的实际用户ID有读权限 */
    process_actual_file_read,
    /* 进程的实际用户ID有写权限*/
    process_actual_file_write,
    /* 读写 */
    process_actual_file_read_write
    
}ch_process_actual_file_access;

/*
 打开文件，文件存在，则打开，文件不存在则创建新文件
 执行成功返回一个文件描述符，执行失败返回-1
 */
int ch_open(const char *filepath,ch_open_style style);

/*
 判断文件是否存在
 */
int ch_file_exist(const char *filepath,ch_bool_type *boolType);

/*
 测试文件的文件类型
 执行成功返回0，否则返回-1
 */
int ch_get_file_type(const char *path,ch_file_type *type);

/*
 检测进程的实际用户，对文件的访问权限
 */
int ch_process_actual_access(const char *path,ch_process_actual_file_access accss,ch_bool_type *type);

#endif /* ch_file_manager_h */

