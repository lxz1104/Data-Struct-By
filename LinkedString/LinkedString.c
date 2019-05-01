//
// Created by longx on 2019/2/11.
//

#include "LinkedString.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//��ʼ������
void initString_L(LString * LinkedStr)
{
    LinkedStr->head = NULL; //ͷָ���ÿ�
    LinkedStr->tail = NULL; //βָ���ÿ�
    LinkedStr->length = 0;  //��������
}

//�������������
Status strAssign_L(LString * LinkedStr,char *chs)
{
    //��ʼ������
    clearString_L(LinkedStr);

    //��ȡ�ַ��ĳ���
    unsigned int len = strlen(chs);
    if(!len)
    {
        //chsΪ���ַ�ʱ����ERROR
        return ERROR;
    }

    //���ݿ鳤�Ȼ����ַ�����
    int i = len / BLOCK_SIZE;   //iΪ������
    int j = len % BLOCK_SIZE;   //jΪ����֮�������ַ�

    //����ж��ಿ�֣���Ҫ��1
    if(j > 0)
    {
        i++;
    }

    /*�������ֺõĿ��ţ������µĿ鲢��ӵ�������*/
    int count = 0;
    for (int k = 1; k <= i; ++k) {
        //�����µĿ鲢�����ڴ�
        Blocks * p = (Blocks *)malloc(sizeof(Blocks));
        if(!p)
        {
            printf("Malloc error!\n");
            exit(OVERFLOW);
        }
        //next�ÿ�
        p->next = NULL;

        //��������:ֻ��һ����ʱ��ͷָ���βָ�붼ָ���µĿ�
        if(k == 1)
        {
            LinkedStr->head = LinkedStr->tail = p;
        } else{
            //������ǰ���һ�����nextָ��ָ���µĿ�
            LinkedStr->tail->next = p;
            //������βָ���Ϊָ�����һ����p
            LinkedStr->tail = p;
        }
        /*���ջ��֣���chs�ַ������Ӧ�Ĳ��ֱ�������ǰ���������*/
        for (count = 0; count < BLOCK_SIZE && (count + (k - 1) * BLOCK_SIZE < len); ++count) {
            LinkedStr->tail->ch[count] = chs[count + (k - 1) * BLOCK_SIZE];
        }
    }

    /*������һ���鱻���Ƶ��ַ����鳤�Ȳ���һ������Զ��峤�ȣ�����Ҫ��ĩβ��ӽ�����*/
    while (count < BLOCK_SIZE)
    {
        LinkedStr->tail->ch[count++] = '\0';
    }

    //��¼�����ĳ���
    LinkedStr->length = len;

    return SUCCESS;
}

//��������
Status strCopy_L(LString * LinkedStr,LString * s)
{
    /* ������� */
    clearString_L(LinkedStr);

    /* ��������s��LinkedStr��ֵ */
    for (Blocks * p = s->head; p != NULL ; MoveToNext(p)) {
        /* ���������Ŀ� */
        Blocks *node = (Blocks *)malloc(sizeof(Blocks));
        if(!node)
        {
            printf("Malloc error!\n");
            exit(OVERFLOW);
        }
        //next�ÿ�
        node->next = NULL;

        /* ֻ��һ����ʱ������LinkedStr��ͷָ���βָ�붼ָ���µĿ�node */
        if(p == s->head)
        {
            LinkedStr->head = LinkedStr->tail = node;
        } else
        {
            LinkedStr->tail->next = node;
            LinkedStr->tail = node;
        }

        /* ����node��ֵ */
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            node->ch[i] = p->ch[i];
        }
    }
    /* ��¼�����ĳ��� */
    LinkedStr->length = s->length;
    return SUCCESS;
}

//�ж������Ƿ�Ϊ��
Status IsEmpty_L(LString LinkedStr)
{
    if(LinkedStr.head == NULL && LinkedStr.tail == NULL && LinkedStr.length == 0)
    {
        return TRUE;
    } else{
        return FLASE;
    }
}

