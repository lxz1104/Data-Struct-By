//
// Created by longx on 2019/1/25.
//

#ifndef CHESS_GOBANG_H
#define CHESS_GOBANG_H

#include <afxres.h>
#include "ChessData.h"

//棋盘大小
#define BOARD_SIZE 20
//上移键值
#define MOVE_UP 119
//下移键值
#define MOVE_DOWN 115
//左移键值
#define MOVE_LEFT 97
//右移键值
#define MOVE_RIGHT 100
//悔棋
#define UNDO 'r'
//悔棋操作
#define UNDO_CHESS -1
//白棋获胜
#define WHITE_WIN 1
//黑棋获胜
#define BLACK_WIN 2
//平局
#define DRAW 3
//尚未结束
#define PLAYING 0

/** 棋盘数组 */
char * ChessBoard[BOARD_SIZE][BOARD_SIZE];

/** 游戏主进程 */
void GameProcess();

/**
 * 判断比赛状态
 * @return 比赛中返回PLAYING；平局返回DRAW；黑棋赢返回BLACK_WIN；白棋赢BLACK_WIN。
 */
int Judge(int x,int y,ChessType type);

/**
 * 初始化/及重置棋盘
 */
void InitChessBoard();

/**
 * 打印棋盘
 */
void PrintChessBoard();

/**
 * 悔棋操作
 * @param linkedStack 要操作的链栈
 */
void UndoChess(LinkedStack * linkedStack);

/**
 * 设置光标坐标
 * @param x X轴坐标
 * @param y Y轴坐标
 */
void SetPos(short int x,short int y);

/**
 * 隐藏光标
 */
void HideInputCursor();

/**
 * 显示光标
 */
void ShowInputCursor();

/**
 * 获取下棋的坐标
 * @param linkedStack 要操作的链表
 * @return 若为下棋，返回棋子对应的坐标；若为悔棋，返回坐标的X,Y值均为UNDO_CHESS。
 */
COORD GetChessPos(LinkedStack * linkedStack);
#endif //CHESS_GOBANG_H
