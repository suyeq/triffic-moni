#include"RowColWeight.h"
#include"Path.h"
#include"Save_all_Train.h"
class RecordTrains{
public:
	int m_col;   //到达车站
	int m_row;  //出发车站
	double m_start;   //记录出发时间
 	double m_arrive;   //记录达到时间
	string m_train;  //自身的车次编号
};
class UseToPrintf{ 
public:
	SeqList<RecordTrains> m_UseToPrintf;
	double m_alltime;  //存储该条方案的时间
	UseToPrintf(){m_alltime=0;};
};
