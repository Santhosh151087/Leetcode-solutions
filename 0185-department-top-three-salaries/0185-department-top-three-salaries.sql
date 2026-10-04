select t2.name as Department , t1.name as Employee , t1.salary  as Salary 
from Employee t1
LEFT JOIN Department t2
on t2.id = t1.departmentId
where (select count(DISTINCT salary) from Employee where
departmentId = t1.departmentId and t1.salary<salary
)<=2
order by  t2.id , salary DESC;