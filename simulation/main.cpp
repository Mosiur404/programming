#include <iostream>
using namespace std;

struct Customer {
  unsigned int id;
  unsigned int randomNumber;
  unsigned int iAt;
  unsigned int arrivalTime;
  unsigned int randomNumberForServiceTime;
  unsigned int serviceTime;
  unsigned int timeServiceBegins;
  unsigned int waitingTime;
  unsigned int timeServiceEnds;
  unsigned int timeSpentInSystem;
  unsigned int idleTimeForServer;
};

class Solution {
 private:
  int totalInterArrivalTime = 0;
  int totalArrivalTime = 0;
  int totalServiceTime = 0;
  int totalWaitingTime = 0;
  int totalIdleTime = 0;
  int totalSpendTimeInSystem = 0;
  int totalCustomerWait = 0;
  int numeberOfCustomers;
  Customer *customers;

 public:
  void startSimulating() {
    int prevArrivalTime = 0;
    int prevTimeOfServiceEnds = 0;
    for (int i = 0; i < this->numeberOfCustomers; i++) {
      Customer *current = &this->customers[i];
      current->id = i + 1;
      if (i == 0) {
        // Random digit
        current->randomNumber = 0;
        // Inter Arrival Time
        current->iAt = 0;
      } else {
        current->randomNumber = rand() % 1000 + 1;
        current->iAt = this->generateIAT(current->randomNumber);
      }
      // Random digit for service
      current->randomNumberForServiceTime = rand() % 100 + 1;
      // Arrival Time
      current->arrivalTime = prevArrivalTime + current->iAt;
      // Service time
      current->serviceTime =
          this->generateServiceTime(current->randomNumberForServiceTime);
      // Time Service begins (check which one is greater, previous one end or
      // current arrival)
      current->timeServiceBegins =
          this->max(prevTimeOfServiceEnds, current->arrivalTime);
      // Waiting time
      current->waitingTime = prevTimeOfServiceEnds > current->arrivalTime
                                 ? prevTimeOfServiceEnds - current->arrivalTime
                                 : 0;
      // Time service end
      current->timeServiceEnds =
          current->timeServiceBegins + current->serviceTime;
      // Time Spent in system
      current->timeSpentInSystem = current->arrivalTime + current->serviceTime;
      // Idle Time
      current->idleTimeForServer = prevTimeOfServiceEnds > current->arrivalTime
                                       ? 0
                                       : current->arrivalTime - prevArrivalTime;
      // Total
      this->totalInterArrivalTime += current->iAt;
      this->totalArrivalTime += current->arrivalTime;
      this->totalServiceTime += current->serviceTime;
      this->totalWaitingTime += current->waitingTime;
      this->totalSpendTimeInSystem += current->timeSpentInSystem;
      this->totalIdleTime += current->idleTimeForServer;
      if (current->waitingTime) this->totalCustomerWait++;
      // extra
      prevArrivalTime = current->arrivalTime;
      prevTimeOfServiceEnds = current->timeServiceEnds;
    }
  }
  int max(int a, int b) { return a > b ? a : b; }
  void init() {
    this->startSimulating();
    this->print();
  }

  int generateIAT(int num) {
    if (num >= 0 && num <= 125)
      return 1;
    else if (num >= 126 && num <= 250)
      return 2;
    else if (num >= 251 && num <= 375)
      return 3;
    else if (num >= 376 && num <= 500)
      return 4;
    else if (num >= 501 && num <= 625)
      return 5;
    else if (num >= 626 && num <= 750)
      return 6;
    else if (num >= 751 && num <= 875)
      return 7;
    else if (num >= 876 && num <= 1000)
      return 8;
    return 0;
  }

  int generateServiceTime(int num) {
    if (num >= 0 && num <= 10)
      return 1;
    else if (num >= 11 && num <= 30)
      return 2;
    else if (num >= 31 && num <= 60)
      return 3;
    else if (num >= 61 && num <= 85)
      return 4;
    else if (num >= 86 && num <= 95)
      return 5;
    else if (num >= 96 && num <= 100)
      return 6;
    return 0;
  }
  // extra
  void print() {
    cout << "ID\t"
         << "RD1\t"
         << "IAT\t"
         << "Arrival\t"
         << "RD2\t"
         << "Service\t"
         << "TSB\t"
         << "Waiting\t"
         << "TSE\t"
         << "TSS\t"
         << "ITS\t"

         << endl;
    for (int i = 0; i < this->numeberOfCustomers; i++) {
      cout << customers[i].id << '\t' << customers[i].randomNumber << '\t'
           << customers[i].iAt << '\t' << customers[i].arrivalTime << '\t'
           << customers[i].randomNumberForServiceTime << '\t'
           << customers[i].serviceTime << '\t' << customers[i].timeServiceBegins
           << '\t' << customers[i].waitingTime << '\t'
           << customers[i].timeServiceEnds << '\t'
           << customers[i].timeSpentInSystem << '\t'
           << customers[i].idleTimeForServer

           << endl;
    }

    cout << "Total Inter Arrival Time: " << totalInterArrivalTime << endl;
    cout << "Total Arrival Time: " << totalArrivalTime << endl;
    cout << "Total Service Time: " << totalServiceTime << endl;
    cout << "Total Waiting Time: " << totalWaitingTime << endl;
    cout << "Total Spend Time in System: " << totalSpendTimeInSystem << endl;
    cout << "Total Idle Time: " << totalIdleTime << endl;
    cout << "Total Customer Wait: " << totalCustomerWait << endl;
  }
  // extra
  Solution(int numOfCustomers = 0) {
    if (!numOfCustomers) {
      cout << "Enter Customer Size: ";
      cin >> this->numeberOfCustomers;
      cout << endl;
    } else
      this->numeberOfCustomers = numOfCustomers;
    // init array
    this->customers = new Customer[this->numeberOfCustomers];
  }

  ~Solution() { delete[] this->customers; }
};

int main(int argc, char const *argv[]) {
  Solution *simulator = new Solution();

  simulator->init();

  return 0;
}
