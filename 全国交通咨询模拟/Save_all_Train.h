#include<string>
using namespace std;
class Save_all_Train{
public:
	string m_Save_All_Train[100][100];	
	Save_all_Train(){
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				m_Save_All_Train[i][j]="";
			}
		}
	};
	int GetRow(int m);    //获取第m列二维数组的行
	int GetCol(int m);  //获取第二维数组的列
};
int Save_all_Train::GetRow(int m){
	for(int i=0;i<100;i++){
		if(m_Save_All_Train[i][m]==""){
			return i;
		}
	}
	return 0;
}
int Save_all_Train::GetCol(int m){
	for(int i=0;i<100;i++){
		if(m_Save_All_Train[m][i]==""){
			return i;
		}
	}
	return 0;
}