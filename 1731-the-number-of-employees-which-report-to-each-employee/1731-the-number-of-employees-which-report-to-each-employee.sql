# Write your MySQL query statement below
SELECT m.employee_id , m.name , COUNT(e.employee_id) as reports_count , ROUND(AVG(e.age),0) as average_age
from Employees m 
LEFT JOIN Employees e
ON m.employee_id = e.reports_to
group by m.employee_id
HAVING reports_count !=0
order by m.employee_id;