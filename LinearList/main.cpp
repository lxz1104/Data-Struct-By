#include "SeqList.h"
#include "LinkedList.h"

int main() {
//    SeqList<int> L(10);
//
//    int data[] = {21,23,14,5,56,17,31};
//    for (int i = -1; i < 6; ++i) {
//        L.Insert(i,data[i + 1]);
//    }
//    L.Output(std::cout);
//    std::cout << "size: " << L.Length() << '\n' << std::endl;
//    L.Insert(L.Search(14),68);
//    L.Delete(5);
//    L.Output(std::cout);

    SingleList<int> SL;
    int data[] = {1,2,4,5};
    for (int i = -1; i < 3; ++i) {
        SL.Insert(i,data[i + 1]);
    }
    SL.Output(std::cout);

    SL.Insert(SL.Search(2),3);
    SL.Delete(4);

    SL.Output(std::cout);
    return 0;
}