//�Ƚ����������Ĵ�С
Status strCompare_L(LString LinkedStr1,LString LinkedStr2)
{
    /* ��ͷָ�뿪ʼ����LinkedStr1��LinkedStr2 */
    Blocks *p = LinkedStr1.head;
    Blocks *q = LinkedStr2.head;

    /* ������һ��������������������� */
    while (p && q)
    {
        /* �Ƚϵ�ǰp��q���ַ������Ƿ���� */
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            /* ��������ʱ����������ASCII��Ĳ�ֵ */
            if(p->ch[i] != q->ch[i]) {
                return p->ch[i] - q->ch[i];
            }
        }
        MoveToNext(p);
        MoveToNext(q);
    }

    /* ��������,�����������Ĳ�ֵ����ֵΪ0����������� */
    return LinkedStr1.length - LinkedStr2.length;
}

//������������
unsigned int strLength_L(LString LinkedStr)
{
    return LinkedStr.length;
}

//�������
void clearString_L(LString * LinkedStr)
{
    if(IsEmpty_L(*LinkedStr))
    {
        return;
    }

    Blocks *p = NULL,*q = NULL;
    p = LinkedStr->head;

    /* �����ͷ��������еĿ� */
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    /* �������� */
    LinkedStr->head = NULL;
    LinkedStr->tail = NULL;
    LinkedStr->length = 0;
}

//������������
void strConcat_L(LString * NewStr,LString s1,LString s2)
{
    /* ������� */
    clearString_L(NewStr);

    /* ������������ֵ */
    Blocks *r = NewStr->head;
    Blocks *p = s1.head;
    Blocks *q = s2.head;
    int i = 0;  //����LinkedStr����ַ��ַ������±����
    int j = 0;  //����s1����ַ��ַ������±����
    int k = 0;  //����s2����ַ��ַ������±����

    while (p || q)
    {
        /* �����¿�r����ӵ�����LinkedStr�� */
        if(!r)
        {
            r = (Blocks *)malloc(sizeof(Blocks));
            if(!r)
            {
                printf("Malloc error!\n");
                exit(OVERFLOW);
            }
            //next�ÿ�
            r->next = NULL;

            if(!NewStr->head)
            {
                NewStr->head = NewStr->tail = r;
            } else{
                NewStr->tail->next = r;
                NewStr->tail = r;
            }
        }

        /* �ȱ�������s1��s1���еĿ鸴�Ƶ�����NewStr�к��ٱ�������s2 */
        if(p)
        {
            /* ��p���������Ƹ���r */
            while (p && p->ch[j])
            {
                r->ch[i] = p->ch[j];
                i = (i + 1) % BLOCK_SIZE;
                j = (j + 1) % BLOCK_SIZE;

                /* ����s1��ǰ����� */
                if(!j || !(p->ch[j]))
                {
                    MoveToNext(p);
                }

                /* ����NewStr��ǰ����� */
                if(!i)
                {
                    MoveToNext(r);
                    break;
                }

            }
        } else{
            /* ��q���������Ƹ���r */
            while (q && q->ch[k])
            {
                r->ch[i] = q->ch[k];
                i = (i + 1) % BLOCK_SIZE;
                k = (k + 1) % BLOCK_SIZE;

                /* ����s2��ǰ����� */
                if(!k || !(q->ch[k]))
                {
                    MoveToNext(q);
                }

                /* ����NewStr��ǰ����� */
                if(!i)
                {
                    MoveToNext(r);
                    break;
                }
            }
        }
    }
}

