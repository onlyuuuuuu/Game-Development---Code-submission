#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getChoice(int choice) 
{
    switch (choice) 
    {
        case 1:
            return "Stone";
        case 2:
            return "Paper";
        case 3:
            return "Scissors";
        default:
            return "Invalid choice";
    }
}

int getResult(int Player_Choice, int Computer_Choice) 
{
    if (Player_Choice == Computer_Choice) 
    {
        return 0; 
    } 
    else if ((Player_Choice == 1 && Computer_Choice == 3) ||
               (Player_Choice == 2 && Computer_Choice == 1) ||
               (Player_Choice == 3 && Computer_Choice == 2) ||
               (Player_Choice == 3 && Computer_Choice == 1)) 
    {
        return 1; 
    } 
    else 
    {
        return -1; 
    }
}

int main() 
{
    int Player_Score = 0;
    int Computer_Score = 0;

    cout << "Welcome to Stone, Paper, Scissors Game!" << endl;

    for (int round = 1; round <= 5; round++) 
    {
        cout << "\nRound " << round << ":" << endl;
        cout << "Enter your choice (1 for Stone, 2 for Paper, 3 for Scissors): ";
        int Player_Choice;
        cin >> Player_Choice;
        int Computer_Choice = rand() % 3 + 1;
        string PlayerChoiceString = getChoice(Player_Choice);
        string ComputerChoiceString = getChoice(Computer_Choice);
        cout << "Player choice: " << PlayerChoiceString << endl;
        cout << "Computer choice: " << ComputerChoiceString << endl;
        int result = getResult(Player_Choice, Computer_Choice);
        if (result == 1) 
        {
            cout << "You win this round!" << endl;
            Player_Score++;
        } 
        else if (result == -1) 
        {
            cout << "Computer wins this round!" << endl;
            Computer_Score++;
        } 
        else 
        {
            cout << "It's a tie!" << endl;
        }
    }

    cout << "\nGame Over!" << endl;
    cout << "Player score: " << Player_Score << endl;
    cout << "Computer score: " << Computer_Score << endl;

    if (Player_Score > Computer_Score) 
    {
        cout << "Congratulations! You win the game!" << endl;
    } 
    else if (Player_Score < Computer_Score) 
    {
        cout << "Sorry! Computer wins the game!" << endl;
    }
    return 0;
}
