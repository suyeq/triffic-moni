#include"AdjMWGraph.h"
#include<iomanip>
using namespace std;
void main(){
	cout << setiosflags(ios::fixed) << setprecision(1);
	int x=1;
	while(x){
		cout<<" —————————————————————"<<endl;
		cout<<"             全国交通咨询模拟系统"<<endl;
		cout<<"              1、选择火车查询"<<endl;
		cout<<"              2、选择飞机查询"<<endl;
		cout<<"              0、退出程序"<<endl;
		cout<<" —————————————————————"<<endl;
		int choose;
		cin>>choose;
		switch(choose){
		case 1:{
					AdjMWGraph train_map(100);
					SeqList<Station> station_list(100);
					SeqList<RowColWeight> rowcolweight_list(100);
					SeqList<Path> path_list(100);
					train_map.IfileStation(station_list);
					train_map.IfileRowColWeight(rowcolweight_list);
					train_map.IfilePath(path_list);
					train_map.Creat(train_map, station_list,station_list.Size(), rowcolweight_list,rowcolweight_list.Size());
					train_map.GetTrainsToEdge(path_list,rowcolweight_list,train_map);
					train_map.Face(station_list,path_list,train_map,rowcolweight_list);
					train_map.OfilePath(path_list);
					train_map.OfileRowColWeight(rowcolweight_list);
					train_map.OfileStation(station_list);
			 }
			break;
		case 2:{
				    AdjMWGraph plane_map(100);
					SeqList<Station> station_list_plane(100);
					SeqList<RowColWeight> rowcolweight_list_plane(100);
					SeqList<Path> path_list_plane(100);
					plane_map.IfileStationOfPlane(station_list_plane);
					plane_map.IfileRowColWeightOfPlane (rowcolweight_list_plane);
					plane_map.IfilePathOfPlane(path_list_plane);
					plane_map.GetTrainsToEdge(path_list_plane,rowcolweight_list_plane,plane_map);
					plane_map.Creat(plane_map, station_list_plane,station_list_plane.Size(), rowcolweight_list_plane,rowcolweight_list_plane.Size());
					plane_map.Face(station_list_plane,path_list_plane,plane_map,rowcolweight_list_plane);
				//	plane_map.OfilePath(path_list_plane);
				//	plane_map.OfileRowColWeight(rowcolweight_list_plane);
					//plane_map.OfileStation(station_list_plane);
			 }
			break;
		case 0:
			x=0;
			break;
		default: 
			cout<<"输入有误!"<<endl;
		}
	}
	
	//train_map.SearchPath(path_list,train_map);

}