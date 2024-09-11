#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int N;
  int red, white, yellow, black, poison, current;
  cin >> N;
  string str;
  for (int i = 0; i<N; i++)
    {
        cin >> red >> white >> yellow >> black >> poison >> current;
        getline(cin , str);
        getline(cin, str);
        int count = 0;
        bool dead = false;
        stringstream line;
        line<<str;
        vector<int>carrots;
        while (true)
        {
            int tmp;
            line>>tmp;
            carrots.push_back(tmp);
            if (line.fail()) break;
        }
        for (int i = 0; i<carrots.size(); i++)
        {
            current -= count * poison;
            if (current <= 0)
            {
                cout << "bye~Rabbit" << endl;
                dead = true;
                break;
            }
            if (carrots[i] == 1)
            {
                current += red;
            }
            else if (carrots[i] == 2)
            {
                current += white;
            }
            else if (carrots[i] == 3)
            {
                current -= yellow;
            }
            else if (carrots[i] == 4)
            {
                current -= black;
                count += 1;
            }
            if (current <= 0)
            {
                cout << "bye~Rabbit" << endl;
                dead = true;
                break;
            }
        }
        if (!dead)
        {
            cout << current << "g" << endl;
        }
    }
}