//��ȡ����
Status subString_L(LString * sub,LString LinkedStr,unsigned int pos,unsigned int length)
{
    /* ��ʼ������ */
    initString_L(sub);

    /* LinkedStrΪ�մ�ʱ����ERROR */
    if(IsEmpty_L(LinkedStr))
    {
        return ERROR;
    }

    /* �жϽ�ȡλ���Ƿ�Խ�� */
    if(pos < 1 || pos > LinkedStr.length || pos + length - 1 > LinkedStr.length)
    {
        printf("posλ�÷Ƿ���\n");
        return ERROR;
    }

    /* ��������LinkedStr�ĵ�posλ�õĿ� */
    Blocks *p = LinkedStr.head;
    int count = 1;
    for (count = 1; pos > count * BLOCK_SIZE ; ++count) {
        MoveToNext(p);
    }

    /* ��������sub����ֵ */
    Blocks *r = sub->head;
    int i = 0;                      //i��¼��pos��ʼ���ַ�������
    int j = 0;                      //j����sub
    int k = (pos % BLOCK_SIZE) - 1; //k����s

    /* ���ȴﵽlength�������� */
    while (i < length)
    {
        /* �½���r����ӵ�����sub�� */
        if(!r)
        {
            r = (Blocks *)malloc(sizeof(Blocks));
            if(!r)
            {
                printf("Malloc error!\n");
                exit(OVERFLOW);
            }
            //next�ÿ�
            r->next = NULL;

            if(!sub->head)
            {
                sub->head = sub->tail = r;
            } else{
                sub->tail->next = r;
                sub->tail = r;
            }
        }

        /* ���ȴﵽlengthʱ���������� */
        while (i < length)
        {
            r->ch[j] = p->ch[k];
            j = (j + 1) % BLOCK_SIZE;
            k = (k + 1) % BLOCK_SIZE;
            i++;

            /* p����� */
            if(!k)
            {
                MoveToNext(p);
            }

            /* r����� */
            if(!j)
            {
                MoveToNext(r);
                break;
            }
        }
    }
    /* ��������sub���� */
    sub->length = length;

    /* �ҵ���һ������λ�ã���ӽ����� */
    count = (sub->length - 1) % BLOCK_SIZE + 1;
    while (count < BLOCK_SIZE)
    {
        sub->tail->ch[count++] = '\0';
    }
    return SUCCESS;
}

//�������Ӵ�ƥ��
unsigned int index_L(LString parent,LString child,unsigned int pos)
{
    if(pos > 0 && pos <= parent.length)
    {
        unsigned int i = pos;
        while (i + child.length - 1 <= parent.length)
        {
            LString sub;
            //subΪ��parent�ĵ�һ���ַ��𣬳���Ϊchild.length���Ӵ�
            subString_L(&sub,parent,i,child.length);

            if(strCompare_L(sub,child) != 0)
            {
                i++;
            } else{
                return i;
            }
        }
    }
    return ERROR;
}

//�������滻
Status strReplace_L(LString * LinkedStr,LString s1,LString s2)
{
    if(IsEmpty_L(*LinkedStr))
    {
        return ERROR;
    }

    /* �������ĵ�һ���ַ���ʼƥ�� */
    unsigned int i = index_L(*LinkedStr,s1,1);
    while (i)
    {
        //ɾ��������LinkedStr�г��ֵĵ�һ������s1
        strDelete_L(LinkedStr,i,strLength_L(s1));
        //������LinkedStr�е�iλ�ò���s2
        strInsert_L(LinkedStr,i,s2);
        //ƥ����ʼλ���ƶ�
        i += strLength_L(s2);
        //����ƥ���ַ�����ֱ��ȫ���滻
        i = index_L(*LinkedStr,s1,i);
    }
    return SUCCESS;
}

