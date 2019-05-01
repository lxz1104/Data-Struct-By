//
// Created by longx on 2019/1/25.
//

#include "GoBang.h"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//��Ϸ������
void GameProcess() {
    //�����ж�����˳��
    int flag = 1;
    //��Ϸ״̬
    int gameStatus = -1;
    //����غ���
    unsigned int Count = 1;
    //����Ԫ��
    ChessMan chess;
    //����λ��
    COORD chessPos;
    //�洢���ӵ���ջ
    LinkedStack *linkedStack = (LinkedStack *) malloc(sizeof(LinkedStack));
    //��ʼ����ջ
    InitLinkedStack(linkedStack);

    //
    //���ع��
    HideInputCursor();
    while (flag) {
        chessPos = GetChessPos(linkedStack);
        //����Ƿ��л������
        if(chessPos.X == UNDO_CHESS || chessPos.Y == UNDO_CHESS)
        {
            if(Count > 1) {
                Count--;
                flag = -flag;
                SetPos(BOARD_SIZE * 2 + 2,1);
                printf("<[��%d�غ�]>",Count);
                SetPos(BOARD_SIZE * 2 + 2,2);
                printf("<%s>",flag > 0 ? "�����������..." : "�����������...");
            }
            PrintChessBoard();
            continue;
        }
        chess.x = chessPos.X;
        chess.y = chessPos.Y;
        chess.type = flag > 0 ? White : Black;

        //��ӡ�������Ϣ
        SetPos(BOARD_SIZE * 2 + 2,0);
        printf("{<---״̬��--->}");
        SetPos(BOARD_SIZE * 2 + 2,1);
        printf("<[��%d�غ�]>",Count);
        SetPos(BOARD_SIZE * 2 + 2,2);
        printf("<%s>",flag > 0 ? "�����������..." : "�����������...");
        SetPos(BOARD_SIZE * 2 + 2,6);
        printf("---��Ϸ����---");
        SetPos(BOARD_SIZE * 2 + 2,7);
        printf("��[w,a,s,d]���ƶ�");
        SetPos(BOARD_SIZE * 2 + 2,8);
        printf("��[Enter]������");
        SetPos(BOARD_SIZE * 2 + 2,9);
        printf("��[r]������");
        //��λ���Ƿ�������
        if(strcmp("ʮ",ChessBoard[chess.y - 1][chess.x - 1]) != 0)
        {
            continue;
        }
        PushLinkedStack(linkedStack, chess);
        //�޸�����
        switch (chess.type) {
            case White:
                ChessBoard[chess.y - 1][chess.x - 1] = "��";
                break;
            case Black:
                ChessBoard[chess.y - 1][chess.x - 1] = "��";
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
            printf("#           �����ʤ!              #\n");
            printf("###################################\n");
            break;
        } else if(gameStatus == BLACK_WIN)
        {
            SetPos(0,BOARD_SIZE / 2);
            printf("###################################\n");
            printf("#           �����ʤ!              #\n");
            printf("###################################\n");
            break;
        } else if(gameStatus == DRAW)
        {
            SetPos(0,BOARD_SIZE / 2);
            printf("###################################\n");
            printf("#             ƽ��!               #\n");
            printf("###################################\n");
            break;
        }
    }
    DestoryLinkedStack(linkedStack);
}

//�ж���Ϸ״̬
int Judge(int x,int y,ChessType type)
{
    int i,j;
    char *str = type != Black ? "��" : "��";
    //������ת��Ϊ�±�
    x--;
    y--;
    x ^= y;
    y ^= x;
    x ^= y;
    //�����ж�
    for(i = x - 4,j = y;i <= x;++i)
    {
        if(i >= 0 && i <= BOARD_SIZE - 5 && !strcmp(str,ChessBoard[i][j]) && !strcmp(str,ChessBoard[i + 1][j]) && !strcmp(str,ChessBoard[i + 2][j]) && !strcmp(str,ChessBoard[i + 3][j]) && !strcmp(str,ChessBoard[i + 4][j]))
        {
            return type != Black ? BLACK_WIN : WHITE_WIN;
        }
    }
    //�����ж�
    for(i = x,j = y - 4;j <= y;++j)
    {
        if(j >= 0 && j <= BOARD_SIZE - 5 && !strcmp(str,ChessBoard[i][j]) && !strcmp(str,ChessBoard[i][j + 1]) && !strcmp(str,ChessBoard[i][j + 2]) && !strcmp(str,ChessBoard[i][j + 3]) && !strcmp(str,ChessBoard[i][j + 4]))
        {
            return type != Black ? BLACK_WIN : WHITE_WIN;
        }
    }
    //б���ж�
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
    //�ж������Ƿ�����
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if(!strcmp("ʮ",ChessBoard[i][j]))
            {
                return PLAYING;
            }
        }
    }
    //����������ƽ��
    return DRAW;
}

//��ʼ������
void InitChessBoard(){

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            ChessBoard[i][j] = "ʮ";
        }
    }
}

//��ӡ����
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

//���������±�
COORD GetChessPos(LinkedStack * linkedStack)
{
    /** �������� */
    COORD ChessPos = {BOARD_SIZE,BOARD_SIZE / 2};
    char key = '0';
    SetPos(ChessPos.X,ChessPos.Y);
    printf("��");
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
        printf("��");
    }
    ChessPos.X  = (SHORT)((int)ChessPos.X / 2 + 1);
    ChessPos.Y++;
    return ChessPos;
}


//�������
void UndoChess(LinkedStack * linkedStack)
{
    ChessMan popChess;
    if(linkedStack->top)
    {
        PopLinkedStack(linkedStack,&popChess);
        ChessBoard[popChess.y - 1][popChess.x - 1] = "ʮ";
    } else
    {
        SetPos(BOARD_SIZE * 2 + 2,11);
        printf("\a�ѻص���ʼ����!");
    }
}

//���ù��λ��
void SetPos(short int x,short int y)
{
    //����������
    HANDLE winHandle;
    COORD pos = { x,y };
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù��λ��
    SetConsoleCursorPosition(winHandle, pos);
}

//���ع��
void HideInputCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//�����������
}

//��ʾ���
void ShowInputCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//�����������
}
