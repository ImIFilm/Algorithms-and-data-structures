### Rok 2013 Zad 1
Prosze zaimplementować funkcję sortująca (rosnąco) listę jednokierunkową metodą QUICKERSORT. Algorytm QUICKERSORT to odmiana algorytmu QUICKSORT, w której funkcja podziału dzieli sortowane dane według przyjętej wartości x na trzy grupy: mniejsze od x, równe x, oraz większe od x. Następnie rekurencyjnie sortowane są grupy pierwsza i trzecia.

struct Node {Node *next;int val;};
Node* QuickerSort(Node *head)

Argumentem funkcji jest wskaźnik na głowę listy do posortowania a wynikiem powinien być wskaźnik na głowę listy posrtowanej. Sortowanie powinno polegać na porównaniu wartości val list oraz przepinaniu wskaźników next.
