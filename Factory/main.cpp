#include <iostream>
using namespace std;

//******************************************************产品类****************************************//
class ComputeOperator{
public:
    virtual double getResult() = 0;
    virtual void setNum(double numA,double numB) = 0;
};

class AddOperator:public ComputeOperator{
public:
    double getResult()
    {
        return m_numA+m_numB;
    }

    void setNum(double numA,double numB)
    {
        m_numA = numA;
        m_numB = numB;
    }
private:
    double m_numA;
    double m_numB;
};

class SubOperator:public ComputeOperator{
public:
    double getResult()
    {
        return m_numA-m_numB;
    }
    void setNum(double numA,double numB)
    {
        m_numA = numA;
        m_numB = numB;
    }
private:
    double m_numA;
    double m_numB;
};

class MultiOperator:public ComputeOperator{
public:
    double getResult()
    {
        return m_numA*m_numB;
    }
    void setNum(double numA,double numB)
    {
        m_numA = numA;
        m_numB = numB;
    }
private:
    double m_numA;
    double m_numB;

};

class DivOperator:public ComputeOperator{
public:
    double getResult()
    {
        if(m_numB == 0)
        {
            cout << "Divisor cannot be zero";
            return -1;
        }

        return m_numA/m_numB;
    }
    void setNum(double numA,double numB)
    {
        m_numA = numA;
        if(numB == 0)
        {
            cout << "Divisor cannot ne zero";
            return;
        }
        m_numB = numB;
    }
private:
    double m_numA;
    double m_numB;

};

//******************************************************工厂类****************************************//
class ComputeFactory{
public:
    virtual ComputeOperator* createOperator() = 0;
};

class AddFactory:public ComputeFactory{
public:
    ComputeOperator* createOperator()
    {
        return new AddOperator();
    }
};

class SubFactory:public ComputeFactory{
public:
    ComputeOperator* createOperator()
    {
        return new SubOperator();
    }
};

class MultiFactory:public ComputeFactory{
public:
    ComputeOperator* createOperator()
    {
        return new MultiOperator();
    }
};

class DivFactory:public ComputeFactory{
public:
    ComputeOperator* createOperator()
    {
        return new DivOperator();
    }
};
int main(int argc,char** argv)
{
    ComputeFactory *factory = new DivFactory();         //只需改变new的工厂类型就可以得到不同结果，当需要添加额外的方法时，只需要加一个该类的工厂和该类并修改此处的工厂类型即可，不会对原有代码产生改变
    ComputeOperator *opera = factory->createOperator();
    opera->setNum(10,10);
    cout << opera->getResult();
    delete factory;
    delete opera;
    return 0;
}
