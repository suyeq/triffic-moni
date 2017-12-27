#include"TreeNode.h"
#include<string>
using namespace std;
class RowColWeight{
public:
	int m_row;							//某站编号
	int m_col;							//下一站站编号
	SeqList<string> rowcol_station;    //该线路段拥有的车号信息
	double m_money;							//权值
}; 
//边的信息

