#include "expr.hh"
#include "parse.hh"

#include <iostream>
#include <cstdlib>

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " PREFIX_EXPR..." << std::endl;
    std::exit(1);
  }
  for (auto i = 1; i < argc; i++) {
    ExprPtr exprP = parse(argv[i]);
    std::cout << exprP->dcCode() << " p c" << std::endl;
  }
}
