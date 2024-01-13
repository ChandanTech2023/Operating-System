#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int numP, n;
    int *pro, *wait, *t, *arr;
    double aWait = 0, aTurn = 0;
    bool premission = false;

    // Number of Process
    cout << "Enter Number of Process : ";
    cin >> numP;

    pro = new int[numP];
    wait = new int[numP];
    t = new int[numP];

    // Enters burst time
    for (int i = 0; i < numP; i++)
    {
        cout << "Enter Burst Time of Process " << (i + 1) << " : ";
        cin >> pro[i];
        wait[i] = 0;
        t[i] = 0;
    }

    // arrivable is or not
    cout << "Arrivable is or not : 1/0 : ";
    cin >> n;
    if (n == 1)
    {
        arr = new int[numP];
        for (int i = 0; i < numP; i++)
        {
            cout << "Enter Arrivable Time of Process " << (i + 1) << " : ";
            cin >> arr[i];
        }
        premission = true;
    }
    else
    {
        cout << "okay, error\n";
    }

    if (premission)
        cout << "Arrivable Time \tProcess \tBurst Time \tWait Time \tTurnaround Time\n";
    else
        cout << "Process \tBurst Time \tWait Time \tTurnaround Time\n";

    // main operation ,calculate  wait and turnaround time
    for (int i = 0; i < numP; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i < numP)
                wait[i + 1] += pro[j];
            t[i] += pro[j];
        }
        if (premission)
        {
            if (wait[i] > 0)
                wait[i] = wait[i] - arr[i];
            t[i] = t[i] - arr[i];
            cout << arr[i] << "\t\t"
                 << "P" << (i + 1) << "\t\t" << pro[i] << "\t\t" << wait[i] << "\t\t" << t[i] << endl;
        }
        else
            cout << "P" << (i + 1) << "\t\t" << pro[i] << "\t\t" << wait[i] << "\t\t" << t[i] << endl;
        aWait += wait[i];
        aTurn += t[i];
    }

    // calculate average wait and turnaround time
    aWait = aWait / numP;
    aTurn = aTurn / numP;
    cout << "Average Wait Time : " << aWait << endl;
    cout << "Average Turnaround Time : " << aTurn << endl;

    return 0;
}