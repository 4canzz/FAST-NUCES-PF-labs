#include <iostream>
#include <string>
using namespace std;

struct candidate {
    string name;
    int votes;
    float percentage;
};

int main (){
    int numOfCandidates, totalVotes = 0, largest = 0;
    string winner;
    cout << "Enter the number of candidates: ";
    cin >> numOfCandidates;
    cin.ignore();
    candidate* candidates = new candidate[numOfCandidates];

    for (int i = 0; i < numOfCandidates; i++) {
        cout << "Enter Candidate " << i + 1 << "'s Name: ";
        getline(cin, candidates[i].name);
        cout << "Enter votes: ";
        cin >> candidates[i].votes;
        totalVotes += candidates[i].votes;
        cin.ignore();
    }

    for (int i = 0; i < numOfCandidates; i++) {
        candidates[i].percentage = ((float) candidates[i].votes / (float) totalVotes) * 100;
    }

    for (int i = 0; i < numOfCandidates; i++) {
        if (candidates[i].votes > largest) {
            largest = candidates[i].votes;
            winner = candidates[i].name;
        }
    }

    cout << "Candidate\tVotes Recieved\t%of Total Votes" << endl;
    for (int i = 0; i < numOfCandidates; i++) {
        cout << candidates[i].name << "\t\t" << candidates[i].votes << "\t\t" << candidates[i].percentage << endl;
    }
    cout << "Total\t\t" << totalVotes << endl;
    cout << "The Winner of the Election is " << winner << endl;

    delete[] candidates;
    return 0;
}

/*Question No. 4 (CLO No. 1) Marks: 6
Write a function PickLarger( ) which compares the corresponding elements of 1 D dynamic array, picks the
larger element among them and saves the larger element in the output array which is double the size of
original arrays. The remaining elements of the output array will be any prime numbers. Write another function which resize the original array to the output array. Sample Input and Output:
Input:
Array 1: 1 2 1 5 9 1 3 5
Array 2: 8 2 1 0 11 10 3 4
Output:
Output Array: 8 2 1 5 11 10 3 5 2 3 5 7 11 13 17 19*/