CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

      SELECT DISTINCT e1.salary from Employee e1 WHERE N-1= 
      ( SELECT COUNT(DISTINCT SALARY) FROM Employee e2 where e2.salary > e1.salary)

  );
END