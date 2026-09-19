# Write your MySQL query statement below
select t1.project_id ,ROUND(SUM(t2.experience_years) / count(t2.experience_years) , 2) as average_years
from Project t1 
LEFT JOIN Employee t2 
ON t1.employee_id= t2.employee_id 
group by project_id 