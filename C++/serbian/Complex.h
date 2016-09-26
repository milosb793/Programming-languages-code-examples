#pragma once
#include<iostream>
#include<math.h>
using namespace std;

#define M_PI acos(-1.0) // Пи


class Complex
{
         // Приватни део //
private:
    double *re;
    double *im;

         // Јавни део //
public:
        // Конструктор //

    // (Без параметара) //
    Complex()
    {
        this->re = new double(0);
        this->im = new double(0);
    }

    Complex(double re, double im)
    {
        this->re = new double(re);
        this->im = new double(im);
    }

         // Copy конструктор //
    Complex(const Complex &C)
    {
        this->re = new double(C.vratiRe());
        this->im =new double(C.vratiIm());
    }

        // Move конструктор //
     Complex(const Complex &&C)
    {
        // Конструктор померач ради следеће:
        // Пре свега битно је напоменути да објекти морају бити показивачи, тј. да им се приступа преко показивача.
        // Када се позива: Complex c1(c2);
        // C1 се иницијализује на вредности C2, а за C2 се позива деструктор

        this->re = new double(C.vratiRe());
        this->im = new double(C.vratiIm());
        delete C.re; delete C.im;
//        C.re = nullptr; C.im = nullptr;
    }

    // Деструктор //
    ~Complex()
    {
        delete this->re;
        delete this->im;
        this->re = this->im = nullptr;
    }

        // Методе //

    void ispisi()
    {
        cout << noshowpos << *this->re << " " << showpos << *this->im << "i" << endl; // showpos(itive) показује + ако је број позитиван
    }

    double vratiRe()const // овде const значи да оно што ће ова метода вратити неће моћи да се мења(рецимо помоћу показивача), тј. биће const double
    {
        return this->re;
    }

    double vratiIm()const
    {
        return this->im;
    }

    void postaviRe(double re)
    {
        *this->re = re;
    }

    void postaviIm(double im)
    {
        *this->im = im;
    }

    Complex konjugovanoKompleksni()
    {
        // *new значи да враћа баш објекат, не показивач
        // Ако би остало new, онда би поврати тип ове методе био Complex*
        return *new Complex( *this->re, - *this->im );
    }

    double vratiRo() // удаљеност од исходишта
    {
        // корен од (re^2 + im^2)
        return ( sqrt( pow(*this->re,2 ) + pow(*this->im,2) ) );
    }

    Complex saberi(Complex c2)
    {
        // враћамо нови објекат, који је сабирак два комплексна броја
        // први комплексни број је број преко кога се позива ова метода. Њему приступамо
        // показивачем this. Другом објекту приступамо помоћу његових метода.
        // На крају враћамо нови објекат који као аругументе прима реални и имагинарни део,
        // који су уствари сабирци ова два броја;
        return *new Complex( (*this->re + c2.vratiRe()), (*this->im + c2.vratiIm() ) );
    }

    Complex oduzmi(Complex c2)
    {
        return *new Complex( (*this->re - c2.vratiRe()), (*this->im - c2.vratiIm() ) );
    }

    Complex& podeli(Complex &c2)
    {

        if (c2.vratiRe() == 0 && c2.vratiIm() == 0)
        {
            cout << "C2 мора бити већи од 0!\n";
            return *new Complex();
        }

        if (*this->re == 0 && *this->im == 0)
            return *new Complex();

        Complex pom = pomnozi(*this, c2); // статичка, доле је дефинисана, први арумент је објекат који позива методу помножи
        pom.postaviRe( pom.vratiRe() / ( pow(c2.vratiRe(), 2.0) + pow(c2.vratiIm(), 2.0) ) );
        pom.postaviIm( pom.vratiIm() / (pow(c2.vratiRe(), 2.0) + pow(c2.vratiIm(), 2.0) ) );
        return pom;
    }

    Complex& pomnozi(Complex c2)
    {
        Complex pom = *new Complex(); // може и Complex pom();
        pom.postaviRe(*this->re * c2.vratiRe() - *this->im * c2.vratiIm()); // минус неутралише i*i
        pom.postaviIm(*this->re * c2.vratiIm() + *this->im * c2.vratiRe());
        return pom;
    }

