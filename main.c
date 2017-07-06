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
    int choice;//皇帝的选择，1~4 之间
    int i, j, tempOrder;
    int searchIndex2 = -1; //用来记录要查找的数组元素的下标
    int searchIndex3 = -1;
    int searchIndex4 = -1;
    int count = 5;                  //当前妃子的数量
    char names[MAX][20] = {"貂蝉", "飞火", "西施", "郭德纲", "林志玲"};
    char levelNames[][10] = {"贵人", "嫔妃", "贵妃", "皇贵妃", "皇后"};
    int level[MAX] = {0, 0, 0, 2, 4, -1, -1};
    int loves[MAX] = {100, 100, 100, 100, 100, -1, -1};
 /*   //测试代码;
    printf("查看当前妃子的状态！\n");
    printf("%-10s级别\t状态\n","姓名");
    for(i = 0; i < count; i++)
    {
        printf("%-10s%s\t%d\n",names[i],levelNames[level[i]],loves[i]);
    }
*/
 printf("请输入当前皇帝的名号：\n");
    scanf("%s",emperorName);
    printf("皇帝%s驾临！\n吾皇万岁万岁万万岁！\n",emperorName);


do
{



PlaySound(TEXT("sounds\\Welcome.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);//背景音乐
printf("*****************************\n");

      printf("当前妃子的状态！\n");
    printf("%-20s级别\t好感度\n","姓名");
    for(i = 0; i < count; i++)
    {
        printf("%-20s%s\t%d\n",names[i],levelNames[level[i]],loves[i]);
    }
printf("*****************************\n");


    printf("第%d天\n",++curryDay);
    printf("陛下请选择\n");
    printf("1、皇帝下旨选妃：\t\t（增加功能）\n");
    printf("2、翻牌宠幸：\t\t（修改状态）\n");
    printf("3、打入冷宫：\t\t（删除功能）\n");
    printf("4、单独召见：去小树林。（增加功能）\n");
    printf("陛下请选择：\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1://皇帝下旨选妃：\t\t（增加功能）
           //1、判断数组有无空间
           //2、增加数组元素 names[],level[],loves[]
 PlaySound(TEXT("sounds\\Normal.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);//背景音乐

           if(count < MAX)
           {
               //增加
               printf("请输入娘娘名讳：");
               scanf("%s",names[count]);
               level[count] = 0;
               loves[count] = 100;
               count++;

           }
           else
           {
               printf("请陛下注意龙体！后宫已满！");
           }
        break;
    case 2://翻牌宠幸：\t\t（修改状态）
        //1、查找
        //2、修改状态1、好感度+10 级别+1，如果最高不再升级  2、其他妃子好感度-10
 do{
        printf("请陛下输入要宠幸的妃子！\n");
        scanf("%s",tempNames);

        //字符串的查找，strcmp


         for(i = 0; i < count; i++)
        {

        if(strcmp(tempNames,names[i]) == 0)
              {
                  searchIndex2 = i;
                  break;
              }

        }
            if(-1 == searchIndex2)
                printf("陛下请恕罪，未找到您要宠幸的娘娘！");
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
    case 3:          //打入冷宫：\t\t（删除功能）
          printf("请陛下输入要打入冷宫的娘娘名讳！\n");
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
             printf("虚惊一场！无人被打入冷宫！\n");
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
    case 4:   //单独召见：去小树林。（增加功能）
              //1、查找；2、增加好感度；

    do{
          printf("请陛下输入要单独召见的娘娘名讳\n");
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
                printf("陛下，您要召见的娘娘不再宫中！\n");
        else
    {
                for(i = 0; i < count; i++)
                {
                    if(strcmp(temp4 , names[i]) == 0)
                    {
                        loves[i] += 10;
                        printf("%s的好感度增加了10！\n",names[i]);
                        break;
                    }

                }
    }


 }while(-1 == searchIndex4);

        break;


    default:
        printf("君无戏言，陛下请再次确认！\n");

    }


    //打印之前 冒泡   排序
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

    printf("测试代码：查看当前妃子的状态！\n");
    printf("%-20s级别\t状态\n","姓名");
    for(i = 0; i < count; i++)
    {
        printf("%-20s%s\t%d\n",names[i],levelNames[level[i]],loves[i]);
    }
printf("*****************************\n");

}
while(curryDay < DAY_COUNT);

    return 0;

}
