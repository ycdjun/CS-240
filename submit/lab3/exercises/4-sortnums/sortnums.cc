#include <iostream>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>

std::vector<int>
readNums(std::vector<std::string> fileNames)
{
  std::vector<int> nums; //empty collection
  for (auto fileName : fileNames) { //let compiler figure out fileName is string
    std::ifstream in(fileName); //open file
    if (!in) {
      std::cerr << "cannot read \"" << fileName << "\"" << std::endl;
      std::exit(1);
    }
    int i;
    while (in >>i) {
      nums.push_back(i);
    }
    if (!in.eof()) {
      std::cerr << "i/o error on file \"" << fileName << "\"" << std::endl;
      std::exit(1);
    }
  } //for
  return nums;
}

bool
cmp(const int &a, const int &b)
{
  return a > b;
}

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " FILE..." << std::endl;
    std::exit(1);
  }
  auto nums = readNums(std::vector<std::string>(&argv[1], &argv[argc]));
  sort(nums.begin(), nums.end(), cmp);
  for (auto n : nums) { std::cout << n << std::endl; }
}
