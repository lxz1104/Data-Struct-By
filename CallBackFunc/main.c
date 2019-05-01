#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���庯��ָ��
typedef void(SKILL)(void);

//�������Խṹ
typedef struct {
    //��������
    char name[32];
    //�����Ǽ�
    char star[32];
    //�����ļ��ܣ��ں�����ʵ�֣����ú���ָ����ã����÷��൱��c++�еĳ������еĴ��麯��
    SKILL * skill;
}Weapon;

//������������
Weapon * create_weapon(const char * name,const char * star,SKILL *skill)
{
    Weapon * weapon = (Weapon *)malloc(sizeof(Weapon));
    if(!weapon)
    {
        return NULL;
    }
    strcpy(weapon->name,name);
    strcpy(weapon->star,star);
    //ע��ص�������Ϊ�ص�����ָ�븳ֵ
    weapon->skill = skill;
    return weapon;
}

//������������
void destroy_weapon(Weapon ** pWeapon)
{
    if(pWeapon)
    {
        free(*pWeapon);
        *pWeapon = NULL;
    }
}

//����չʾ�����ĺ���
void show_weapon(Weapon * pWeapon)
{
    printf("��������:%s\n",pWeapon->name);
    printf("�Ǽ�:%s\n",pWeapon->star);
    printf("����:\n");
    pWeapon->skill();
    printf("-------------------------\n");
}



//����1
void skill1()
{
    printf("+80������\n");
    printf("+25%%��������\n");
    printf("Ψһ����:�������225%%�˺�������200%%\n");
}

//����2
void skill2()
{
    printf("+40%%�����ٶ�\n");
    printf("+25������\n");
    printf("Ψһ������ÿ����ͨ���������20�ƶ��ٶȣ�����2�롣ÿ�λ�ɱ��λ�󣬻��60�ƶ��ٶȣ���ǰ�߲����ӣ�������ƶ��ٶȼӳɶ�Զ��Ӣ�ۼ��롣\n");
}

//����3
void skill3()
{
    printf("+120����ǿ��\n");
    printf("Ψһ����:����ǿ������40%%\n");
}


int main() {
    //������������
    Weapon * weapon1 = create_weapon("�޾�֮��","������",skill1);
    Weapon * weapon2 = create_weapon("����֮��","��������",skill2);
    Weapon * weapon3 = create_weapon("������ʦñ","���������",skill3);

    //���ú�����ʾ��������
    show_weapon(weapon1);
    show_weapon(weapon2);
    show_weapon(weapon3);

    //������������
    destroy_weapon(&weapon1);
    destroy_weapon(&weapon2);
    destroy_weapon(&weapon3);
    return 0;
}