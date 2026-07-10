# Write your MySQL query statement below

with cte as (
select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() OVER (PARTITION BY d.name ORDER BY e.salary DESC) as drank from Employee e INNER JOIN Department d ON e.departmentId= d.id )

select Department, Employee, Salary from cte where drank <= 3