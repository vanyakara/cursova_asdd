#include <iostream>
#include <stack>
#include <list>

using namespace std;

// Функция за създаване на списък с елементите, които са само в стека p
list<int> elementsOnlyInP(stack<int> p, stack<int> q) {
    list<int> result;

    // Прехвърляме елементите на стека p във временен стек tempP
    stack<int> tempP;
    while (!p.empty()) {
        tempP.push(p.top());
        p.pop();
    }

    // Прехвърляме обратно елементите от временния стек tempP в стека p
    // и добавяме само тези, които не са в стека q
    while (!tempP.empty()) {
        int current = tempP.top();
        tempP.pop();

        if (q.empty() || q.top() < current) {
            // Проверка дали текущият елемент не присъства в стека q
            // и дали q е празен или текущият елемент е по-голям от най-горния в q
            result.push_front(current); // Добавяме в началото на списъка
        }

        p.push(current); // Връщаме обратно текущият елемент в стека p
    }

    return result;
}

int main() {
    // Създаваме два стека p и q с произволни цели числа
    stack<int> p, q;

    // Добавяме произволни числа към стека p
    p.push(5);
    p.push(3);
    p.push(8);
    p.push(2);

    // Добавяме произволни числа към стека q
    q.push(3);
    q.push(7);
    q.push(2);

    // Създаваме списък с елементите, които са само в стека p, но не и в q
    list<int> result = elementsOnlyInP(p, q);

    // Извеждаме елементите на списъка
    cout << "Elements only in stack p, but not in stack q (in ascending order):" << endl;
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
