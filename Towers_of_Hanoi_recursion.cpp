#include <iostream>
using namespace std;

void towersOfHanoi(int start, int end, char source, char helper, char destination)
{

    // base case
    if (start > end)
    {
        return;
    }
    // first move n-1 discs from source to helper
    towersOfHanoi(start, end - 1, source, destination, helper);

    // then move last largest node in source to destination
    cout << "Move disc " << end << " from " << source << " to " << destination << endl;

    // move n-1 discs in helper to destination
    towersOfHanoi(start, end - 1, helper, source, destination);
}

int main()
{
    int end;
    cout << "Enter total no of disks: " << endl;
    cin >> end;

    towersOfHanoi(1, end, 'A', 'B', 'C');
    return 0;
}