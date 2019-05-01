//
// Created by longx on 2019/1/25.
//

#include "GoBang.h"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//游戏主进程
void GameProcess() {
    //用于判断下棋顺序
    int flag = 1;
    //游戏状态
    int gameStatus = -1;
    //下棋回合数
    unsigned int Count = 1;
    //棋子元素
    ChessMan chess;
    //棋子位置
    COORD chessPos;
    //存储棋子的链栈
    LinkedStack *linkedStack = (LinkedStack *) malloc(sizeof(LinkedStack));
    //初始化链栈
    InitLinkedStack(linkedStack);

    //
    //隐藏光标
    HideInputCursor();
    while (flag) {
        chessPos = GetChessPos(linkedStack);
        //检测是否有悔棋操作
        if(chessPos.X == UNDO_CHESS || chessPos.Y == UNDO_CHESS)
        {
            if(Count > 1) {
                Count--;
                flag = -flag;
                SetPos(BOARD_SIZE * 2 + 2,1);
                printf("<[第%d回合]>",Count);
                SetPos(BOARD_SIZE * 2 + 2,2);
                printf("<%s>",flag > 0 ? "白棋玩家下棋..." : "黑棋玩家下棋...");
            }
            PrintChessBoard();
            continue;
        }
        chess.x = chessPos.X;
        chess.y = chessPos.Y;
        chess.type = flag > 0 ? White : Black;

        //打印侧边栏信息
        SetPos(BOARD_SIZE * 2 + 2,0);
        printf("{<---状态栏--->}");
        SetPos(BOARD_SIZE * 2 + 2,1);
        printf("<[第%d回合]>",Count);
        SetPos(BOARD_SIZE * 2 + 2,2);
        printf("<%s>",flag > 0 ? "白棋玩家下棋..." : "黑棋玩家下棋...");
        SetPos(BOARD_SIZE * 2 + 2,6);
        printf("---游戏帮助---");
        SetPos(BOARD_SIZE * 2 + 2,7);
        printf("按[w,a,s,d]键移动");
        SetPos(BOARD_SIZE * 2 + 2,8);
        printf("按[Enter]键下棋");
        SetPos(BOARD_SIZE * 2 + 2,9);
        printf("按[r]键悔棋");
        //该位置是否已有棋
        if(strcmp("十",ChessBoard[chess.y - 1][chess.x - 1]) != 0)
        {
            continue;
        }
        PushLinkedStack(linkedStack, chess);
        //修改棋盘
        switch (chess.type) {
            case White:
                ChessBoard[chess.y - 1][chess.x - 1] = "○";
                break;
            case Black:
                ChessBoard[chess.y - 1][chess.x - 1] = "●";
                break;
        }

        PrintChessBoard();
        gameStatus = Judge(chessPos.X,chessPos.Y,chess.type);
        flag = -flag;
        Count++;
        if(gameStatus == PLAYING)
        {
            continue;
        } else if(gameStatus == WHITE_WIN)
        {
            SetPos(0,BOARD_SIZE / 2);
            printf("###################################\n");
            printf("#           白棋获胜!              #\n");
            printf("###################################\n");
            break;
        } else if(gameStatus == BLACK_WIN)
        {
            SetPos(0,BOARD_SIZE / 2);
            printf("###################################\n");
            printf("#           黑棋获胜!              #\n");
            printf("###################################\n");
            break;
        } else if(gameStatus == DRAW)
        {
            SetPos(0,BOARD_SIZE / 2);
            printf("###################################\n");
            printf("#             平局!               #\n");
            printf("###################################\n");
            break;
        }
    }
    DestoryLinkedStack(linkedStack);
}

