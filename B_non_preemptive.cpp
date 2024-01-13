#include <iostream>
using namespace std;
class head
{
public:
    int brust, wait, turn, priority;
};

class preemptive
{
    head *arr;
    head *newarr;
    int size;
    float aveWait = 0, aveTurn = 0;
public:
    preemptive(int size)
    {
        this->size = size;
        arr = new head[size];
        newarr = new head[size];
    }
    ~preemptive()
    {
        delete arr;
        delete newarr;
    }
    void getData()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter brust time of process " << (i + 1) << " : ";
            cin >> arr[i].brust;
            newarr[i].brust = arr[i].brust;
            newarr[i].wait = 0;
            newarr[i].turn = 0;
        }
        for (int i = 0; i < size; i++)
        {
            cout << "Enter priority of process " << (i + 1) << " : ";
            cin >> arr[i].priority;
            newarr[i].priority = arr[i].priority;
        }
    }

    void operation()
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - 1 - i; j++)
                if (newarr[j].priority > newarr[j + 1].priority)
                    swap(newarr[j], newarr[j + 1]);

        for (int i = 0; i < size; i++)
            for (int j = 0; j <= i; j++)
            {
                newarr[i + 1].wait += newarr[j].brust;
                newarr[i].turn += newarr[j].brust;
            }

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if ((arr[i].brust == newarr[j].brust) && (arr[i].priority == newarr[j].priority))
                {
                    arr[i].wait = newarr[j].wait;
                    arr[i].turn = newarr[j].turn;
                    break;
                }
        
        for (int i = 0; i < size; i++)
        {
            aveWait += arr[i].wait;
            aveTurn += arr[i].turn;
        }
        aveWait = aveWait/size;
        aveTurn = aveTurn/size;
        
    }
    void display()
    {
        cout << "Process \tBrust Time \tPriority \tWait Time \tTurnaround Time\n";
        for (int i = 0; i < size; i++)
            cout << (i + 1) << "\t\t" << arr[i].brust << "\t\t" << arr[i].priority << "\t\t" << arr[i].wait << "\t\t" << arr[i].turn << endl;
        cout<<"Average Wait Time : "<<aveWait<<endl;
        cout<<"Average Turnaround Time : "<<aveTurn<<endl;
    }
};
int main()
{
    int n;
    cout << "Enter Number of Process : ";
    cin >> n;
    preemptive p(n);
    p.getData();
    p.operation();
    p.display();
    return 0;
}