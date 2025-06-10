#include "PatienceSort.h"

vector<int> PatienceSort::patienceSort(vector<int>& array)
{
    vector<stack<int>> piles;

    for (int card : array) {
        auto it = lower_bound(piles.begin(), piles.end(), card, [](const stack<int>& s, int value) {
            return s.top() < value;
            });

        if (it == piles.end()) {
            stack<int> newPile;
            newPile.push(card);
            piles.push_back(newPile);
        }
        else {
            it->push(card);
        }
    }

    vector<int> sortedArray;
    while (!piles.empty()) {
        int minIndex = 0;
        for (int i = 1; i < piles.size(); ++i) {
            if (piles[i].top() < piles[minIndex].top()) {
                minIndex = i;
            }
        }
        sortedArray.push_back(piles[minIndex].top());
        piles[minIndex].pop();

        if (piles[minIndex].empty()) {
            piles.erase(piles.begin() + minIndex);
        }
    }

    return sortedArray;
}
