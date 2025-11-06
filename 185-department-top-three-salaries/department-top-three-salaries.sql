# Approach 1 -> window function (dense_rank)

WITH CTE AS(
    select d.name as Department, e.name as Employee, e.salary as Salary, 
    dense_rank() over (partition by e.departmentId order by e.salary desc) as drank
     FROM Employee e JOIN Department d on e.departmentId= d.id
)

select Department, Employee, Salary from CTE where drank <= 3;