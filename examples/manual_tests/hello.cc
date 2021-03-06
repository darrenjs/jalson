#include "wampcc/json.h"

#include <iostream>
#include <stdint.h>

#include <limits>
#include <stdio.h>
#include <stdlib.h>


#define PUSH_INT( T )                              \
  {                                                \
    T i = std::numeric_limits<T>::max();           \
    wampcc::json_value v(i);                        \
    msg.push_back( v );                            \
    std::cout << "  " << #T << ":" << i <<"\n";    \
  }


void test_ints()
{
  wampcc::json_array msg;

  std::cout << "adding:\n";
  PUSH_INT( int );
  PUSH_INT( long );
  PUSH_INT( long long );
  PUSH_INT( unsigned int );
  PUSH_INT( unsigned long );
  PUSH_INT( unsigned long long );
  std::cout <<  "\n";

  std::string enc = wampcc::json_encode( msg );

  std::cout << "jalson encoded: " << enc << "\n";
  std::cout << "\n";
}


void test_make()
{
  wampcc::json_array msg;
  std::cout << "adding:\n";
  {
    std::cout << "  null\n";
    msg.push_back( wampcc::json_value::make_null() );
  }
  {
    std::cout << "  array\n";
    msg.push_back( wampcc::json_value::make_array() );
  }
  {
    std::cout << "  object\n";
    msg.push_back( wampcc::json_value::make_object() );
  }
  {
    std::cout << "  string\n";
    msg.push_back( wampcc::json_value::make_string() );
  }
  {
    std::cout << "  bool\n";
    msg.push_back( wampcc::json_value::make_bool() );
  }
  {
    std::cout << "  int\n";
    msg.push_back( wampcc::json_value::make_int() );
  }
  {
    std::cout << "  uint\n";
    msg.push_back( wampcc::json_value::make_uint() );
  }
  {
    std::cout << "  double\n";
    msg.push_back( wampcc::json_value::make_double() );
  }
  std::string enc = wampcc::json_encode( msg );
  std::cout << "jalson encoded: " << enc << "\n";
  std::cout << "\n";
}

int main(int, char**)
{

  test_ints();
  test_make();

  wampcc::json_value v = wampcc::json_value::make_array();
  wampcc::json_append<wampcc::json_array>(v.as_array()).push_back(1);
  v.as_array().push_back(true);
  v.as_array().push_back(false);
  v.as_array().push_back(wampcc::json_value());
  wampcc::json_append<wampcc::json_array>(v.as_array()).push_back("hello");
  std::cout << ">>" << v << "\n";

  return 0;
}
