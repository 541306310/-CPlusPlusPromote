// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "List.hpp"

int main()
{
    TList<int> list;
    for (int i =0 ;i<10;i++)
    {
        list.push(i);
    }

    list.Show();
//    list.Insert(5, 999);
    list.Remove(5);
    list.Show();
}


