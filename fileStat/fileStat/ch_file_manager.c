//
//  ch_file_manager.c
//  fileStat
//
//  Created by xtkj20170918 on 28/11/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "ch_file_manager.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int ch_open(const char *filepath,ch_open_style style)
{
    int result = style & 0x111;
    int fd = -1;
    int flag;
    
    if ( result == 0x100 ) {
        flag = O_RDWR|O_CREAT|O_EXCL;
        //fd = open(filepath,O_RDWR|O_CREAT|O_EXCL,0x7777);
    }else if ( result == 0x001 ){
        flag = O_RDONLY|O_CREAT|O_EXCL;
        //fd = open(filepath,O_RDONLY|O_CREAT|O_EXCL,0x7777);
    }else{
        flag = O_WRONLY|O_CREAT|O_EXCL;
        //fd = open(filepath,O_WRONLY|O_CREAT|O_EXCL,0x7777);
    }
    
    //当fd返回-1并且errno等于文件存在
    fd = open(filepath, flag,0x7777);
    
    if ( fd < 0 && errno==EEXIST) {
        flag = flag & 0xff0f & 0xfff;
        fd = open(filepath, flag,0x7777);
    }
    
    return fd;
}


int ch_file_exist(const char *filepath,ch_bool_type *boolType)
{
    int fd;
    ch_bool_type bool_type;
    
    fd = open(filepath, O_RDONLY|O_CREAT|O_EXCL);
    if ( fd < 0 && fd==EEXIST ) {
        bool_type = ch_bool_true;
        *boolType = bool_type;
        return 0;
    }
    if ( fd > 0 ) {
        //关闭文件
        close(fd);
        //删除文件 TODO...
        return 0;
    }

    return -1;
}

int ch_get_file_type(const char *path,ch_file_type *type)
{
    struct stat buf;

    if ( lstat(path, &buf) < 0  ) {
        return -1;
    }
    if ( S_ISREG(buf.st_mode) ) {
        *type = regular_file;
    }else if ( S_ISDIR(buf.st_mode) ){
       *type = directory_file;
    }else if ( S_ISCHR(buf.st_mode)){
        *type = character_file;
    }else if ( S_ISBLK(buf.st_mode)){
        *type = block_file;
    }else if ( S_ISFIFO(buf.st_mode)){
        *type = fifo_file;
    }else if ( S_ISLNK(buf.st_mode)){
        *type = link_file;
    }else if ( S_ISSOCK(buf.st_mode)){
        *type = socket_file;
    }else{
        *type = un_known_file;
    }
    
    return 0;
}


int ch_process_actual_access(const char *path,ch_process_actual_file_access accss,ch_bool_type *type)
{
    ch_process_actual_file_access file_access;
    
    switch (accss) {
        case :
            <#statements#>
            break;
            
        default:
            break;
    }
    
    if ( access(path, R_OK) > 0 ) {
        file_access = process_actual_file_read;
    }
    
    if ( access(path, W_OK) > 0 ) {
        file_access = process_actual_file_write;
    }
    
}
