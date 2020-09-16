#include<iostream>

using namespace std;

//C#��sealed�ؼ��ֺ�Java��final�ؼ��֣�����ʹһ�����Ϊ���ɼ̳���,�Ӷ��γɵ���ģʽ����C++��û���������õĹؼ���
/*����ģʽҲ��Ϊ����ģʽ������ģʽ��������ʹ����㷺�����ģʽ��
����ͼ�Ǳ�֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㣬��ʵ�������г���ģ�鹲��*/

//����һ�������࣬ʹ�����˽�о�ָ̬�����ָ�����Ψһʵ��������һ�����еľ�̬������ȡ��ʵ����
//����ģʽ
class Singleton {
private:
	//���캯��˽�л�
	Singleton() {}
	
	//ָ��Ψһʵ���ľ�ָ̬��M_Instance��������˽�е�
	static Singleton* M_Instance;
	class CleanGarbage {
	public:
		~CleanGarbage() {
			if (Singleton::M_Instance != NULL) {
				delete Singleton::M_Instance;
			}
		}
	};

	static CleanGarbage CG;
public:
	/*�û�����Ψһʵ���ķ���ֻ��GetInstance()��Ա������
	�����ͨ������������κδ���ʵ���ĳ��Զ���ʧ�ܣ���Ϊ��Ĺ��캯����˽�еġ�
	GetInstance()ʹ�������ʼ����Ҳ����˵���ķ���ֵ�ǵ���������״α�����ʱ��������*/
	static Singleton* GetInstance() {
		if (M_Instance == NULL) {
			M_Instance = new Singleton();
		}
		return M_Instance;
	}
};

//����ģʽ
class Singleton2 {
private:
	//���캯��˽�л�
	Singleton2() {}
	Singleton2(const Singleton2&);
	Singleton2& operator = (const Singleton2&);
public:
	static Singleton2* GetInstance() {
		//�ֲ���̬����
		static Singleton2 instance;
		return &instance;
	}
};