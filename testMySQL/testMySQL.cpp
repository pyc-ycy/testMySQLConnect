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
        // 增加数据
        //mysql_query(pConn, "insert into tb_product(name,price,num,unit) values('萝卜',63.4,80,'袋');");
        //修改数据
        //mysql_query(pConn, "update tb_product set num=100 where name='猕猴桃';");
        //删除数据
        //mysql_query(pConn, "delete from tb_product where unit='袋'");
        //查询数据
        if (!mysql_query(pConn, "select * from tb_product;"))
        {
            MYSQL_RES* result = mysql_store_result(pConn);
            MYSQL_ROW row;
            cout << "ID\tName\tprice\tnum\tunit" << endl;
            while (row = mysql_fetch_row(result))
            {
                cout << row[0] << '\t' << row[1] << '\t' << row[2] << '\t' << row[3] << '\t' << row[4] << endl;;
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

