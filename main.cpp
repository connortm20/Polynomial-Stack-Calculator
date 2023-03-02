/**********************
written by Connor Marshall
for use in Data Structures Project 2
02-13-23
*************************/
#include <iostream>
#include <list>

#include "Polynomial.hpp"
#include "Term.hpp"
#include "Stack.tpp"

using namespace std;

int main(int argc, char *argv[])
{

  Stack<Polynomial> stack;//polynomial stack implemented from in class template file

  char command;
  while(command!='q')
  {
    cout << ">>>";
    cin >> command;

    //remove all elements from the accumulator ie clear stack
    if(command == 'd')
    {
      while(!stack.isEmpty())
        stack.pop();
    }


    //allow user input to store to top of stack
    else if(command == 's')
    {
      Term t;
      Polynomial poly;

      // you can enter any polynomial you like. 
      cout << "Enter Polynomial to push: ";

      // read first term from polynomial
      cin>>t;

      // as long as term just read was not the "terminating" term (";") ...
      while (t.coefficient()!=0)
      {
        // add the new term to the list
        poly.add(t);

        // try to read another term ...
        cin >>t;
      }
      stack.push(poly);
      cout << stack.top();
    }


    //evaluate given a floating point number
    else if(command == 'e')
    {
      double userValue;
      cout << "Enter floating point number to be evaluated: ";
      cin >> userValue;

      double evalValue = stack.top().evaluate(userValue);
      cout << evalValue << endl;
      cout << stack.top();
    }


    //remove the top two elements, add them, return to accumulator
    else if(command == '+')
    {
      Polynomial poly1 = stack.pop();
      Polynomial poly2 = stack.pop();

      poly1.add(poly2);
      stack.push(poly1);

      cout << stack.top();
    }


    //remove the top two elements, subtract them, return to accumulator
    else if(command == '-')
    {
      Polynomial poly1 = stack.pop();
      Polynomial poly2 = stack.pop();

      poly2.sub(poly1);
      stack.push(poly2);

      cout << stack.top();
    }

  
    //remove top two elements, multiply them, return to accumulator
    else if(command == '*')
    {
      Polynomial poly1 = stack.pop();
      Polynomial poly2 = stack.pop();

      poly1.mul(poly2);
      stack.push(poly1);

      cout << stack.top();
    }


    //print the value at the top of the accumulator
    else if(command == 'p')
    {
      if(stack.isEmpty())
        cout << "ACCUMULATOR IS EMPTY" << endl;
      else
        cout << stack.top();
    }

    else if(command == 'q') continue;
    else
    {
      cout << "COMMAND UNRECOGNIZED" << endl;
    }
  }

  cout << "Thank you for using polyCalc!" << endl;
  return 0;
}

