# Write your MySQL query statement below
select employee_id from Employees t1
where (select sum(t1.manager_id = employee_id) from Employees) =0 and salary <30000
order by t1.employee_id;