#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef int Info;

struct Elem {
    Info info;
    Elem* next;
};

void insert(Elem*& L, Info value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = L;
    L = tmp;
}

Info remove(Elem*& L) {
    Info value = L->info;
    Elem* tmp = L->next;
    delete L;
    L = tmp;
    return value;
}

void print(Elem* L) {
    while (L != NULL) {
        cout << setw(4) << L->info;
        L = L->next;
    }
    cout << endl;
}

bool isPartOf(Elem* L1, Elem* L2) {
    while (L2 != NULL) {
        if (L1 == NULL) {
            return true;
        }
        if (L1->info == L2->info) {
            L1 = L1->next;
        }
        L2 = L2->next;
    }
    return L1 == NULL;
}

int main() {
    srand((unsigned)time(nullptr));
    Elem* L1 = NULL;
    Elem* L2 = NULL;
    for (int i = 0; i < 2; i++) {
        int random = (rand() % 13) - 6;
        insert(L1, random);
    }
    for (int i = 0; i < 10; i++) {
        int random = (rand() % 13) - 6;
        insert(L2, random);
    }
    cout << "L1: ";
    print(L1);
    cout << "L2: ";
    print(L2);
    bool result = isPartOf(L1, L2);
    if (result == 1) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    while (L1 != NULL) {
        remove(L1);
    }
    while (L2 != NULL) {
        remove(L2);
    }
    return 0;
}
