
select Department, Employee, Salary from
(select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() OVER (
PARTITION BY d.name ORDER BY e.salary desc) AS drank
from Employee e JOIN Department d on e.departmentId= d.id) t
where t.drank= 1 
