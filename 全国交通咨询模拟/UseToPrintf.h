#include"RowColWeight.h"
#include"Path.h"
#include"Save_all_Train.h"
class RecordTrains{
public:
	int m_col;   //���ﳵվ
	int m_row;  //������վ
	double m_start;   //��¼����ʱ��
 	double m_arrive;   //��¼�ﵽʱ��
	string m_train;  //����ĳ��α��
};
class UseToPrintf{ 
public:
	SeqList<RecordTrains> m_UseToPrintf;
	double m_alltime;  //�洢����������ʱ��
	UseToPrintf(){m_alltime=0;};
};
