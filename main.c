#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.Lib")
#define MAX 7
#include <string.h>
#define DAY_COUNT 10
int main()
{
    char emperorName[20];
    char tempNames[20];
    char tempDel[20];
    char temp4[20];
    int curryDay = 0;
    int choice;//�ʵ۵�ѡ��1~4 ֮��
    int i, j, tempOrder;
    int searchIndex2 = -1; //������¼Ҫ���ҵ�����Ԫ�ص��±�
    int searchIndex3 = -1;
    int searchIndex4 = -1;
    int count = 5;                  //��ǰ���ӵ�����
    char names[MAX][20] = {"����", "�ɻ�", "��ʩ", "���¸�", "��־��"};
    char levelNames[][10] = {"����", "����", "����", "�ʹ���", "�ʺ�"};
    int level[MAX] = {0, 0, 0, 2, 4, -1, -1};
    int loves[MAX] = {100, 100, 100, 100, 100, -1, -1};
 /*   //���Դ���;
    printf("�鿴��ǰ���ӵ�״̬��\n");
    printf("%-10s����\t״̬\n","����");
    for(i = 0; i < count; i++)
    {
        printf("%-10s%s\t%d\n",names[i],levelNames[level[i]],loves[i]);
    }
*/
 printf("�����뵱ǰ�ʵ۵����ţ�\n");
    scanf("%s",emperorName);
    printf("�ʵ�%s���٣�\n����������������꣡\n",emperorName);


do
{



PlaySound(TEXT("sounds\\Welcome.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);//��������
printf("*****************************\n");

      printf("��ǰ���ӵ�״̬��\n");
    printf("%-20s����\t�øж�\n","����");
    for(i = 0; i < count; i++)
    {
        printf("%-20s%s\t%d\n",names[i],levelNames[level[i]],loves[i]);
    }
printf("*****************************\n");


    printf("��%d��\n",++curryDay);
    printf("������ѡ��\n");
    printf("1���ʵ���ּѡ����\t\t�����ӹ��ܣ�\n");
    printf("2�����Ƴ��ң�\t\t���޸�״̬��\n");
    printf("3�������乬��\t\t��ɾ�����ܣ�\n");
    printf("4�������ټ���ȥС���֡������ӹ��ܣ�\n");
    printf("������ѡ��\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1://�ʵ���ּѡ����\t\t�����ӹ��ܣ�
           //1���ж��������޿ռ�
           //2����������Ԫ�� names[],level[],loves[]
 PlaySound(TEXT("sounds\\Normal.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);//��������

           if(count < MAX)
           {
               //����
               printf("�������������䣺");
               scanf("%s",names[count]);
               level[count] = 0;
               loves[count] = 100;
               count++;

           }
           else
           {
               printf("�����ע�����壡��������");
           }
        break;
    case 2://���Ƴ��ң�\t\t���޸�״̬��
        //1������
        //2���޸�״̬1���øж�+10 ����+1�������߲�������  2���������Ӻøж�-10
 do{
        printf("���������Ҫ���ҵ����ӣ�\n");
        scanf("%s",tempNames);

        //�ַ����Ĳ��ң�strcmp


         for(i = 0; i < count; i++)
        {

        if(strcmp(tempNames,names[i]) == 0)
              {
                  searchIndex2 = i;
                  break;
              }

        }
            if(-1 == searchIndex2)
                printf("������ˡ�δ�ҵ���Ҫ���ҵ����");
            else
            {
                 for(i = 0; i < count; i++)
                {
                  if(strcmp(tempNames,names[i]) == 0)
                            {
                                loves[i] += 10;
                                level[i] >= 4 ? 4 : level[i]++;
                            }
                else
                {
                  loves[i] -= 10;
                }
               }
            }


 }while(-1 == searchIndex2);

        break;
    case 3:          //�����乬��\t\t��ɾ�����ܣ�
          printf("���������Ҫ�����乬���������䣡\n");
        scanf("%s",tempDel);
        for(i = 0; i < count; i++)
                {
                  if(strcmp(tempDel,names[i]) == 0)
                            {
                                searchIndex3 = i;
                                break;
                            }
                }
         if(-1 == searchIndex3)
         {
             printf("�龪һ�������˱������乬��\n");
         }
         else
         {
             for(i = searchIndex3; i < count - 1; i++)
             {
                 strcpy(names[i],names[i+1]);
                 level[i] = level[i+1];
                 loves[i] = loves[i+1];
             }
             count--;

             for(i = 0; i < count; i++)
             {
                 loves[i] += 10;

             }
         }


        break;
    case 4:   //�����ټ���ȥС���֡������ӹ��ܣ�
              //1�����ң�2�����Ӻøжȣ�

    do{
          printf("���������Ҫ�����ټ�����������\n");
          scanf("%s",temp4);

              for(i = 0; i < count; i++)
            {

            if(strcmp(temp4,names[i]) == 0)
                {
                  searchIndex4 = i;
                  break;
                }

            }
                if(-1 == searchIndex4)
                printf("���£���Ҫ�ټ������ﲻ�ٹ��У�\n");
        else
    {
                for(i = 0; i < count; i++)
                {
                    if(strcmp(temp4 , names[i]) == 0)
                    {
                        loves[i] += 10;
                        printf("%s�ĺøж�������10��\n",names[i]);
                        break;
                    }

                }
    }


 }while(-1 == searchIndex4);

        break;


    default:
        printf("����Ϸ�ԣ��������ٴ�ȷ�ϣ�\n");

    }


    //��ӡ֮ǰ ð��   ����
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if (level[j] < level[j + 1])
            {
                tempOrder = level[j];
                level[j] = level[j + 1];
                level[j + 1] = tempOrder;
                tempOrder = loves[j];
                loves[j] = loves[j + 1];
                loves[j + 1] = tempOrder;
                strcpy(tempNames,names[j]);
                strcpy(names[j],names[j + 1]);
                strcpy(names[j + 1],tempNames);
            }


        }
    }


printf("*****************************\n");

    printf("���Դ��룺�鿴��ǰ���ӵ�״̬��\n");
    printf("%-20s����\t״̬\n","����");
    for(i = 0; i < count; i++)
    {
        printf("%-20s%s\t%d\n",names[i],levelNames[level[i]],loves[i]);
    }
printf("*****************************\n");

}
while(curryDay < DAY_COUNT);

    return 0;

}
