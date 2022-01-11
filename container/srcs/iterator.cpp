// iterator_traits.cpp
// compile with: /EHsc
#include <iostream>
#include "../includes/container.hpp"
//#include <iterator>
//#include <vector>
//#include <list>

//using namespace std;

template< class it >
void function( it i1, it i2 )
{
   iterator_traits<it>::iterator_category cat;
   cout << typeid( cat ).name( ) << endl;
   while ( i1 != i2 )
   {
      iterator_traits<it>::value_type x;
      x = *i1;
      cout << x << " ";
      i1++;
   };
   cout << endl;
};

int main( )
{
   ft::Vector<char> vc( 10,'a' );
   function( vc.begin( ), vc.end( ) );

}
/* Output:
struct std::random_access_iterator_tag
a a a a a a a a a a
struct std::bidirectional_iterator_tag
0 0 0 0 0 0 0 0 0 0
*/
