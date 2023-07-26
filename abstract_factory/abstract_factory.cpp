#include <iostream>

using namespace std;

// Abstract product class of chair
class Chair
{
    public:
    int legsCount = 4 ;
    virtual int getLegsCount() =0;
    virtual  void show() = 0 ;
};
// concrete product class
class ModernChair: public Chair
{
    public:
    void show()
    {
        cout<<"This is a Modern Chair \n";
    }
     int getLegsCount()
    {
        return legsCount;
    }
};
class VictorianChair: public Chair
{

    public:
    int legsCount = 3;
    void show()
    {
        cout<<"This is a victorian Chair \n";
    }
    int getLegsCount()
    {
        return legsCount;
    }


};
class ArtDecorChair : public Chair
{
    public:
    void show()
    {
        cout <<"This is a ArtDecorChair \n";
    }
     int getLegsCount()
    {
        return legsCount;
    }
};

// Abstract product class of sofa

class Sofa
{
    public:
    int legsCount = 4;
    virtual int getLegsCount() = 0 ;
    virtual void show() =0;
};
// concrete Sofa Class
class ModernSofa :public Sofa
{
    public:
    void show()
    {
        cout<<"This is Modern Sofa \n";
    }
    int getLegsCount()
    {
        return this->legsCount;
    }

};
class VictorianSofa :public Sofa
{
    public:
    int legsCount = 6;
    virtual void show()
    {
        cout<<"This is Victorian Sofa \n";
    }
    int getLegsCount()
    {
        return this->legsCount;
    }
};
class ArtDecorSofa :public Sofa
{
    public:
    int legsCount = 5;
    virtual void show()
    {
        cout<<"This is ArtDecor Sofa \n";
    }
    int getLegsCount()
    {
        return this->legsCount;
    }
};

// AbstractFactory
class AbstractFactory
{
    public:
      virtual Chair* createChair() =0;
      virtual Sofa* createSofa() =0;
};
// concrete Factories

class ModernFactory: public AbstractFactory
{
    public:
        Chair* createChair()
        {
            return new ModernChair;
        }
        Sofa* createSofa()
        {
            return new ModernSofa;
        }
};
class VictorianFactory: public AbstractFactory
{
    public:
        Chair* createChair()
        {
            return new VictorianChair;
        }
        Sofa* createSofa()
        {
            return new VictorianSofa;
        }
};
class ArtDecorFactory: public AbstractFactory
{
    public:
        Chair* createChair()
        {
            return new ArtDecorChair;
        }
        Sofa* createSofa()
        {
            return new ArtDecorSofa;
        }
};

// Abstract class for creatingFactory based on input 
class CreateFactory
{
    public:
    static AbstractFactory* createFactory(string str)
    {
        if(str=="modern")
        {
            return new ModernFactory;
        }
        if(str == "victorian")
            return new VictorianFactory;
        return new ArtDecorFactory;
    }
};

// client 
class Client
{
    public:
    Client()
    {
        string factoryType;
        cout<<"which Type of furnityre you want to see...\t";
        cin>>factoryType;
        AbstractFactory* factory = CreateFactory::createFactory(factoryType);

        Chair* chair = factory->createChair();
        Sofa* sofa = factory->createSofa();
        chair->show();
        cout<<"legs count ="<<chair->getLegsCount()<<endl<<endl;
        sofa->show();
        cout<<"legs Count = "<<sofa->getLegsCount()<<endl;

    }
};

int main()
{
    Client Adarsh;
    return 0;
}
