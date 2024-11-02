#include <stdio.h>
#include <stdlib.h>

typedef struct node//定义结构 名字是struct node
{
    int number;
    struct node* next;//引用
}node;//将struct node 缩为node表达

int main(int argc,char* argv[])
{
    node* list=NULL;
    for(int i=1;i<argc;i++)//注意是i=1,否则会将./...本身也作为参数
    {
        int number = atoi(argv[i]);
        node *n=malloc(sizeof(node));
        if(n==NULL) return 1;
        n->number=number;
        n->next=NULL;
        if(list==NULL) list=n;
        else if(n->number<list->number)//小于起始数，插入至表头
        {
            n->next=list;
            list=n;
        }
        //n->number>list->number,即大于起始数，要遍历寻找合适插入点
        else
        {    
            for(node* ptr=list;ptr!=NULL;ptr=ptr->next)
            {
                if(ptr->next==NULL) {ptr->next=n;break;}//next指向空，说明已经到表尾，插入至表尾
                if(n->number<ptr->next->number)
                //小于下一个数，隐含条件为大于等于现在的数（因为是遍历），插入中间
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    break;                    
                }
            }
        }
    }
    //打印
    node* ptr=list;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
    free(list);
    free(ptr);
    free(n);
}