#include "GoBang.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    InitChessBoard();
    PrintChessBoard();
    //打印侧边栏信息
    SetPos(BOARD_SIZE * 2 + 2,0);
    printf("按[Enter]键开始...");
    GameProcess();
    system("pause");
    return 0;
}
