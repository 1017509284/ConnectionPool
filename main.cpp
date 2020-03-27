#include <iostream>
using namespace std;
#include "Connection.h"
#include "CommonConnectionPool.h"
int main()
{
    /*clock_t begin=clock();
    for (int i = 0; i < 1000; ++i)
	{
		Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "123456", "connectpool");
		conn.update(sql);
	}
    clock_t end=clock();
    cout<<end-begin<<"ms"<<endl;*/



    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    clock_t begin=clock();
    for(int i=0;i<1000;i++)
    {
        char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')","zhang san", 20, "male");
        shared_ptr<Connection> sp=cp->getConnection();
        sp->update(sql);
    }
    clock_t end=clock();
    cout<<end-begin<<"ms"<<endl;
    return 0;
}
