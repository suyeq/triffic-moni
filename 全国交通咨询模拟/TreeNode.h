#include"SeqList.h"
class TreeNode{
public:
	int m_hasNeighborCount;   //�洢ĳվ��ӵ�վ̨����	
	int m_stationInNode;      //��ǰ�ڵ��վ̨���
	TreeNode *pm_next;    //����ָ���������վ̨�ı���ڵ� 
	int size;    //��ǰ�ڵ����
	SeqList<int> m_hasVisitStation;        //������¼��ǰ·��
	TreeNode(){size=0;}
};

