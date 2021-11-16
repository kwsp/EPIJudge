#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using namespace std;

int FindMaximumSubarray(const vector<int>& A) {
  // TODO - you fill in here.
  int max_seen = 0, max_end = 0;
  for (auto v : A) {
    max_seen = max(max_seen + v, v);
    max_end = max(max_seen, max_end);
  }
  return max_end;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_sum_subarray.cc", "max_sum_subarray.tsv",
                         &FindMaximumSubarray, DefaultComparator{},
                         param_names);
}
