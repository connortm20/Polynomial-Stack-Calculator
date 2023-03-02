/**********************
written by Connor Marshall
for use in Data Structures Project 2
02-13-23
*************************/

#ifndef _POLYNOMIAL_HPP
#define _POLYNOMIAL_HPP

#include <iostream>
#include <list>

#include "Term.hpp"

class Polynomial
{
private:
  std::list<Term> _termList; //stl list of terms with different coefficients

public:
  //constructors
  Polynomial(){};

  //modifiers
  void addNewTerm(Term inputTerm){_termList.push_back(inputTerm);_termList.sort();}//adds term to back of _termList
  void removeTerm(unsigned int degree);//remove the term at the given degree
  void clear(); //clear the polynomial's term list

  //accessors
  std::list<Term> termList() const {return _termList;}

  //"calculator" functions to apply to polynomials
  double evaluate(double inputValue);

  void add(const Term &otherTerm);
  void add(const Polynomial & otherPoly);//add given poly. uses add(term)

  void sub(const Polynomial & otherPoly);//subtract given poly. uses add(term) 

  Polynomial mul(const Term &otherTerm);
  void mul(const Polynomial &otherPoly);//multiply given poly. uses mul(term)

  //methods for performing I/O. They are directly utilized in overloaded <<,>>
  std::ostream& print(std::ostream &os) const;
  friend std::ostream& operator<<(std::ostream &os, const Polynomial &p);
};



#endif

