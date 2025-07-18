#include <iostream>
using namespace std;

// Function declarations
void initiateIncredibleHulkApp();
string expressFeeling(int layer);

// Main function
int main()
{
    initiateIncredibleHulkApp();
    return 0;
}

// This function returns the Hulk's emotional rant
string expressFeeling(int layer)
{
    string feelingOfLayer1 = "I hate";
    string feelingOfLayer2 = "I love";
    string connector = " that ";
    string resultFeeling = "";

    for (int i = 1; i <= layer; i++)
    {
        // Alternate feelings: odd = hate, even = love
        if (i % 2 == 1)
        {
            resultFeeling += feelingOfLayer1;
        }
        else
        {
            resultFeeling += feelingOfLayer2;
        }

        // Add "that" if not the last layer
        if (i < layer)
        {
            resultFeeling += connector;
        }
    }

    // End with "it"
    resultFeeling += " it";

    return resultFeeling;
}

// Handles user input and prints the Hulk's feelings
void initiateIncredibleHulkApp()
{
    int layer;

    cout << "Enter number of emotional layers (1–100): ";
    cin >> layer;

    // Validate input
    while (layer < 1 || layer > 100)
    {
        cout << "Try again. Enter a number between 1 and 100: ";
        cin >> layer;
    }

    // Output the final emotional state
    cout << expressFeeling(layer) << endl;
}
