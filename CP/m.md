## IMP on recursion linked list 

---

 ```
   if(head==NULL|| head->next==NULL) return head; 
         node* p = fun(head->next);
         head->next->next=head;
         head->next=null;
         return p;
   ```
consider 1->2->3->4->5
         5->4->null;
         5->4->3->null;

## Valid Parenthisis
- look for a mirror pass,If first pass is valid then second pass also must be valid;

