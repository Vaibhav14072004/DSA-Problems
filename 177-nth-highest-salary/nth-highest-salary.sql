# Approach 2 

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

    # Bcoz we need Nth highest salary
    SET N= N-1;

  RETURN (
    # write your MySQL query statment below
     SELECT DISTINCT SALARY FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET N
  );
  END





# Approach 1
/*

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

      SELECT DISTINCT e1.salary from Employee e1 WHERE N-1= 
      ( SELECT COUNT(DISTINCT SALARY) FROM Employee e2 where e2.salary > e1.salary)

  );
END

*/

