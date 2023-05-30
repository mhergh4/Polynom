#include <iostream>
#include <array>
#include <time.h>
#include <math.h>
#include <stdbool.h>

using namespace std;
const size_t size = 7;
static int count = 0;

class Polynom
{
public:
   Polynom()
   {
      arrOfCoefficient.fill(0);
      arrOfDegrees.fill(0);
      variable = 'x';
      count++;
   }
   Polynom(array<double, size> aOC)
   {
      setCoefficient(aOC);
      arrOfDegrees.fill(1);
      count++;
      variable = 'x';
   }
   Polynom(array<int, size> aOD)
   {
      setDegrees(aOD);
      arrOfCoefficient.fill(1);
      count++;
      variable = 'x';
   }
   Polynom(array<double, size> aOC, array<int, size> aOD, char v)
   {
      setCoefficient(aOC);
      setDegrees(aOD);
      setV(v);
      count++;
   }
   void setCoefficient(const array<double, size> &aOC)
   {
      for (int i = 0; i < size; i++)
         arrOfCoefficient[i] = aOC[i];
   }
   void setDegrees(const array<int, size> &aOD)
   {
      for (int i = 0; i < size; i++)
         arrOfDegrees[i] = aOD[i];
   }

   void setV(const char &v)
   {
      variable = v;
   }

   const array<double, size> &getCoefficient() const
   {
      return arrOfCoefficient;
   }

   const array<int, size> &getDegrees() const
   {
      return arrOfDegrees;
   }

   const char &getV() const
   {
      return variable;
   }

   const int &getCount() const
   {
      return count;
   }

   void print()
   {
      bool whasAPrevius = false;
      for (int i = 0; i < size; i++)
      {

         if (arrOfCoefficient[i] == 0)
            continue;
         else
         {
            if (i != 0 && whasAPrevius)
               cout << " + ";
            whasAPrevius = true;
            if (arrOfCoefficient[i] != 1)
            {
               if (arrOfDegrees[i] != 0)
                  cout << arrOfCoefficient[i] << "*" << variable;
            }
            else if (arrOfDegrees[i] != 0)
               cout << variable;
         }
         if (arrOfDegrees[i] == 0)
         {
            cout << arrOfCoefficient[i];
            continue;
         }
         else
         {
            if (arrOfDegrees[i] != 1 && i != size - 1)
               cout << "^" << arrOfDegrees[i];
            if (i == size - 1)
               cout << "^" << arrOfDegrees[i];
         }
      }
      cout << endl;
   }

private:
   array<double, size> arrOfCoefficient;
   array<int, size> arrOfDegrees;
   char variable;
};
Polynom calcDerivative(const Polynom &pol, int degree)
{

   array<double, size> newArrOfCof = pol.getCoefficient();

   array<int, size> newArrOfDeg = pol.getDegrees();

   for (int i = 0; i < degree; i++)
   {

      for (int j = 0; j < size; j++)
      {
         if (newArrOfDeg[j] == 0)
         {
            newArrOfCof[j] = 0;
            continue;
         }
         newArrOfCof[j] *= newArrOfDeg[j];
         newArrOfDeg[j] -= 1;
      }
   }
   return Polynom(newArrOfCof, newArrOfDeg, pol.getV());
}
double calcPolynomAt(const Polynom &pol, double x)
{
   double sum = 0;
   const array<double, size> &newArrOfCof = pol.getCoefficient();
   const array<int, size> &newArrOfDeg = pol.getDegrees();
   for (int j = 0; j < size; j++)
   {
      sum += pow(x, newArrOfDeg[j]) * newArrOfCof[j];
   }
   return sum;
}
int main()
{
   time_t t;
   srand((unsigned)time(&t));
   array<double, size> Coefficient;
   array<int, size> Degrees;
   for (int i = 0; i < size; i++)
   {
      Coefficient[i] = rand() % 7;
      Degrees[i] = rand() % 7;
   }
   char var;
   cout << "Enter your variable ";
   cin >> var;
   cout << endl;
   Polynom p(Coefficient, Degrees, var);
   p.print();
   calcDerivative(p, 3).print();
   cout << calcPolynomAt(p, 2) << endl;
   Polynom milena(Degrees);
   milena.print();
   Polynom p2(Coefficient, Degrees, 'x');
   cout << p.getCount();
   return 0;
}
// #include <iostream>
// #include <cmath>
// #include <array>
// #include <stdexcept>
// #include <time.h>

