/**********************
written by Connor Marshall
for use in Data Structures Project 2
02-13-23
*************************/

#include <iostream>
#include <math.h>

#include "Polynomial.hpp"

using namespace std;


void
Polynomial::clear()
{
  _termList.clear();
}


void 
Polynomial::removeTerm(unsigned int degree)
{
  for(Term currTerm: _termList)
  {
    if(currTerm.degree() == degree)
    {
      _termList.remove(currTerm);
      return;
    }
  }
}


double 
Polynomial::evaluate(double inputValue)
{
  double sum = 0;

  for(Term currTerm: this->termList())
  {
    //coef * input^degree
    sum += currTerm.coefficient() * pow(inputValue, currTerm.degree());
  }

  return sum;
}

//add an inputted term to this polynomial
void 
Polynomial::add(const Term &otherTerm)
{
  for(Term &currTerm: _termList)
  {
    if(currTerm.degree() == otherTerm.degree())
    {
      double sum = currTerm.coefficient() + otherTerm.coefficient();
       currTerm.coefficient() = sum;

      //check for term coef == 0
      if(currTerm.coefficient()==0)
        removeTerm(currTerm.degree());

      return;
    }
  }
  //if there was no matching degree in the poly
  addNewTerm(otherTerm);
}


//add all terms from inputed polynomial
void
Polynomial::add(const Polynomial &otherPoly)
{
  for(Term currTerm: otherPoly.termList())
    add(currTerm);
}


//subtact all terms from inputed polynomial
void
Polynomial::sub(const Polynomial &otherPoly)
{
  for(Term currTerm: otherPoly.termList())
  {
    currTerm.coefficient() = -1 * currTerm.coefficient();
    add(currTerm);
  }
}


Polynomial 
Polynomial::mul(const Term &otherTerm)
{
  Polynomial newPoly;
  newPoly.clear();

  for(Term currTerm: _termList)
  {
    newPoly.add(Term(otherTerm.coefficient() * currTerm.coefficient(), otherTerm.degree()+currTerm.degree()));
  }
  return newPoly;
}

//multiply all terms from inputed polynomial
void 
Polynomial::mul(const Polynomial &otherPoly)
{
  Polynomial newPoly;

  for(Term &currTerm: otherPoly.termList())
  {
    newPoly.add(mul(currTerm));
  }
  clear();
  add(newPoly);
}


ostream& 
Polynomial::print(std::ostream &os) const
{
  bool firstTerm=true;
  for(Term nextTerm: this->termList())
  {
    if (nextTerm.coefficient()>0 && !firstTerm)
      os << '+';
    os << nextTerm;
    firstTerm=false;
  }
  os << endl;

  return os;
}

ostream& operator<<(ostream &os, const Polynomial &p)
{
  return p.print(os);
}
