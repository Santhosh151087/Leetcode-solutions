# Write your MySQL query statement below
select (
    select DISTINCT salary 
from (
select  salary , DENSE_RANK() over(order by salary DESC) as rankk from Employee

) as t
where rankk = 2
) as SecondHighestSalary