    Complex stepenuj(int stepen)
    {
        //Moavrove formule
        // z=Re+Im; r=sqrt(Re^2 + Im^2); fi=arctg(Im/Re);
        // z^n = r^n * cos(n*fi) + i*r^n * sin(n*fi) );

        Complex pom = *new Complex();
        double r;
        float fi;

        if( stepen == 0)
            return *new Complex(1,1);

        if( stepen == 1)
            return *this; // пошто је this показивач, ако је степен 1, враћамо сам објекат преко кога се позива ова метода

        r = sqrt(pow(*this->re, 2) + pow(*this->im, 2));
        fi = M_PI + atan(*this->im / *this->re);		// Pi горе дефинисан

        pom.postaviRe( pow(r, stepen) * cos( stepen*fi ) );
        pom.postaviIm( pow( r, stepen ) * sin( stepen * fi) );
        return pom;
    }

        // Статичке методе //

    //позивају се без објекта, помоћу оператора досега ::
    // тако што се као аргумент проследи објекат са којим се оперише

    static Complex konjugovanoKompleksni(Complex c)
    {
        return *new Complex( c.vratiRe(), - c.vratiIm() );
    }

    static void ispisi(Complex C)
    {
        C.ispisi();
    }

    static double vratiRo(Complex C)
    {
        C.vratiRo();
    }

    static Complex saberi(Complex c1, Complex c2)
    {
        c1.saberi(c2);
    }

    static Complex oduzmi(Complex c1, Complex c2)
    {
        c1.oduzmi(c2);
    }

    static Complex& pomnozi(Complex c1, Complex c2)
    {
        c1.pomnozi(c2);
    }

    static Complex podeli(Complex c1, Complex c2)
    {
        c1.podeli(c2);
    }

    static Complex stepenuj(Complex c, int stepen)
    {
        c.stepenuj(stepen);
    }

        // Оператори //

// Спецификатор friend представља пријатељску (friendly) функцију
// пријатељске функције "обећавају" сигуран приступ приватним атрибутима класе
// тако да се у њима сме приступати приватним члановима као јавним

    friend Complex& operator+(Complex &k1, Complex &k2)
    {
        // Функција враћа адресу објекта,
        // Ова функција се позива: Complex c = c1 + c2;
        return *new Complex(*k1.re + *k2.re, *k1.im + *k2.im);
        // само new Complex враћа обичан показивач. Са оператором dereferenciranja *, ми приступамо садржају показивача, тј
        // објекту на који он показује. Тако да *new Complex значи да враћамо сам садржај(објекат) на који показује показивач.
        // ово нам треба ради саме адресе објекта, а не адресе показивача
    }

    friend Complex& operator-(Complex &k1, Complex &k2)
    {
        return *new Complex(*k1.re - *k2.re, *k1.im - *k2.im);
    }

    friend ostream& operator<<(ostream& out, const Complex& kb)
    {
        // ова функција служи за директно исписивање броја
        // пример: cout<<c1;
        // враћа објекат Излазног тога оstream
        return out << "(" << (*kb.re) << "," << *kb.im << ")"<<endl;

    }

    //post increment
    Complex  operator++(int)
    {
        // Ова метода се позива: c1++; и  мења стање објекта c1, јер је еквивалент c1 = c1+1; Могло би се избећи навођењем оператора += који се понаша другачије
        // да би се знало да је реч о пост инкременту а не пре, користи се као атрибут реч int
        return *new Complex(*this->re++, *this->im++);
    }

    //pre increment
    Complex operator++()
    {
       return *new Complex(++*this->re, ++*this->im);
    }

    friend Complex& operator~(Complex k) //operator konjugacije
    {
        return *new Complex( *k.re, -*k.im ) ;
    }

    friend Complex& operator+=(Complex &k1, const Complex k2)
    {
        // измениће леви операнд: c1+=c2; c2 ће постати сабирак ова два броја;
        k1.postaviRe( *k1.re + *k2.re);
        k1.postaviIm( *k1.im + *k2.im);
    }

    bool operator>(Complex k)
    {
        // враћа true или false
        return ( *this->re > k.vratiRe() && *this->im > k.vratiIm() );
    }

    bool operator<(Complex k)
    {
        return ( *this->re < k.vratiRe() && *this->im < k.vratiIm() );
    }

    bool operator==(Complex k)
    {
        return ( *this->re == k.vratiRe() && *this->im == k.vratiIm() );
    }

    Complex& operator=(const Complex &k)
    {
        if(this != &k)
        {
            *this->re = k.vratiRe();
            *this->im = k.vratiIm();
        }
        return *this;

    }


}; // не заборавити на ;