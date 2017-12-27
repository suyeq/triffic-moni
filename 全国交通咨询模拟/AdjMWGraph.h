#include"UseToPrintf.h"
#include<iostream>
#include<iomanip>
#include<fstream>
class AdjMWGraph
{
private:
	SeqList<Station> Vertices;  //ͼ�Ķ���	
	double Edge[100][100];  //�ߵ�Ȩֵ��Ϣ
	int numOfEdges;    //�ߵĸ���

public:
	AdjMWGraph(const int sz = 100);			//���캯��
	~AdjMWGraph(void){};						 	//��������

	int NumOfVertices(void)	const						//ȡ�������
		{return Vertices.Size();}
	int NumOfEdges(void)const							//ȡ�ߵĸ���
		{return numOfEdges;}
	Station GetValue(const int v)const;	//ȡ������ֵ
	void DeleteEdge(const int v1, const int v2);     //ɾ����
	double GetWeight(const int v1, const int v2)const;		//ȡ�ߵ�Ȩֵ
	void InsertVertex(const Station &vertex);			//���붥��
	void InsertEdge(const int v1, const int v2, double weight);//�����
	int GetFirstNeighbor(const int v)const;				//ȡ��һ���ڽӶ���
	int GetNextNeighbor(const int v1, const int v2)const;//ȡ��һ���ڽӶ���
	int IsVertex(int v)const;  // �ж϶���vertex�Ƿ�������ͼG�Ķ���
	int IsVertex(string vertex)const;	
	int IsEdge(int v1,int v2)const;		//�жϵ�v1�����㵽��v2������ı��Ƿ�������ͼG�ıߣ����򷵻�1�����򷵻�0�� 
	void Creat(AdjMWGraph &G, SeqList<Station> station, int n, SeqList<RowColWeight> rowcolweight,int e);
	void IfileStation(SeqList<Station> & );    //��Station�ļ��������г�վ��Ϣ���ڴ�
	void IfileStationOfPlane(SeqList<Station> &);
	void IfileRowColWeight(SeqList<RowColWeight> &) ; //��RowColWeight�ļ��ж������бߵ���Ϣ
	void IfileRowColWeightOfPlane(SeqList<RowColWeight> &);
	void IfilePath(SeqList<Path> &);   //��Path�ļ��ж�ȡ�г�ʱ�̱�
	void IfilePathOfPlane(SeqList<Path> &);  
	void AddStation(SeqList<Station> &,AdjMWGraph &);    //��ӳ�վ��Ϣ
	void GetTrainsToEdge(SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &);   //���ڴ��е�ʱ�̱��ȡÿ���������ļ��г���
	void AddTrain(SeqList<Station> &,SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &); //����µ��г�����·��
	bool IshasTrain(SeqList<Path> &,string);    //�жϸû��Ƿ����
	void IsNeedAddRowColWeight(string ,SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &);   //����������ʱ����Ҫ����·�ߣ�������
	void ShowAllStaion(SeqList<Station> &);   //������г�վ��Ϣ
	TreeNode FindAllPath(SeqList<Station> &,SeqList<RowColWeight> &,AdjMWGraph &,SeqList<Path> &);  //Ѱ������·��
	int GetNeighborCount(int,AdjMWGraph &G);   //��ȡĳվ�ж����ٽ�վ
	void GetNeighborStation(TreeNode &,TreeNode * ,AdjMWGraph &);  //���ٽ�վ��������
	void RecurseFind(int,int,TreeNode ,TreeNode &,AdjMWGraph &,SeqList<SeqList<int>>&) ;         //�ݹ�Ĳ���
	bool CheckSameStationInVisit(SeqList<int> &);   //���� 
	//void GetSuitPath(TreeNode &,int ,SeqList<SeqList<int>>&);    //������·�����ҵ����ʵ�·��
	void GetRowColWeight(SeqList<SeqList<RowColWeight>> &,SeqList<SeqList<int>> &,SeqList<RowColWeight> &);
	//��ÿһ��·����Ӧ�ı߰�˳�򱣴�����
	void LeastCostWay(SeqList<SeqList<RowColWeight>> &,AdjMWGraph &);  //��Ѱ��̻��ѷ��������
	void LeastTimeWay(SeqList<SeqList<string>> &,SeqList<SeqList<RowColWeight>> &,AdjMWGraph &,SeqList<Path> &);   //��Ѱ���ʱ�䷽�������
	void SearchPath(SeqList<Path> &,AdjMWGraph &);   //��ѯı�л���Ϣ
	void PrintfPath(Path &,AdjMWGraph &);    //��ӡı�л���Ϣ
	void GetAPathOfTrain(SeqList<Save_all_Train> &,SeqList<SeqList<string>> &,SeqList<SeqList<RowColWeight>> &,AdjMWGraph &);
	//��һ��·�����ҳ����п��ܵĳ�������
	int GetCalculate(int,SeqList<RowColWeight> &);  //��ĳ��·���м����ȥK����������С�˻�
	void FullColTrain(int,int,int,Save_all_Train &,SeqList<RowColWeight> &);    //��ÿ��������д�г�����
	void CalculateALLTime(SeqList<Save_all_Train>&,SeqList<SeqList<RowColWeight>>&,SeqList<Path> &,AdjMWGraph &);
	//������ʱ��
	void GetATrainInformation(int i,int j,SeqList<Save_all_Train>&,SeqList<Path> &,SeqList<SeqList<RowColWeight>>&,SeqList<UseToPrintf>&);//�Ӿ������ȡ��Ϣ
	void PrintfPathOfTime(SeqList<UseToPrintf>&,AdjMWGraph &);  //��ӡ
	void Face(SeqList<Station> &,SeqList<Path> & ,AdjMWGraph &,SeqList<RowColWeight> &); //��������
	void DeleteTrain(SeqList<Station> &,SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &);//ɾ���г�����
	void ShowAllTrain(SeqList<Path> &,AdjMWGraph &);//�鿴�����г�
	void OfileStation(SeqList<Station> & );    //��Station�ļ��������г�վ��Ϣ���ڴ�
	void OfileStationOfPlane(SeqList<Station> & );
	void OfileRowColWeight(SeqList<RowColWeight> &) ; 
	void OfileRowColWeightOfPlane(SeqList<RowColWeight> &) ; 
	void OfilePath(SeqList<Path> &);   //��Path�ļ��ж�ȡ�г�ʱ�̱�
	void OfilePathOfPlane(SeqList<Path> &);   //��Path�ļ��ж�ȡ�г�ʱ�̱�
	UseToPrintf  & operator =(UseToPrintf &b);  
};
UseToPrintf & AdjMWGraph::operator=(UseToPrintf & b){
	UseToPrintf a;
	a.m_alltime=b.m_alltime;
	for(int i=0;i<b.m_UseToPrintf.Size();i++){
		a.m_UseToPrintf[i].m_arrive=b.m_UseToPrintf[i].m_arrive;
		a.m_UseToPrintf[i].m_col=b.m_UseToPrintf[i].m_col;
		a.m_UseToPrintf[i].m_row=b.m_UseToPrintf[i].m_row;
		a.m_UseToPrintf[i].m_start=b.m_UseToPrintf[i].m_start;
		a.m_UseToPrintf[i].m_train=b.m_UseToPrintf[i].m_train;
	}
	return a;
}
AdjMWGraph::AdjMWGraph(const int sz): Vertices(sz)
//���캯��
{
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
		{
			if(i == j) {
				Edge[i][j]=0;
			}
			else{
				Edge[i][j]=-1;
			}
		}
	numOfEdges = 0;
}
Station AdjMWGraph::GetValue(const int v)const
//ȡ����v����ֵ
{
	if(IsVertex(v)==0)//�ж����v�ĺϷ���
	{
		cout << "����vԽ�����!" << endl;
		exit(0);
	}
	return Vertices.GetData(v);
}
double AdjMWGraph::GetWeight(const int v1, const int v2)const
//ȡ��ʼ����Ϊv1����ֹ����Ϊ v2�ıߵ�Ȩֵ
{
	if(IsVertex(v1)==0 || IsVertex(v2)==0)//�ж����v1��v2�ĺϷ���
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}
	return Edge[v1][v2];
}
void AdjMWGraph::InsertVertex(const Station &vertex)
//���붥��vertex
{
	if (IsVertex(vertex.m_station_name)<0)//�ж��Ƿ�ͼ���Ѿ���ֵΪvertex�Ķ��㣬ʱ�临�Ӷ�O(n��		
		Vertices.Insert(vertex, Vertices.Size());//�Ѷ���vertex���뵽˳���ĵ�ǰ��βλ��
	else 
		cout<<"�ó�վ�Ѵ��ڣ���ֹ��ӣ�"<<endl;
}
void AdjMWGraph::InsertEdge(const int v1, const int v2, double weight)
//����һ����ʼ����Ϊv1����ֹ����Ϊ v2��ȨֵΪweight�ı�
{
	switch (IsEdge(v1,v2))//�ж�ͼ�е�v1�����㵽��v2������ıߵ����
	{	
	case -2:			//���v1��v2��һ������ͼ�еĶ��㣬��ͼ���䣻
		break;
	case -1:			//���v1��v2��ȣ���ͼ���䡣
		break;
	case 0:				//����߲����ڣ���ߵ���Ŀ��1�������
		numOfEdges++;
	case 1:				//����ߴ��ڣ����޸�Ȩֵ
		;
	default:
		Edge[v1][v2]=weight;
	}
}
int AdjMWGraph::GetFirstNeighbor(const int v)const
{
	if(IsVertex(v)==0)//�ж����v�ĺϷ���
	{
		cout << "����vԽ�����!" << endl;
		exit(0);
	}
	/*Ѱ���ڽӾ���v���д�����ʼ��һ��ֵ�����ҷǸ�����Ȩֵ��Ӧ�Ķ���*/
	for(int col = 0; col < NumOfVertices(); col++)
		if(Edge[v][col]> 0) 
			return col;
	return -1;
}
int AdjMWGraph::GetNextNeighbor(const int v1, const int v2)const
{
	if(IsVertex(v1)==0 || IsVertex(v2)==0)//�ж����v1��v2�ĺϷ���
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}

	for(int col = v2+1; col <= NumOfVertices(); col++)
		if(Edge[v1][col]> 0 ) 
			return col;
	return -1;
} 
int AdjMWGraph::IsVertex(string vertex)const
{
	int i;
	for (i=0;i<NumOfVertices();i++)
	{
		if(Vertices.GetData(i).m_station_name==vertex)     
		{
			break;
		}
	}
	if (i==NumOfVertices())
		return -1;
	else
		return i;
}
int AdjMWGraph::IsVertex(int v)const
{	if(v < 0 || v >= NumOfVertices())
		return 0;
	else
		return 1;
} //ʱ�临�Ӷ�O(1)
void AdjMWGraph::DeleteEdge(const int v1, const int v2)
//ɾ��һ����ʼ����Ϊv1����ֹ����Ϊ v2�ı�
{
	switch (IsEdge(v1,v2))//�ж�ͼ�е�v1�����㵽��v2������ıߵ����
	{	
	case -2:	//���v1��v2��һ������ͼ�еĶ��㣬��ͼ���䣻
		break;
	case -1:	//���v1��v2��ȣ���ͼ���䣻
		break;
	case 0:		//���<v1,v2>����ͼ�ıߣ���ͼ���䣻
		break;
	case 1:		//���<v1,v2>��ͼ�ıߣ����ڴ�Ȩ����ͼG��ɾ����v1������ָ���v2�����������ߡ�
		{	
			Edge[v1][v2] =-1;/*�Ѹñߵ�Ȩֵ��Ϊ����󣬼�Ϊɾ���ñ�*/
			numOfEdges--;
		}
	default:;
	}
}
void AdjMWGraph::Creat(AdjMWGraph &G, SeqList<Station> V, int n, SeqList<RowColWeight> E,int e)
//��ͼG�в���n������V��e����E
{
	//��ͼG�в���n������
	for(int i = 0; i < n; i++) 
		G.InsertVertex(V[i]);

	//��ͼG�в���e����
	for(int k = 0; k < e; k++) 
		G.InsertEdge(E[k].m_row, E[k].m_col, E[k].m_money);
}
int AdjMWGraph::IsEdge(int v1,int v2)const
{
	if ( IsVertex(v1)==0 || IsVertex(v2)==0 )//�ж����v1��v2�ĺϷ���
		return -2;	//�ж��㲻����
	if ( v1==v2 )
		return -1;	//������ڣ�v1��v2���
	if ( Edge[v1][v2]== -1 )
		return 0;	//������ڣ�v1��v2����ȣ��߲�����
	return 1;		//�ߴ���

}
void AdjMWGraph::IfileStation(SeqList<Station> & station){
	fstream ifile;
	ifile.open("Station.txt");
	if(!ifile)  cout<<"Դ�ļ���ʧ��"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		Station temp;
		while(!ifile.eof()){
			ifile>>temp.m_station_name>>temp.m_station_id;
			station.Insert(temp,station.Size());
		}
		ifile.close();
	}
	
}
void AdjMWGraph::IfileStationOfPlane(SeqList<Station> & station){
      fstream ifile;
	ifile.open("StationOfPlane.txt");
	if(!ifile)  cout<<"Դ�ļ���ʧ��"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		Station temp;
		while(!ifile.eof()){
			ifile>>temp.m_station_name>>temp.m_station_id;
			station.Insert(temp,station.Size());
		}
		ifile.close();
	}
}
void AdjMWGraph::IfileRowColWeight(SeqList<RowColWeight> & row){
	fstream ifile;
	ifile.open("RowColWeight.txt");
	if(!ifile)  cout<<"Դ�ļ���ʧ��"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		while(!ifile.eof()){
			RowColWeight temp;
			ifile>>temp.m_row>>temp.m_col>>temp.m_money;
			row.Insert(temp,row.Size());
		}
		ifile.close();
	}
}
void AdjMWGraph::IfileRowColWeightOfPlane(SeqList<RowColWeight> & row){
	fstream ifile;
	ifile.open("RowColWeightOfPlane.txt");
	if(!ifile)  cout<<"Դ�ļ���ʧ��"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		while(!ifile.eof()){
			RowColWeight temp;
			ifile>>temp.m_row>>temp.m_col>>temp.m_money;
			row.Insert(temp,row.Size());
		}
		ifile.close();
	}
}
void AdjMWGraph::IfilePath(SeqList<Path> &path){
	fstream ifile;
	ifile.open("Path.txt");
	if(!ifile)  cout<<"Դ�ļ���ʧ��"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		while(!ifile.eof()){ 
			Path temp;
			ifile>>temp.m_trian>>temp.all_through_station;
			PathNode *p=new PathNode[temp.all_through_station];    //pָ�����о����ĳ�վ������,�ڳ������ǵ�deleteÿһ��m_first
			temp.m_first=p;
			for(int i=0;i<temp.all_through_station;i++){
				ifile>>p[i].m_station>>p[i].m_arrive>>p[i].m_start;
			}
			path.Insert(temp,path.Size());
		}
	}
}
void AdjMWGraph::IfilePathOfPlane(SeqList<Path> &path){
	fstream ifile;
	ifile.open("PathOfPlane.txt");
	if(!ifile)  cout<<"Դ�ļ���ʧ��"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		while(!ifile.eof()){ 
			Path temp;
			ifile>>temp.m_trian>>temp.all_through_station;
			PathNode *p=new PathNode[temp.all_through_station];    //pָ�����о����ĳ�վ������,�ڳ������ǵ�deleteÿһ��m_first
			temp.m_first=p;
			for(int i=0;i<temp.all_through_station;i++){
				ifile>>p[i].m_station>>p[i].m_arrive>>p[i].m_start;
			}
			path.Insert(temp,path.Size());
		}
	}
}
void AdjMWGraph::AddStation(SeqList<Station> &station,AdjMWGraph &G){
	cout<<"���������ӳ�վ�����ƣ�"<<endl;
	Station s;
	cin>>s.m_station_name;
	for(int i=0;i<station.Size();i++){
		if(s.m_station_name==station[i].m_station_name)
		{
			cout<<"�ó�վ�Ѿ�����,���ʧ��!"<<endl;
			return;
		}
	}
	s.m_station_id=station[station.Size()-1].m_station_id+1;    //���ӳ�վ���Ϊ���������һ����վ�ı�ż�1;
	station.Insert(s,station.Size());
	G.InsertVertex(s);                            //�Ѹ�վ����ͼ��
	cout<<"��ӳ�վ�ɹ���"<<endl;
}
void AdjMWGraph::GetTrainsToEdge(SeqList<Path> & path,SeqList<RowColWeight> & row,AdjMWGraph &G){
	for(int i=0;i<path.Size();i++){                                              //����Path����ѭ��
		for(int j=0;j<path[i].all_through_station-1;j++){          //�ڲ��PathNode����ѭ��
			for(int k=0;k<row.Size();k++){                                  //�ӱߵ��������ҵ���ǰ��վ��ı�
				if(row.GetData(k).m_row==path[i].m_first[j].m_station&&row.GetData(k).m_col==path[i].m_first[j+1].m_station){
					row.GetData(k). rowcol_station.Insert(path[i].m_trian,row[k].rowcol_station.Size());
					break;
				}
			}
		}
	}
}
bool AdjMWGraph::IshasTrain(SeqList<Path> &path,string train){
	for(int i=0;i<path.Size();i++){
		if(path[i].m_trian==train){
			return true;
		}
	}
	return false;
}
void AdjMWGraph::AddTrain(SeqList<Station> &station,SeqList<Path> &path,SeqList<RowColWeight> &row,AdjMWGraph &G){
	cout<<"��������Ҫ�����Ļ𳵵ĳ��Σ�"<<endl;
	string train;
	cin>>train;
	if(IshasTrain(path,train))
	{
		cout<<"�ó����Ѿ����ڣ�"<<endl;
		return ;
	}
	else{
		Path temp;
		temp.m_trian=train;
		cout<<"������ó���һ����������վ̨����"<<endl;
		cin>>temp.all_through_station;
		cout<<"��ǰ����վ̨��Ϣ��"<<endl;
		ShowAllStaion(station);
		temp.m_first=new PathNode[temp.all_through_station];
		for(int i=0;i<temp.all_through_station;i++){
			cout<<"�������"<<i+1<<"����վ��Ϣ:"<<endl;
			cout<<"��վ��ţ�";
			cin>>temp.m_first[i].m_station;
			if(i!=0){
				cout<<"�ﵽʱ�䣺";
				cin>>temp.m_first[i].m_arrive;
			}
			else temp.m_first[i].m_arrive=-1;        //ʼ��վ����ʱ����-1
			if(i==temp.all_through_station-1)
				temp.m_first[i].m_start=-1;	  //�յ�վ����ʱ����-1
			else{
				cout<<"����ʱ�䣺";
				cin>>temp.m_first[i].m_start;   
			}
		}
		path.Insert(temp,path.Size());    //���µ��г�ʱ�̱���뵽������
	}
	IsNeedAddRowColWeight(train,path,row,G);
}
void AdjMWGraph::IsNeedAddRowColWeight(string train,SeqList<Path> &path,SeqList<RowColWeight> &row,AdjMWGraph &G){
	for(int i=0;i<path[path.Size()-1].all_through_station-1;i++){
				if(IsEdge(path[path.Size()-1].m_first[i].m_station,path[path.Size()-1].m_first[i+1].m_station)<=0){   //�����վ�仹�����ڱߣ������ӱ�,������ͼ��
					cout<<G.GetValue(path[path.Size()-1].m_first[i].m_station).m_station_name <<"��"<<G.GetValue(path[path.Size()-1].m_first[i+1].m_station) .m_station_name
						<<"֮ǰ��δ�޽���·!"<<endl<<"�����޽�..."<<endl<<"�޽����!"<<endl<<"������վ����շѣ�";
					RowColWeight temp;
					cin>>temp.m_money;
					temp.rowcol_station.Insert(train,temp.rowcol_station.Size());
					temp.m_row=path[path.Size()-1].m_first[i].m_station;
					temp.m_col=path[path.Size()-1].m_first[i+1].m_station;
					row.Insert(temp,row.Size());                  //���ӵ��ߵ�������
					G.InsertEdge(path[path.Size()-1].m_first[i].m_station,path[path.Size()-1].m_first[i+1].m_station,temp.m_money); //�߲��뵽ͼ��
				}
		else {
							for(int k=0;k<row.Size();k++){                                  //�ӱߵ��������ҵ���ǰ��վ��ı�
								if(row.GetData(k).m_row==path[path.Size()-1].m_first[i].m_station&&row.GetData(k).m_col==path[path.Size()-1].m_first[i+1].m_station){
									row.GetData(k). rowcol_station.Insert(train,row[k].rowcol_station.Size());
									break;
								}
				}
		}
	}
}
void AdjMWGraph::ShowAllStaion(SeqList<Station> &station){
	for(int i=0;i<station.Size();i++){
		cout<<station[i].m_station_name<<"("<<station[i].m_station_id<<")  ";
	}
	cout<<endl;
}
int AdjMWGraph::GetNeighborCount(int station_id,AdjMWGraph &G){
	int count=0;	
	int next_id=G.GetFirstNeighbor(station_id);
	if(next_id<0){
		return count;
	}
	else{
		count++;
		while(G.GetNextNeighbor(station_id,next_id)>0){
			count++;
			next_id=G.GetNextNeighbor(station_id,next_id);
		}
		return count;
	}
}
TreeNode  AdjMWGraph::FindAllPath(SeqList<Station> &station,SeqList<RowColWeight> &row,AdjMWGraph &G,SeqList<Path> &path){
	ShowAllStaion(station);
	cout<<endl<<"��������ʼ��վ���յ�վ��"<<endl;
	int start_id,end_id;
	cin>>start_id>>end_id;
	while(!IsVertex(start_id)||!IsVertex(end_id)){
		cout<<"�����վ̨��Ϣ����!���������룺"<<endl;
		cin>>start_id>>end_id;
	}
	TreeNode firstNode;     //����ʼվ���������в�ͬ·����ͷ���
	SeqList<SeqList<int>>  SuitPath_List(100);    //��������������ʼվ��Ŀ��վ��ͨ·
	SeqList<SeqList<RowColWeight>> SuitPathOfRowCol_List(200);   //������������ͨ·֮������б�
	SeqList<SeqList<string>> PathOfTrain_List(500);    //������ͨ·�ϵĲ�ͬת����Ϣ���浽����
	firstNode.size=GetNeighborCount(start_id,G);
	firstNode.m_hasVisitStation.Insert(start_id,firstNode.m_hasVisitStation.Size());
	RecurseFind(start_id,end_id,firstNode,firstNode,G,SuitPath_List);
	//��ÿһ��·����Ӧ�ı߰�˳�򱣴�����
	GetRowColWeight(SuitPathOfRowCol_List,SuitPath_List,row);
	cout<<"��ѡ�񷽰��� ���ʱ�䣨1��    ���ٻ��ѣ�2��:"<<endl;
	int choose;
	cin>>choose;
	switch(choose){
	case 1:    //�� SuitPathOfRowCol_List�������ʱ��
		LeastTimeWay(PathOfTrain_List,SuitPathOfRowCol_List,G,path);
		break;
	case 2:	//����̻���
		LeastCostWay(SuitPathOfRowCol_List,G);
		break;
	default:
			cout<<"��������!";
	}
	//ѡȡһ���߾���ʱ���ϵļ���

	return firstNode;
}
void AdjMWGraph::RecurseFind(int station_id,int end_id,TreeNode  firstNode,TreeNode & AllfirstNode,AdjMWGraph & G,SeqList<SeqList<int>>& suitpath_list){
	firstNode.m_hasNeighborCount=G.GetNeighborCount(station_id,G);   //��ǰ��վ�����ٽ�վ����
	firstNode.m_stationInNode=station_id;
	if(firstNode.m_stationInNode==end_id) {
		suitpath_list.Insert(firstNode.m_hasVisitStation,suitpath_list.Size());          //������Ŀ��վ��ֹͣ�ݹ�,�����ص�����
		//ѡ����������������·��������������
		return;     //�ݹ��˳�����1���ҵ�Ŀ�ĵ�
	}  
	if(firstNode.m_hasNeighborCount==0) {
		return;		//�ݹ��˳�����2������Ϊ0
	}
	//���������洢�����ٽ�վ������	
	TreeNode * next_treeNode_List=new TreeNode[firstNode.m_hasNeighborCount];    //�ǵ��ͷ�
	firstNode.pm_next=next_treeNode_List;
	//����ĳ��������,�ǽ��ٽ�վ����next_treeNode�У�����¼·����Visit 
	GetNeighborStation(firstNode,next_treeNode_List,G);
	for(int i =0;i<firstNode.m_hasNeighborCount;i++){
		//if(�Ե�ǰ·������(),���ظ���continue)
		if(CheckSameStationInVisit(firstNode.pm_next[i].m_hasVisitStation))
			continue;    //�ݹ��˳����ظ�·���ˣ��������ǰ�ݹ�   
		RecurseFind(firstNode.pm_next[i].m_stationInNode,end_id,firstNode.pm_next[i],AllfirstNode,G,suitpath_list);  //�ݹ����
	}
}
void AdjMWGraph::GetNeighborStation(TreeNode &firstnode,TreeNode * next_treeNode,AdjMWGraph &G){
	int next_id=G.GetFirstNeighbor(firstnode.m_stationInNode);      //�����Ѿ�����һ���ٽ�վ
	TreeNode temp;
	temp.m_stationInNode=next_id;
	//temp.m_hasVisitStation=firstnode.m_hasVisitStation;                            
	for(int i=0;i<firstnode.m_hasVisitStation.Size();i++){
		temp.m_hasVisitStation.Insert(firstnode.m_hasVisitStation[i],temp.m_hasVisitStation.Size());
	}
	//����һ�ڵ��Visit��������
	temp.m_hasVisitStation.Insert(next_id,temp.m_hasVisitStation.Size());      //����վ����hasVisitStation��
	//next_treeNode.Insert(temp,next_treeNode.Size());
	next_treeNode[next_treeNode->size]=temp;
	next_treeNode->size++;
	while(G.GetNextNeighbor(firstnode.m_stationInNode,next_id)>0){
			next_id=G.GetNextNeighbor(firstnode.m_stationInNode,next_id);
			TreeNode temp;
			temp.m_stationInNode=next_id;
			for(int i=0;i<firstnode.m_hasVisitStation.Size();i++){
				temp.m_hasVisitStation.Insert(firstnode.m_hasVisitStation[i],temp.m_hasVisitStation.Size());
			}                          
			//����һ�ڵ��Visit��������
			temp.m_hasVisitStation.Insert(next_id,temp.m_hasVisitStation.Size());      //����վ����hasVisitStation��
			next_treeNode[next_treeNode->size]=temp;
			next_treeNode->size++;
		}
}
bool AdjMWGraph::CheckSameStationInVisit(SeqList<int> & hasVistStation){
	for(int i=0;i<hasVistStation.Size();i++){
		for(int j=i+1;j<hasVistStation.Size();j++){
			if(hasVistStation[i]==hasVistStation[j])
				return true;   //�ظ�
		}
	}
	return false  ;//δ�ظ�
}
void AdjMWGraph::GetRowColWeight
(SeqList<SeqList<RowColWeight>> &SuitPathOfRowCol_List,SeqList<SeqList<int>> &SuitPath_List,SeqList<RowColWeight> &row)
{

	for(int i=0;i<SuitPath_List.Size();i++){    //������·����ѡһ��
			SeqList<RowColWeight>temp;
		for(int j=0;j<SuitPath_List[i].Size()-1;j++){    //��ѡ�е�ĳ��·���������ұ�
			for(int k=0;k<row.Size();k++){                   //��row��ѡȡ���ʵı߲��洢
				if(row.GetData(k).m_row== SuitPath_List[i][j]&&row.GetData(k).m_col==SuitPath_List[i][j+1]){
					temp.Insert(row.GetData(k),temp.Size());
				}
			}
		}
		SuitPathOfRowCol_List.Insert(temp,SuitPathOfRowCol_List.Size());
	}
}
void AdjMWGraph::LeastCostWay(SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List,AdjMWGraph &G ){
	if(SuitPathOfRowCol_List.Size()==0){
		cout<<"û���κο��з�����"<<endl;
		return;
	}
	double *AllCost=new double[SuitPathOfRowCol_List.Size()];     //��̬���٣� �ǵ��ͷţ���������ÿ��·�ķ���
	int *hasVisiti=new int[SuitPathOfRowCol_List.Size()];     //��̬���٣� �ǵ��ͷţ��������ĳ��·�Ƿ��������
	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
		hasVisiti[i]=1;    //��δ�������
		AllCost[i]=0;    //��ʼ������
	}

	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
		for(int j=0;j<SuitPathOfRowCol_List[i].Size();j++){
			AllCost[i]+=SuitPathOfRowCol_List[i][j].m_money;
		}
	}
	double temp=10000;    //���浱ǰ��С����
	int current=0;    //��¼��ǰ��ָ·��
	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
		for(int j=0;j<SuitPathOfRowCol_List.Size();j++){
			if(temp>AllCost[j]&&hasVisiti[j]==1){
				temp=AllCost[j];
				current=j;
			}
		}
		for(int k=0;k<SuitPathOfRowCol_List[current].Size();k++){
			if(k==0) cout<<G.GetValue(SuitPathOfRowCol_List[current][k].m_row).m_station_name
				<<" "<<G.GetValue(SuitPathOfRowCol_List[current][k].m_col).m_station_name<<" ";
			else
				cout<<G.GetValue(SuitPathOfRowCol_List[current][k].m_col).m_station_name<<" ";
		}
		cout<<"���ѣ�"<<temp<<endl;
		hasVisiti[current]=0;
		temp=10000;
	}
}
void AdjMWGraph::LeastTimeWay(SeqList<SeqList<string>>&PathOfTrain_List,SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List,AdjMWGraph &G,SeqList<Path> & path){
	
	SeqList<Save_all_Train> Save_all_Train_List;     //�洢����ͨ·��Ӧ������תվ
	GetAPathOfTrain(Save_all_Train_List,PathOfTrain_List,SuitPathOfRowCol_List,G);
	//����ʱ��
	CalculateALLTime(Save_all_Train_List,SuitPathOfRowCol_List,path,G);
}
void AdjMWGraph::GetAPathOfTrain
(SeqList<Save_all_Train> &Save_all_Train_List,SeqList<SeqList<string>>&PathOfTrain_List,SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List,AdjMWGraph &G)
{	//��Ҫһ����ά����������ÿ��·�������г����εĿ���
	//��ά���������������ڼ���·��
	//�м�һ�����ܵ����и���

	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
			int rowCount=1;
			int colCount=SuitPathOfRowCol_List[i].Size();   //ĳһ��ͨ·�ϵıߵ�������Ϊ�е����ֵ
			for(int j=0;j<SuitPathOfRowCol_List[i].Size();j++){
			rowCount*=SuitPathOfRowCol_List[i][j].rowcol_station.Size();   //��������п��ܵ�������������Ϊ�е����ֵ
		}
		//string Save_train[100][100]={""};  
		Save_all_Train temp;    //�洢ĳһ��ͨ·����������
		for(int k=0;k<colCount;k++){     //���н���ѭ��
			//�����ȥ��K���������������С�ĳ˻�calculate
			int calculate=GetCalculate(k,SuitPathOfRowCol_List[i]);
			//��colCount����calculate��Ϊk����ÿ��Ԫ����д�ļ��
			FullColTrain(k,colCount,rowCount,temp,SuitPathOfRowCol_List[i]);
		}
		Save_all_Train_List.Insert(temp,Save_all_Train_List.Size());
	}
}
void AdjMWGraph::FullColTrain(int k,int colCount,int rowCount,Save_all_Train &temp,SeqList<RowColWeight> & row_list){
	

	int front=1;  //ͳ��ǰ�������Ԫ�ظ���
	for(int i=0;i<k+1;i++){
		front*=row_list[i].rowcol_station.Size();
	}
	int methed=rowCount/front;    //��д�ĸ���
	int circle=front/row_list[k].rowcol_station.Size(); //ѭ������
	int num=0;
	for(int i=0;i<circle;i++){
		for(int j=0;j<row_list[k].rowcol_station.Size();j++){
			for(int x=0;x<methed;x++){
				temp.m_Save_All_Train[num][k]=row_list[k].rowcol_station[j];
				num++;
			}
		}
	}


}
int AdjMWGraph::GetCalculate(int k,SeqList<RowColWeight> & row_list){
	int temp=1;
	for(int i=0;i<row_list.Size();i++){
		if(i!=k){
			temp*=row_list[i].rowcol_station.Size();
		}
	}
	return temp;
}
void AdjMWGraph::SearchPath(SeqList<Path> & path,AdjMWGraph &G){
	cout<<"��������Ҫ���ҵ��г����Σ�";
	string train;
	cin>>train;
	int x=0;   //�����ж��Ƿ��иó���
	for(int i=0;i<path.Size();i++){
		if(path[i].m_trian==train){
			PrintfPath(path[i],G);
			x=1;
		}
	}
	if(x==0)  cout<<"δ�ҵ����г���Ϣ��"<<endl;
}
void AdjMWGraph::PrintfPath(Path & path,AdjMWGraph &G){
	cout<<path.m_trian<<"��"<<endl;
	cout<<"վ̨  "<<"����ʱ��  "<<"����ʱ��  "<<endl;
	for(int i=0;i<path.all_through_station;i++){
		cout<<G.GetValue(path.m_first[i].m_station).m_station_name<<"      ";
		if(path.m_first[i].m_arrive==-1)
			cout<<"--     ";
		else
			cout<<path.m_first[i].m_arrive<<"    ";
		if(path.m_first[i].m_start==-1)
			cout<<"--     ";
		else
			cout<<path.m_first[i].m_start<<"    ";
		cout<<endl;
	}
		cout<<endl;
}
void AdjMWGraph::CalculateALLTime
	(SeqList<Save_all_Train>& Save_all_Train_List,SeqList<SeqList<RowColWeight>>& SuitPathOfRowCol_List,SeqList<Path> &path,AdjMWGraph & G){
	SeqList<UseToPrintf> UseToPrintf_List; // �洢��ӡ��Ϣ
	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){  //���ѡ��һ��·��
			for(int j=0;j<Save_all_Train_List[i].GetRow(0);j++){ //�ڲ�ѡ��һ������
				//�ȴ�suitpathrow����t1����վ��վ���ڽ��t1������վ�ҵ�ʱ����Ϣ
				GetATrainInformation(i,j,Save_all_Train_List,path,SuitPathOfRowCol_List,UseToPrintf_List);//i�����i��ͨ·  j�����i��ͨ·�еĵ�j������
				}
		}
	PrintfPathOfTime(UseToPrintf_List,G);  //��ӡ
}
void AdjMWGraph::GetATrainInformation
(int i,int j,SeqList<Save_all_Train>&Save_all_Train_List ,SeqList<Path> &path,SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List ,SeqList<UseToPrintf>& UseToPrintf_List){
	UseToPrintf temp2;
	int col=Save_all_Train_List[i].GetCol(j);   //�洢��j������������
	for(int m=0;m<col;m++){   
		RecordTrains temp;  
		temp.m_train=Save_all_Train_List[i].m_Save_All_Train[j][m];            //��ȡĳһ���α��
		temp.m_row=SuitPathOfRowCol_List[i][m].m_row;                         //��ȡĳһ������ĳ���ϵĳ���վ
		temp.m_col=SuitPathOfRowCol_List[i][m].m_col;					   //��ȡĳһ������ĳ���ϵĵ���վ
			//��path�л�ȡʱ����Ϣ
			for(int q=0;q<path.Size();q++){
				if(path[q].m_trian==temp.m_train){
					for(int n=0;n<path[q].all_through_station;n++){
						if(temp.m_row==path[q].m_first[n].m_station){
							temp.m_start=path[q].m_first[n].m_start;
							temp.m_arrive=path[q].m_first[n+1].m_arrive;
							}
						}	 
					}
			}
			temp2.m_UseToPrintf.Insert(temp,temp2.m_UseToPrintf.Size());
		}
	//������ʱ��
	temp2.m_alltime=0;
	for(int k=0;k<temp2.m_UseToPrintf.Size();k++){
		temp2.m_alltime+=temp2.m_UseToPrintf[k].m_arrive-temp2.m_UseToPrintf[k].m_start;
		if(k!=0){
			if(temp2.m_UseToPrintf[k].m_start-temp2.m_UseToPrintf[k-1].m_arrive<0){
				temp2.m_alltime+=24+temp2.m_UseToPrintf[k-1].m_arrive-temp2.m_UseToPrintf[k].m_start;
			}
			else
				temp2.m_alltime+=temp2.m_UseToPrintf[k].m_start-temp2.m_UseToPrintf[k-1].m_arrive;
		}
	}
	UseToPrintf_List.Insert(temp2,UseToPrintf_List.Size());
}
void AdjMWGraph::PrintfPathOfTime(SeqList<UseToPrintf>& UseToPrintf_List,AdjMWGraph &G){
	if(UseToPrintf_List.Size()==0){
		cout<<"����س���!"<<endl;
		return;
	}
	cout<<"      ����վ̨    "<<"����ʱ��    "<<"����վ̨    "<<"����ʱ��"<<endl;
	  //Shell����
	for (int gap = UseToPrintf_List.Size() / 2; gap > 0;gap = (gap == 2) ? 1 : (int) (gap / 2.2))
	{
        for (int i = gap; i < UseToPrintf_List.Size(); i++)
		{
			UseToPrintf tmp = UseToPrintf_List[i];
            int j = i;
		for (; (j >= gap) && (tmp.m_alltime < UseToPrintf_List[j - gap].m_alltime); j -= gap)
			{
				UseToPrintf_List[j]= UseToPrintf_List[j - gap];
			}
			UseToPrintf_List[j] = tmp;
		}
	}
	for(int current=0;current<UseToPrintf_List.Size();current++){
		cout<<"����"<<current+1<<"��"<<endl;
			for(int x=0;x<UseToPrintf_List[current].m_UseToPrintf.Size();x++){
			if(x==0){          //�����һ����վ��Ϣ
				cout<< UseToPrintf_List[current].m_UseToPrintf[x].m_train<<"��"<<endl;
				cout<<setw(10)<<G.GetValue( UseToPrintf_List[current].m_UseToPrintf[x].m_row).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_start <<setw(14)
					<<G.GetValue(UseToPrintf_List[current].m_UseToPrintf[x].m_col).m_station_name <<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_arrive<<endl;
			}
			
			else if(x!=UseToPrintf_List[current].m_UseToPrintf.Size()-1){
				string temp=UseToPrintf_List[current].m_UseToPrintf[x-1].m_train;  //��¼֮ǰ�ĳ���
				if(temp!=UseToPrintf_List[current].m_UseToPrintf[x].m_train){
					cout<<"  ת����"<<UseToPrintf_List[current].m_UseToPrintf[x].m_train<<endl;
				}
					cout<<setw(10)<<G.GetValue( UseToPrintf_List[current].m_UseToPrintf[x].m_row).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_start<<setw(14)
					<<G.GetValue(UseToPrintf_List[current].m_UseToPrintf[x].m_col).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_arrive<<endl;
					
			}
			else {
					string temp=UseToPrintf_List[current].m_UseToPrintf[x-1].m_train;  //��¼֮ǰ�ĳ���
				if(temp!=UseToPrintf_List[current].m_UseToPrintf[x].m_train){
					cout<<"  ת����"<<UseToPrintf_List[current].m_UseToPrintf[x].m_train<<endl;
				}
					cout<<setw(10)<<G.GetValue( UseToPrintf_List[current].m_UseToPrintf[x].m_row).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_start<<setw(14)
					<<G.GetValue(UseToPrintf_List[current].m_UseToPrintf[x].m_col).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_arrive<<setw(14)<<endl;
			}
		}
		cout<<"�ܺ�ʱ��"<<UseToPrintf_List[current].m_alltime<<"Сʱ"<<endl;
	}
}
void AdjMWGraph::Face(SeqList<Station> &station,SeqList<Path> & path,AdjMWGraph &G,SeqList<RowColWeight> &row){
	int x=1;
	while(x){
		cout<<" ������������������������������������������"<<endl;
		cout<<"             ȫ����ͨ��ѯģ��ϵͳ                        "<<endl;
		cout<<"              1���鿴��վ/������Ϣ                        "<<endl;
		cout<<"              2���鿴����/������Ϣ                        "<<endl;
		cout<<"              3�����ҳ���/������Ϣ                        "<<endl;
		cout<<"              4��·�߲�ѯ                                        "<<endl;
		cout<<"              5������վ̨                                        "<<endl;
		cout<<"              6����������/����                               "<<endl;
		cout<<"              7��ɾ������/����                               "<<endl;
		cout<<"              0��������һ��                                    "<<endl;
		cout<<" ������������������������������������������"<<endl;
			int choose;
			cin>>choose;
			switch(choose){
			case 1:
					ShowAllStaion(station);
				break;
			case 2:
					ShowAllTrain(path,G);
				break;
			case 3:
					SearchPath(path,G);
				break;
			case 4:
					FindAllPath(station,row,G,path);
				break;
			case 5:
					AddStation(station,G);
				break;
			case 6:
					AddTrain(station,path,row,G);
					break;
			case 7:
					DeleteTrain(station,path,row,G);
					break;
			case 0:
					x=0;
					break;
			default:
					cout<<"��������!"<<endl;
			}
	}
	
}
void AdjMWGraph::DeleteTrain(SeqList<Station> &station, SeqList<Path> & path,SeqList<RowColWeight> &row,AdjMWGraph &G){
	cout<<"������Ҫɾ�����г����κţ�"<<endl;
	string train;
	cin>>train;
	//��path����train��ɾ��
	int x=1;
	for(int i=0;i<path.Size();i++){
		if(path[i].m_trian==train){
				path.Delete(i);
				x=0;
				break;
		}
	}
	if(x)  {
		cout<<"δ�ҵ����˳���!"<<endl;
		return;
	}
	//�ӱ���ɾ������rowcol_station ���train 
	for(int i=0;i<row.Size();i++){
		for(int j=0;j<row[i].rowcol_station.Size();j++){
			if(row[i].rowcol_station[j]==train)
				row.GetData(i).rowcol_station.Delete(j);  
		}
	}
	//�����û��train�ˣ�ɾ���ñ�
	for(int i=0;i<row.Size();){
		if(row[i].rowcol_station.Size()==0){
				G.DeleteEdge(row[i].m_row,row[i].m_col);
				row.Delete(i);
				continue;
		}
		
		i++;
	}
	cout<<"ɾ���ɹ���"<<endl;
}
void AdjMWGraph::ShowAllTrain(SeqList<Path> &path,AdjMWGraph &G){
	cout<<"����    "<<"����վ    "<<"����ʱ��    "<<"����վ    "<<"����ʱ��    "<<endl;
	for(int i=0;i<path.Size();i++){
		cout<<path[i].m_trian<<setw(9)<<G.GetValue(path[i].m_first[0].m_station).m_station_name<<setw(10)<<path[i].m_first[0].m_start<<setw(10)
			<<G.GetValue(path[i].m_first[path[i].all_through_station-1].m_station).m_station_name <<setw(10)<<path[i].m_first[path[i].all_through_station-1].m_arrive<<endl;
	}
}
void AdjMWGraph::OfileStation(SeqList<Station> &  station){
	fstream ofile;
	ofile.open("Station.txt");
	if(!ofile)  cout<<"Դ�ļ���ʧ��"<<endl;
	int i=0;
	for(i;i<station.Size()-1;i++){
		ofile<<station[i].m_station_name<<" "<<station[i].m_station_id<<endl;
	}
	ofile<<station[i].m_station_name<<" "<<station[i].m_station_id;
	ofile.close();
}
void AdjMWGraph::OfileStationOfPlane(SeqList<Station> &  station){
	fstream ofile;
	ofile.open("StationOfPlane.txt");
	if(!ofile)  cout<<"Դ�ļ���ʧ��"<<endl;
	int i=0;
	for(i;i<station.Size()-1;i++){
		ofile<<station[i].m_station_name<<" "<<station[i].m_station_id<<endl;
	}
	ofile<<station[i].m_station_name<<" "<<station[i].m_station_id;
	ofile.close();
}
void AdjMWGraph::OfileRowColWeight(SeqList<RowColWeight> &row){
	fstream ofile;
	ofile.open("RowColWeight.txt");
	if(!ofile)  cout<<"Դ�ļ���ʧ��"<<endl;
	int i=0;
	for(i;i<row.Size()-1;i++){
		ofile<<row[i].m_row<<" "<<row[i].m_col<<" "<<row[i].m_money<<endl;
	}
	ofile<<row[i].m_row<<" "<<row[i].m_col<<" "<<row[i].m_money;
	ofile.close();
}
void AdjMWGraph::OfileRowColWeightOfPlane(SeqList<RowColWeight> &row){
	fstream ofile;
	ofile.open("RowColWeightOfPlane.txt");
	if(!ofile)  cout<<"Դ�ļ���ʧ��"<<endl;
	int i=0;
	for(i;i<row.Size()-1;i++){
		ofile<<row[i].m_row<<" "<<row[i].m_col<<" "<<row[i].m_money<<endl;
	}
	ofile<<row[i].m_row<<" "<<row[i].m_col<<" "<<row[i].m_money;
	ofile.close();
}
void AdjMWGraph::OfilePath(SeqList<Path> &path){
	fstream ofile;
	ofile.open("Path.txt");
	if(!ofile)  cout<<"Դ�ļ���ʧ��"<<endl;
	int i=0;
	for(i;i<path.Size()-1;i++){
		ofile<<path[i].m_trian<<" "<<path[i].all_through_station<<" ";
		int j=0;
		for(j;j<path[i].all_through_station-1;j++){
			ofile<<path[i].m_first[j].m_station<<" "<<path[i].m_first[j].m_arrive<<" "<<path[i].m_first[j].m_start<<" ";
		}
		ofile<<path[i].m_first[j].m_station<<" "<<path[i].m_first[j].m_arrive<<" "<<path[i].m_first[j].m_start;
		ofile<<endl;
	}
	ofile<<path[i].m_trian<<" "<<path[i].all_through_station<<" ";
	int j=0;
	for(j;j<path[i].all_through_station-1;j++){
		ofile<<path[i].m_first[j].m_station<<" "<<path[i].m_first[j].m_arrive<<" "<<path[i].m_first[j].m_start<<" ";
		}
	ofile<<path[i].m_first[j].m_station<<" "<<path[i].m_first[j].m_arrive<<" "<<path[i].m_first[j].m_start;
	ofile.close();
} 
void AdjMWGraph::OfilePathOfPlane(SeqList<Path> &path){
	fstream ofile;
	ofile.open("PathOfPlane.txt");
	if(!ofile)  cout<<"Դ�ļ���ʧ��"<<endl;
	int i=0;
	for(i;i<path.Size()-1;i++){
		ofile<<path[i].m_trian<<" "<<path[i].all_through_station<<" ";
		for(int j=0;j<path[i].all_through_station;j++){
			ofile<<path[i].m_first[j].m_station<<" "<<path[i].m_first[j].m_start<<" "<<path[i].m_first[j].m_arrive;
		}
		cout<<endl;
	}
	for(int j=0;j<path[i].all_through_station;j++){
			ofile<<path[i].m_first[j].m_station<<" "<<path[i].m_first[j].m_start<<" "<<path[i].m_first[j].m_arrive;
		}
	ofile.close();
} 