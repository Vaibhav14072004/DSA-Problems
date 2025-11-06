# approach 1 -> window function (dense rank)

/*
select Department, Employee, Salary from
(select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() OVER (
PARTITION BY d.name ORDER BY e.salary desc) AS drank
from Employee e JOIN Department d on e.departmentId= d.id) t
where t.drank= 1 
*/


# approach 2 -> window func (dense rank)

WITH CTE AS (
    select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() 
    OVER (PARTITION BY d.name ORDER BY e.salary desc) AS drank
    FROM Employee e JOIN Department d on e.departmentId= d.id
) 

SELECT Department,Employee,Salary from CTE where drank= 1;
