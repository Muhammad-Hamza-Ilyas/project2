#include <iostream>
#include <ctime>   // time()
#include <cstdlib> // srand(), rand()
#include <string>  // string
#include <cctype>  // tolower()

using namespace std;

int Randomize();
void displayhangman(int lives);

int main()
{
    cout << "********************************************\n";
    cout << "*                                          *\n";
    cout << "*          Welcome to Hangman Game!        *\n";
    cout << "*                                          *\n";
    cout << "********************************************\n\n";

    cout << "Hangman is a classic word-guessing game. The computer will randomly\n";
    cout << "select a word, and your task is to guess the letters in that word.\n";
    cout << "You have a limited number of lives, so be careful with your guesses!\n";

    cout << "\nRules:\n";
    cout << "- You start with some lives which are displayed.\n";
    cout << "- The computer will choose a random word.\n";
    cout << "- Guess one letter at a time.\n";
    cout << "- If you enter a word or a sentence the first letter will be considered as the guess\n";
    cout << "- Correct guesses reveal the letters in the word.\n";
    cout << "- Incorrect guesses cost a life.\n";
    cout << "- Try to guess the entire word before running out of lives!\n\n";

    cout << "Let's see if you can guess the word and avoid the hangman!\n\n";

    char start_end;
    while (true)
    {
        cout << "Press E To Continue.....\n";
        cout << "        OR              \n";
        cout << "Press Q To QUIT.........\n\n";

        cin >> start_end;
        cout << "\n";

        if (start_end == 'E' || start_end == 'e' ||
            start_end == 'Q' || start_end == 'q')
            break;
    }

    if (start_end == 'Q' || start_end == 'q')
    {
        cout << "QUITTING......\n";
        return 0;
    }

    char play_again;

    do
    {
        string word_library[23] = {
            "red", "blue", "green", "orange", "white",
            "tiger", "cat", "monkey", "lion", "dog", "wolf", "rhino",
            "happiness", "sadness", "fear", "disgust", "anger",
            "orange", "apple", "banana",
            "toyota", "suzuki", "ford"};

        int random_index = Randomize();
        int length = word_library[random_index].length();

        int numcorrect = 0, oldcorrect;
        char guessarray[100];
        char guessletter;
        char guess[11] = {0};
        int repitition = 0;
        int blanks = 0;

        int lives = length / 2 + 1;

        cout << "Your Total Lives are \"" << lives << "\"\n";

        if (random_index <= 4)
            cout << "Hint ...... Its A Color\n";
        else if (random_index <= 11)
            cout << "Hint ...... One of the Animals\n";
        else if (random_index <= 16)
            cout << "Hint ...... Emotions\n";
        else if (random_index <= 19)
            cout << "Hint ...... Fruit\n";
        else
            cout << "Hint ...... Car Company\n";

        cout << "\n";
        displayhangman(lives);
        cout << "\n";

        while (numcorrect < length)
        {
            do
            {
                oldcorrect = numcorrect;
                cout << "* ";

                for (int i = 0; i < length; i++)
                {
                    if (guess[i] == 0)
                    {
                        cout << "_ ";
                        blanks++;
                    }
                    else
                        cout << word_library[random_index][i];
                }

                cout << "   " << blanks << " blanks left";
                blanks = 0;

                cout << "\n\nGuess Letter = ";
                cin >> guessarray;

                guessletter = tolower(guessarray[0]);

                if (guessletter < 'a' || guessletter > 'z')
                {
                    cout << "\nPlz Enter an Alphabet\n\n";
                    displayhangman(lives);
                    cout << "Current Lives " << lives << "\n\n";
                }

            } while (guessletter < 'a' || guessletter > 'z');

            repitition = 0;

            for (int i = 0; i < length; i++)
            {
                if (guess[i] == 1)
                    continue;

                if (word_library[random_index][i] == guessletter)
                {
                    guess[i] = 1;
                    numcorrect++;

                    if (repitition == 0)
                    {
                        cout << "\nCongrats Correct Guess\n\n";
                        displayhangman(lives);
                        repitition = 1;
                    }
                }
            }

            if (oldcorrect == numcorrect)
            {
                cout << "\nOops Wrong Guess\n\n";
                lives--;
                displayhangman(lives);
            }

            cout << "Current Lives " << lives << "\n\n";

            if (lives == 0)
                break;
        }

        if (lives == 0)
            cout << "\nSorry you ran out of lives\n";
        else
            cout << "Wow!!! You Won the Game\n";

        cout << "\n//////Want to play Again?//////\n";
        cout << "Press Y for Yes or any other character for No\n";
        cin >> play_again;
        cout << "\n";

    } while (play_again == 'Y' || play_again == 'y');

    return 0;
}

int Randomize()
{
    srand(time(NULL));
    return rand() % 23;
}

void displayhangman(int lives)
{
    switch (lives)
    {
    case 7:
        cout << "  +---+\n      |\n      |\n      |\n      |\n      |\n";
        break;
    case 6:
        cout << "  +---+\n  |   |\n      |\n      |\n      |\n      |\n";
        break;
    case 5:
        cout << "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n";
        break;
    case 4:
        cout << "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n";
        break;
    case 3:
        cout << "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n";
        break;
    case 2:
        cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n";
        break;
    case 1:
        cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n";
        break;
    case 0:
        cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n";
        break;
    default:
        break;
    }
}
