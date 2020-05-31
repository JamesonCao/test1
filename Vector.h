#ifndef VECTOR
#define VECTOR
#include <iostream>
using namespace std;
class Vector{
public:
    friend ostream &operator<<(ostream &cout, const Vector &vec);
    Vector();
    void Set_vec();//��������
    void Set_n();//����ά��
    Vector operator+(Vector &v);//���������"+"
    Vector operator-(Vector &v);//���������"-"
    Vector &operator=(const Vector &v);//���������"="
    ~Vector();
private:
    int m_N;
    int *m_vec;
};

Vector::Vector()
{
    m_vec = new int[m_N];//���ٶ����ռ�
}
void Vector::Set_vec()
{
    for(int i = 0; i < m_N; i++)
    {
        cin >> m_vec[i];
    }
}

void Vector::Set_n()
{
    cin >> m_N;
}
Vector::~Vector()
{
    if(m_vec != NULL)
    {
        delete[] m_vec;
        m_vec = NULL;
    }
}
Vector Vector::operator+(Vector &v)
{
    Vector temp;
    temp.m_N = this->m_N;
    for(int i = 0; i < m_N; i++)
    {
        temp.m_vec[i] = this->m_vec[i] + v.m_vec[i];
    }
    return temp;
}
Vector Vector::operator-(Vector &v)
{
    Vector temp;
    temp.m_N = this->m_N;
    for(int i = 0; i < m_N; i++)
    {
        temp.m_vec[i] = this->m_vec[i] - v.m_vec[i];
    }
    return temp;
}
Vector &Vector::operator=(const Vector &v)//����vֻ��
{
    if(m_vec != NULL)
    {
        delete[] m_vec;
        m_vec = NULL;
    }
    m_vec = new int[m_N];
    this->m_N = v.m_N;
    for(int i = 0; i < m_N; i++)
    {
        m_vec[i] = v.m_vec[i];
    }
    return *this;
    
}
ostream &operator<<(ostream &cout,const Vector &vec)//ȫ�ֺ�������"<<", ����vecֻ��
{
    for(int i = 0; i < vec.m_N; i++)
    {
        cout << vec.m_vec[i] << " ";
    } 
    return cout;
}
#endif

