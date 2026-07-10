# Write your MySQL query statement below

with cte as (
    select d.name as Department, e.name as Employee, e.salary as Salary,
     dense_rank() over (partition by d.name order by e.salary desc) as drank
    from Employee e JOIN Department d on e.departmentId= d.id
)

select Department,Employee,Salary from cte where drank = 1