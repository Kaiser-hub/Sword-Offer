// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class CMyString {
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	void Print() {
		cout << m_pData << endl;
	}

	CMyString& operator = (const CMyString& str);
private:
	char* m_pData;
};

CMyString::CMyString(char* pData) {
	if (pData == nullptr) {
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else {
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str) {
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void) {
	delete[]m_pData;
}

CMyString&CMyString::operator = (const CMyString& str) {
	if (this == &str) {
		return *this;
	}

	delete []m_pData;

	m_pData = nullptr;
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}


void testCMyString() {
	char p[] = "haha";
	CMyString cms(p);
	CMyString aa;
	CMyString bb;
	bb = aa = cms;
	bb.Print();
	aa.Print();
}

/*int main() {
	testCMyString();
	return 0;
}*/