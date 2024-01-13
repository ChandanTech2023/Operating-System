#include <iostream>
using namespace std;

class ram
{
public:
    int memory, process;
};

class memory_alloca
{
    int *memory_space, *processes, *index;
    int memory_size, process_size;
    ram *head;
    bool check = false;
    int option;

public:
    void getData()
    {
        cout << "Enter Number of Memory Space : ";
        cin >> memory_size;
        memory_space = new int[memory_size];
        index = new int[memory_size];
        for (int i = 0; i < memory_size; i++)
        {
            cout << "Enter size of Memory Space " << (i + 1) << " : ";
            cin >> memory_space[i];
            index[i] = i + 1;
        }
        cout << "Enter number of processes : ";
        cin >> process_size;
        processes = new int[process_size];
        for (int i = 0; i < process_size; i++)
        {
            cout << "Enter size of Process " << (i + 1) << " : ";
            cin >> processes[i];
        }
        head = new ram[process_size];
    }
    void operation()
    {
        int id;
        cout << "Select any one : \n1.first-fit \n2.best-fit \n3.worst-fit\n";
        cin >> option;
        if (option == 1)
        {
            for (int i = 0; i < process_size; i++)
            {
                for (int j = 0; j < memory_size; j++)
                {
                    if (processes[i] < memory_space[j])
                    {
                        head[i].memory = j + 1;
                        head[i].process = processes[i];
                        memory_space[j] -= processes[i];
                        check = false;
                        break;
                    }
                    else
                        check = true;
                }
                if (check)
                {
                    head[i].process = processes[i];
                    head[i].memory = -1;
                }
            }
        }

        else if (option == 2)
        {
            for (int i = 0; i < memory_size; i++)
                for (int j = 0; j < memory_size - 1 - i; j++)
                    if (memory_space[j] > memory_space[j + 1])
                    {
                        swap(memory_space[j], memory_space[j + 1]);
                        swap(index[j], index[j + 1]);
                    }

            for (int i = 0; i < process_size; i++)
            {
                for (int j = 0; j < memory_size; j++)
                    if (processes[i] <= memory_space[j])
                    {
                        head[i].memory = index[j];
                        head[i].process = processes[i];
                        memory_space[j] -= processes[i];
                        check = false;
                        break;
                    }
                if (check)
                {
                    head[i].process = processes[i];
                    head[i].memory = -1;
                }
            }
        }
        else if (option == 3)
        {
            for (int i = 0; i < process_size; i++)
            {
                id = 0;
                for (int j = 1; j < memory_size; j++)
                    if (memory_space[id] < memory_space[j])
                        id = j;
                if (processes[i] < memory_space[id])
                {
                    head[i].memory = id + 1;
                    head[i].process = processes[i];
                    memory_space[id] -= processes[i];
                    check = false;
                }
                else
                    check = true;
                if (check)
                {
                    head[i].process = processes[i];
                    head[i].memory = -1;
                }
            }
        }
    }
    void display()
    {
        for (int i = 0; i < process_size; i++)
        {
            if (head[i].memory == -1)
                cout << "Process " << (i + 1) << " whose size " << head[i].process << "KB is can't allocating in memory partiation" << endl;
            else
                cout << "Process " << (i + 1) << " whose size " << head[i].process << "KB is allocating in memory partiation\t\t" << head[i].memory << endl;
        }
    }
};

int main()
{
    memory_alloca ma;
    ma.getData();
    ma.operation();
    ma.display();
    return 0;
}