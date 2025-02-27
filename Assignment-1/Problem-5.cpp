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

/*Question No. 5 (CLO No. 1) Marks: 6

Write a program that allows the user to enter the last names of five candidates in a local election and the
number of votes received by each candidate. The program should then output each candidate’s name, the
number of votes received, and the percentage of the total votes received by the candidate. Your program
should also output the winner of the election. A sample output is:
Candidate   Votes Received      % of Total Votes
Johnson         5000              25.91
Miller          4000              20.73
Duffy           6000              31.09
Robinson        2500              12.95
Ashtony         1800              9.33
Total           19300

The Winner of the Election is Duffy. */