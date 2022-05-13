#include <iostream>
#include <queue>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct Process {
  int index;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnArroundTime() { return this->completionTime - this->arrivalTime; };
  int waitingTime() { return this->completionTime - this->burstTime; };
  int responseTime;
};

class Schduler {
 private:
  queue<Process> allProcess;

  queue<Process*> readyQueue;
  queue<Process*> runningQueue;

  int timeQuantum;

 public:
  Schduler& enqueue(Process prc) {
    this->allProcess.push(prc);
    return *this;
  }

  void print() {
    while (!allProcess.empty()) {
      cout << "P" << allProcess.front().index << ' ';
      allProcess.pop();
    }

    cout << endl;
  }

  Schduler(int tq = 0) { this->timeQuantum = tq; }
  ~Schduler() {}
};

int main(int argc, char const* argv[]) {
  Schduler roundRobin;
  roundRobin.enqueue({1, 0, 5}).enqueue({2, 1, 4});
  roundRobin.enqueue({3, 2, 2}).enqueue({4, 4, 1});

  roundRobin.print();
  return 0;
}
