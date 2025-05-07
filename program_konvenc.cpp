#include <iostream>

struct Pair {
  int a;
  int b;
};

void PrintEqual() {
  std::cout << "===" << std::endl;
}

void PrintDash() {
  std::cout << "---" << std::endl;
}

void PrintOutput() {
  std::cout << "Output:" << std::endl;
}

void SortPairs(Pair* data, int length) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < length - 1; ++j) {
      if (data[j].a > data[j + 1].a) {
        std::swap(data[j].a, data[j + 1].a);
        std::swap(data[j].b, data[j + 1].b);
      }
    }
  }
}

void ProcessAndPrintPairs(const Pair* data, int size) {
  for (int i = 0; i < size; ++i) {
    int a = data[i].a;
    int b = data[i].b;
    int result = 0;

    if (a % 2 == 0) {
      if (b % 2 == 0) {
        result = a * b;
      } else {
        result = a + b;
      }
    } else {
      if (b % 2 == 0) {
        result = a - b;
      } else {
        result = a;
      }
    }
    std::cout << result << std::endl;
  }
}

void Process(Pair* data, int length) {
  SortPairs(data, length);
  PrintEqual();
  PrintOutput();
  PrintDash();
  ProcessAndPrintPairs(data, length);
}

int main() {
  Pair pairs[5] = {
      {5, 1},
      {2, 4},
      {3, 7},
      {1, 6},
      {4, 5}
  };

  Process(pairs, 5);
  return 0;
}
