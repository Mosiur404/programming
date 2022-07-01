#include <iostream>
using namespace std;

class Solution {
private:
  unsigned int n, r, result1, result2;
  unsigned long long int *memo;

public:
  void genFactorials() {
    for (int i = 2; i <= this->n; i++)
      this->memo[i] = i * this->memo[i - 1];
  }

  Solution *init() {
    if (this->n < this->r || this->n == 0 || this->r == 0) return this;

    this->memo = new unsigned long long int[this->n + 1];
    this->memo[0] = 0, this->memo[1] = 1;

    this->genFactorials();
    int t = this->memo[this->n];
    int t1 = this->memo[this->n - this->r];
    // n! / (n - r)!
    this->result1 = this->memo[this->n] / this->memo[this->n - this->r];
    // n! / r!(n - r)!
    this->result2 = this->memo[this->n] /
                    (this->memo[this->r] * this->memo[this->n - this->r]);
    return this;
  }

  void setN() { cin >> this->n; }
  void setR() { cin >> this->r; }
  int getN() { return this->n; }
  int getR() { return this->r; }
  int getResult1() { return this->result1; }
  int getResult2() { return this->result2; }

  Solution(int n = 0, int r = 0) {
    this->n = n;
    this->r = r;
  };
  ~Solution() { delete[] this->memo; };
};

int main(int argc, char const *argv[]) {
  Solution *obj = new Solution();

  cout << "Enter value of n: ";
  obj->setN();
  cout << "Enter value of r: ";
  obj->setR();

  cout << obj->getN() << 'P' << obj->getR() << " = ";
  cout << obj->init()->getResult1() << endl;
  cout << obj->getN() << 'C' << obj->getR() << " = ";
  cout << obj->init()->getResult2() << endl;
  return 0;
}