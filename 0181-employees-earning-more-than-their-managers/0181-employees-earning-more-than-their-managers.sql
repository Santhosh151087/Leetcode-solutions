# Write your MySQL query statement below
select name as 'Employee'
from Employee t1
where managerId is not null and salary> (select DISTINCT salary from Employee where id = t1.managerId);