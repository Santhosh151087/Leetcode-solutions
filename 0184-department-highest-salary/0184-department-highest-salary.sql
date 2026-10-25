# Write your MySQL query statement below
select t2.name as Department , t1.name as Employee , t1.salary as Salary 
from Employee t1
LEFT JOIN Department t2
ON t1.departmentId = t2.id
where t1.salary = (select max(salary) from Employee where departmentId = t1.departmentId)