// using namespace std;

// const int size = 10;

// class Polynom {
// public:
//     Polynom() {
//         for (int i = 0; i < size; i++) {
//             Coefficient[i] = 0;
//             Degrees[i] = 0;
//         }
//         var = 'x';
//         count = 0;
//     }

//     Polynom(array<double, size> c, array<int, size> d, char v) {
//         Coefficient = c;
//         Degrees = d;
//         var = v;
//         count = 0;
//         for (int i = 0; i < size; i++) {
//             if (Coefficient[i] != 0) {
//                 count++;
//             }
//         }
//     }

//     Polynom(array<int, size> d, char v = 'x') {
//         Degrees = d;
//         var = v;
//         for (int i = 0; i < size; i++) {
//             Coefficient[i] = 0;
//         }
//         count = 0;
//     }

//     int getCount() const {
//         return count;
//     }

//     char getVar() const {
//         return var;
//     }

//     void setVar(char v) {
//         var = v;
//     }

//     double getCoefficient(int index) const {
//         if (index < 0 || index >= size) {
//             throw out_of_range("Index out of range");
//         }
//         return Coefficient[index];
//     }

//     int getDegree(int index) const {
//         if (index < 0 || index >= size) {
//             throw out_of_range("Index out of range");
//         }
//         return Degrees[index];
//     }

//     void setCoefficient(int index, double c) {
//         if (index < 0 || index >= size) {
//             throw out_of_range("Index out of range");
//         }
//         Coefficient[index] = c;
//     }

//     void setDegree(int index, int d) {
//         if (index < 0 || index >= size) {
//             throw out_of_range("Index out of range");
//         }
//         Degrees[index] = d;
//     }

//     void print() const {
//         bool first = true;
//         for (int i = 0; i < size; i++) {
//             if (Coefficient[i] == 0) {
//                 continue;
//             }
//             if (first) {
//                 first = false;
//             } else {
//                 if (Coefficient[i] > 0) {
//                     cout << " + ";
//                 } else {
//                     cout << " - ";
//                 }
//             }
//             double abs_coeff = abs(Coefficient[i]);
//             if (abs_coeff != 1 || Degrees[i] == 0) {
//                 cout << abs_coeff;
//                 if (Degrees[i] != 0) {
//                     cout << var;
//                 }
//             } else {
//                 if (Degrees[i] != 0) {
//                     cout << var;
//                 } else {
//                     cout << abs_coeff;
//                 }
//             }
//             if (Degrees[i] > 1) {
//                 cout << "^" << Degrees[i];
//             }
//         }
//         cout << endl;
//     }

// private:
//     array<double, size> Coefficient;
//     array<int, size> Degrees;
//     char var;
//     int count;
// };

// Polynom calcDerivative(const Polynom& p, int n) {
//     Polynom deriv(p);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < deriv.getCount(); j++) {
//             if (deriv.getDegree(j)== 0) {
// deriv.setCoefficient(j, 0);
// } else {
// deriv.setCoefficient(j, deriv.getCoefficient(j) * deriv.getDegree(j));
// deriv.setDegree(j, deriv.getDegree(j) - 1);
// }
// }
// }
// return deriv;
// }

// double calcPolynomAt(const Polynom& p, double x) {
// double result = 0;
// for (int i = 0; i < p.getCount(); i++) {
// result += p.getCoefficient(i) * pow(x, p.getDegree(i));
// }
// return result;
// }

// int main() {
// time_t t;
// srand((unsigned) time(&t));
// array<double, size> Coefficient;
// array<int, size> Degrees;
// for (int i = 0; i < size; i++) {
// Coefficient[i] = rand() % 7;
// Degrees[i] = rand() % 7;
// }
// char var;
// cout << "Enter your variable ";
// std::cin >> var;
// cout << endl;
// Polynom p(Coefficient, Degrees, var);
// p.print();
// calcDerivative(p, 3).print();
// cout << calcPolynomAt(p, 2) << endl;
// Polynom milena(Degrees);
// milena.print();
// Polynom p2(Coefficient, Degrees, 'x');
// cout << p.getCount();
// return 0;
// }
