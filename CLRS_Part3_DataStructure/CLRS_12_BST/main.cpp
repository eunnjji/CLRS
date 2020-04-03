// Tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree T;
    T.setRoot(new Node(15)); // new로 할당해서 넣어줘야 함
    T.add_repeat(new Node(6)); 
    T.add_repeat(new Node(18));
    T.add_repeat(new Node(3));
    T.add_repeat(new Node(7));
    T.add_repeat(new Node(17));
    T.add_repeat(new Node(20));
    T.add_repeat(new Node(2));
    T.add_repeat(new Node(4));
    T.add_repeat(new Node(13));
    T.add_repeat(new Node(9));
    /*T.add_recur(new Node(6));
    T.add_recur(new Node(18));
    T.add_recur(new Node(3));
    T.add_recur(new Node(7));
    T.add_recur(new Node(17));
    T.add_recur(new Node(20));
    T.add_recur(new Node(2));
    T.add_recur(new Node(4));
    T.add_recur(new Node(13));
    T.add_recur(new Node(9)); */ 
    
    printf("root: [%d]\n", T.root->getData());
    T.inorder_recur(T.root); 
    cout << "\n";
    T.preorder_recur(T.root); 
    cout << "\n";
    T.postorder_recur(T.root); 
    cout << "\n";

    cout<< T.maximum(T.root)->getData() <<"\n"; 
    cout << T.max_recur(T.root)->getData() << "\n"; 
    cout << T.minimum(T.root)->getData() << "\n"; 
    cout << T.min_recur(T.root)->getData() << "\n"; 

    printf("successor : [%d]\n",T.successor(15)->getData());
    printf("predecessor : [%d]\n", T.predecessor(15)->getData());
   
    cout << "\ntest remove 7\n";
    T.remove(7); 
    T.preorder_recur(T.root);
    cout << "\ntest remove 15\n";
    T.remove(15);
    T.preorder_recur(T.root);
    cout << "\ntest remove 13\n";
    T.remove(13);
    T.preorder_recur(T.root);

    cout << "\ntest search_repeat\n";
    printf("search 3: [%d]\n", T.search_repeat(T.root, 3)->getData());
    printf("search 5: [%d]\n", T.search_repeat(T.root, 5)->getData());

    //printf(" : [%d]\n", );

}
