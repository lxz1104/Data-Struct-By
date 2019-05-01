//
// Created by longx on 2019/2/11.
//

#ifndef LINKEDSTRING_STATUSLIB_H
#define LINKEDSTRING_STATUSLIB_H


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

//如果系统中已经有了下面状态码的定义，就不在重复定义了。
#ifndef _MAX_H_
//堆栈上溢 超过所能表示的最大正数
#define OVERFLOW -2
//堆栈下溢 超过所能表示的最大负数
#define UNDERFLOW -3
#endif // _MAX_H_

//自定义状态码识别类型
typedef int Status;

/**宏函数*/

//结点后移
#define MoveToNext(node) node = node->next

//暂停一段时间
//利用空循环延时
#define Delay(x)\
{\
    double _loopNum;\
    for(_loopNum = 0.001;_loopNum <= 100000.0 * x;_loopNum += 0.01)\
        ;\
}\

//点击键盘回车键继续
#define PressEnter()\
{\
  fflush(stdin);\
  printf("Press Enter to continue...\n");\
  getchar();\
  fflush(stdin);\
}\

#endif //LINKEDSTRING_STATUSLIB_H
