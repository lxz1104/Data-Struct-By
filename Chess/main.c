#include "GoBang.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    InitChessBoard();
    PrintChessBoard();
    //��ӡ�������Ϣ
    SetPos(BOARD_SIZE * 2 + 2,0);
    printf("��[Enter]����ʼ...");
    GameProcess();
    system("pause");
    return 0;
}
