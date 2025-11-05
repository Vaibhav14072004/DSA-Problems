# Approach 3 ->

SELECT(
 SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1
) as SecondHighestSalary;


# Approach 2 ->

/*
SELECT(
SELECT DISTINCT e1.salary FROM Employee e1 WHERE 1= (
    SELECT COUNT(DISTINCT salary) FROM Employee e2 WHERE e1.salary < e2.salary)
) AS SecondHighestSalary;
*/


# Approach 1 -> 

/*
SELECT DISTINCT MAX(salary) AS SecondHighestSalary FROM Employee WHERE salary NOT in  
( SELECT DISTINCT MAX(salary) FROM Employee);
*/