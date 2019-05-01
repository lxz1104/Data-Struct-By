#include <stdio.h>
#include <string.h>

//BF算法匹配字符串
int BFCompare(char *parent,char *child,int pos);

int main() {
    char * str1 = "--hello123---";
    char  * str2 = "he";
    printf("\"%s\"在\"%s\"中第一次出现的位置为:%d\n",str1,str2,BFCompare(str1,str2,1));
    return 0;
}

int BFCompare(char *parent,char *child,int pos)
{
    int i = pos - 1,j = 0;
    //主串长度
    int pLen = strlen(parent);
    //子串长度
    int cLen = strlen(child);

    while (i < pLen && j < cLen)
    {
        if(parent[i] == child[j])
        {
            i++;
            j++;
        } else{
            i = i - j + 1; //指针回溯
            j = 0;
        }
    }
    if(j >= cLen)
    {
        return i - cLen + 1;
    } else{
        return -1;
    }
}