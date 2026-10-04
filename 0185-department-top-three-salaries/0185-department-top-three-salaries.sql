select t2.name as Department , t1.name as Employee , t1.Salary
from
(
select name , Salary , departmentId , DENSE_RANK() OVER(
    PARTITION BY departmentID
    order by salary desc
    
) as rankk
from Employee
) as t1

LEFT JOIN Department t2
ON t1.departmentId = t2.id 
where t1.rankk<=3
order by Department;