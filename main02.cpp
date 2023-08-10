#include <string>
#include <iostream>
using namespace std;

struct ListElement
{
    int id;
    ListElement* p_next;
};

ListElement* p_root = nullptr;

// Fügt ein neues Element am Anfang der Liste hinzu.
void add_new_head_element(int id)
{
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    p_root = p_new_element;
}

// Fügt ein neues Element am Ende der Liste hinzu.
void add_new_tail_element(int id)
{
    // Neues Listen-Element erzeugen.
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = nullptr;

    if (p_root == nullptr)
    {
        // Liste ist leer. Das neue Element wird das erste Element.
        p_root = p_new_element;
    }
    else
    {
        // Ans Ende der Liste navigieren.
        ListElement* p_last_element = p_root;
        while (p_last_element->p_next != nullptr) {
            p_last_element = p_last_element->p_next;
        }

        // Neues Element an das Ende der Liste anhängen.
        p_last_element->p_next = p_new_element;
    }
}

// Löscht das Element mit der angegebenen ID aus der Liste.
void delete_element(int id)
{
    ListElement *p_tmp = p_root;
    ListElement *p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id)
    {
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            p_root = p_tmp->p_next;
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next;
        }
        delete p_tmp;
    }
}

// Gibt alle Elemente der Liste aus.
void print_list()
{
    ListElement* p_tmp = p_root;
    while (p_tmp != nullptr) {
        cout << p_tmp->id << endl;
        p_tmp = p_tmp->p_next;
    }
}

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
}
