// testMySQL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <winsock.h>
#include <mysql.h>
#include <iostream>
using namespace std;
void test()
{
    MYSQL* pConn;
    pConn = mysql_init(NULL);
    if (mysql_real_connect(pConn, "localhost", "root", "root19537", "test", 0, NULL, 0))
    {
        cout << "成功连接MySQL数据库" << endl;
        mysql_query(pConn, "set names gbk");
       
        if (!mysql_query(pConn, "select * from tb_product;"))
        {
            MYSQL_RES* result = mysql_store_result(pConn);
            MYSQL_ROW row;
            while (row = mysql_fetch_row(result))
            {
                cout << row[0] << " " << row[1] << endl;
            }
            mysql_free_result(result);
        }
        else
        {
            cout << "查询失败：" << mysql_errno(pConn) << endl;
            return;
        }
        mysql_close(pConn);
        return;
    }
    else
    {
        cout << "无法连接MySQL数据库:" << mysql_errno(pConn) << endl;
        return;
    }
}

int main()
{
    test();
    return 0;
}