//��ָ��λ�ò����ַ�
Status strInsert_L(LString * LinkedStr, unsigned int pos,LString L)
{
    int i,j,k,count;
    Blocks *r,*p1,*p2,*q;
    LString temp;

    //�ж�pos�Ƿ�Ϸ�
    if(pos < 1 || pos > LinkedStr->length + 1)
    {
        return ERROR;
    }
    initString_L(&temp);

    r = temp.head;
    p1 = LinkedStr->head;
    p2 = NULL;
    q = L.head;
    i = j = k = 0;
    count = 1;

    while (p1 || p2 || q){
        if(!r){
            r = (Blocks *)malloc(sizeof(Blocks));
            if(!r){
                printf("Malloc error!\n");
                exit(OVERFLOW);
            }
            //next�ÿ�
            r->next = NULL;

            if(!temp.head){
                temp.head = temp.tail = r;
            } else{
                temp.tail->next = r;
                temp.tail = r;
            }
        }

        if(p1){
            while (p1 && count < pos){
                r->ch[i] = p1->ch[j];
                i = (i + 1) % BLOCK_SIZE;
                j = (j + 1) % BLOCK_SIZE;
                count++;

                if(!j || !(p1->ch[j])){
                    MoveToNext(p1);
                }
                if(!i){
                    MoveToNext(r);
                    break;
                }
            }
            if(count == pos){
                p2 = p1;
                p1 = NULL;
            }
        } else if(q){
            while (q && q->ch[k]){
                r->ch[i] = q->ch[k];
                i = (i + 1) % BLOCK_SIZE;
                k = (k + 1) % BLOCK_SIZE;

                if(!k || !(q->ch[k])){
                    MoveToNext(q);
                }
                if(!i)
                {
                    MoveToNext(r);
                    break;
                }
            }
        } else{
            while (p2 && p2->ch[j]){
                r->ch[i] = p2->ch[j];
                i = (i + 1) % BLOCK_SIZE;
                j = (j + 1) % BLOCK_SIZE;

                if(!j || !(p2->ch[j])){
                    MoveToNext(p2);
                }
                if(!i){
                    MoveToNext(r);
                    break;
                }
            }
        }
    }

    temp.length = LinkedStr->length + L.length;

    count = (temp.length - 1) % BLOCK_SIZE + 1;
    while (count < BLOCK_SIZE){
        temp.tail->ch[count++] = '\0';
    }

    clearString_L(LinkedStr);

    LinkedStr->length = temp.length;
    LinkedStr->head = temp.head;
    LinkedStr->tail = temp.tail;

    return SUCCESS;
}

//ɾ��������ָ��λ��ָ�����ȵ�����
Status strDelete_L(LString * LinkedStr, unsigned int pos, unsigned int length)
{
    if(IsEmpty_L(*LinkedStr))
    {
        return ERROR;
    }

    int count,first,last,m,n;
    Blocks *r,*p,*q;

    if(pos < 1 || pos > LinkedStr->length || pos + length - 1 > LinkedStr->length || length < 0){
        return ERROR;
    }
    if(pos == 1 && length == LinkedStr->length){
        clearString_L(LinkedStr);
    }

    first = pos;
    last = pos + length - 1;

    //ʹpָ��first���ڵĿ�
    for (count = 1, p = LinkedStr->head; first > count * BLOCK_SIZE ; ++count,MoveToNext(p));
    //ʹqָ��last���ڵĿ�
    for (q = p;last > count * BLOCK_SIZE;++count,MoveToNext(q));

    m = (first - 1) % BLOCK_SIZE;
    n = (last - 1) % BLOCK_SIZE;
    n = (n + 1) % BLOCK_SIZE;
    if(!n){
        MoveToNext(q);
    }

    while (q && q->ch[n]){
        p->ch[m] = q->ch[n];
        m = (m + 1) % BLOCK_SIZE;
        n = (n + 1) % BLOCK_SIZE;

        if(!m){
            MoveToNext(p);
        }
        if(!n){
            MoveToNext(q);
        }
    }

    LinkedStr->length -= length;

    //rָ��ɾ�������յ���
    for(count = 1,LinkedStr->tail = LinkedStr->head;LinkedStr->length > count * BLOCK_SIZE;++count,MoveToNext(LinkedStr->tail));

    count = (LinkedStr->length - 1) % BLOCK_SIZE + 1;
    while (count < BLOCK_SIZE){
        LinkedStr->tail->ch[count++] = '\0';
    }

    r = LinkedStr->tail->next;
    while (r){
        LinkedStr->tail->next = r->next;
        free(r);
        r = LinkedStr->tail->next;
    }
    return SUCCESS;
}

//��������
void destoryString(LString * LinkedStr)
{
    if(IsEmpty_L(*LinkedStr))
    {
        LinkedStr = NULL;
    } else
    {
        clearString_L(LinkedStr);
        LinkedStr = NULL;
    }
}

//��ӡ����������
void printString_L(LString LinkedStr)
{
    if(IsEmpty_L(LinkedStr))
    {
        printf("����Ϊ�գ����ʧ��!\n");
        return;
    }

    Blocks *p = LinkedStr.head;
    int i = 0;

    while (p)
    {
        if(p->ch[i])
        {
            printf("%c",p->ch[i]);
        }

        /* ��������Ϊ0����˵����û�н��� */
        i = (i + 1) % BLOCK_SIZE;
        if(!i)
        {
            MoveToNext(p);
        }
    }
}