# Write your MySQL query statement below
select e.employee_id , e.department_id from
Employee e
where primary_flag = 'Y' or (select count(primary_flag) from Employee where employee_id = e.employee_id) = 1
group by e.employee_id; 
