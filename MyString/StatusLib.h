//
// Created by longx on 2019/2/2.
//

#ifndef MYSTRING_STATUSLIB_H
#define MYSTRING_STATUSLIB_H

/**
 * 常用状态码以及宏函数定义
 */

/** 状态码 */
//出错
#define ERROR 0
//成功
#define SUCCESS 1
//真
#define TRUE 1
//假
#define FLASE 0
//相等
#define EQ 0
//大于
#define GT 1
//小于
#define LT -1
//如果系统中已经有了下面状态码的定义，就不在重复定义了。
#ifndef _STATUS_H_
    //堆栈上溢 超过所能表示的最大正数
    #define OVERFLOW -2
    //堆栈下溢 超过所能表示的最大负数
    #define UNDERFLOW -3
#endif // _STATUS_H_

//自定义状态码识别类型
typedef int Status;

#endif //MYSTRING_STATUSLIB_H
