#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
  int index, arrivalTime, burstTime, priority, startTime, completionTime;
  int turnArroundTime() { return this->completionTime - this->arrivalTime; };
  int waitingTime() { return this->startTime - this->arrivalTime; };
};

class Scheduler {
private:
  queue<Process> processQueue;
  vector<Process> readyQueue;
  queue<Process> terminatedQueue;
  unsigned int totalCT, totalTAT, totalWT, totalIdle, counter, duration;

public:
  Scheduler *enqueue(Process prc) {
    this->processQueue.push(prc);
    return this;
  }
  Scheduler *init() {
    int prevCompletionTime = 0;
    this->duration = 0;
    while (!processQueue.empty()) {
      while (processQueue.front().arrivalTime <= duration) {
        Process *prc = &processQueue.front();
        this->readyQueue.push_back(*prc);
        processQueue.pop();
      }
      // sorting
      if (!readyQueue.empty())
        sort(this->readyQueue.begin(), this->readyQueue.end(),
             [this](Process a, Process b) {
               return this->comparePriority(a, b);
             });
      // process sorted array
      for (int i = 0; i < readyQueue.size(); i++) {
        Process *prc = &readyQueue[i];

        prc->startTime = prevCompletionTime > prc->arrivalTime
                             ? prevCompletionTime
                             : prc->arrivalTime;
        prc->completionTime = prc->startTime + prc->burstTime;

        // extra
        this->totalCT += prc->completionTime;
        this->totalTAT += prc->turnArroundTime();
        this->totalWT += prc->waitingTime();
        this->totalIdle += prevCompletionTime < prc->arrivalTime
                               ? prc->arrivalTime - prevCompletionTime
                               : 0;
        prevCompletionTime = prc->completionTime;
        terminatedQueue.push(*prc);
        counter++;
        this->duration += prc->completionTime - 1;
      }
      if (!readyQueue.empty()) readyQueue.clear();

      this->duration++;
    }
    return this;
  }
  bool comparePriority(Process i1, Process i2) {
    return (i1.priority < i2.priority);
  }
  // extra
  void print() {
    cout << "ID\tArrival\tBurst\tStart\tCompletion\tTAT\tWaiting" << endl;
    while (!this->terminatedQueue.empty()) {
      Process *prc = &terminatedQueue.front();

      cout << "P" << prc->index << '\t' << prc->arrivalTime << '\t'
           << prc->burstTime << '\t' << prc->startTime << '\t'
           << prc->completionTime << "\t\t" << prc->turnArroundTime() << '\t'
           << prc->waitingTime();
      terminatedQueue.pop();
      cout << endl;
    }
    cout << "Total Completion Time: " << this->totalCT << endl;
    cout << "Total Turn Arround Time: " << this->totalTAT << endl;
    cout << "Total Waiting Time: " << this->totalWT << endl;
    cout << "Average Completion Time: " << (float)this->totalCT / this->counter
         << endl;
    cout << "Average Turn Arround Time: "
         << (float)this->totalTAT / this->counter << endl;
    cout << "Average Waiting Time: " << (float)this->totalWT / this->counter
         << endl;
  }
  Scheduler() {
    this->totalCT = 0, this->totalTAT = 0, this->totalWT = 0, this->counter = 0;
  }
  ~Scheduler() {}
};

int main(int argc, char const *argv[]) {
  Scheduler *ps = new Scheduler();
  ps->enqueue({1, 0, 10, 3})->enqueue({2, 0, 1, 1});
  ps->enqueue({3, 0, 2, 4})->enqueue({4, 0, 1, 5});
  ps->enqueue({5, 0, 5, 2});
  ps->init()->print();
  return 0;
}