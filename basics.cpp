#include <iostream>
using namespace std;

class GameEntry
{
    int score;
    string name;

public:
    GameEntry(const string &name = "", int score = 0)  //constructor
    {
        this->name= name;
        this->score = score;
    }
    int getScore()
    {
        return score;
    }
    string getName()
    {
        return name;
    }
};

class Score
{
    GameEntry *entries;
    int numEntries, maxEntries;

public:
    Score(int max = 10)
    {
        maxEntries = max;
        numEntries = 0;
        entries = new GameEntry[maxEntries];
    }
    void add(GameEntry &e)
    {
        int newScore = e.getScore();
        if (numEntries == 0)
        {
            entries[numEntries] = e;
            numEntries++;
        }
        else if (numEntries == maxEntries)
        {
            if (newScore < entries[maxEntries - 1].getScore())
                return;
        }
        else{
            numEntries++;
            int i = numEntries - 2;
            while(i>=0 && newScore > entries[i].getScore()){
                entries[i + 1] = entries[i];
                i--;
            }
            entries[++i] = e;
        }
    }
    void display(){
        cout << "Name : Score \n";
        for (int i = 0; i < numEntries;i++){
            cout << entries[i].getName() << " " << entries[i].getScore() << endl;
        }
    }
};

int main(){

    Score obj;
    GameEntry *g;
    int n, score;
    string name;
    cout << "Enter number of data entries : ";
    cin >> n;
    g = new GameEntry[n];
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << ".Name ";
        cin >> name;
        cout << (i + 1) << ".Score : ";
        cin >> score;
        g[i] = GameEntry(name, score);
        obj.add(g[i]);
    }
    obj.display();
    return 0;
}
