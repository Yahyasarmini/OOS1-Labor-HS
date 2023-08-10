#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{

    // HIER programmieren:
    string name;
    cout << "Name des Spielers: ";
    cin.clear();
    getline(cin, name);
    return name;
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"

}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Wie funktioniert die funktion rand?
        // rand generieret eine Zufallzahl 0 und einschließlich 2(unser Bereich für die Aufgabe)
        // Was bewirkt die funktion srand?
        // die Festlegung von startwert die von rand() generiert wird.
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // um sicher zu stellen dass bei jeder programmausführung ein anderer start wert verwendet wird
        // Warum wird hier modulo 3 verwendet?
        // es gibt drei möglichkeiten(Schere,Stein,papier) und der Rest durch die Division von 3 ergibt 0,1 oder 2

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{

    // HIER programmieren:
    if (object==Object::PAPER) {
        return "Papier";
    }
    if (object==Object::ROCK) {
        return "Stein";
    }
    else {
        return "Schere";
    }
    // Abhängig vom vorliegenden Object einen entsprechenden String zurückgeben.
    // z.B: Wenn Object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{

    // HIER programmieren:
    if (player.choice == Object::ROCK) {
        cout <<  player.name<< " hat das Objekt Stein gewählt\n";
    }
    else if (player.choice == Object::PAPER){
        cout << player.name << " hat das Objekt Papier gewählt\n";
    }
    else{
        cout << player.name << " hat das Objekt Schere gewählt\n";
    }
    // Auf der Konsole ausgeben, für welches Object sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Object Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name

}

// Die Wahl des Spielers abfragen
Object chose()
{

    // HIER programmieren:Object chose()
    {
        int choice;

        std::cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        std::cin >> choice;

        while (choice < 1 || choice > 3)
        {
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl zwischen 1 und 3 ein." << std::endl;
            std::cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
            std::cin >> choice;
        }

        return static_cast<Object>(choice - 1);
    }

}

Result determine_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    int comparison = static_cast<int>(player_1.choice) - static_cast<int>(player_2.choice);
       if (comparison == 0)
       {
           return Result::DRAW;
       }
       else if (comparison == -2 || comparison == 1)
       {
           return Result::PLAYER_TWO_WINS;
       }
       else
       {
           return Result::PLAYER_ONE_WINS;
       }
    
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"

}

void print_result(Player player_1, Player player_2)
{

    // HIER programmieren:
        Result result = determine_result(player_1, player_2);
    switch (result)
        {
        case Result::DRAW:
            cout << "Unentschieden" << endl;
            break;
        case Result::PLAYER_ONE_WINS:
            cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
            break;
        case Result::PLAYER_TWO_WINS:
            cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
            break;
        }
//        if (result == Result::PLAYER_ONE_WINS) {
//            std::cout << "\nSpieler " << player_1.name << " hat gewonnen." << std::endl;
//        } else if (result == Result::PLAYER_TWO_WINS) {
//            std::cout << "\nSpieler " << player_2.name << " hat gewonnen." << std::endl;
//        } else {
//            std::cout << "Unentschieden.\n" << std::endl;
//        }
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"

}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = chose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}


//    if (i==1) {
//        return Object::ROCK;
//    }
//    if (i==2) {
//        return Object::SCISSORS;
//    }
//    else {
//        return Object::PAPER;
//    }
    
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"
//if(player_2.choice == Object::ROCK && player_1.choice == Object::SCISSORS)
//{
//    return static_cast<Result>(0);
//}
//else if(player_2.choice == Object::ROCK && player_1.choice == Object::ROCK)
//{
//    return static_cast<Result>(2);
//}
//else if(player_2.choice == Object::ROCK && player_1.choice == Object::PAPER)
//{
//    return static_cast<Result>(1);
//}
//else if (player_1.choice == player_2.choice)
//{
//    return static_cast<Result>(2);
//}
//else return static_cast<Result>(0);
