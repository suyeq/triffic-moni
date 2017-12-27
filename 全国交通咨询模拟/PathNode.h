//包含了关于所有路线信息:开车时间，等待时间，下一个结点指针
#include"Station.h"
class PathNode{
public:
	int m_station;   //该站台编号
	double m_arrive;   //到达时间
	double m_start;   //出发时间
};
