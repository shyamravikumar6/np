<<<<<<< HEAD
#POSTGRE SQL    
=======
# POSTGRE SQL    
>>>>>>> 519c8971bce270f5df7033e1c55d09bf30755f6c
- post gre sql two name can be concatinated by using some special syntax like 

first_name || '' || last_name  AS  full_name

``
SELECT
	film_id,
	title,
	release_year
FROM
	film
ORDER BY
	film_id
LIMIT 4 OFFSET 3;
``

### fetch clause use:
 SELECT
    film_id,
    title
FROM
    film
ORDER BY
    title 
FETCH FIRST 1 ROW ONLY;

### important concept of null the NULL=Null it return false 
- because null is also not even equal to itself 
 use this syntax 
  
  - SELECT
    id,
    first_name,
    last_name,
    email,
    phone
FROM
    contacts
WHERE
    phone IS NULL;



## inner Joins
SELECT
    a,
    fruit_a,
    b,
    fruit_b
FROM
    basket_a
INNER JOIN basket_b
    ON fruit_a = fruit_b;

![](https://sp.postgresqltutorial.com/wp-content/uploads/2018/12/PostgreSQL-Join-Inner-Join.png)
