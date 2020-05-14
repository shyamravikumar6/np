## Natural joins 
 - It is  just equal joins .
 - just keep in mind that the question framing.

 ## DBMS  
 ### Durabilty
 - Recovery management takes cares of durabilty.

 ## Transcation states 

- all first transction is done in local buffers.

### Dirty reads 
- Problems:
    
  | T1 | T2 |
  |----|----|

## conflicts serializable
- serial transcation is always safe.
- converting non serial transcation into serial transcation is know as conflict transcation.
 

 ### Recoverable schedules

- To  recover conflict    

## Concurrency control
- Concurrency control protocols ensure atomicity, isolation, and         serializability of concurrent transactions. The concurrency control   protocol can be divided into three categories:

1.    Time  Stamping
-   It allows conflict seriablity and view serialiblity.
- possiblity of dirty read and no commit restrictions, irrecoverable schedules and cascading rollbacks are possible.

T.s subset of conflict serializeable.

2. ## 2-way locking
- In this trascation will at two phase first growing and shrinking. 
- In growing phase it will have lock and it cannot release in that  phase.
- In shrinking phase transcation cannot acquire a lock.
- Trancatios can perform read and write operation in between the two lock .- may generate in cascading rollback.