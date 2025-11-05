# Write your MySQL query statement below

  SELECT DISTINCT MAX(salary) AS SecondHighestSalary FROM Employee WHERE salary NOT in
  ( SELECT DISTINCT MAX(salary) FROM Employee);