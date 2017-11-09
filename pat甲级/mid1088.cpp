//
// @author prime on 2017/7/24.
//
#include <iostream>

using namespace std;

long long gcd(long long a,long long b)
{//求最大公约数，可能为负，需要绝对值
    return b==0?abs(a):gcd(b,a%b);
}

struct Frac
{
    Frac(long long n,long long d):numerator(n),denominator(d){};
    Frac()= default;
    long long int numerator,denominator;
    friend Frac operator+(const Frac&o1,const Frac&o2);
    friend Frac operator-(const Frac&o1,const Frac&o2);
    friend Frac operator*(const Frac&o1,const Frac&o2);
    friend Frac operator/(const Frac&o1,const Frac&o2);
    friend ostream& operator<<(ostream& out,const Frac&o);
    //friend ostream& operator<<(ostream& out,Frac&&o);
    friend void simplify(Frac&o);
};

void simplify(Frac &o)
{
    long long a=1;
    if(o.numerator!=0)
        a=gcd(o.numerator,o.denominator);
    o.numerator/=a;
    o.denominator/=a;
}

ostream& operator<<(ostream& out,const Frac&o)
{
    long long a=o.numerator,b=o.denominator;
    if(b==0)
    {
        out<<"Inf";
        return out;
    }
    long long coefficient=o.numerator/o.denominator;
    if(a==0)
    {
        out<<"0";
    } else if(a>0)
    {
        a-=b*coefficient;
        if(a==0)
            out<<coefficient;
        else
            if(coefficient==0)
                out<<a<<"/"<<b;
            else
                out<<coefficient<<" "<<a<<"/"<<b;
    }
    else
    {//分子小于0，显然系数也小于0
        a-=b*coefficient;
        if(a==0)
            out<<"("<<coefficient<<")";
        else
        {
            if(coefficient==0)
                out<<"("<<a<<"/"<<b<<")";
            else
                out<<"("<<coefficient<<" "<<-a<<"/"<<b<<")";
        }
    }
    return out;
}

//ostream& operator<<(ostream& out,Frac&&o)
//{
//    long long a=o.numerator,b=o.denominator;
//    if(b==0)
//    {
//        out<<"Inf";
//        return out;
//    }
//    long long coefficient=o.numerator/o.denominator;
//    if(a==0)
//    {
//        out<<"0";
//    } else if(a>0)
//    {
//        a-=b*coefficient;
//        if(a==0)
//            out<<coefficient;
//        else
//        if(coefficient==0)
//            out<<a<<"/"<<b;
//        else
//            out<<coefficient<<" "<<a<<"/"<<b;
//    }
//    else
//    {//分子小于0，显然系数也小于0
//        a-=b*coefficient;
//        if(a==0)
//            out<<"("<<coefficient<<")";
//        else
//        {
//            if(coefficient==0)
//                out<<"("<<a<<"/"<<b<<")";
//            else
//                out<<"("<<coefficient<<" "<<-a<<"/"<<b<<")";
//        }
//    }
//    return out;
//}

Frac operator+(const Frac &o1, const Frac &o2)
{
    Frac res;
    res.denominator=o1.denominator*o2.denominator;
    res.numerator=o1.numerator*o2.denominator+o2.numerator*o1.denominator;
    long long a=1;
    simplify(res);
    return res;
}

Frac operator*(const Frac&o1,const Frac&o2)
{
    Frac res;
    res.numerator=o1.numerator*o2.numerator;
    res.denominator=o1.denominator*o2.denominator;
    simplify(res);
    return res;
}

Frac operator-(const Frac &o1,const Frac &o2)
{
    Frac tmp=o2;
    tmp.numerator=-tmp.numerator;
    return o1+tmp;
}

Frac operator/(const Frac&o1,const Frac&o2)
{
    Frac tmp(o2.denominator,o2.numerator);
    if(tmp.denominator*tmp.numerator<0)
    {//保证符号始终在分子上
        tmp.denominator=abs(tmp.denominator);
        tmp.numerator=-abs(tmp.numerator);
    }
    return o1*tmp;
}


int main()
{
    long long a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    Frac o1(a,b),o2(c,d);
    simplify(o1);
    simplify(o2);
    cout<<o1<<" + "<<o2<<" = "<<o1+o2<<endl;
    cout<<o1<<" - "<<o2<<" = "<<o1-o2<<endl;
    cout<<o1<<" * "<<o2<<" = "<<o1*o2<<endl;
    cout<<o1<<" / "<<o2<<" = "<<o1/o2<<endl;
    return 0;
}