//判断游戏状态
int Judge(int x,int y,ChessType type)
{
    int i,j;
    char *str = type != Black ? "○" : "●";
    //将坐标转换为下标
    x--;
    y--;
    x ^= y;
    y ^= x;
    x ^= y;
    //横向判断
    for(i = x - 4,j = y;i <= x;++i)
    {
        if(i >= 0 && i <= BOARD_SIZE - 5 && !strcmp(str,ChessBoard[i][j]) && !strcmp(str,ChessBoard[i + 1][j]) && !strcmp(str,ChessBoard[i + 2][j]) && !strcmp(str,ChessBoard[i + 3][j]) && !strcmp(str,ChessBoard[i + 4][j]))
        {
            return type != Black ? BLACK_WIN : WHITE_WIN;
        }
    }
    //纵向判断
    for(i = x,j = y - 4;j <= y;++j)
    {
        if(j >= 0 && j <= BOARD_SIZE - 5 && !strcmp(str,ChessBoard[i][j]) && !strcmp(str,ChessBoard[i][j + 1]) && !strcmp(str,ChessBoard[i][j + 2]) && !strcmp(str,ChessBoard[i][j + 3]) && !strcmp(str,ChessBoard[i][j + 4]))
        {
            return type != Black ? BLACK_WIN : WHITE_WIN;
        }
    }
    //斜向判断
    for(i  = x - 4,j = y - 4;i <= x || j <= y;++i,++j)
    {
        if(i >= 0 && i <= BOARD_SIZE - 5 && j >= 0 && j <= BOARD_SIZE - 5  && !strcmp(str,ChessBoard[i][j]) && !strcmp(str,ChessBoard[i + 1][j + 1]) && !strcmp(str,ChessBoard[i + 2][j + 2]) && !strcmp(str,ChessBoard[i + 3][j + 3]) && !strcmp(str,ChessBoard[i + 4][j + 4]))
        {
            return type != Black ? BLACK_WIN : WHITE_WIN;
        }
    }
    for(i  = x - 4,j = y + 4;i <= x || j >= 0;++i,--j)
    {
        if(i >= 0 && i <= BOARD_SIZE - 5 && j >= 0 && j <= BOARD_SIZE - 5 && !strcmp(str,ChessBoard[i][j]) && !strcmp(str,ChessBoard[i + 1][j - 1]) && !strcmp(str,ChessBoard[i + 2][j - 2]) && !strcmp(str,ChessBoard[i + 3][j - 3]) && !strcmp(str,ChessBoard[i + 4][j - 4]))
        {
            return type != Black ? BLACK_WIN : WHITE_WIN;
        }
    }
    //判断棋盘是否已满
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if(!strcmp("十",ChessBoard[i][j]))
            {
                return PLAYING;
            }
        }
    }
    //棋盘已满，平局
    return DRAW;
}

//初始化棋盘
void InitChessBoard(){

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            ChessBoard[i][j] = "十";
        }
    }
}

//打印棋盘
void PrintChessBoard()
{
    SetPos(0,0);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%s",ChessBoard[i][j]);
        }
        printf("\n");
    }
}

//设置棋子下标
COORD GetChessPos(LinkedStack * linkedStack)
{
    /** 棋子坐标 */
    COORD ChessPos = {BOARD_SIZE,BOARD_SIZE / 2};
    char key = '0';
    SetPos(ChessPos.X,ChessPos.Y);
    printf("⊙");
    while (key != '\r')
    {
        fflush(stdin);
        key = (char)getch();
        switch (key)
        {
            case MOVE_UP:
                ChessPos.Y--;
                break;
            case MOVE_DOWN:
                ChessPos.Y++;
                break;
            case MOVE_LEFT:
                ChessPos.X-=2;
                break;
            case MOVE_RIGHT:
                ChessPos.X+=2;
                break;
            case UNDO:
                UndoChess(linkedStack);
                ChessPos.X = UNDO_CHESS;
                ChessPos.Y = UNDO_CHESS;
                return ChessPos;
            default:
                continue;
        }
        if(ChessPos.X > BOARD_SIZE * 2 - 1)
        {
            ChessPos.X = 0;
        } else if(ChessPos.X < 0)
        {
            ChessPos.X = BOARD_SIZE * 2 - 1;
        }
        if(ChessPos.Y > BOARD_SIZE - 1)
        {
            ChessPos.Y = 0;
        } else if(ChessPos.Y < 0)
        {
            ChessPos.Y = BOARD_SIZE - 1;
        }
        if(ChessPos.X % 2 != 0 || ChessPos.X == 1)
        {
            ChessPos.X--;
        }
        PrintChessBoard();
        SetPos(ChessPos.X,ChessPos.Y);
        printf("⊙");
    }
    ChessPos.X  = (SHORT)((int)ChessPos.X / 2 + 1);
    ChessPos.Y++;
    return ChessPos;
}


//悔棋操作
void UndoChess(LinkedStack * linkedStack)
{
    ChessMan popChess;
    if(linkedStack->top)
    {
        PopLinkedStack(linkedStack,&popChess);
        ChessBoard[popChess.y - 1][popChess.x - 1] = "十";
    } else
    {
        SetPos(BOARD_SIZE * 2 + 2,11);
        printf("\a已回到开始界面!");
    }
}

//设置光标位置
void SetPos(short int x,short int y)
{
    //定义输出句柄
    HANDLE winHandle;
    COORD pos = { x,y };
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置
    SetConsoleCursorPosition(winHandle, pos);
}

//隐藏光标
void HideInputCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏输入符号
}

//显示光标
void ShowInputCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏输入符号
}
