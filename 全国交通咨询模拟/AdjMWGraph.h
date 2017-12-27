#include"UseToPrintf.h"
#include<iostream>
#include<iomanip>
#include<fstream>
class AdjMWGraph
{
private:
	SeqList<Station> Vertices;  //图的顶点	
	double Edge[100][100];  //边的权值信息
	int numOfEdges;    //边的个数

public:
	AdjMWGraph(const int sz = 100);			//构造函数
	~AdjMWGraph(void){};						 	//析构函数

	int NumOfVertices(void)	const						//取顶点个数
		{return Vertices.Size();}
	int NumOfEdges(void)const							//取边的个数
		{return numOfEdges;}
	Station GetValue(const int v)const;	//取顶点数值
	void DeleteEdge(const int v1, const int v2);     //删除边
	double GetWeight(const int v1, const int v2)const;		//取边的权值
	void InsertVertex(const Station &vertex);			//插入顶点
	void InsertEdge(const int v1, const int v2, double weight);//插入边
	int GetFirstNeighbor(const int v)const;				//取第一个邻接顶点
	int GetNextNeighbor(const int v1, const int v2)const;//取下一个邻接顶点
	int IsVertex(int v)const;  // 判断顶点vertex是否是有向图G的顶点
	int IsVertex(string vertex)const;	
	int IsEdge(int v1,int v2)const;		//判断第v1个顶点到第v2个顶点的边是否是有向图G的边，是则返回1，否则返回0。 
	void Creat(AdjMWGraph &G, SeqList<Station> station, int n, SeqList<RowColWeight> rowcolweight,int e);
	void IfileStation(SeqList<Station> & );    //从Station文件读入所有车站信息到内存
	void IfileStationOfPlane(SeqList<Station> &);
	void IfileRowColWeight(SeqList<RowColWeight> &) ; //从RowColWeight文件中读入所有边的信息
	void IfileRowColWeightOfPlane(SeqList<RowColWeight> &);
	void IfilePath(SeqList<Path> &);   //从Path文件中读取列车时刻表
	void IfilePathOfPlane(SeqList<Path> &);  
	void AddStation(SeqList<Station> &,AdjMWGraph &);    //添加车站信息
	void GetTrainsToEdge(SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &);   //从内存中的时刻表获取每条边上有哪几列车次
	void AddTrain(SeqList<Station> &,SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &); //添加新的列车及其路线
	bool IshasTrain(SeqList<Path> &,string);    //判断该火车是否存在
	void IsNeedAddRowColWeight(string ,SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &);   //若新增车次时，需要新增路线，则增加
	void ShowAllStaion(SeqList<Station> &);   //输出所有车站信息
	TreeNode FindAllPath(SeqList<Station> &,SeqList<RowColWeight> &,AdjMWGraph &,SeqList<Path> &);  //寻找所有路径
	int GetNeighborCount(int,AdjMWGraph &G);   //获取某站有多少临接站
	void GetNeighborStation(TreeNode &,TreeNode * ,AdjMWGraph &);  //将临接站放入数组
	void RecurseFind(int,int,TreeNode ,TreeNode &,AdjMWGraph &,SeqList<SeqList<int>>&) ;         //递归的查找
	bool CheckSameStationInVisit(SeqList<int> &);   //查重 
	//void GetSuitPath(TreeNode &,int ,SeqList<SeqList<int>>&);    //从所有路径中找到合适的路径
	void GetRowColWeight(SeqList<SeqList<RowColWeight>> &,SeqList<SeqList<int>> &,SeqList<RowColWeight> &);
	//将每一条路径对应的边按顺序保存起来
	void LeastCostWay(SeqList<SeqList<RowColWeight>> &,AdjMWGraph &);  //找寻最短花费方案并输出
	void LeastTimeWay(SeqList<SeqList<string>> &,SeqList<SeqList<RowColWeight>> &,AdjMWGraph &,SeqList<Path> &);   //找寻最短时间方案并输出
	void SearchPath(SeqList<Path> &,AdjMWGraph &);   //查询谋列火车信息
	void PrintfPath(Path &,AdjMWGraph &);    //打印谋列火车信息
	void GetAPathOfTrain(SeqList<Save_all_Train> &,SeqList<SeqList<string>> &,SeqList<SeqList<RowColWeight>> &,AdjMWGraph &);
	//从一条路径中找出所有可能的车次排列
	int GetCalculate(int,SeqList<RowColWeight> &);  //在某条路径中计算出去K以外的数组大小乘积
	void FullColTrain(int,int,int,Save_all_Train &,SeqList<RowColWeight> &);    //往每列里面填写列车车次
	void CalculateALLTime(SeqList<Save_all_Train>&,SeqList<SeqList<RowColWeight>>&,SeqList<Path> &,AdjMWGraph &);
	//计算总时间
	void GetATrainInformation(int i,int j,SeqList<Save_all_Train>&,SeqList<Path> &,SeqList<SeqList<RowColWeight>>&,SeqList<UseToPrintf>&);//从矩阵里获取信息
	void PrintfPathOfTime(SeqList<UseToPrintf>&,AdjMWGraph &);  //打印
	void Face(SeqList<Station> &,SeqList<Path> & ,AdjMWGraph &,SeqList<RowColWeight> &); //操作界面
	void DeleteTrain(SeqList<Station> &,SeqList<Path> &,SeqList<RowColWeight> &,AdjMWGraph &);//删除列车车次
	void ShowAllTrain(SeqList<Path> &,AdjMWGraph &);//查看所有列车
	void OfileStation(SeqList<Station> & );    //从Station文件读入所有车站信息到内存
	void OfileStationOfPlane(SeqList<Station> & );
	void OfileRowColWeight(SeqList<RowColWeight> &) ; 
	void OfileRowColWeightOfPlane(SeqList<RowColWeight> &) ; 
	void OfilePath(SeqList<Path> &);   //从Path文件中读取列车时刻表
	void OfilePathOfPlane(SeqList<Path> &);   //从Path文件中读取列车时刻表
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
//构造函数
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
//取顶点v的数值
{
	if(IsVertex(v)==0)//判断序号v的合法性
	{
		cout << "参数v越界出错!" << endl;
		exit(0);
	}
	return Vertices.GetData(v);
}
double AdjMWGraph::GetWeight(const int v1, const int v2)const
//取起始顶点为v1、终止顶点为 v2的边的权值
{
	if(IsVertex(v1)==0 || IsVertex(v2)==0)//判断序号v1和v2的合法性
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}
	return Edge[v1][v2];
}
void AdjMWGraph::InsertVertex(const Station &vertex)
//插入顶点vertex
{
	if (IsVertex(vertex.m_station_name)<0)//判断是否图中已经有值为vertex的顶点，时间复杂度O(n）		
		Vertices.Insert(vertex, Vertices.Size());//把顶点vertex插入到顺序表的当前表尾位置
	else 
		cout<<"该车站已存在，禁止添加！"<<endl;
}
void AdjMWGraph::InsertEdge(const int v1, const int v2, double weight)
//插入一条起始顶点为v1、终止顶点为 v2、权值为weight的边
{
	switch (IsEdge(v1,v2))//判断图中第v1个顶点到第v2个顶点的边的情况
	{	
	case -2:			//如果v1和v2有一个不是图中的顶点，则图不变；
		break;
	case -1:			//如果v1和v2相等，则图不变。
		break;
	case 0:				//如果边不存在，则边的数目加1，插入边
		numOfEdges++;
	case 1:				//如果边存在，则修改权值
		;
	default:
		Edge[v1][v2]=weight;
	}
}
int AdjMWGraph::GetFirstNeighbor(const int v)const
{
	if(IsVertex(v)==0)//判断序号v的合法性
	{
		cout << "参数v越界出错!" << endl;
		exit(0);
	}
	/*寻找邻接矩阵v行中从最左开始第一个值非零且非负数的权值对应的顶点*/
	for(int col = 0; col < NumOfVertices(); col++)
		if(Edge[v][col]> 0) 
			return col;
	return -1;
}
int AdjMWGraph::GetNextNeighbor(const int v1, const int v2)const
{
	if(IsVertex(v1)==0 || IsVertex(v2)==0)//判断序号v1和v2的合法性
	{
		cout << "参数v1或v2越界出错!" << endl;
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
} //时间复杂度O(1)
void AdjMWGraph::DeleteEdge(const int v1, const int v2)
//删除一条起始顶点为v1、终止顶点为 v2的边
{
	switch (IsEdge(v1,v2))//判断图中第v1个顶点到第v2个顶点的边的情况
	{	
	case -2:	//如果v1和v2有一个不是图中的顶点，则图不变；
		break;
	case -1:	//如果v1和v2相等，则图不变；
		break;
	case 0:		//如果<v1,v2>不是图的边，则图不变；
		break;
	case 1:		//如果<v1,v2>是图的边，则在带权有向图G中删除第v1个顶点指向第v2个顶点的有向边。
		{	
			Edge[v1][v2] =-1;/*把该边的权值置为无穷大，即为删除该边*/
			numOfEdges--;
		}
	default:;
	}
}
void AdjMWGraph::Creat(AdjMWGraph &G, SeqList<Station> V, int n, SeqList<RowColWeight> E,int e)
//在图G中插入n个顶点V和e条边E
{
	//在图G中插入n个顶点
	for(int i = 0; i < n; i++) 
		G.InsertVertex(V[i]);

	//在图G中插入e条边
	for(int k = 0; k < e; k++) 
		G.InsertEdge(E[k].m_row, E[k].m_col, E[k].m_money);
}
int AdjMWGraph::IsEdge(int v1,int v2)const
{
	if ( IsVertex(v1)==0 || IsVertex(v2)==0 )//判断序号v1和v2的合法性
		return -2;	//有顶点不存在
	if ( v1==v2 )
		return -1;	//顶点存在，v1和v2相等
	if ( Edge[v1][v2]== -1 )
		return 0;	//顶点存在，v1和v2不相等，边不存在
	return 1;		//边存在

}
void AdjMWGraph::IfileStation(SeqList<Station> & station){
	fstream ifile;
	ifile.open("Station.txt");
	if(!ifile)  cout<<"源文件丢失！"<<endl;
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
	if(!ifile)  cout<<"源文件丢失！"<<endl;
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
	if(!ifile)  cout<<"源文件丢失！"<<endl;
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
	if(!ifile)  cout<<"源文件丢失！"<<endl;
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
	if(!ifile)  cout<<"源文件丢失！"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		while(!ifile.eof()){ 
			Path temp;
			ifile>>temp.m_trian>>temp.all_through_station;
			PathNode *p=new PathNode[temp.all_through_station];    //p指向所有经过的车站的数组,在程序最后记得delete每一个m_first
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
	if(!ifile)  cout<<"源文件丢失！"<<endl;
	else{
		if(ifile.eof())
			ifile.get();
		while(!ifile.eof()){ 
			Path temp;
			ifile>>temp.m_trian>>temp.all_through_station;
			PathNode *p=new PathNode[temp.all_through_station];    //p指向所有经过的车站的数组,在程序最后记得delete每一个m_first
			temp.m_first=p;
			for(int i=0;i<temp.all_through_station;i++){
				ifile>>p[i].m_station>>p[i].m_arrive>>p[i].m_start;
			}
			path.Insert(temp,path.Size());
		}
	}
}
void AdjMWGraph::AddStation(SeqList<Station> &station,AdjMWGraph &G){
	cout<<"请输入所加车站的名称："<<endl;
	Station s;
	cin>>s.m_station_name;
	for(int i=0;i<station.Size();i++){
		if(s.m_station_name==station[i].m_station_name)
		{
			cout<<"该车站已经存在,添加失败!"<<endl;
			return;
		}
	}
	s.m_station_id=station[station.Size()-1].m_station_id+1;    //所加车站编号为数组里最后一个车站的编号加1;
	station.Insert(s,station.Size());
	G.InsertVertex(s);                            //把该站放入图中
	cout<<"添加车站成功！"<<endl;
}
void AdjMWGraph::GetTrainsToEdge(SeqList<Path> & path,SeqList<RowColWeight> & row,AdjMWGraph &G){
	for(int i=0;i<path.Size();i++){                                              //外层对Path数组循环
		for(int j=0;j<path[i].all_through_station-1;j++){          //内层对PathNode数组循环
			for(int k=0;k<row.Size();k++){                                  //从边的数组里找到当前两站间的边
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
	cout<<"请输入需要新增的火车的车次："<<endl;
	string train;
	cin>>train;
	if(IshasTrain(path,train))
	{
		cout<<"该车次已经存在！"<<endl;
		return ;
	}
	else{
		Path temp;
		temp.m_trian=train;
		cout<<"请输入该车次一共所经历的站台数："<<endl;
		cin>>temp.all_through_station;
		cout<<"当前已有站台信息："<<endl;
		ShowAllStaion(station);
		temp.m_first=new PathNode[temp.all_through_station];
		for(int i=0;i<temp.all_through_station;i++){
			cout<<"请输入第"<<i+1<<"个车站信息:"<<endl;
			cout<<"车站编号：";
			cin>>temp.m_first[i].m_station;
			if(i!=0){
				cout<<"达到时间：";
				cin>>temp.m_first[i].m_arrive;
			}
			else temp.m_first[i].m_arrive=-1;        //始发站到达时间置-1
			if(i==temp.all_through_station-1)
				temp.m_first[i].m_start=-1;	  //终点站出发时间置-1
			else{
				cout<<"出发时间：";
				cin>>temp.m_first[i].m_start;   
			}
		}
		path.Insert(temp,path.Size());    //将新的列车时刻表加入到数组中
	}
	IsNeedAddRowColWeight(train,path,row,G);
}
void AdjMWGraph::IsNeedAddRowColWeight(string train,SeqList<Path> &path,SeqList<RowColWeight> &row,AdjMWGraph &G){
	for(int i=0;i<path[path.Size()-1].all_through_station-1;i++){
				if(IsEdge(path[path.Size()-1].m_first[i].m_station,path[path.Size()-1].m_first[i+1].m_station)<=0){   //如果两站间还不存在边，则增加边,并插入图中
					cout<<G.GetValue(path[path.Size()-1].m_first[i].m_station).m_station_name <<"到"<<G.GetValue(path[path.Size()-1].m_first[i+1].m_station) .m_station_name
						<<"之前还未修建铁路!"<<endl<<"正在修建..."<<endl<<"修建完成!"<<endl<<"输入两站间的收费：";
					RowColWeight temp;
					cin>>temp.m_money;
					temp.rowcol_station.Insert(train,temp.rowcol_station.Size());
					temp.m_row=path[path.Size()-1].m_first[i].m_station;
					temp.m_col=path[path.Size()-1].m_first[i+1].m_station;
					row.Insert(temp,row.Size());                  //增加到边的数组中
					G.InsertEdge(path[path.Size()-1].m_first[i].m_station,path[path.Size()-1].m_first[i+1].m_station,temp.m_money); //边插入到图中
				}
		else {
							for(int k=0;k<row.Size();k++){                                  //从边的数组里找到当前两站间的边
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
	cout<<endl<<"请输入起始车站和终点站："<<endl;
	int start_id,end_id;
	cin>>start_id>>end_id;
	while(!IsVertex(start_id)||!IsVertex(end_id)){
		cout<<"输入的站台信息有误!请重新输入："<<endl;
		cin>>start_id>>end_id;
	}
	TreeNode firstNode;     //由起始站出发的所有不同路径的头结点
	SeqList<SeqList<int>>  SuitPath_List(100);    //用来保存所有起始站到目的站的通路
	SeqList<SeqList<RowColWeight>> SuitPathOfRowCol_List(200);   //用来保存所有通路之间的所有边
	SeqList<SeqList<string>> PathOfTrain_List(500);    //将所有通路上的不同转车信息保存到数组
	firstNode.size=GetNeighborCount(start_id,G);
	firstNode.m_hasVisitStation.Insert(start_id,firstNode.m_hasVisitStation.Size());
	RecurseFind(start_id,end_id,firstNode,firstNode,G,SuitPath_List);
	//将每一条路径对应的边按顺序保存起来
	GetRowColWeight(SuitPathOfRowCol_List,SuitPath_List,row);
	cout<<"请选择方案： 最短时间（1）    最少花费（2）:"<<endl;
	int choose;
	cin>>choose;
	switch(choose){
	case 1:    //从 SuitPathOfRowCol_List中找最短时间
		LeastTimeWay(PathOfTrain_List,SuitPathOfRowCol_List,G,path);
		break;
	case 2:	//找最短花费
		LeastCostWay(SuitPathOfRowCol_List,G);
		break;
	default:
			cout<<"输入有误!";
	}
	//选取一条边经行时间上的计算

	return firstNode;
}
void AdjMWGraph::RecurseFind(int station_id,int end_id,TreeNode  firstNode,TreeNode & AllfirstNode,AdjMWGraph & G,SeqList<SeqList<int>>& suitpath_list){
	firstNode.m_hasNeighborCount=G.GetNeighborCount(station_id,G);   //当前车站所有临接站数量
	firstNode.m_stationInNode=station_id;
	if(firstNode.m_stationInNode==end_id) {
		suitpath_list.Insert(firstNode.m_hasVisitStation,suitpath_list.Size());          //若满足目的站则停止递归,并返回到数组
		//选出所有满足条件的路径，并保存下来
		return;     //递归退出条件1、找到目的地
	}  
	if(firstNode.m_hasNeighborCount==0) {
		return;		//递归退出条件2、出度为0
	}
	//开辟用来存储所有临接站的数组	
	TreeNode * next_treeNode_List=new TreeNode[firstNode.m_hasNeighborCount];    //记得释放
	firstNode.pm_next=next_treeNode_List;
	//经过某个函数后,是将临接站放入next_treeNode中，并记录路径到Visit 
	GetNeighborStation(firstNode,next_treeNode_List,G);
	for(int i =0;i<firstNode.m_hasNeighborCount;i++){
		//if(对当前路径查重(),若重复则continue)
		if(CheckSameStationInVisit(firstNode.pm_next[i].m_hasVisitStation))
			continue;    //递归退出若重复路径了，便结束当前递归   
		RecurseFind(firstNode.pm_next[i].m_stationInNode,end_id,firstNode.pm_next[i],AllfirstNode,G,suitpath_list);  //递归入口
	}
}
void AdjMWGraph::GetNeighborStation(TreeNode &firstnode,TreeNode * next_treeNode,AdjMWGraph &G){
	int next_id=G.GetFirstNeighbor(firstnode.m_stationInNode);      //至少已经存在一个临接站
	TreeNode temp;
	temp.m_stationInNode=next_id;
	//temp.m_hasVisitStation=firstnode.m_hasVisitStation;                            
	for(int i=0;i<firstnode.m_hasVisitStation.Size();i++){
		temp.m_hasVisitStation.Insert(firstnode.m_hasVisitStation[i],temp.m_hasVisitStation.Size());
	}
	//将上一节点的Visit拷贝下来
	temp.m_hasVisitStation.Insert(next_id,temp.m_hasVisitStation.Size());      //将该站插入hasVisitStation中
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
			//将上一节点的Visit拷贝下来
			temp.m_hasVisitStation.Insert(next_id,temp.m_hasVisitStation.Size());      //将该站插入hasVisitStation中
			next_treeNode[next_treeNode->size]=temp;
			next_treeNode->size++;
		}
}
bool AdjMWGraph::CheckSameStationInVisit(SeqList<int> & hasVistStation){
	for(int i=0;i<hasVistStation.Size();i++){
		for(int j=i+1;j<hasVistStation.Size();j++){
			if(hasVistStation[i]==hasVistStation[j])
				return true;   //重复
		}
	}
	return false  ;//未重复
}
void AdjMWGraph::GetRowColWeight
(SeqList<SeqList<RowColWeight>> &SuitPathOfRowCol_List,SeqList<SeqList<int>> &SuitPath_List,SeqList<RowColWeight> &row)
{

	for(int i=0;i<SuitPath_List.Size();i++){    //从所有路径中选一条
			SeqList<RowColWeight>temp;
		for(int j=0;j<SuitPath_List[i].Size()-1;j++){    //从选中的某条路径中两两找边
			for(int k=0;k<row.Size();k++){                   //从row中选取合适的边并存储
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
		cout<<"没有任何可行方案！"<<endl;
		return;
	}
	double *AllCost=new double[SuitPathOfRowCol_List.Size()];     //动态开辟， 记得释放，用来保存每条路的费用
	int *hasVisiti=new int[SuitPathOfRowCol_List.Size()];     //动态开辟， 记得释放，用来标记某条路是否已输出过
	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
		hasVisiti[i]=1;    //均未被输出过
		AllCost[i]=0;    //初始化花费
	}

	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
		for(int j=0;j<SuitPathOfRowCol_List[i].Size();j++){
			AllCost[i]+=SuitPathOfRowCol_List[i][j].m_money;
		}
	}
	double temp=10000;    //保存当前最小花费
	int current=0;    //记录当前所指路线
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
		cout<<"花费："<<temp<<endl;
		hasVisiti[current]=0;
		temp=10000;
	}
}
void AdjMWGraph::LeastTimeWay(SeqList<SeqList<string>>&PathOfTrain_List,SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List,AdjMWGraph &G,SeqList<Path> & path){
	
	SeqList<Save_all_Train> Save_all_Train_List;     //存储所有通路对应的所有转站
	GetAPathOfTrain(Save_all_Train_List,PathOfTrain_List,SuitPathOfRowCol_List,G);
	//计算时间
	CalculateALLTime(Save_all_Train_List,SuitPathOfRowCol_List,path,G);
}
void AdjMWGraph::GetAPathOfTrain
(SeqList<Save_all_Train> &Save_all_Train_List,SeqList<SeqList<string>>&PathOfTrain_List,SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List,AdjMWGraph &G)
{	//需要一个二维数组来保存每条路上所坐列车车次的可能
	//二维数组的列用来代表第几条路线
	//行即一共可能的排列个数

	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){
			int rowCount=1;
			int colCount=SuitPathOfRowCol_List[i].Size();   //某一条通路上的边的总数作为列的最大值
			for(int j=0;j<SuitPathOfRowCol_List[i].Size();j++){
			rowCount*=SuitPathOfRowCol_List[i][j].rowcol_station.Size();   //计算出所有可能的排列种数，作为行的最大值
		}
		//string Save_train[100][100]={""};  
		Save_all_Train temp;    //存储某一条通路上所有排列
		for(int k=0;k<colCount;k++){     //对列进行循环
			//计算除去第K数组外其他数组大小的乘积calculate
			int calculate=GetCalculate(k,SuitPathOfRowCol_List[i]);
			//用colCount除以calculate作为k列上每个元素填写的间隔
			FullColTrain(k,colCount,rowCount,temp,SuitPathOfRowCol_List[i]);
		}
		Save_all_Train_List.Insert(temp,Save_all_Train_List.Size());
	}
}
void AdjMWGraph::FullColTrain(int k,int colCount,int rowCount,Save_all_Train &temp,SeqList<RowColWeight> & row_list){
	

	int front=1;  //统计前面数组的元素个数
	for(int i=0;i<k+1;i++){
		front*=row_list[i].rowcol_station.Size();
	}
	int methed=rowCount/front;    //填写的个数
	int circle=front/row_list[k].rowcol_station.Size(); //循环次数
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
	cout<<"请输入需要查找的列车车次：";
	string train;
	cin>>train;
	int x=0;   //用来判断是否有该车次
	for(int i=0;i<path.Size();i++){
		if(path[i].m_trian==train){
			PrintfPath(path[i],G);
			x=1;
		}
	}
	if(x==0)  cout<<"未找到该列车信息！"<<endl;
}
void AdjMWGraph::PrintfPath(Path & path,AdjMWGraph &G){
	cout<<path.m_trian<<"："<<endl;
	cout<<"站台  "<<"出发时间  "<<"到达时间  "<<endl;
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
	SeqList<UseToPrintf> UseToPrintf_List; // 存储打印信息
	for(int i=0;i<SuitPathOfRowCol_List.Size();i++){  //外层选中一条路线
			for(int j=0;j<Save_all_Train_List[i].GetRow(0);j++){ //内层选中一个方案
				//先从suitpathrow中找t1的上站下站，在结合t1和上下站找到时间信息
				GetATrainInformation(i,j,Save_all_Train_List,path,SuitPathOfRowCol_List,UseToPrintf_List);//i代表第i条通路  j代表第i条通路中的第j个方案
				}
		}
	PrintfPathOfTime(UseToPrintf_List,G);  //打印
}
void AdjMWGraph::GetATrainInformation
(int i,int j,SeqList<Save_all_Train>&Save_all_Train_List ,SeqList<Path> &path,SeqList<SeqList<RowColWeight>>&SuitPathOfRowCol_List ,SeqList<UseToPrintf>& UseToPrintf_List){
	UseToPrintf temp2;
	int col=Save_all_Train_List[i].GetCol(j);   //存储第j个方案的列数
	for(int m=0;m<col;m++){   
		RecordTrains temp;  
		temp.m_train=Save_all_Train_List[i].m_Save_All_Train[j][m];            //获取某一车次编号
		temp.m_row=SuitPathOfRowCol_List[i][m].m_row;                         //获取某一车次在某边上的出发站
		temp.m_col=SuitPathOfRowCol_List[i][m].m_col;					   //获取某一车次在某边上的到达站
			//从path中获取时间信息
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
	//计算总时间
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
		cout<<"无相关车次!"<<endl;
		return;
	}
	cout<<"      出发站台    "<<"出发时间    "<<"到达站台    "<<"到达时间"<<endl;
	  //Shell排序
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
		cout<<"方案"<<current+1<<"："<<endl;
			for(int x=0;x<UseToPrintf_List[current].m_UseToPrintf.Size();x++){
			if(x==0){          //输出第一个车站信息
				cout<< UseToPrintf_List[current].m_UseToPrintf[x].m_train<<"："<<endl;
				cout<<setw(10)<<G.GetValue( UseToPrintf_List[current].m_UseToPrintf[x].m_row).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_start <<setw(14)
					<<G.GetValue(UseToPrintf_List[current].m_UseToPrintf[x].m_col).m_station_name <<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_arrive<<endl;
			}
			
			else if(x!=UseToPrintf_List[current].m_UseToPrintf.Size()-1){
				string temp=UseToPrintf_List[current].m_UseToPrintf[x-1].m_train;  //记录之前的车次
				if(temp!=UseToPrintf_List[current].m_UseToPrintf[x].m_train){
					cout<<"  转车到"<<UseToPrintf_List[current].m_UseToPrintf[x].m_train<<endl;
				}
					cout<<setw(10)<<G.GetValue( UseToPrintf_List[current].m_UseToPrintf[x].m_row).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_start<<setw(14)
					<<G.GetValue(UseToPrintf_List[current].m_UseToPrintf[x].m_col).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_arrive<<endl;
					
			}
			else {
					string temp=UseToPrintf_List[current].m_UseToPrintf[x-1].m_train;  //记录之前的车次
				if(temp!=UseToPrintf_List[current].m_UseToPrintf[x].m_train){
					cout<<"  转车到"<<UseToPrintf_List[current].m_UseToPrintf[x].m_train<<endl;
				}
					cout<<setw(10)<<G.GetValue( UseToPrintf_List[current].m_UseToPrintf[x].m_row).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_start<<setw(14)
					<<G.GetValue(UseToPrintf_List[current].m_UseToPrintf[x].m_col).m_station_name<<setw(14)<<UseToPrintf_List[current].m_UseToPrintf[x].m_arrive<<setw(14)<<endl;
			}
		}
		cout<<"总耗时："<<UseToPrintf_List[current].m_alltime<<"小时"<<endl;
	}
}
void AdjMWGraph::Face(SeqList<Station> &station,SeqList<Path> & path,AdjMWGraph &G,SeqList<RowColWeight> &row){
	int x=1;
	while(x){
		cout<<" —————————————————————"<<endl;
		cout<<"             全国交通咨询模拟系统                        "<<endl;
		cout<<"              1、查看车站/机场信息                        "<<endl;
		cout<<"              2、查看车次/航班信息                        "<<endl;
		cout<<"              3、查找车次/航班信息                        "<<endl;
		cout<<"              4、路线查询                                        "<<endl;
		cout<<"              5、新增站台                                        "<<endl;
		cout<<"              6、新增车次/航班                               "<<endl;
		cout<<"              7、删除车次/航班                               "<<endl;
		cout<<"              0、返回上一级                                    "<<endl;
		cout<<" —————————————————————"<<endl;
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
					cout<<"输入有误!"<<endl;
			}
	}
	
}
void AdjMWGraph::DeleteTrain(SeqList<Station> &station, SeqList<Path> & path,SeqList<RowColWeight> &row,AdjMWGraph &G){
	cout<<"输入需要删除的列车车次号："<<endl;
	string train;
	cin>>train;
	//从path里找train并删除
	int x=1;
	for(int i=0;i<path.Size();i++){
		if(path[i].m_trian==train){
				path.Delete(i);
				x=0;
				break;
		}
	}
	if(x)  {
		cout<<"未找到该趟车次!"<<endl;
		return;
	}
	//从边里删除所有rowcol_station 里的train 
	for(int i=0;i<row.Size();i++){
		for(int j=0;j<row[i].rowcol_station.Size();j++){
			if(row[i].rowcol_station[j]==train)
				row.GetData(i).rowcol_station.Delete(j);  
		}
	}
	//如果边没有train了，删除该边
	for(int i=0;i<row.Size();){
		if(row[i].rowcol_station.Size()==0){
				G.DeleteEdge(row[i].m_row,row[i].m_col);
				row.Delete(i);
				continue;
		}
		
		i++;
	}
	cout<<"删除成功！"<<endl;
}
void AdjMWGraph::ShowAllTrain(SeqList<Path> &path,AdjMWGraph &G){
	cout<<"车次    "<<"出发站    "<<"出发时间    "<<"到达站    "<<"到达时间    "<<endl;
	for(int i=0;i<path.Size();i++){
		cout<<path[i].m_trian<<setw(9)<<G.GetValue(path[i].m_first[0].m_station).m_station_name<<setw(10)<<path[i].m_first[0].m_start<<setw(10)
			<<G.GetValue(path[i].m_first[path[i].all_through_station-1].m_station).m_station_name <<setw(10)<<path[i].m_first[path[i].all_through_station-1].m_arrive<<endl;
	}
}
void AdjMWGraph::OfileStation(SeqList<Station> &  station){
	fstream ofile;
	ofile.open("Station.txt");
	if(!ofile)  cout<<"源文件丢失！"<<endl;
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
	if(!ofile)  cout<<"源文件丢失！"<<endl;
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
	if(!ofile)  cout<<"源文件丢失！"<<endl;
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
	if(!ofile)  cout<<"源文件丢失！"<<endl;
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
	if(!ofile)  cout<<"源文件丢失！"<<endl;
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
	if(!ofile)  cout<<"源文件丢失！"<<endl;
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