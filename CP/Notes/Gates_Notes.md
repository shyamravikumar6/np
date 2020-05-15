# B trees And  B+  trees

### disk structure 
*  The storage disk is divided in tracks ,and tracks is divided in sections and intersections of tracks is blocks.  
* All blocks size is approximately 512B 
*  if record is of 100 each record size is 4 bytes 
then 100 records will take 25 blocks 
so in order to access  atmost 25 blocks we makes indexing with such a way each index points each block  address.

### B trees
*  this is a kind of tree where each nodes consists of at least ceil[n/2] elements , so it will reduce the size of tree.

* Root can have two children that means it have singleton key. but rest must have the half of the children.

* All leaf nodes at same level.

* the insertion approach is bottom up.


### B+ Trees
* This  is almost similar to B Trees.
* With modification like all leaf note contains copy of non-leaf node and all leaf node is linked all the way.

---
~~I am the highest in the room.~~
---
 ```
 print(ln);
```
[travis scott](https://www.google.com/travis-scott)

  
### IMp questions on Indexing
--- 
``
  Consider a file of 16384 records. Each record is 32 bytes long and its key field is of size 6 bytes. The file is ordered on a non-key field, and the file organization is unspanned. The file is stored in a file system with block size 1024 bytes, and the size of a block pointer is 10 bytes. If the secondary index is built on the key field of the file, and a multi-level index scheme is used to store the secondary index, the number of first-level and second-level blocks in the multi-level index are respectively?
  ``

  >> Given Record pointer      size= 10;
    record key size **6**  total size is (key+Block_size= 16;

>> total occupied at First level is 16384*16/1024 =256; 
similarlly for second index 256*16/1024 = 4;  

### NOtes on DBMS

- A tuple relational calculus expression may at times generate an infinite relation. It may also contain values that do not even appear in the database. Such expressions are said to be unsafe.

- A safe tuple relational calculus expression is the one which surely generates finite results.
To pose a restriction over the unsafety of expressions in tuple relational calculus there is a concept of domain of a tuple relational formula denoted by dom (P) is the set of values referenced by P i.e.