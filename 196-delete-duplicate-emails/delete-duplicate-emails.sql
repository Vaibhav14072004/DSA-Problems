# Approach 2 -> USING ROW_NUMBER() window function...

with temp as(
    select id, row_number() over (partition by email order by id) as rn from Person
)

delete from Person where id in(
    select id from temp where rn > 1
);



/* If we want to display only the duplicate records

Select id, email FROM (select id, email, row_number() OVER (PARTITION by email order by id asc) as rn from Person) t WHERE t.rn > 1;

*/


# Approach 1 -> Using SELF JOIN

/*
DELETE p1 FROM Person p1 INNER JOIN Person p2 on p1.email = p2.email 
WHERE p1.id > p2.id;
*/