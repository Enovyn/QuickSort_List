#include <iostream>
#include "LIST.H"

liste* getTail(liste* cur)
{
    while (cur->getNext() != NULL)
        cur = cur->getNext();
    return cur;
}

liste* partition(liste* head, liste* end, liste** newHead, liste** newEnd)
{
    liste* pivot = end;
    liste* prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->getValue() < pivot->getValue())
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->getNext();
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->setNext(cur->getNext());
            liste* tmp = cur->getNext();
            cur->setNext(NULL);
            tail->setNext(cur);
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}


//here the sorting happens exclusive of the end node
liste* QuickSortRecur(liste* head, liste* end)
{
    // base condition
    if (!head || head == end)
        return head;

    liste* newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    liste* pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        liste* tmp = newHead;
        while (tmp->getNext() != pivot)
            tmp = tmp->getNext();
        tmp->setNext(NULL);

        // Recur for the list before pivot
        newHead = QuickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->setNext(pivot);
    }

    // Recur for the list after the pivot element
    pivot->setNext(QuickSortRecur(pivot->getNext(), newEnd));

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void QuickSort(liste **headRef)
{
    (*headRef) = QuickSortRecur(*headRef, getTail(*headRef));
    return;
}

int main(){
    liste* start = NULL;;
    liste f(10);
    liste e(4, &f);
    liste d(3, &e);
    liste c(19, &d);
    liste b(7, &c);
    liste a(9, &b);
    start = &a;
    start->printValue();

    QuickSort(&start);
    printf("\n");
    start->printValue();

return 0;
}
