//
//  main.m
//  fileStat
//
//  Created by xtkj20170918 on 28/11/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <errno.h>
#include <string.h>
#include "ch_file_manager.h"
#include "error.h"


void file_state(const char *filepath)
{
    ch_file_type type;
    char *ptr;
    
    if ( ch_get_file_type(filepath, &type) < 0 ) {
        err_print_exit("file type error");
    }
    switch ( type ) {
        case regular_file:
            ptr = "regular";
            break;
        case directory_file:
            ptr = "directory_file";
            break;
        case character_file:
            ptr = "character_file";
            break;
        case block_file:
            ptr = "block_file";
            break;
        case fifo_file:
            ptr = "fifo_file";
            break;
        case link_file:
            ptr = "link_file";
            break;
        case socket_file:
            ptr = "socket_file";
            break;
        default:
            ptr = "unknow_file";
        break;
    }
    
    printf("%s is %s\n",filepath,ptr);
}

void file_access( const char *filepath )
{
    /* 测试读的权限,access函数测试的是进程的实际ID对文件的访问权限
     当进程运行时，如果要进行文件操作，内核会对文件的访问有如下规则:
     如果进程的有效用户id等于等于文件的拥有者，如果文件所有者的适当的权限被设置，则允许访问，如果，进程的有效组ID等于文件的组ID，有适当的访问权限则允许访问
     */
    if( access(filepath, R_OK) < 0 ){
        err_print("access_error");
    }
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        char filepath[100];
        
        int input;
        
        printf("please select program function:\n");
        printf("1 indicates test file access\n");
        printf("2 indicates test file stat\n");
        scanf("%d",&input);
        
        while (1) {
            
            printf("input a file path\n");
            scanf("%s",filepath);
            if ( input==1 ) {
                
                
            }else if ( input==2 ) {
                file_state(filepath);
            }
            
        }
    }
    return 0;
}
