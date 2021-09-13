/*
gfgIntersection Point in Y Shapped Linked Lists 
Medium Accuracy: 49.55% Submissions: 100k+ Points: 4
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
  */

int intersectPoint(Node *head1, Node *head2)
{
    int len1 = findLength(head1);
    int len2 = findLength(head2);
    int maxLength = max(len1, len2);
    if (maxLength == len1)
    {
        int diff = len1 - len2;
        for (int i = 0; i < diff; i++)
        {
            head1 = head1->next;
        }
    }
    else
    {
        int diff = len2 - len1;
        for (int i = 0; i < diff; i++)
        {
            head2 = head2->next;
        }
    }

    while (head1->next && head2->next)
    {
        if (head1->next == head2->next)
        {
            return head1->next->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
    // Your Code Here
}