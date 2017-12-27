#include"PathNode.h"
class Path{
public:
	PathNode * m_first;   //头指针，指向始发车站
	string m_trian;
	int all_through_station;   //经过车站的总数
};
//每一车次对应的线路