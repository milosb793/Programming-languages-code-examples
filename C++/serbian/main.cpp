//#include <iostream>
//#include "Complex.h"

//int main()
//{
//
//    // Статичка декларација
//    Complex c1(5,6);
//    Complex c2(7,-8);
//    Complex c3;
//
//    // Динамичка прича
//    Complex *cd1 = new Complex(30,12);
//    Complex *cd2 = new Complex(20,2);
//
//
//    cout << c1 << c2;
//    cout << "Сабрана: " << c1+c2;
//    cout << "Одузета: " << c1-c2;
//    cout << "Степенован c1 на 2: " << c1.stepenuj(2);
//    cout << "c1 подељен са c2: " << c1.podeli(c2);
//    cout << "Пре-инкремент c1: "<< ++c1;
//    cout << "Пост-инкремент c1: "<< c1++;
//    cout << "c1: "<<c1;
//    cout << "Mодуо c1: " << c1.vratiRo();
//    cout << "\nc1 > c2: " << (c1 > c2) ? "Да": "Не";
//    cout << "\nc1 < c2: " << (c1 < c2) ? "Да": "Не";
//    cout << "\nc1 == c2: " << (c1 == c1) ? "Да": "Не";
//    cout << "\nТестирање оператора +=, c1+=c2: \n";
//    c1+=c2; cout<< c1;
//    c3 = c1; cout << "c3 постаје c1, оператор =: "<< c3;
//    cout << "Конјугација c1: " << c1.konjugovanoKompleksni();
//    cout << "Заборавили смо да помножимо два броја: \n";
//    cout << Complex::pomnozi(c1,c2);
//
//
//    cout <<"\n\n Динамичка прича: \n"<< *cd1 << *cd2;
//    cout << *cd1 + *cd2;
//    cout << *cd1 - *cd2;
//    cout << cd1->pomnozi(*cd2);
//    cout << cd1->podeli(*cd2);
//
//    return 0;
//}

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        {
        for(int j = 0;j<=i;j++)
            {
                for(int k=0; k<j;k++)
                    printf(" ");

                printf("#");
        }
        printf("\n");
    }
        return 0;

}