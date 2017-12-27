template <class T>
class SeqList
{
protected:
	T *list;							//����
	int maxSize;							//���Ԫ�ظ���
	int size;								//��ǰԪ�ظ���
public:
	SeqList();	
	SeqList(int max);		      			//���캯��
	~SeqList(void);		      				//��������

	int Size(void) const;					//ȡ��ǰ����Ԫ�ظ���
	void Insert(const T& item, int i);//����
	T Delete(const int i);			//ɾ��
	T & GetData(int i)const;			//ȡ����Ԫ��
	T &operator [](int i);           //����[]
};
template <class T>
T &SeqList<T>::operator[](int i){
	if(i<0||i>size){
		exit(0);
	}
	else {
			return list[i];	
	}
}
template <class T>
SeqList<T>::SeqList()					//���캯��
{
	maxSize = 100;
	size = 0;
	list = new T[maxSize];
}
template <class T>
SeqList<T>::SeqList(int max)					//���캯��
{
	maxSize = max;
	size = 0;
	list = new T[maxSize];
}
template <class T>
SeqList<T>::~SeqList(void)						//��������
{
	//delete []list;
}							
template <class T>
int SeqList<T>::Size(void) const			//ȡ��ǰ����Ԫ�ظ���
{
	return size;
}
template <class T>
void SeqList<T>::Insert(const T& item, int i)	//����
//��ָ��λ��iǰ����һ������Ԫ��item
{
	if (size == maxSize)
	{
 		cout << "˳��������޷����룡" << endl;
		exit(0);
	}
	if(i < 0 || i > size)					//������ȷ����ж�
	{
		cout << "����iԽ�����!" << endl;
		exit(0);
	}

	//��size-1��i���Ԫ�غ���
	for(int j = size; j > i; j--) list[j] = list[j-1];
        
	list[i] = item;						//��iλ�ò���item	
	size++;								//��ǰԪ�ظ�����1
}
template <class T>
T SeqList<T>::Delete(const int i)				//ɾ��
//ɾ��ָ��λ��i������Ԫ�أ�ɾ����Ԫ���ɺ�������
{
	if (size == 0)
	{
		cout << "˳����ѿ���Ԫ�ؿ�ɾ��" << endl;
		exit(0);
	}
	if(i < 0 || i > size - 1)			//������ȷ����ж�
	{
		cout<<"����iԽ�����!"<<endl;
		exit(0);
	}

	T x = list[i];				//ȡ��Ҫɾ����Ԫ��

	//��i+1��size-1���Ԫ��ǰ��
	for(int j = i;j < size-1; j++) list[j] = list[j+1];

	size--;								//��ǰԪ�ظ�����1
	return x;							//����ɾ����Ԫ��
}
template <class T>
T & SeqList<T>::GetData(int i) const	//ȡ����Ԫ��
//ȡλ��i������Ԫ�أ�ȡ��������Ԫ���ɺ�������
{
	if(i < 0 || i > size - 1)			//������ȷ����ж�
	{
		cout << "����iԽ�����!" << endl;
		exit(0);
	}
	return list[i];						//����ȡ����Ԫ��
}
