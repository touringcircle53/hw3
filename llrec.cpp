#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == nullptr) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* temp = head;
  head = head->next;
  temp->next = nullptr;

  if (temp->val <= pivot) {
    Node* tailSmall = nullptr;
    llpivot(head, tailSmall, larger, pivot);
    temp->next = tailSmall;
    smaller = temp;
  }
  else {
    Node* tailLarge = nullptr;
    llpivot(head, smaller, tailLarge, pivot);
    temp->next = tailLarge;
    larger = temp;
  }
}

