#include <iostream>
#include <queue>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct Process {
  int index;
  int arrivalTime;
  int burstTime;
  int burstTimeRemaining = this->burstTime;
  int completionTime;
  int turnArroundTime() { return this->completionTime - this->arrivalTime; };
  int waitingTime() { return this->completionTime - this->burstTime; };
  int responseTime;
};

class Schduler {
 private:
  queue<Process> allProcess;

  queue<Process> readyQueue;
  queue<Process> runningQueue;
  queue<Process> history;

  int timeQuantum;
  int duration;

 public:
  Schduler& enqueue(Process prc) {
    this->allProcess.push(prc);
    return *this;
  }

  // extra
  void print(queue<Process> prc) {
    while (!prc.empty()) {
      cout << "P" << prc.front().index << ' ';
      prc.pop();
    }

    cout << endl;
  }
  void printReadyQueue() { this->print(this->readyQueue); }
  void printRunningQueue() { this->print(this->runningQueue); }
  void printHistory() {
    while (!this->history.empty()) {
      int index = this->history.front().index;
      int completionTime = this->history.front().completionTime;
      cout << "P" << index << '(' << completionTime << ") ";
      this->history.pop();
    }

    cout << endl;
  }
  int completionTimeTotal() { return this->duration; }
  int min(int a, int b) { return a > b ? b : a; }
  // extra

  void startProcessing() {
    this->checkReadyQueue();
    while (!readyQueue.empty()) {
      // log(this->duration);

      this->moveReadyToRunning();
      this->checkReadyQueue();

      this->moveRunningToReady();
    }
  }

  void moveRunningToReady() {
    if (this->runningQueue.empty()) return;
    Process& prc = this->runningQueue.front();

    // if process has burst time remaining then push it back to ready
    if (this->isProcessingDone(prc)) {
      prc.completionTime = this->duration;
    }

    if (!this->isProcessingDone(prc)) readyQueue.push(prc);

    this->runningQueue.pop();
  }

  void moveReadyToRunning() {
    if (this->readyQueue.empty()) return;

    Process& prc = this->readyQueue.front();

    this->duration += this->min(prc.burstTimeRemaining, this->timeQuantum);
    prc.burstTimeRemaining -= this->timeQuantum;
    this->runningQueue.push(prc);
    this->history.push(prc);
    log(prc.completionTime);

    this->readyQueue.pop();
  }

  void checkReadyQueue() {
    if (allProcess.empty()) return;
    while (allProcess.front().arrivalTime <= this->duration) {
      readyQueue.push(allProcess.front());
      allProcess.pop();
    }
  }

  bool isProcessingDone(Process prc) { return prc.burstTimeRemaining <= 0; }

  Schduler(int tq = 0) {
    this->timeQuantum = tq;
    this->duration = 0;
  }
  ~Schduler() {}
};

int main(int argc, char const* argv[]) {
  Schduler roundRobin(2);

  roundRobin.enqueue({1, 0, 5}).enqueue({2, 1, 4});
  roundRobin.enqueue({3, 2, 2}).enqueue({4, 4, 1});

  roundRobin.startProcessing();
  cout << "Ready: ";
  roundRobin.printReadyQueue();
  cout << "Running: ";
  roundRobin.printRunningQueue();
  cout << "History: ";
  roundRobin.printHistory();

  cout << "Total time: ";
  log(roundRobin.completionTimeTotal());
  return 0;
}
