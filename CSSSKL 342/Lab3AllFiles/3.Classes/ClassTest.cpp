#include <iostream>
#include "Square.h"
#include "SquareContainer.h"

using namespace std;

int main (int argc, char * const argv[]) {
   SquareContainer c;
   
   for (int i = 0; i < 20; i++) {
      Square s;
      s.setSize(i);
      c.insertNext(s);
   }
   SquareContainer d(c); // copy
   SquareContainer e = d; // assignment

   Square small, big;
   small.setSize(10);
   big.setSize(20);
   bool lessTrue = small < big;
   bool lessFalse = big < small;
   cout << "Small is less than big: " << lessTrue << endl;
   cout << "Big is less than small: " << lessFalse << endl;

   SquareContainer f;
   SquareContainer g;
   for (int i = 0; i < 10; i++) {
      Square s;
      s.setSize(i);
      f.insertNext(s);
   }
   for (int i = 0; i < 20; i++) {
      Square s;
      s.setSize(i);
      g.insertNext(s);
   }
   g = f;

   try {
      cout << g.size() << endl;
      cout << f.size() << endl;
      for (int i = 0; i < g.size(); i++) {
         cout << "Square " << i << " size is " 
            << g.deleteLast().getSize() << " for SquareContainer g" << endl;
      }
      cout << g.size() << endl;
      cout << f.size() << endl;
      for (int i = 0; i < f.size(); i++) {
         cout << "Square " << i << " size is " 
            << f.deleteLast().getSize() << " for SquareContainer f" << endl;
      }
      cout << g.size() << endl;
      cout << f.size() << endl;
      for (int i = 0; i < 21; i++) {
         cout << "Square " << i << " size is " 
         << c.deleteLast().getSize() << endl;
      }
   }
   catch (SquareContainerException sqe) {
      cerr << sqe.what();
   }

   
   
    return 0;
}
