#include <iostream>
using namespace std;
int main() {
  int at[50];
  int bt[50];
  int ct[50];
  int ta[50];
  int wt[50];
  int temp[50];
  int n;
  int av_ct = 0, av_ta = 0, av_wt = 0;
  //   cout << "Enter the number of process : ";
  //   cin >> n;
  //   cout << "-----Enter Arrival & Burst Time----\n";
  //   for (int i = 0; i < n; i++) {
  //     cout << "Arrival Time for no " << i + 1 << " process : ";
  //     cin >> at[i]; // rd[i]=0 + (rand() % 1000);
  //     cout << "Burst Time for no " << i + 1 << " process : ";
  //     cin >> bt[i];
  //   }

  n = 3;
  at[0] = 0, bt[0] = 18, at[1] = 1, bt[1] = 3, at[2] = 2, bt[2] = 3;

  // bubble sort
  for (int step = 0; step < n - 1; step++) {
    for (int i = 0; i < n - step - 1; i++) {
      if (at[i] > at[i + 1]) {
        swap(at[i], at[i + 1]);
        swap(bt[i], bt[i + 1]);
      }
    }
  }

  cout << " Process  Arrival Time  Burst Time   Completion Time   Turn Around "
          "Time   Waiting Time\n";
  for (int j = 0; j < n; j++) {
    int k = j + 1;
    // Completion Time
    ct[j] = bt[j] + ct[j - 1];
    if (j == 0) ct[0] = bt[0];
    // Turn Around Time
    ta[j] = ct[j] - at[j];
    // Waiting Time
    wt[j] = ta[j] - bt[j];
    cout << "\t" << k << "\t" << at[j] << "\t\t" << bt[j] << "\t" << ct[j]
         << "\t\t" << ta[j] << "\t\t\t" << wt[j] << "\n";
  }

  for (int l = 0; l < n; l++) {
    av_ct = av_ct + ct[l];
    av_ta = av_ta + ta[l];
    av_wt = av_wt + wt[l];
  }
  cout << "\nAvarage Completion Time :" << (av_ct / n) << "\n";
  cout << "Avarage Turn Around Time :" << (av_ta / n) << "\n";
  cout << "Avarage Waiting Time :" << (av_wt / n) << "\n";
  return 0;
}