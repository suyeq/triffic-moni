#include"SeqList.h"
class TreeNode{
public:
	int m_hasNeighborCount;   //存储某站相接的站台个数	
	int m_stationInNode;      //当前节点的站台编号
	TreeNode *pm_next;    //用来指向所有相接站台的保存节点 
	int size;    //当前节点个数
	SeqList<int> m_hasVisitStation;        //用来记录当前路径
	TreeNode(){size=0;}
};

