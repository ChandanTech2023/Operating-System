#include <iostream>
using namespace std;

class sjf
{
public:
    int brust, wait, turn, arrival;
};

class sjftable
{
    sjf *arr;
    sjf *newarr;
    int size;
    float aveWait = 0, aveTurn = 0;

public:
    sjftable(int n)
    {
        size = n;
        arr = new sjf[size];
        newarr = new sjf[size];
    }
    ~sjftable()
    {
        delete arr;
        delete newarr;
    }
    void getData()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter brust time of process " << i << " : ";
            cin >> arr[i].brust;
            newarr[i].brust = arr[i].brust;
            newarr[i].wait = 0;
            newarr[i].turn = 0;
        }
    }

    void operation()
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (newarr[j].brust > newarr[j + 1].brust)
                    swap(newarr[j], newarr[j + 1]);

        newarr[0].wait = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i < size)
                    newarr[i + 1].wait += newarr[j].brust;
                newarr[i].turn += newarr[j].brust;
            }
        }

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (arr[i].brust == newarr[j].brust)
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
        aveWait = aveWait / size;
        aveTurn = aveTurn / size;
    }
    void display()
    {
        cout << "Process Brust Time  Wait Time  Trunaround Time\n";
        for (int i = 0; i < size; i++)
            cout << (i + 1) << "\t" << arr[i].brust << "\t\t" << arr[i].wait << "\t" << arr[i].turn << endl;
        cout << "Average Wait Time : " << aveWait << endl;
        cout << "Average Trun Time : " << aveTurn << endl;
    }
};

int main()
{
    int n;
    cout << "Enter Number of Proccess : ";
    cin >> n;
    sjftable s(n);
    s.getData();
    s.operation();
    s.display();
    return 0;
}